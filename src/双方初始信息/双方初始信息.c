#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../Common/GYF/include/GYF.h"
#include "../../include/Fight_Info_Struct.h"
#include "../../include/双方初始信息.h"

void Fight_info_show(Fight_info * self)
{
	printf("攻:%g 血:%g 防:%g 敏:%g\n", self->攻, self->血, self->防, self->敏);
}

void Fight_info_input(Fight_info * self, const char *prompt)
{
	while (1)
	{
		puts(prompt);
		if (scanf("%g%g%g%g", &self->攻, &self->血, &self->防, &self->敏) != 4
			|| getchar() != 10)
		{
			puts("❌输入无效，请重新输入。\n");
			while (getchar() != 10);
			continue;
		}
		break;
	}
}

void Fight_info_init(Fight_info * self, char *who)
{
	/*
	当前对手(self,who);
	if (!strcmp(who,"我"))
	{
		应龙流(self,5);
		//鸾鸟流(self,1.11);
		
	}
	*/
	
	// 当前对手_另一个号反暴的(self,who);

	/*if (!strcmp(who,"敌")) 
	{
		将人物能力置为默认值(self,1);
		应龙流(self,5);
		self->敏+=100;
	}
	else 
	{
		将人物能力置为默认值(self,1);
		应龙流(self,5);
	}*/
	
	// 当前对手_97亿越战140亿(self,who);
	
	当前对手_回归斗法打1点6倍对手(self,who);
	
	// 当前对手_新区炼气之前(self,who);


}


/* 
   轮序到协同灵兽(轮序方,对方) { if
   (!strcmp(轮序方->协同灵兽名称,"计蒙") { 对方->强疗-=0.5;
   对方->减强疗buff回合数+=2; } }


   每回合自动变化() { if (每一方->减强疗buff回合数>0) {
   每一方->减强疗buff回合数-=1; }

   if (每一方->减强疗buff回合数==0) { 强疗 }



   }

   协同灵兽是否行动(协同灵兽行动概率) { srand(time(NULL);
   随机数=rand()%100+1; if (in_interval(随机数,1,20)) { return 1； }
   return 0;

   }
*/


void 当前对手_新区炼气之前(Fight_info *self, char *who)
{
	双方初始信息的开头统一部分以及先行初始化(self);
	
	if (!strcmp(who, "敌"))
	{
		self->攻=1935;
		self->血=13440;
		self->剩余生命=self->血;
		self->防=387;
		self->敏=574;
	}
	else
	{
		self->攻=1742;
		self->血=11718;
		self->剩余生命=self->血;
		self->防=285;
		self->敏=485;
		self->战斗属性之暴击=30;
	}
	双方初始信息的结尾统一部分(self);

}

void 当前对手_回归斗法打1点6倍对手(Fight_info *self, char *who)
{
	双方初始信息的开头统一部分以及先行初始化(self);
	
	Creature_handbook_init(self,who);
	Beast_handbook_init(self,who);
	Avator_handbook_init(self,who);
	
	if (!strcmp(who, "敌"))
	{
		self->攻=47.57;
		self->血=428.25;
		self->剩余生命=self->血;
		self->防=7.1884;
		self->敏=4489;
		self->道法伤倍率_乘在攻=1.6;
		self->道法回血倍率_乘在攻=0;
		self->道法名称="法天象地";
		self->主灵兽伤倍率_乘在攻=5.5;
		self->主灵兽出手频率=5;
		self->主灵兽名称="应龙";
		self->协同灵兽伤倍率_乘在攻=0;
		self->协同灵兽回血倍率_乘在攻=1.42;
		self->协同灵兽出手频率=2;
		self->协同灵兽出手概率=0.25;
		self->协同灵兽名称="玄武";
		self->携带神通="法天象地,附灵术,煌气,金刚不坏";
		self->神通图鉴->扶桑_回血量=0.12;
		//self->神通图鉴->识海钉=0.028;
		self->增伤系数=(100 + 3.9 - 12.5) / 100.0;
		self->强灵系数=(100 + 16.1 - 3.7) / 100.0;
		self->携带精怪="扶桑,紫晴龙狮,大山妖";
		self->无视战斗属性=12.5;
		self->战斗抗性之抗晕=127;
		self->战斗属性之击晕=53;
		self->漏晕几次=0;
		self->自行设置额外伤=0;
		self->额外伤限定回合数=0;
		self->战斗属性之暴击=122.8;
		self->战斗抗性之抗暴=66.2;
	}
	else
	{
		self->攻=29.35;
		self->血=277.98;
		self->已损生命=0;
		self->剩余生命=self->血;
		self->防=4.7262;
		// 故意弄到后手方
		self->敏=4137;
		self->道法伤倍率_乘在攻=1.6;
		self->道法名称="冰封千里";
		self->主灵兽伤倍率_乘在攻=5;
		self->主灵兽回血倍率_乘在攻=0;
		self->主灵兽出手频率=5;
		self->主灵兽名称="应龙";
		self->协同灵兽伤倍率_乘在攻=0.6;
		self->协同灵兽回血倍率_乘在攻=0;
		self->协同灵兽出手频率=1;
		self->协同灵兽出手概率=0.25;
		self->协同灵兽名称="青龙";
		self->携带神通="冰封千里,蚀魂咒,碎心法,金刚不坏";
		self->神通图鉴->碎心法_回血量=0.12;
		self->增伤系数=(100 + 9.5 - 19.1) / 100.0;
		self->强灵系数=(100 + 14.6 - 1.4) / 100.0;
		self->携带精怪="山泽精,破阵书生,大明王";
		self->无视战斗属性=12.5;
		self->无视战斗抗性=8.9;
		self->战斗抗性之抗晕=132;
		self->战斗属性之击晕=45;
		self->朱雀灵脉层数=0;
		// 设置大于已知回合数可无晕
		self->漏晕几次=0;
		self->自行设置额外伤=0;
		self->额外伤限定回合数=0;
		self->战斗属性之暴击=134;
		self->战斗抗性之抗暴=109;
		self->暴伤系数+=(5-3.4)/100.0;
		self->青龙灵脉层数=4;
	}
	
	双方初始信息的结尾统一部分(self);
}


// 知陆暴击抗暴打猪了个猪击晕不抗暴
void 当前对手_97亿越战140亿(Fight_info *self, char *who)
{
	双方初始信息的开头统一部分以及先行初始化(self);

	if (!strcmp(who, "敌"))
	{
		self->攻=26.07;
		self->血=202.66;
		self->剩余生命=self->血;
		self->防=3.14;
		self->敏=6509;
		self->道法伤倍率_乘在攻=1.6;
		self->道法回血倍率_乘在攻=0;
		self->道法名称="冰封千里";
		self->主灵兽伤倍率_乘在攻=1.92;
		self->主灵兽出手频率=2;
		self->主灵兽名称="朱雀";
		self->协同灵兽伤倍率_乘在攻=0;
		self->协同灵兽回血倍率_乘在攻=0;
		self->协同灵兽出手频率=2;
		self->协同灵兽名称="玄武";
		self->携带神通="冰封千里,撼心咒,啸月,万妖体";
		self->神通图鉴->扶桑_回血量=0.12;
		//self->神通图鉴->识海钉=0.028;
		self->增伤系数=(100 + 188.9 - 159.4) / 100.0;
		self->强灵系数=(100 + 421.9 - 79.4) / 100.0;
		self->携带精怪="扶桑,小龙女,皇帝";
		self->精怪图鉴->皇帝_攻倍=3.11;
		self->无视战斗属性=36.3;
		self->无视战斗抗性=25.9;
		self->战斗抗性之抗晕=393.2;
		self->战斗属性之击晕=718.7;
		self->朱雀灵脉层数=4;
		self->漏晕几次=0;
		self->自行设置额外伤=0;
		self->额外伤限定回合数=0;
		self->战斗属性之暴击=334.2;
		self->战斗抗性之抗暴=574.9;
	}
	else
	{
		self->攻=20.32;
		self->血=147.78;
		self->已损生命=0;
		self->剩余生命=self->血;
		self->防=2.33;
		// 故意弄到后手方
		self->敏=468;
		self->道法伤倍率_乘在攻=1.6;
		self->道法名称="冰封千里";
		self->主灵兽伤倍率_乘在攻=1.08;
		self->主灵兽回血倍率_乘在攻=0;
		self->主灵兽出手频率=1;
		self->主灵兽名称="青龙";
		self->协同灵兽伤倍率_乘在攻=5.5;
		self->协同灵兽回血倍率_乘在攻=0;
		self->协同灵兽出手频率=5;
		self->协同灵兽名称="应龙";
		self->携带神通="冰封千里,灭心魔种,啸月,万妖体";
		self->神通图鉴->扶桑_回血量=0.12;
		self->增伤系数=(100 + 161.7 - 182.4) / 100.0;
		self->强灵系数=(100 + 143.4 - 90.1) / 100.0;
		self->携带精怪="扶桑";
		self->无视战斗属性=28.6;
		self->战斗属性之击晕=280.2;
		self->战斗抗性之抗晕=756.5;
		self->朱雀灵脉层数=0;
		// 设置大于已知回合数可无晕
		self->漏晕几次=0;
		self->自行设置额外伤=0;
		self->额外伤限定回合数=0;
		self->战斗属性之暴击=694.7;
		self->战斗抗性之抗暴=331.6;
		self->暴伤系数+=(205-43.1)/100.0;
	}
	
	双方初始信息的结尾统一部分(self);
}





// 另一个号：反暴号
void 当前对手_另一个号反暴的(Fight_info *self, char *who)
{
	双方初始信息的开头统一部分以及先行初始化(self);

	if (!strcmp(who, "敌"))
	{
		self->攻=24.8;
		self->血=197;
		self->剩余生命=self->血;
		self->防=4.7765;
		self->敏=3465;
		self->道法伤倍率_乘在攻=1.3;
		self->道法回血倍率_乘在攻=0.6;
		self->道法名称="噬魂汲髓";
		self->主灵兽伤倍率_乘在攻=4;
		self->主灵兽出手频率=5;
		self->主灵兽名称="应龙";
		self->协同灵兽伤倍率_乘在攻=1.2;
		self->协同灵兽回血倍率_乘在攻=0;
		self->协同灵兽出手频率=2;
		self->协同灵兽名称="鸾鸟";
		self->携带神通="拘神,共鸣,兽灵体";
		self->神通图鉴->扶桑_回血量=0.12;
		//self->神通图鉴->识海钉=0.028;
		self->增伤系数=(100 + 2.8 - 8.8) / 100.0;
		self->强灵系数=(100 +  10.8 - 3.7) / 100.0;
		self->携带精怪="扶桑,马面,大山妖";
		self->战斗抗性之抗晕=157;
		self->战斗属性之击晕=68;
		self->朱雀灵脉层数=0;
		self->漏晕几次=0;
		self->自行设置额外伤=0;
		self->额外伤限定回合数=0;
		self->百分百闪避=true;
		self->勾陈灵脉层数=3;
	}
	else
	{
		self->攻=28.4;
		self->血=276.43;
		self->已损生命=0;
		self->剩余生命=self->血;
		self->防=4.7262;
		// 故意弄到后手方
		self->敏=4137;
		self->道法伤倍率_乘在攻=1.6;
		self->道法名称="冰封千里";
		self->主灵兽伤倍率_乘在攻=5;
		self->主灵兽回血倍率_乘在攻=0;
		self->主灵兽出手频率=5;
		self->主灵兽名称="应龙";
		self->协同灵兽伤倍率_乘在攻=0.6;
		self->协同灵兽回血倍率_乘在攻=0;
		self->协同灵兽出手频率=1;
		self->协同灵兽名称="青龙";
		self->携带神通="冰封千里,蚀魂咒,碎心法,铜皮铁骨";
		self->神通图鉴->碎心法_回血量=0.12;
		self->神通图鉴->识海钉=0.03;
		self->增伤系数=(100 + 9.5 - 9.2) / 100.0;
		self->强灵系数=(100 + 14.6 - 8.5) / 100.0;
		self->大树妖层数=0;
		self->携带精怪="山泽精,破阵书生";
		self->战斗属性之击晕=43+8.9;
		self->战斗抗性之抗晕=132+12.5;
		self->朱雀灵脉层数=0;
		// 设置大于已知回合数可无晕
		self->漏晕几次=0;
		self->自行设置额外伤=0;
		self->额外伤限定回合数=0;
	}
	
	双方初始信息的结尾统一部分(self);
}



//主号：击晕号
void 当前对手(Fight_info *self, char *who)
{
	双方初始信息的开头统一部分以及先行初始化(self);

	if (!strcmp(who, "敌"))
	{
		self->攻=55.9949;
		self->血=524.63;
		self->剩余生命=self->血;
		self->防=9.5549;
		self->敏=4045;
		self->道法伤倍率_乘在攻=2.2;
		self->道法回血倍率_乘在攻=0;
		self->道法名称="七十二变";
		self->主灵兽伤倍率_乘在攻=5;
		self->主灵兽回血倍率_乘在攻=0;
		self->主灵兽出手频率=5.5;
		self->主灵兽名称="应龙";
		self->协同灵兽伤倍率_乘在攻=0.72;
		self->协同灵兽回血倍率_乘在攻=0;
		self->协同灵兽出手频率=1;
		self->协同灵兽名称="青龙";
		self->携带神通="";
		self->神通图鉴->扶桑_回血量=0.12;
		self->神通图鉴->碎心法_回血量=0.12;
		self->增伤系数=(100 + 3.5 - 13.5) / 100.0;
		self->强灵系数=(100+ 8.1 - 6.3) / 100.0;
		self->携带精怪="小龙女";
		self->战斗抗性之抗晕=93;
		self->战斗属性之击晕=58;
		self->朱雀灵脉层数=1;
		self->漏晕几次=0;
		self->额外伤限定回合数=0;
		self->自行设置额外伤=0;
		// 威吓暂用
		self->强灵系数+=0.2;
	}
	else
	{
		self->攻=27.7;
		self->血=276;
		self->已损生命=0;
		self->剩余生命=self->血;
		self->防=4.8;
		// 故意弄到后手方
		self->敏=4646;
		self->道法伤倍率_乘在攻=1.2;
		self->道法名称="三味火";
		self->主灵兽伤倍率_乘在攻=0;
		self->主灵兽回血倍率_乘在攻=1.11;
		self->主灵兽出手频率=2;
		self->主灵兽名称="鸾鸟";
		self->协同灵兽伤倍率_乘在攻=0;
		self->协同灵兽回血倍率_乘在攻=0.85;
		self->协同灵兽出手频率=2;
		self->协同灵兽名称="鸾鸟";
		self->携带神通="三味火,识海钉,碎心法,化羽";
		self->神通图鉴->碎心法_回血量=0.12;
		self->神通图鉴->识海钉=0.028;
		self->增伤系数=(100 + 6.8 - 5.8) / 100.0;
		self->强灵系数=(100 + 4.3 - 15.1) / 100.0;
		self->大树妖层数=0;
		self->携带精怪="小龙女,大树妖";
		self->战斗属性之击晕=212+6;
		self->战斗抗性之抗晕=113+8;
		self->朱雀灵脉层数=4;
		// 设置大于已知回合数可无晕
		// 设置漏晕0次，以及「除了设置漏晕以外的皆必晕」为true，可必晕
		self->漏晕几次=0;
		self->除了设置漏晕以外的皆必晕=true ;
		//self->自行设置额外伤=30.0527/52.428*0.03;
		//self->额外伤限定回合数=20;
	}
	
	双方初始信息的结尾统一部分(self);
}


// 随时准备下次打的对手：妖盟悬赏
/*
void 当前对手(Fight_info *self, char *who)
{
	双方初始信息的开头统一部分以及先行初始化(self);

	if (!strcmp(who, "敌"))
	{
		self->攻=50.6;
		self->血=480;
		self->剩余生命=self->血;
		self->防=8.72;
		self->敏=4243;
		self->道法伤倍率_乘在攻=1.2;
		self->道法回血倍率_乘在攻=0;
		self->道法名称="三味火";
		self->主灵兽伤倍率_乘在攻=5.5;
		self->主灵兽出手频率=5;
		self->主灵兽名称="应龙";
		self->协同灵兽伤倍率_乘在攻=0;
		self->协同灵兽回血倍率_乘在攻=1.42;
		self->协同灵兽名称="玄武";
		self->携带神通="三味火,侵神三重,灵脉唤醒,金刚不坏";
		self->神通图鉴->扶桑_回血量=0.12;
		self->增伤系数=(100 + 3.5 - 13.5) / 100;
		self->强灵系数=(100+ + 8.5 - 4.4) / 100;
		self->携带精怪="扶桑,大树妖,山魈";
		self->战斗抗性之抗晕=120;
		self->战斗属性之击晕=97;
		self->朱雀灵脉层数=0;
	}
	else
	{
		self->攻=27.8;
		self->血=281;
		self->已损生命=0;
		self->剩余生命=self->血;
		self->防=4.8;
		self->敏=4458;
		self->道法伤倍率_乘在攻=2.2;
		self->道法名称="七十二变";
		self->主灵兽伤倍率_乘在攻=0;
		self->主灵兽回血倍率_乘在攻=1.11;
		self->主灵兽出手频率=2;
		self->主灵兽名称="鸾鸟";
		self->协同灵兽伤倍率_乘在攻=0;
		self->协同灵兽回血倍率_乘在攻=0.85;
		self->协同灵兽名称="鸾鸟";
		self->携带神通="七十二变,识海钉,碎心法,铜皮铁骨";
		self->神通图鉴->碎心法_回血量=0.12;
		self->神通图鉴->识海钉=0.028;
		self->增伤系数=(100 + 6.8 - 13.4) / 100;
		self->强灵系数=(100 + 4.3 - 1.4) / 100;
		self->大树妖层数=0;
		self->携带精怪="小龙女,大树妖,山泽精";
		self->战斗属性之击晕=188;
		self->战斗抗性之抗晕=74;
		self->朱雀灵脉层数=4;
		self->漏晕几次=0;
	}
	
	双方初始信息的结尾统一部分(self);
}

*/

void Save_init(Fight_info *self)
{
	self->存档->被晕的需要失去几次行动=0;
	self->存档->复活未起身=0;
	self->存档->被冰冻的需要失去几次行动=0;
	self->存档->识海钉已触发=0;
}


bool Save_hasChanged(Fight_info *self, char *field)
{
	if (!strcmp(field,"被晕的需要失去几次行动"))
	{
		return self->存档->被晕的需要失去几次行动!=self->被晕的需要失去几次行动;
	}
	if (!strcmp(field,"复活未起身"))
	{
		return self->存档->复活未起身!=self->复活未起身;
	}
	if (!strcmp(field,"被冰冻的需要失去几次行动"))
	{
		return self->存档->被冰冻的需要失去几次行动!=self->被冰冻的需要失去几次行动;
	}
	if (!strcmp(field,"识海钉已触发"))
	{
		return self->存档->识海钉已触发!=self->识海钉已触发;
	}
}


void Save_update(Fight_info *self, char *field)
{
	if (!strcmp(field,"被晕的需要失去几次行动"))
	{
		self->存档->被晕的需要失去几次行动=self->被晕的需要失去几次行动;
		return;
	}
	if (!strcmp(field,"复活未起身"))
	{
		self->存档->复活未起身=self->复活未起身;
		return;
	}
	if (!strcmp(field,"被冰冻的需要失去几次行动"))
	{
		self->存档->被冰冻的需要失去几次行动=self->被冰冻的需要失去几次行动;
		return;
	}
	if (!strcmp(field,"识海钉已触发"))
	{
		self->存档->识海钉已触发=self->识海钉已触发;
		return;
	}
}

void Trigger_count_init(Fight_info *self)
{
	self->触发计数->回春=
	self->触发计数->兽灵体=
	self->触发计数->大魔邪身=
	self->触发计数->勾陈灵脉=
	self->触发计数->煌气=0;
}

void Creature_handbook_common(Fight_info *self)
{
	self->精怪图鉴->紫晴龙狮=0.2;
		
	// 大明王
	self->精怪图鉴->大明王_满层=5;
	self->精怪图鉴->大明王_战斗属性之暴击加成=8;
	self->精怪图鉴->大明王_层数=0;
	
	self->精怪图鉴->小龙女_血线=0.7;
	self->精怪图鉴->小龙女_减伤=0.35;
	
	self->精怪图鉴->山泽精_血线=0.7;
	self->精怪图鉴->山泽精_治疗=0.24;
	
	self->精怪图鉴->大树妖_满层=5;
	self->精怪图鉴->大树妖_层数=0;
	self->精怪图鉴->大树妖_强灵加成=0.07;
}

// 精怪图鉴初始化
void Creature_handbook_init(Fight_info *self, char *who)
{
	// --- 共 用 ---
	Creature_handbook_common(self);
	
	if (!strcmp(who,"敌"))
	{

	}
	else
	{		
		// 皇帝
		self->精怪图鉴->皇帝_攻倍=1.3;

		// 破阵书生
		self->精怪图鉴->破阵书生=1.14;
	}
}

// 灵兽图鉴初始化
void Beast_handbook_init(Fight_info *self, char *who)
{
	// --- 共 用 ---
	// 青龙
	self->灵兽图鉴->青龙_满层=5;
	self->灵兽图鉴->青龙_战斗属性之暴击加成=10;
	self->灵兽图鉴->青龙_层数=0;
	
	if (!strcmp(who,"敌")){}
	else
	{

	}
}


// 神通图鉴共用部分
void Avator_handbook_common(Fight_info *self)
{
	self->神通图鉴->碎心法_次数=1;
	self->神通图鉴->飘渺身_持续回合数=3;
	self->神通图鉴->飘渺身_剩余回合数=0;
	self->神通图鉴->飘渺身_减伤=0.2;	
	self->神通图鉴->金刚不坏_持续回合数=3;
	self->神通图鉴->金刚不坏_剩余回合数=0;
	self->神通图鉴->金刚不坏_限伤=0.08;
	self->神通图鉴->煌气_始于第几回合=4;
	self->神通图鉴->煌气_免疫冰冻燃烧持续回合数=4;
	self->神通图鉴->煌气_回血量=0.14;
}


// 神通图鉴初始化
void Avator_handbook_init(Fight_info *self, char *who)
{
	// --- 共 用 ---
	Avator_handbook_common(self);
	
	if (!strcmp(who,"敌"))
	{
		self->神通图鉴->附灵术=0.048;
		self->神通图鉴->附灵术_限伤之攻倍=0.72;
		
		self->神通图鉴->金刚不坏_血线=0.65;		
	}
	else
	{
		// 碎心法
		self->神通图鉴->碎心法_回血量=1.12;
		
		// 化羽
		self->神通图鉴->化羽=1.18;
		
		self->神通图鉴->铜皮铁骨=0.08;
		
		
		// 识海钉
		self->神通图鉴->识海钉=0.03;
		self->神通图鉴->识海钉_限伤之攻倍=0.42;
		
		// 金刚不坏
		self->神通图鉴->金刚不坏_血线=0.7;
	}
}


void 双方初始信息的开头统一部分以及先行初始化(Fight_info *self)
{
	// 开头统一
	self->携带精怪=self->携带神通="";
	self->已损生命=self->被晕的需要失去几次行动=0;
	self->小龙女已触发=self->山泽精已触发=self->金刚不坏已触发=0;
	self->大树妖层数=self->雷公层数=0;
	self->妖气=self->已完成补气=0;
	self->复活未起身=false;
	self->朱雀灵脉层数=0;
	self->本次伤害=self->本次治疗=0;
	self->击晕率=0;
	self->漏晕几次=0;
	self->自行设置额外伤=self->额外伤限定回合数=0;
	self->拘神层数=0;
	self->被冰冻的需要失去几次行动=0;
	self->识海钉已触发=0;
	self->处于被晕状态=0;
	self->存档=(Save *)malloc(sizeof (Save));
	Save_init(self);
	self->触发计数=(Trigger_count *)malloc(sizeof (Trigger_count));
	Trigger_count_init(self);
	self->除了设置漏晕以外的皆必晕=0;
	self->处于冰冻状态=false;
	self->百分百闪避=false;
	self->勾陈灵脉层数=0;
	self->精怪图鉴=(Creature_handbook *)malloc(sizeof (Creature_handbook));
	self->触发了暴击=false;
	self->灵兽图鉴=(Beast_handbook *)malloc(sizeof (Beast_handbook));
	self->青龙灵脉层数=0;
	self->第几回合=0;
	self->神通图鉴=(Avator_handbook *)malloc(sizeof (Avator_handbook));
	
	
	// 先行初始化
	self->道法回血倍率_乘在攻=self->道法伤倍率_乘在攻=
	self->主灵兽回血倍率_乘在攻=self->主灵兽伤倍率_乘在攻=
	self->协同灵兽回血倍率_乘在攻=self->协同灵兽伤倍率_乘在攻=0;
	self->增伤系数=self->强灵系数=1;
	self->暴伤系数=2;
	self->无视战斗属性=self->无视战斗抗性=0;
}


void 双方初始信息的结尾统一部分(Fight_info *self)
{
	self->精怪分组=GYF_strsplit(self->携带精怪, &self->精怪数量);
	self->神通分组=GYF_strsplit(self->携带神通, &self->神通数量);

	self->战斗属性之击晕+=self->无视战斗抗性;
	self->战斗抗性之抗晕+=self->无视战斗属性;
	self->战斗属性之暴击+=self->无视战斗抗性;
	self->战斗抗性之抗暴+=self->无视战斗属性;
}

void 青龙流(Fight_info *self, float 倍率)
{
	self->主灵兽伤倍率_乘在攻=倍率;
	self->主灵兽回血倍率_乘在攻=0;
	self->主灵兽出手频率=1;
	self->主灵兽名称="青龙";
}


void 应龙流(Fight_info *self, float 倍率)
{
	self->主灵兽伤倍率_乘在攻=倍率;
	self->主灵兽回血倍率_乘在攻=0;
	self->主灵兽出手频率=5;
	self->主灵兽名称="应龙";		
}


void 鸾鸟流(Fight_info *self, float 倍率)
{
	self->主灵兽伤倍率_乘在攻=0;
	self->主灵兽回血倍率_乘在攻=倍率;
	self->主灵兽出手频率=2;
	self->主灵兽名称="鸾鸟";		
}


void 将人物能力置为默认值(Fight_info *self, float 对手倍数)
{
	双方初始信息的开头统一部分以及先行初始化(self);
	
	self->攻=24*对手倍数;
	self->血=self->攻*10;
	self->防=self->攻/6.0;
	self->敏=4000;
	self->道法伤倍率_乘在攻=2.2;
	self->道法名称="七十二变";
	self->主灵兽伤倍率_乘在攻=0;
	self->主灵兽回血倍率_乘在攻=1.11;
	self->主灵兽出手频率=2;
	self->主灵兽名称="鸾鸟";
	self->协同灵兽回血倍率_乘在攻=0.85;
	self->协同灵兽名称="鸾鸟";
	self->战斗抗性之抗晕=150;
	self->战斗属性之击晕=0;
	self->携带神通="七十二变,识海钉,碎心法";
	self->神通图鉴->碎心法_回血量=0.12;
	self->神通图鉴->识海钉=0.028;
	self->携带精怪="小龙女,大树妖";
	
	
	双方初始信息的结尾统一部分(self);
}




#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"atible-pointer-types"-pointer-types"