#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

void 载入神通与精怪(Fight_info * self, Fight_info * opponent)
{
	if (strstr(self->携带神通, "碎心法") != NULL || strstr(self->携带精怪, "扶桑") != NULL)
	{
		self->可复活次数=self->神通图鉴->碎心法_次数;

	}

	if (strstr(self->携带神通, "化羽") != NULL)
	{
		self->敏*=self->神通图鉴->化羽;
	}

	if (strstr(self->携带神通, "铜皮铁骨") != NULL)
	{
		opponent->增伤系数-=self->神通图鉴->铜皮铁骨;
	}
	
	
	if (strstr(self->携带精怪, "破阵书生") != NULL)
	{
		self->血 *= self->精怪图鉴->破阵书生;
	}
	
	if (strstr(self->携带神通, "飘渺身" ) != NULL)
	{
		self->神通图鉴->飘渺身_剩余回合数 = self->神通图鉴->飘渺身_持续回合数;
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