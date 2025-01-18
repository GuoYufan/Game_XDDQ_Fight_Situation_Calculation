#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

// 统一管理所有伤害
void 计算本次伤害(Fight_info *self, Fight_info *opponent, char *伤害种类)
{
	self->本次伤害 = 重新计算指定伤害(self,opponent,伤害种类);
	if (opponent->神通图鉴->飘渺身_剩余回合数>0)
	{
		self->本次伤害*=(1-opponent->神通图鉴->飘渺身_减伤);
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
				灵脉跟随(opponent,"成功闪避");
			}
		}
	}
	
	
	if (opponent->神通图鉴->金刚不坏_剩余回合数>0 && self->本次伤害>opponent->神通图鉴->金刚不坏_限伤)
	{
		self->本次伤害 = opponent->神通图鉴->金刚不坏_限伤;
	}
}