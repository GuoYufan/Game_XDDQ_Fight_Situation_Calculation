#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"
#include "../../include/双方初始信息.h"

void 释放道法(Fight_info *self, Fight_info *opponent)
{
	if (self->道法伤倍率_乘在攻 != 0)
	{
		计算本次伤害(self, opponent, "道法伤");
		// 道法暴击
		//if (strstr(self->哪一方,"先")) self->本次伤害*=2;	
		printf("%s人物道法神通%s攻击力伤%g%%\n", self->哪一方, self->道法名称, self->本次伤害 * 100);
		受伤(opponent, self, self->本次伤害 );
	}
	
	if (self->道法回血倍率_乘在攻 != 0)
	{
		计算本次治疗(self, opponent, "道法回血");
		printf("%s人物道法神通%s攻击力回血%g%%\n",
		 self->哪一方, self->道法名称,  self->本次治疗*100);
		治疗(self);
	}
	
	if (!strcmp(self->道法名称, "五行补缺"))
	{
		self->本次治疗=self->已损生命*0.2;
		printf("%s人物道法神通%s效果回血%g%%\n",
		 self->哪一方, self->道法名称,  self->本次治疗*100);
		治疗(self);		
	}
	
	
	妖气变化(self, -2);
	
	if (!strcmp(self->道法名称, "冰封千里"))
	{
		if (!opponent->免疫冰冻燃烧回合数 && !opponent->被冰冻的需要失去几次行动)
		{
			opponent->被冰冻的需要失去几次行动++;
			opponent->处于冰冻状态=true;
		}
	}
}



void 进行普攻(Fight_info *self, Fight_info *opponent)
{
	计算本次伤害(self, opponent, "有视防御伤");
	printf("%s人物普攻%g%%\n", self->哪一方, self->本次伤害 * 100);
	妖气变化(self, -1);
	受伤(opponent, self, self->本次伤害 );
}


void 解复活未起身(Fight_info *self, Fight_info *opponent)
{
	Fight_info *先手方=self, *后手方=opponent;

	if (strstr(self->哪一方, "后") != NULL)
	{
		先手方=opponent;
		后手方=self;
	}
	
	if (self->复活未起身 && self->被冰冻的需要失去几次行动==0)
	{
		self->复活未起身=0;
		short 是碎心法复活的=(strstr(self->携带神通, "碎心法")!=NULL);
		self->已损生命=(1 - (是碎心法复活的?self->神通图鉴->碎心法_回血量:self->神通图鉴->扶桑_回血量));
		self->可复活次数--;
		
		printf("⚡️️(目前:先手方%g%% VS 后手方%g%%)\n", 后手方->已损生命*100,
				   先手方->已损生命*100);
		
		if (是碎心法复活的)
		{
			神通跟随(self,opponent,"");
			精怪跟随(self,opponent,"");
		}
		else
		{
			精怪跟随(self,opponent,"");
			神通跟随(self,opponent,"");
		}
	}
}


void 检查人物受控状态是否可恢复(Fight_info * self)
{
	if (self->处于被晕状态)
	{
		if (self->被晕的需要失去几次行动==0)
		{
			self->处于被晕状态=0;
			printf("✅%s人物被晕状态已恢复\n", self->哪一方);
		}
		else
			printf("❗️%s人物被晕状态未恢复\n", self->哪一方);
	}
	
	if (self->处于冰冻状态)
	{
		if (self->被冰冻的需要失去几次行动==0)
		{
			self->处于冰冻状态=false;
			printf("✅%s人物冰冻状态已恢复\n", self->哪一方);
		}
		else
			printf("❗️%s人物冰冻状态未恢复\n", self->哪一方);
	}
	
}


void 轮序到人物(Fight_info *self, Fight_info *opponent)
{
	if (Save_hasChanged(self,"被晕的需要失去几次行动"))
	{
		printf("⭐️%s人物需要因为被晕失去%d次行动\n", self->哪一方, self->被晕的需要失去几次行动);
		Save_update(self,"被晕的需要失去几次行动");
	}
	if (Save_hasChanged(opponent,"复活未起身"))
	{
		printf("⭐️%s人物复活未起身:%s\n", opponent->哪一方, opponent->复活未起身?"是":"否");
		Save_update(opponent,"复活未起身");
	}
	if (Save_hasChanged(self,"被冰冻的需要失去几次行动"))
	{
		printf("⭐️%s人物需要因为被冰冻失去%d次行动\n", self->哪一方, self->被冰冻的需要失去几次行动);
		Save_update(self,"被冰冻的需要失去几次行动");
	}
	
	
	
	if (self->复活未起身)
	{
		if (self->处于冰冻状态)
		{
			if (strstr(self->携带神通, "碎心法") == NULL)
			{
				printf("(%s方已死，扶桑被冰冻不能复活)\n", self->哪一方);
				printf("\n📖\n(%s方告负)\n", self->哪一方);
				
				//统一free(self,opponent);
				exit(EXIT_SUCCESS);
			}
			
			self->被冰冻的需要失去几次行动--;
			if (self->被冰冻的需要失去几次行动<0) self->被冰冻的需要失去几次行动=0;
			return;
		}
		else
		{
			printf("(%s复活未起身:%s 可复活次数:%d)\n",
			 self->哪一方, self->复活未起身?"是":"否", self->可复活次数);
			解复活未起身(self,opponent);
		}
	}
	
	if (!opponent->复活未起身 && !(self->处于冰冻状态 || self->处于被晕状态))
	{
		精怪跟随(self, opponent, "普攻前");
		神通跟随(self, opponent, "普攻前");
		神通跟随(opponent, self, "受击");
		击晕判定及相关经过(self, opponent);
		暴击判定及相关经过(self, opponent);

		if (self->已完成补气)
			释放道法(self, opponent);
		else 进行普攻(self, opponent);
		神通跟随(self, opponent, "普攻后");
		精怪跟随(self, opponent, "普攻后");
	
	}
	else
	{
		if (self->被冰冻的需要失去几次行动>0)
		{
			self->被冰冻的需要失去几次行动--;
			if (self->被冰冻的需要失去几次行动<0) self->被冰冻的需要失去几次行动=0;
		}
		
		if (self->被晕的需要失去几次行动>0)
		{
			self->被晕的需要失去几次行动--;
			if (self->被晕的需要失去几次行动<0) self->被晕的需要失去几次行动=0;
		}
	}
	
}


void 灵兽效果(Fight_info *self, Fight_info *opponent, char *灵兽名称)
{
	if (!strcmp(灵兽名称, "青龙"))
	{
		if (self->灵兽图鉴->青龙_层数 < self->灵兽图鉴->青龙_满层)
		{
			计算实际暴击率(self, opponent);
			printf("(灵兽效果：此前暴击率%g%%, ", self->暴击率);
			战斗属性_setter(self,opponent,"暴击",self->战斗属性之暴击+self->灵兽图鉴->青龙_战斗属性之暴击加成);
			self->灵兽图鉴->青龙_层数++;
			printf("现暴击率%g%%)", self->暴击率);	
		}
	}
	
	// 玄武是强疗。当前版本计算器暂时不考虑强疗系数。
}


void 轮序到灵兽(Fight_info *self, Fight_info *opponent)
{
	if (self->第几回合 % self->主灵兽出手频率 == 0)
	{
		精怪跟随(self, opponent, "灵兽释放技能时");
		神通跟随(self, opponent, "灵兽释放技能时");
		
		if (self->主灵兽回血倍率_乘在攻 != 0)
		{
			if (self->复活未起身) return;
			计算本次治疗(self, opponent, "主灵兽回血");
			printf("%s主灵兽%s回血%g%%", self->哪一方, self->主灵兽名称, self->本次治疗 * 100);
			治疗(self);
			灵兽效果(self, opponent, self->主灵兽名称);
			putchar(10);
		}
		else
		{
			if (opponent->复活未起身) return;
			计算本次伤害(self, opponent, "主灵兽伤");	
			printf("%s主灵兽%s%g%%", self->哪一方, self->主灵兽名称, self->本次伤害 * 100);
			受伤(opponent, self, self->本次伤害);
			灵兽效果(self, opponent, self->主灵兽名称);
			putchar(10);
		}
	}
	
	if (self->第几回合 % self->协同灵兽出手频率 == 0)
	{
		if (rand()%100+1 > self->协同灵兽出手概率*100) return;
		
		精怪跟随(self, opponent, "灵兽释放技能时");
		神通跟随(self, opponent, "灵兽释放技能时");
		
		if (self->协同灵兽回血倍率_乘在攻 != 0)
		{
			if (self->复活未起身) return;
			计算本次治疗(self, opponent, "协同灵兽回血");
			printf("%s协同灵兽%s回血%g%%", self->哪一方, self->协同灵兽名称, self->本次治疗 * 100);
			治疗(self);
			灵兽效果(self, opponent, self->协同灵兽名称);
			putchar(10);
		}
		else
		{
			if (opponent->复活未起身) return;
			计算本次伤害(self, opponent, "协同灵兽伤");	
			printf("%s协同灵兽%s%g%%", self->哪一方, self->协同灵兽名称, self->本次伤害 * 100);
			受伤(opponent, self, self->本次伤害);
			灵兽效果(self, opponent, self->协同灵兽名称);
			putchar(10);
		}
	}
}