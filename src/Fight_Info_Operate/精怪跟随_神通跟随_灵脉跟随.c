#include <stdio.h>
#include <stdlib.h>
#define DEBUG printf("---debug位置---\n行号:%d\n文件名:<%s>",__LINE__,__FILE__);getchar();
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

//extern short 第几场;

void 精怪跟随(Fight_info * self, Fight_info * opponent, char *时刻)
{
	if (self->处于冰冻状态) return;
	
	/*
	for (int i = 0; i < self->精怪数量/第几场; i++)
	{
		if (第几场>1){
		printf("num:%d\n",self->精怪数量);
		for (int n=self->精怪数量/第几场; n<self->精怪数量; n++)
		{
			printf("p:%p\n",&self->精怪分组[n]);
			printf("group[%d]:%s\n",n,self->精怪分组[n]);
		}
		DEBUG}
		
		// printf("第%d/%d:%s",i+1,self->精怪数量,self->精怪分组[i]);
		// getchar();
		检查精怪(self, opponent, self->精怪分组[i+(self->精怪数量/第几场)*(第几场-1)], 时刻);
	}
	
	for (int i = 0; i < self->精怪数量; i++)
	{
		检查精怪(self, opponent, self->精怪分组[i+(self->精怪数量/第几场)*(第几场-1)], 时刻);
	}
	*/
	
	for (int i = 0; i < self->精怪数量; i++)
	{	
		// printf("第%d/%d:%s",i+1,self->精怪数量,self->精怪分组[i]);
		// getchar();
		检查精怪(self, opponent, self->精怪分组[i], 时刻);
	}
}


void 神通跟随(Fight_info * self, Fight_info * opponent, char *时刻)
{
	for (int i = 0; i < self->神通数量; i++)
	{
		检查神通(self, opponent, self->神通分组[i], 时刻);
	}
}

void 灵脉跟随(Fight_info *self, char *时刻)
{
	if (!strcmp(时刻,"回合开始时") && self->朱雀灵脉层数>0)
	{
		self->战斗属性之击晕+=6+2*(self->朱雀灵脉层数-1);
	}
	
	// 成功闪避
	if (!strcmp(时刻,"成功闪避") && self->勾陈灵脉层数>0)
	{
		if (self->触发计数->勾陈灵脉<5)
		{
			self->强灵系数 += 0.04 + 0.02*(self->勾陈灵脉层数-1);
			self->触发计数->勾陈灵脉++;
		}
	}
	
	// 成功暴击
	if (!strcmp(时刻,"成功暴击") && self->青龙灵脉层数>0)
	{
		self->暴伤系数+=(7+5*self->青龙灵脉层数)/100.0;
	}
}