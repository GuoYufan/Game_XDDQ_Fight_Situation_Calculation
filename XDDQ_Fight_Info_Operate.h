#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <XDDQ_双方初始信息.h>


// 1:必须正确输入
// 0:允许使用默认值
// int _Settings_input_mode=0;


void Fight_info_show(Fight_info *);
void Fight_info_init(Fight_info *, char *);
void Fight_info_input(Fight_info *, const char *);

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

   } */

void 统一free(Fight_info *, Fight_info *);
void 载入神通与精怪(Fight_info *, Fight_info *);
void 不受影响的计算与显示(Fight_info *, Fight_info *);
void 检查复活(Fight_info *, Fight_info *);
void 妖气变化(Fight_info *, float);
void 治疗溢出修正(Fight_info *);
void 受伤(Fight_info *, Fight_info *, float );
void 检查精怪(Fight_info *, Fight_info *, char *, char *);
void 精怪跟随(Fight_info *, Fight_info *, char *);
void 检查人物被晕状态是否可恢复(Fight_info *);
void 战斗属性_setter(Fight_info *, Fight_info *, char *, float );
void 计算实际击晕率(Fight_info *, Fight_info *);
void 计算实际暴击率(Fight_info *, Fight_info *);
bool 击晕率是否足够(Fight_info *, Fight_info *);
bool 暴击率是否足够(Fight_info *, Fight_info *);
void 被击晕(Fight_info *);
void 击晕判定及相关经过(Fight_info *, Fight_info *);
void 暴击判定及相关经过(Fight_info *, Fight_info *);
void 灵脉跟随(Fight_info *, char *);
void 进行识海钉流血(Fight_info *, Fight_info *);
void 检查神通(Fight_info *, Fight_info *, char *, char *);
void 神通跟随(Fight_info *, Fight_info *, char *);
void 重新计算全部伤害(Fight_info *, Fight_info *);
float 重新计算指定伤害(Fight_info *, Fight_info *, char *);
void 计算本次伤害(Fight_info *, Fight_info *, char *);
float 重新计算指定治疗(Fight_info *self, Fight_info *opponent, char *治疗种类);
void 计算本次治疗(Fight_info *self, Fight_info *opponent, char *治疗种类);
void 治疗(Fight_info *self);
void 释放道法(Fight_info *, Fight_info *);
void 进行普攻(Fight_info *, Fight_info *);
void 解复活未起身(Fight_info *, Fight_info *);
void 灵兽效果(Fight_info *, Fight_info *, char *);
void 轮序到人物(Fight_info *, Fight_info *);
void 轮序到灵兽(Fight_info *, Fight_info *);



void 统一free(Fight_info *self, Fight_info *opponent)
{
	
	for (int i=0; i<self->精怪数量; i++)
		free(self->精怪分组[i]);

	for (int i=0; i<self->神通数量; i++)
		free(self->神通分组[i]);

	for (int i=0; i<opponent->精怪数量; i++)
		free(opponent->精怪分组[i]);

	for (int i=0; i<opponent->神通数量; i++)
		free(opponent->神通分组[i]);
		
	
	
	free(self->精怪分组);
	free(self->神通分组);
	free(opponent->精怪分组);
	free(opponent->神通分组);
	
	free(self->触发计数);
	free(self->存档);
	
	free(self);
	free(opponent);
}


void 载入神通与精怪(Fight_info * self, Fight_info * opponent)
{
	if (strstr(self->携带神通, "碎心法") != NULL || strstr(self->携带精怪, "扶桑") != NULL)
	{
		self->可复活次数=1;

	}

	if (strstr(self->携带神通, "化羽") != NULL)
	{
		self->敏*=1.18;
	}

	if (strstr(self->携带神通, "铜皮铁骨") != NULL)
	{
		opponent->增伤系数-=0.08;
	}
	
	
	if (strstr(self->携带精怪, "破阵书生") != NULL)
	{
		self->血 *= 1.14;
	}
	
	if (strstr(self->携带神通, "飘渺身" ) != NULL)
	{
		self->飘渺身剩余回合数 = 3;
	}
	
	if (strstr(self->携带精怪, "玄冥蛟" ) !=NULL)
	{
		self->攻+=self->防*0.6;
	}
	
	if (strstr(self->携带神通, "共鸣") != NULL )
	{
		self->强灵系数+=0.136;
	}
	
	if (strstr(self->携带精怪, "马面") != NULL )
	{
		self->强灵系数+=0.16;
	}
	
	if (strstr(self->携带精怪, "黑麒麟") != NULL )
	{
		self->战斗抗性之抗晕+=28;
	}
	
	if (strstr(self->携带精怪, "大山妖") != NULL )
	{
		opponent->增伤系数-=0.1;
	}
	
	
	
}



void 不受影响的计算与显示(Fight_info * 先手方, Fight_info * 后手方)
{
	// 计算
	重新计算全部伤害(先手方, 后手方);
	
	// 展示信息
	putchar(10);
	printf("[先手方增伤系数%g|后手方增伤系数%g]\n", 先手方->增伤系数,
		   后手方->增伤系数);
	printf("[先手方强灵系数%g|后手方强灵系数%g]\n", 先手方->强灵系数,
		   后手方->强灵系数);
	printf("[先手方是后手方的%g（攻倍）~%g~%g倍对手]\n",
		   先手方->攻/后手方->攻, 先手方->血/后手方->血,
		   先手方->防/后手方->防);
	printf("[后手方是先手方的%g（攻倍）~%g~%g倍对手]\n",
		   后手方->攻/先手方->攻, 后手方->血/先手方->血,
		   后手方->防/先手方->防);

	printf("[先手方有视防御伤%g%%|后手方有视防御伤%g%%]\n",
		   先手方->有视防御伤*100, 后手方->有视防御伤*100);
	printf("[先手方无视防御伤%g%%|后手方无视防御伤%g%%]\n",
		   先手方->无视防御伤*100, 后手方->无视防御伤*100);
	printf
		("[先手方道法%s伤%g%%+回血%g%%|后手方道法%s伤%g%%+回血%g%%]\n",
		 先手方->道法名称, 先手方->道法伤*100, 先手方->道法回血*100,
		 后手方->道法名称, 后手方->道法伤*100, 后手方->道法回血*100);
	printf("[先手方主灵兽%s伤%g%%+回血%g%%|后手方主灵兽%s伤%g%%+回血%g%%]\n",
		   先手方->主灵兽名称, 先手方->主灵兽伤*100, 先手方->主灵兽回血*100,
		   后手方->主灵兽名称, 后手方->主灵兽伤*100,
		   后手方->主灵兽回血*100);
	printf
		("[先手方协同灵兽%s伤%g%%+回血%g%%|后手方协同灵兽%s伤%g%%+回血%g%%]\n",
		 先手方->协同灵兽名称, 先手方->协同灵兽伤*100,
		 先手方->协同灵兽回血*100, 后手方->协同灵兽名称,
		 后手方->协同灵兽伤*100, 后手方->协同灵兽回血*100);
	printf("[先手方精怪%s|后手方精怪%s]\n", 先手方->携带精怪, 后手方->携带精怪);
	printf("[先手方神通%s|后手方神通%s]\n", 先手方->携带神通, 后手方->携带神通);
	printf("[先手方暴击率%g%%+击晕率%g%%|后手方暴击率%g%%+击晕率%g%%]\n", 先手方->暴击率, 先手方->击晕率, 后手方->暴击率, 后手方->击晕率);
}



void 检查复活(Fight_info * self, Fight_info * opponent)
{
	Fight_info *先手方=self, *后手方=opponent;

	if (strstr(self->哪一方, "后") != NULL)
	{
		先手方=opponent;
		后手方=self;
	}
	
	if (self->已损生命>=1)
	{
		printf("(目前:先手方%g%% VS 后手方%g%%)\n", 后手方->已损生命*100,
			   先手方->已损生命*100);
		printf("(目前妖气:先手方%g VS 后手方 %g)\n", 先手方->妖气,
			   后手方->妖气);
			   
		if (!self->复活未起身 && self->可复活次数<1)
		{
			printf("(%s方已死，无复活)\n", self->哪一方);
			printf("\n📖\n(%s方告负)\n", self->哪一方);
			
			
			//统一free(self,opponent);
			exit(EXIT_SUCCESS);
		}
		else if (self->处于冰冻状态)
		{
			if (strstr(self->携带神通, "碎心法") == NULL)
			{
				printf("(%s方已死，扶桑被冰冻不能复活)\n", self->哪一方);
				printf("\n📖\n(%s方告负)\n", self->哪一方);
				
				//统一free(self,opponent);
				exit(EXIT_SUCCESS);
			}
		}
				

		printf("(%s方已死，有复活)\n", self->哪一方);
		self->复活未起身=1;
	}

}



// -1:普攻
// -2:刚刚释放完道法，需要清空妖气
// -3:啸月
// -4:万妖体
// 大于等于0:受伤并输入受伤值
// -800:被对手蚀魂咒
void 妖气变化(Fight_info * self, float 本次掉血多少)
{
	if (!self->神通数量) return;
	// 刚刚释放完道法，需要清空妖气
	if (本次掉血多少==-2)
	{
		self->妖气=0;
		self->已完成补气=0;
		if (!strcmp(self->道法名称, "七十二变"))
		{
			self->妖气+=3000;
		}
		return;
	}

	if (本次掉血多少>=0)
	{
		// 掉血补气
		self->妖气+=本次掉血多少*5000;
	}
	else if (本次掉血多少==-1)
	{
		// 普攻补气
		self->妖气+=2000;
	}		
	else if (本次掉血多少==-800)
	{
		// 被蚀魂咒减气
		self->妖气-=800;
	}
	else if (本次掉血多少==-3)
	{
		// 啸月
		self->妖气+=2240;
	}
	else if (本次掉血多少==-4)
	{
		// 万妖体
		self->妖气+=800;
	}
	

	if (self->妖气>10000)
		self->妖气=10000;	
	else if (self->妖气<0)
		self->妖气=0;

				
	if (self->妖气==10000)
	{
		self->已完成补气=1;
	}
	else
	{
		self->已完成补气=0;
	}
}



void 治疗溢出修正(Fight_info * self)
{
	if (self->已损生命<0)
		self->已损生命=0;
}


void 受伤(Fight_info * self, Fight_info * opponent, float 本次掉血多少 )
{
	if (strstr(self->携带神通, "飘渺身")!=NULL && self->飘渺身剩余回合数>0)
	{
		本次掉血多少 *= (1-0.2);		
	}
	
	float 被妖气计算的掉血量=本次掉血多少;
	
	if (self->已损生命+被妖气计算的掉血量>1)
	{
		被妖气计算的掉血量=1-self->已损生命;
	}
	
	self->已损生命+=本次掉血多少;
	//治疗溢出修正(self);
	妖气变化(self, 被妖气计算的掉血量);
	检查复活(self, opponent);
	if (!self->复活未起身)
	{
		神通跟随(self, opponent, "");
		精怪跟随(self, opponent, "");
	}
}


void 检查精怪(Fight_info * self, Fight_info * opponent, char *精怪名称, char *时刻)
{
	if (!strcmp(精怪名称, "小龙女") && !self->小龙女已触发 && self->已损生命>=0.7)
	{
		if (self->复活未起身) return;
		printf("🧥\n%s精怪%s触发\n", self->哪一方, 精怪名称);
		opponent->增伤系数-=0.35;
		self->小龙女已触发=1;
		return;
	}
		
	if (!strcmp(精怪名称, "山泽精") && !self->山泽精已触发 && self->已损生命>=0.7)
	{
		if (self->复活未起身) return;
		printf("🌳\n%s精怪%s触发\n", self->哪一方, 精怪名称);
		self->本次治疗=0.24;
		治疗(self);
		self->山泽精已触发=1;
		return;
	}
	

	if (!strcmp(精怪名称, "干饭人") && !strcmp(时刻, "回合开始时"))
	{
		if (self->复活未起身) return;
		if (self->已损生命==0) return;
		printf("❗️%s精怪%s触发\n", self->哪一方, 精怪名称);
		printf("%s精怪干饭人回血%g%%\n", self->哪一方, 1.2);
		self->本次治疗=0.012;
		治疗(self);
		return;
	}

	if (!strcmp(精怪名称, "大树妖") && !strcmp(时刻, "普攻前")
		&& self->大树妖层数<5)
	{
		self->强灵系数+=0.07;
		self->大树妖层数++;
		printf("❗️%s精怪%s触发, 目前%d层",
		 self->哪一方, 精怪名称, self->大树妖层数 );
		 
		if (self->大树妖层数==5) printf("(现已满层)");
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
		self->皇帝已触发=1;
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

}



void 精怪跟随(Fight_info * self, Fight_info * opponent, char *时刻)
{
	if (self->处于冰冻状态) return;
	
	for (int i = 0; i < self->精怪数量; i++)
	{
		// printf("第%d/%d:%s",i+1,self->精怪数量,self->精怪分组[i]);
		// getchar();
		检查精怪(self, opponent, self->精怪分组[i], 时刻);
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
	
	short 随机数=0;
	
	随机数=rand() % 100 + 1;
	printf("随机数%d",随机数);
	
	return in_interval(随机数, 1, self->击晕率);
}


bool 暴击率是否足够(Fight_info * self, Fight_info * opponent)
{
	计算实际暴击率(self,opponent);
	
	short 随机数=0;
	
	随机数=rand() % 100 + 1;
	
	if (in_interval(随机数, 1, self->暴击率))
	{
		printf("随机数%d",随机数);
		return true;		
	}
	else return false;
}



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



void 灵脉跟随(Fight_info *self, char *时刻)
{
	if (!strcmp(时刻,"回合开始时") && self->朱雀灵脉层数>0)
	{
		self->战斗属性之击晕+=6+2*(self->朱雀灵脉层数-1);
	}
}


void 进行识海钉流血(Fight_info *self, Fight_info * opponent)
{
	char *战况用语= self->识海钉已触发?"正在流血":"触发";
	
	float 识海钉限伤 = self->攻 * 0.42 ;
			
	if (识海钉限伤 < self->识海钉掉血伤 * opponent->血)
	{
		self->识海钉掉血伤 = 识海钉限伤 / opponent->血 ;
	}
			
	printf("❗️%s人物神识神通识海钉%s, 造成%g%%伤害\n",
	 self->哪一方, 战况用语, self->识海钉掉血伤*100);
	受伤(opponent, self, self->识海钉掉血伤);
}


void 检查神通(Fight_info * self, Fight_info * opponent, char *神通名称, char *时刻)
{
	if (!strcmp(神通名称, "识海钉") )
	{
		if (opponent->复活未起身) return;
		
		if (!strcmp(时刻, "普攻前") && !self->识海钉已触发)
		{
			进行识海钉流血(self, opponent);
			self->识海钉已触发=1;
			return;
		}
		else if (!strcmp(时刻, "回合结束时"))
		{
			if (Save_hasChanged(self,"识海钉已触发"))
			{
				Save_update(self, "识海钉已触发");
				return;
			}
			进行识海钉流血(self, opponent);
			return;
		}
	}
	
	if (!strcmp(神通名称, "金刚不坏") )
	{
		if (self->已损生命>=0.7 && self->金刚不坏已触发==0)
		{
			if (self->复活未起身) return;
			self->金刚不坏已触发=1;
			self->金刚不坏剩余回合数=3;
			printf("🛎\n%s人物被动神通%s已触发, 剩余%d回合\n",
			 self->哪一方, 神通名称, self->金刚不坏剩余回合数);
		}
		
		if (!strcmp(时刻, "回合结束时") && self->金刚不坏剩余回合数>0)
		{
			self->金刚不坏剩余回合数--;
			printf("❗%s人物被动神通%s剩余%d回合\n",
			 self->哪一方, 神通名称, self->金刚不坏剩余回合数);
		}
		return;
	}
	
	if (!strcmp(神通名称, "飘渺身") && !strcmp(时刻, "回合结束时"))
	{
		if (self->飘渺身剩余回合数>0)
		{
			self->飘渺身剩余回合数--;
			printf("❗%s人物被动神通%s剩余%d回合\n",
			 self->哪一方, 神通名称, self->飘渺身剩余回合数);
		}
		return;
	}
	
	if (!strcmp(神通名称, "丹心同并") && !strcmp(时刻, "灵兽释放技能时"))
	{
		if (self->复活未起身) return;
		self->本次治疗 = 0.05;
		printf("❗%s灵兽释放技能时触发驭兽神通%s, 治疗了%g%%生命\n",
			 self->哪一方, 神通名称, self->本次治疗 * 100);
		治疗(self);
	}
	
	if (!strcmp(神通名称, "拘神") && !strcmp(时刻, "普攻前") && self->拘神层数<5)
	{	
		if (opponent->复活未起身) return;
		
		float 本次偷取攻击力 = opponent->攻 * 0.023;
		if (本次偷取攻击力 > self->攻 * 0.165)
		{
			本次偷取攻击力 = self->攻 * 0.165;
		}
		 
		self->攻+=本次偷取攻击力;
		opponent->攻-=本次偷取攻击力;
		self->拘神层数++;
		
		printf("❗️%s人物神识神通%s触发, 目前%d层%s, 本次偷取%g攻击力\n",
		 self->哪一方, 神通名称, self->拘神层数,
		 self->拘神层数==5?"(已满层)":"", 本次偷取攻击力);
	}
	
	if (!strcmp(神通名称, "附灵术") && !strcmp(时刻, "普攻前"))
	{
		if (opponent->复活未起身) return;
		
		计算本次伤害(self, opponent, "附灵术伤");
		
		printf("❗️%s人物神识神通%s触发, 造成%g%%伤害\n",
		 self->哪一方, 神通名称, self->本次伤害 * 100);
		受伤(opponent, self, self->本次伤害);
		return;
	}
	
	if (!strcmp(神通名称, "回春") && !strcmp(时刻, "灵兽释放技能时"))
	{
		if (self->触发计数->回春 !=0) return;
		
		if (self->复活未起身) return;
		
		计算本次治疗(self,opponent,"回春");
		
		printf("❗%s灵兽释放技能时触发驭兽神通%s, 治疗了%g%%生命\n",
		 self->哪一方, 神通名称, self->本次治疗 * 100);
		治疗(self);
		self->触发计数->回春++;
		return;
	}
	
	if (!strcmp(神通名称, "长生体") && !strcmp(时刻, "回合开始时"))
	{
		if (self->复活未起身) return;
		
		计算本次治疗(self,opponent,"长生体");
		
		printf("❗%s人物被动神通%s触发, 治疗了%g%%生命\n",
		 self->哪一方, 神通名称, self->本次治疗 * 100);
		治疗(self);
		return;
	}
	
	if (!strcmp(神通名称, "兽灵体"))
	{
		if (!strcmp(时刻, "受击"))
		{
			if (self->复活未起身) return;
			if (self->触发计数->兽灵体<10)
			{
				self->强灵系数+=0.03;
				self->触发计数->兽灵体++;
				printf("❗%s人物被动神通%s触发, 目前%d层, 强灵系数%g\n",
				self->哪一方, 神通名称, self->触发计数->兽灵体, self->强灵系数);
				return;
			}
		}
		else if (!strcmp(时刻, "灵兽释放技能时"))
		{
			self->强灵系数-= 0.03 * self->触发计数->兽灵体;
			self->触发计数->兽灵体=0;
			return;
		}
	}
	
	if (!strcmp(神通名称, "暗袭") && !strcmp(时刻, "灵兽释放技能时"))
	{
		if (opponent->复活未起身) return;
		
		计算本次伤害(self,opponent,"暗袭");
		
		printf("❗%s灵兽释放技能时触发驭兽神通%s, 造成%g%%伤害\n",
		 self->哪一方, 神通名称, self->本次伤害 * 100);
		受伤(opponent, self, self->本次伤害);
		return;
	}
	
	if (!strcmp(神通名称, "大魔邪身") && !strcmp(时刻, "受击") )
	{
		if (self->复活未起身) return;
		if (self->触发计数->大魔邪身<5)
		{
			self->攻*=1.029;
			self->触发计数->大魔邪身++;
			printf("❗%s人物被动神通%s触发, 目前%d层%s, 攻击力%g\n",
			 self->哪一方, 神通名称, self->触发计数->大魔邪身,
			 self->触发计数->大魔邪身<5?"":"(已满层)",
			 self->攻);
			return;
		}
	}
	
	if (!strcmp(神通名称, "蚀魂咒") && !strcmp(时刻, "普攻后"))
	{
		// if (opponent->复活未起身) return;
		
		printf("❗️%s人物神识神通%s触发, %s人物此前妖气%g",
		 self->哪一方, 神通名称, opponent->哪一方, opponent->妖气);
		
		妖气变化(opponent,-800);
		printf(", 目前妖气%g\n",opponent->妖气);
		
		return;
	}
	
	
	if (!strcmp(神通名称, "吞灵") && !strcmp(时刻, "普攻前"))
	{
		if (opponent->复活未起身) return;
		
		self->剩余生命=1-self->已损生命;
		float 本次吞灵掉血_自己=self->剩余生命*0.1;
		float 本次吞灵掉血_对方=self->血*self->剩余生命*0.1/opponent->血;
		
		printf("❗️%s人物神识神通%s触发, 自己掉血%g%%,对方掉血%g%%\n",
		 self->哪一方, 神通名称, 本次吞灵掉血_自己 * 100, 本次吞灵掉血_对方*100);
		受伤(self,opponent,本次吞灵掉血_自己);
		受伤(opponent, self, 本次吞灵掉血_对方);
		return;
	}
	
	if (!strcmp(神通名称, "啸月") && !strcmp(时刻, "灵兽释放技能时"))
	{
		if (self->复活未起身) return;
		
		妖气变化(self,-3);
		return;
	}
	
	if (!strcmp(神通名称, "万妖体") && !strcmp(时刻, "回合开始时"))
	{
		妖气变化(self,-4);
		return;
	}
	
	if (!strcmp(神通名称, "煌气") && self->第几回合>=4 )
	{
		if (!strcmp(时刻, "灵兽释放技能时"))
		{
			if (self->触发计数->煌气 !=0) return;
			
			if (self->复活未起身) return;
			
			计算本次治疗(self,opponent,"煌气");
			
			printf("❗%s灵兽释放技能时触发驭兽神通%s, 治疗了%g%%生命, 并且免疫冰冻燃烧4回合\n",
			 self->哪一方, 神通名称, self->本次治疗 * 100);
			治疗(self);
			
			self->免疫冰冻燃烧回合数=4;
			
			self->触发计数->煌气++;
			return;
		}
		else if (!strcmp(时刻, "回合结束时") && self->免疫冰冻燃烧回合数>0)
		{
			self->免疫冰冻燃烧回合数--;
			return;
		}
	}
}

void 神通跟随(Fight_info * self, Fight_info * opponent, char *时刻)
{
	for (int i = 0; i < self->神通数量; i++)
	{
		检查神通(self, opponent, self->神通分组[i], 时刻);
	}
}

// 使用奇技淫巧
void 重新计算全部伤害(Fight_info *self, Fight_info *opponent)
{
	// 双方无视防御伤
	self->无视防御伤=self->攻/opponent->血;
	opponent->无视防御伤=opponent->攻/self->血;

	// 标准关系中，防御代表的掉血伤固定为1.66%（准确值1/6）
	// 奇技淫巧：有视防御伤=无视防御伤-防御代表的掉血伤
	self->有视防御伤=self->无视防御伤-opponent->防/opponent->血;

	opponent->有视防御伤=opponent->无视防御伤-self->防/self->血;

	// 双方道法伤或道法回血
	// 奇技淫巧：道法加成（加在有视防御上）=无视防御伤*(道法倍率-1)
	self->道法伤=self->有视防御伤+self->无视防御伤*(self->道法伤倍率_乘在攻-1);
	self->道法回血=self->攻*self->
		道法回血倍率_乘在攻/self->血;
	opponent->道法伤=opponent->有视防御伤+opponent->无视防御伤*(opponent->道法伤倍率_乘在攻-1);


	// 双方主灵兽
	// 奇技淫巧：主灵兽掉血伤=(主灵兽倍率/对手倍数*10)%
	self->主灵兽伤=self->无视防御伤*self->主灵兽伤倍率_乘在攻;
	opponent->主灵兽伤=opponent->无视防御伤*opponent->主灵兽伤倍率_乘在攻;

	self->主灵兽回血=self->攻*self->
		主灵兽回血倍率_乘在攻/self->血;
	opponent->主灵兽回血=opponent->攻*opponent->
		主灵兽回血倍率_乘在攻/opponent->血;
		
	// 双方协同灵兽
	self->协同灵兽伤=self->无视防御伤*self->
		协同灵兽伤倍率_乘在攻;
	opponent->协同灵兽伤=opponent->无视防御伤*opponent->
		协同灵兽伤倍率_乘在攻;

	self->协同灵兽回血=self->攻*self->
		协同灵兽回血倍率_乘在攻/self->血;
	opponent->协同灵兽回血=opponent->攻*opponent->
		协同灵兽回血倍率_乘在攻/opponent->血;

	计算实际暴击率(self,opponent);
	计算实际暴击率(opponent,self);
	计算实际击晕率(self,opponent);
	计算实际击晕率(opponent,self);
}

// 使用原式，非奇技淫巧
float 重新计算指定伤害(Fight_info *self, Fight_info *opponent, char *伤害种类)
{
	if (!strcmp(伤害种类, "主灵兽伤"))
	{
		self->主灵兽伤 = self->攻 * self->主灵兽伤倍率_乘在攻 / opponent->血 * self->强灵系数 * self->增伤系数;
		return self->主灵兽伤;
	}
	
	if (!strcmp(伤害种类, "协同灵兽伤"))
	{
		self->协同灵兽伤 = self->攻 * self->协同灵兽伤倍率_乘在攻 / opponent->血 * self->强灵系数 * self->增伤系数;
		return self->协同灵兽伤;
	}
	
	if (!strcmp(伤害种类, "有视防御伤"))
	{
		self->有视防御伤 = (self->攻 - opponent->防) / opponent->血 * self->增伤系数;
		if (self->触发了暴击)
		{
			self->有视防御伤*=self->暴伤系数;
			self->暴伤系数+=(7+5*self->青龙灵脉层数)/100.0;
			self->触发了暴击=false;
		}
		return self->有视防御伤;
	}
	
	if (!strcmp(伤害种类, "道法伤"))
	{
		self->道法伤 = (self->攻 * self->道法伤倍率_乘在攻 - self->防) / opponent->血 * self->增伤系数;
		if (self->触发了暴击)
		{
			self->道法伤*=self->暴伤系数;
			self->触发了暴击=false;
		}
		return self->道法伤;
	}
	
	if (!strcmp(伤害种类, "紫晴龙狮伤"))
	{
		return self->攻 * 0.2 / opponent->血 * self->增伤系数;
	}
	
	if (!strcmp(伤害种类, "附灵术伤"))
	{
		opponent->剩余生命 = 1 - opponent->已损生命;
		float 附灵术掉血伤 = opponent->剩余生命 * 0.042;
		float 附灵术限伤= self->攻 * 0.63 / opponent->血;
		
		if (附灵术限伤 < 附灵术掉血伤)
		{
			附灵术掉血伤 = 附灵术限伤;
		}
		return 附灵术掉血伤 * self->增伤系数;
	}
	
	if (!strcmp(伤害种类, "皇帝伤"))
	{
		return self->攻 * self->精怪图鉴->皇帝_攻倍 / opponent->血 * self->增伤系数;
	}
	
	if (!strcmp(伤害种类, "暗袭"))
	{
		return self->攻 * 0.26 / opponent->血 * self->增伤系数;
	}
	
	if (!strcmp(伤害种类, "雷公"))
	{
		return self->攻 * 0.2 / opponent->血 * self->增伤系数;
	}
	
	
}

// 统一管理所有伤害
void 计算本次伤害(Fight_info *self, Fight_info *opponent, char *伤害种类)
{
	self->本次伤害 = 重新计算指定伤害(self,opponent,伤害种类);
	if (opponent->飘渺身剩余回合数>0)
	{
		self->本次伤害*=(1-0.2);
	}
	// 人物伤害管理
	if (strstr(伤害种类,"道法") || strstr(伤害种类,"有视"))
	{
		// 鬼将：60%↑ 1.32
		if (strstr(self->携带精怪, "鬼将"))
		{
			opponent->剩余生命 = 1 - opponent->已损生命;
			if (opponent->剩余生命 >= 0.6 )
			{
				printf("🗡\n%s精怪鬼将触发\n",self->哪一方);
				self->本次伤害 *= 1.32;
			}
		}
		
		// 骨魅：35%↓ 1.45
		if (strstr(self->携带精怪, "骨魅"))
		{
			opponent->剩余生命 = 1 - opponent->已损生命;
			if (opponent->剩余生命 <= 0.35 )
			{
				printf("🗡\n%s精怪骨魅触发\n",self->哪一方);
				self->本次伤害 *= 1.45;
			}
		}
		
		
		
		// 操纵战况：自己设置的人物普攻额外伤
		if (self->额外伤限定回合数>0)
		{
			self->本次伤害 += self->自行设置额外伤;
			self->额外伤限定回合数--;
		}
		
		if (opponent->百分百闪避)
		{
			if (strstr(伤害种类,"道法")==NULL)
			{
				self->本次伤害=0;
				if (opponent->触发计数->勾陈灵脉<5)
				{
					opponent->强灵系数 += 0.04 + 0.02*(opponent->勾陈灵脉层数-1);
					opponent->触发计数->勾陈灵脉++;
				}
			}
		}
	}
	
	
	if (opponent->金刚不坏剩余回合数>0 && self->本次伤害>0.08)
	{
		self->本次伤害 = 0.08;
	}
}

float 重新计算指定治疗(Fight_info *self, Fight_info *opponent, char *治疗种类)
{
	if (!strcmp(治疗种类, "道法回血"))
	{
		self->道法回血 = self->攻 * self->道法回血倍率_乘在攻 / self->血;
		return self->道法回血;
	}
	
	if (!strcmp(治疗种类, "主灵兽回血"))
	{
		self->主灵兽回血 = self->攻 * self->主灵兽回血倍率_乘在攻 / self->血 * self->强灵系数;
		return self->主灵兽回血;
	}
	
	if (!strcmp(治疗种类, "协同灵兽回血"))
	{
		self->协同灵兽回血 = self->攻 * self->协同灵兽回血倍率_乘在攻 / self->血 * self->强灵系数;
		return self->协同灵兽回血;
	}
	
	if (!strcmp(治疗种类, "回春"))
	{
		return self->已损生命 * 0.22;
	}
	
	if (!strcmp(治疗种类, "长生体"))
	{
		return self->已损生命 * 0.057;
		
	}
	
	if (!strcmp(治疗种类, "煌气"))
	{
		return 0.14;
	}
	
}


void 计算本次治疗(Fight_info *self, Fight_info *opponent, char *治疗种类)
{
	self->本次治疗 = 重新计算指定治疗(self, opponent, 治疗种类);
}

void 治疗(Fight_info *self)
{
	self->已损生命-=self->本次治疗;
	治疗溢出修正(self);
}

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
		self->已损生命=(1 - (是碎心法复活的?self->碎心法回血:self->扶桑回血));
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

#pragma GCC diagnostic warning "-Wincompatible-pointer-types"