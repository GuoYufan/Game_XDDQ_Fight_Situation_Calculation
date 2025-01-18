#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

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


	self->已完成补气=(self->妖气==10000?true: false );
}