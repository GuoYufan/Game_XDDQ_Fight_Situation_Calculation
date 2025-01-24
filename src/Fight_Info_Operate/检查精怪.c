#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

void 检查精怪(Fight_info * self, Fight_info * opponent, char *精怪名称, char *时刻)
{
	if (!strcmp(精怪名称, "小龙女") && !self->小龙女已触发 && self->已损生命>=self->精怪图鉴->小龙女_血线)
	{
		if (self->复活未起身) return;
		printf("🧥\n%s精怪%s触发\n", self->哪一方, 精怪名称);
		opponent->增伤系数-=self->精怪图鉴->小龙女_减伤;
		self->小龙女已触发=true;
		return;
	}
		
	if (!strcmp(精怪名称, "山泽精") && !self->山泽精已触发 && self->已损生命>=self->精怪图鉴->山泽精_血线)
	{
		if (self->复活未起身) return;
		printf("🌳\n%s精怪%s触发\n", self->哪一方, 精怪名称);
		计算本次治疗(self,opponent,"山泽精");
		printf("%s精怪山泽精回血%g%%\n", self->哪一方, self->本次治疗*100);
		治疗(self);
		self->山泽精已触发=true;
		return;
	}
	

	if (!strcmp(精怪名称, "干饭人") && !strcmp(时刻, "回合开始时"))
	{
		if (self->复活未起身) return;
		if (self->已损生命==0) return;
		printf("❗️%s精怪%s触发\n", self->哪一方, 精怪名称);
		计算本次治疗(self,opponent,"干饭人");
		printf("%s精怪干饭人回血%g%%\n", self->哪一方, self->本次治疗*100 );
		治疗(self);
		return;
	}

	if (!strcmp(精怪名称, "大树妖") && !strcmp(时刻, "普攻前")
		&& self->精怪图鉴->大树妖_层数<5)
	{
		self->强灵系数 += self->精怪图鉴->大树妖_强灵加成;
		self->精怪图鉴->大树妖_层数++;
		printf("❗️%s精怪%s触发, 目前%d层",
		 self->哪一方, 精怪名称, self->精怪图鉴->大树妖_层数 );
		 
		if (self->精怪图鉴->大树妖_层数==self->精怪图鉴->大树妖_满层) printf("(现已满层)");
		printf(", 强灵系数%g",self->强灵系数);
		putchar(10);
		return;
	}

	if (!strcmp(精怪名称, "雷公") && !strcmp(时刻, "灵兽释放技能时")
		&& self->雷公层数<5)
	{
		if (opponent->复活未起身) return;
		
		self->雷公层数++;
		计算本次伤害(self,opponent,"雷公");
		self->战斗属性之击晕+=5;
		
		printf("❗️%s精怪%s触发, 目前%d层, 造成%g%%伤害, 战斗属性之击晕%g%%\n",
			   self->哪一方, 精怪名称, self->雷公层数, self->本次伤害 * 100, self->战斗属性之击晕);
			   
		受伤(opponent, self, self->本次伤害);
		return;
	}
	
	if (!strcmp(精怪名称, "紫晴龙狮") && !strcmp(时刻, "回合开始时"))
	{
		if (opponent->复活未起身) return;
		计算本次伤害(self, opponent, "紫晴龙狮伤");
		printf("❗️%s精怪%s触发\n", self->哪一方, 精怪名称);
		printf("%s精怪%s造成伤害%g%%\n", self->哪一方, 精怪名称, self->本次伤害*100);
		受伤(opponent, self, self->本次伤害);
		return;
	}
	
	if (!strcmp(精怪名称, "皇帝") && !strcmp(时刻, "回合开始时"))
	{
		if (self->皇帝已触发) return;
		计算本次伤害(self, opponent, "皇帝伤");
		printf("❗️%s精怪%s触发\n", self->哪一方, 精怪名称);
		printf("%s精怪%s造成伤害%g%%\n", self->哪一方, 精怪名称, self->本次伤害*100);
		受伤(opponent, self, self->本次伤害);		
		击晕判定及相关经过(self, opponent);
		self->皇帝已触发=true;
		return;
	}
	
	if (!strcmp(精怪名称, "大明王") && !strcmp(时刻, "普攻后"))
	{
		// static也是可行的。static也是一种存档作用。它只初始化一次。
		// static short 大明王已触发几次=0;
		
		if (self->精怪图鉴->大明王_层数>=self->精怪图鉴->大明王_满层) return;
		
		战斗属性_setter(self, opponent, "暴击", self->战斗属性之暴击+8);
		self->精怪图鉴->大明王_层数++;
		printf("❗️%s精怪%s触发, 目前%d次",
		 self->哪一方, 精怪名称, self->精怪图鉴->大明王_层数 );
		 
		if (self->精怪图鉴->大明王_层数==self->精怪图鉴->大明王_满层) printf("(现已满)");
		printf(", 暴击率%g%%",self->暴击率);
		putchar(10);
	}
	
	
	if (!strcmp(精怪名称, "虞美人") && !self->虞美人已触发 && self->第几回合==3 && !strcmp(时刻, "回合开始时"))
	{
		self->强疗系数+=0.2;
		self->虞美人已触发=true;
	}
}