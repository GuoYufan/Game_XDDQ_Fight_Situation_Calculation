#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

#include <string.h>
#include <../../Common/GYF_Custom.h>
#include <XDDQ_Fight_Info_Struct.h>


void 将人物能力置为默认值(Fight_info *, float );
void 双方初始信息的开头统一部分以及先行初始化(Fight_info *);
void 双方初始信息的结尾统一部分(Fight_info *);
void 青龙流(Fight_info *, float );
void 应龙流(Fight_info *, float );
void 鸾鸟流(Fight_info *, float );
void 当前对手(Fight_info *, char *);
void 当前对手_另一个号反暴的(Fight_info *, char *);
void Save_init(Fight_info *);
short Save_hasChanged(Fight_info *, char *field);
void Save_update(Fight_info *, char *field);



// 另一个号：反暴号
void 当前对手_另一个号反暴的(Fight_info *self, char *who)
{
	双方初始信息的开头统一部分以及先行初始化(self);

	if (!strcmp(who, "敌"))
	{
		self->攻=29.8;
		self->血=266.93;
		self->剩余生命=self->血;
		self->防=5.2213;
		self->敏=4213;
		self->道法伤倍率_乘在攻=0;
		self->道法回血倍率_乘在攻=1.375;
		self->道法名称="护体金光";
		self->主灵兽伤倍率_乘在攻=5;
		self->主灵兽出手频率=5;
		self->主灵兽名称="应龙";
		self->协同灵兽伤倍率_乘在攻=1.56;
		self->协同灵兽回血倍率_乘在攻=0;
		self->协同灵兽出手频率=3;
		self->协同灵兽名称="麒麟";
		self->携带神通="护体金光,识海钉,碎心法,金刚不坏";
		self->碎心法回血=0.12;
		self->识海钉掉血伤=0.028;
		self->增伤系数=(100 + 3.5 - 8.8) / 100.0;
		self->强灵系数=(100+ + 9.1 - 3.7) / 100.0;
		self->携带精怪="";
		self->战斗抗性之抗晕=124;
		self->战斗属性之击晕=82;
		self->朱雀灵脉层数=1;
		self->漏晕几次=0;
		self->自行设置额外伤=0;
		self->额外伤限定回合数=0;
	}
	else
	{
		self->攻=28.4;
		self->血=276;
		self->已损生命=0;
		self->剩余生命=self->血;
		self->防=4.7;
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
		self->携带神通="冰封千里,识海钉,碎心法,飘渺身";
		self->碎心法回血=0.12;
		self->识海钉掉血伤=0.03;
		self->增伤系数=(100 + 9.5 - 11.7) / 100.0;
		self->强灵系数=(100 + 14.6 - 4.4) / 100.0;
		self->大树妖层数=0;
		self->携带精怪="山泽精,马面,骨魅";
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
		self->扶桑回血=0.12;
		self->碎心法回血=0.12;
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
		self->碎心法回血=0.12;
		self->识海钉掉血伤=0.028;
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
		self->扶桑回血=0.12;
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
		self->碎心法回血=0.12;
		self->识海钉掉血伤=0.028;
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


short Save_hasChanged(Fight_info *self, char *field)
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
	self->存档->触发计数->回春=
	self->存档->触发计数->兽灵体=
	self->存档->触发计数->大魔邪身=0;
}

void 双方初始信息的开头统一部分以及先行初始化(Fight_info *self)
{
	// 开头统一
	self->已损生命=self->被晕的需要失去几次行动=0;
	self->小龙女已触发=self->山泽精已触发=self->金刚不坏已触发=0;
	self->大树妖层数=self->雷公层数;
	self->金刚不坏剩余回合数;
	self->妖气=self->已完成补气=0;
	self->复活未起身=0;
	self->朱雀灵脉层数=0;
	self->本次伤害=self->本次治疗=0;
	self->击晕率=0;
	self->漏晕几次=0;
	self->飘渺身剩余回合数=0;
	self->自行设置额外伤=self->额外伤限定回合数=0;
	self->拘神层数=0;
	self->被冰冻的需要失去几次行动=0;
	self->识海钉已触发=0;
	self->处于被晕状态=0;
	self->存档=(Save *)malloc(sizeof (Save));
	Save_init(self);
	self->存档->触发计数=(Trigger_count *)malloc(sizeof (Trigger_count));
	Trigger_count_init(self);
	self->除了设置漏晕以外的皆必晕=0;
	self->处于冰冻状态=false;
	
	
	// 先行初始化
	self->道法回血倍率_乘在攻=self->主灵兽回血倍率_乘在攻=self->协同灵兽回血倍率_乘在攻=0;
	self->协同灵兽伤倍率_乘在攻=0;
	self->增伤系数=self->强灵系数=1;
}


void 双方初始信息的结尾统一部分(Fight_info *self)
{
	self->精怪分组=GYF_strsplit(self->携带精怪, &self->精怪数量);
	self->神通分组=GYF_strsplit(self->携带神通, &self->神通数量);
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
	self->碎心法回血=0.12;
	self->识海钉掉血伤=0.028;
	self->携带精怪="小龙女,大树妖";
	
	
	双方初始信息的结尾统一部分(self);
}




#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"