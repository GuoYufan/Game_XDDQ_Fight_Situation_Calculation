#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"
#include "../../../../Common/GYF/include/GYF.h"

void 计算实际击晕率(Fight_info *self, Fight_info *opponent)
{
	self->击晕率 = self->战斗属性之击晕-opponent->战斗抗性之抗晕;	
	
	if (self->击晕率<0)
	{
		self->击晕率 = 0;
		return;
	}
	
	if (self->击晕率>80)
	{
		self->击晕率 = 80;
		return;
	}
}

void 战斗属性_setter(Fight_info *self,Fight_info *opponent, char *名称, float value)
{
	if (!strcmp(名称, "暴击"))
	{
		self->战斗属性之暴击=value;
		计算实际暴击率(self,opponent);
	}
	else if (!strcmp(名称, "击晕"))
	{
		self->战斗属性之击晕=value;
		计算实际击晕率(self,opponent);
	}
}

void 计算实际暴击率(Fight_info *self, Fight_info *opponent)
{
	self->暴击率 = self->战斗属性之暴击-opponent->战斗抗性之抗暴;	
	
	if (self->暴击率<0)
	{
		self->暴击率 = 0;
		return;
	}
	
	if (self->暴击率>100)
	{
		self->暴击率 = 100;
		return;
	}
}


bool 击晕率是否足够(Fight_info * self, Fight_info * opponent)
{
	计算实际击晕率(self,opponent);
	
	if (self->除了设置漏晕以外的皆必晕 && self->漏晕几次==0)
	{
		return true;
	}

	short 随机数=rand() % 100 + 1;
	printf("随机数%d",随机数);	
	return in_interval(随机数, 1, self->击晕率);
}


bool 暴击率是否足够(Fight_info * self, Fight_info * opponent)
{
	计算实际暴击率(self,opponent);

	short 随机数=rand() % 100 + 1;
	//printf("随机数%d",随机数);	
	return in_interval(随机数, 1, self->暴击率);
}

/*
void main()
{
	srand(time(NULL));
	printf("%d",in_interval(rand()%100+1,1,80.5));
}
*/

void 被击晕(Fight_info * self)
{
	self->被晕的需要失去几次行动++;
	self->处于被晕状态=1;
}



void 击晕判定及相关经过(Fight_info *self, Fight_info *opponent)
{
	if (opponent->处于被晕状态)
	{
		printf("❌%s人物仍然处于由于被晕造成的不可行动, 所以不可被由击晕使不可行动, 所以不可被%s人物击晕\n", opponent->哪一方, self->哪一方);
	}
	else
	{
		if (击晕率是否足够(self, opponent) && self->漏晕几次<=0)
		{
			printf("⏰%s人物成功击晕%s人物, ", self->哪一方, opponent->哪一方);
			被击晕(opponent);
		}
		else 
		{
			if (self->漏晕几次>0) self->漏晕几次--;
			printf("❌%s人物击晕失败, ", self->哪一方);
		}
		printf("此前面板击晕率%g%%, 实际击晕率%g%%\n",
		 self->战斗属性之击晕-opponent->战斗抗性之抗晕, self->击晕率);
	}
}


void 暴击判定及相关经过(Fight_info *self, Fight_info *opponent)
{
	if (暴击率是否足够(self, opponent))
	{
		printf("⏰%s人物成功暴击%s人物, ", self->哪一方, opponent->哪一方);
		self->触发了暴击=true;
		printf("此前面板暴击率%g%%, 实际暴击率%g%%, ",
		 self->战斗属性之暴击-opponent->战斗抗性之抗暴, self->暴击率);
		printf("暴伤系数%g\n",self->暴伤系数);
	}
	else 
	{
		//printf("❌%s人物暴击失败, ", self->哪一方);
		self->触发了暴击=false;
	}
}