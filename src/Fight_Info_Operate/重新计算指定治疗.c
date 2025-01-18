#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

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
		return self->神通图鉴->煌气_回血量;
	}
	
}