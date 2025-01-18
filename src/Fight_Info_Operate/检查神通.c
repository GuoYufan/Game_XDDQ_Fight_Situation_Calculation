#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"
#include "../../include/双方初始信息.h"

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
		if (self->已损生命>=self->神通图鉴->金刚不坏_血线 && !self->金刚不坏已触发)
		{
			if (self->复活未起身) return;
			self->金刚不坏已触发=true;
			self->神通图鉴->金刚不坏_剩余回合数=3;
			printf("🛎\n%s人物被动神通%s已触发, 剩余%d回合\n",
			 self->哪一方, 神通名称, self->神通图鉴->金刚不坏_剩余回合数);
		}
		
		if (!strcmp(时刻, "回合结束时") && self->神通图鉴->金刚不坏_剩余回合数>0)
		{
			self->神通图鉴->金刚不坏_剩余回合数--;
			printf("❗%s人物被动神通%s剩余%d回合\n",
			 self->哪一方, 神通名称, self->神通图鉴->金刚不坏_剩余回合数);
		}
		return;
	}
	
	if (!strcmp(神通名称, "飘渺身") && !strcmp(时刻, "回合结束时"))
	{
		if (self->神通图鉴->飘渺身_剩余回合数>0)
		{
			self->神通图鉴->飘渺身_剩余回合数--;
			printf("❗%s人物被动神通%s剩余%d回合\n",
			 self->哪一方, 神通名称, self->神通图鉴->飘渺身_剩余回合数);
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
	
	if (!strcmp(神通名称, "煌气") && self->第几回合>=self->神通图鉴->煌气_始于第几回合)
	{
		if (!strcmp(时刻, "灵兽释放技能时"))
		{
			if (self->触发计数->煌气 !=0) return;
			
			if (self->复活未起身) return;
			
			计算本次治疗(self,opponent,"煌气");
			
			printf("❗%s灵兽释放技能时触发驭兽神通%s, 治疗了%g%%生命, 并且免疫冰冻燃烧4回合\n",
			 self->哪一方, 神通名称, self->本次治疗 * 100);
			治疗(self);
			
			self->免疫冰冻燃烧回合数=self->神通图鉴->煌气_免疫冰冻燃烧持续回合数;
			
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