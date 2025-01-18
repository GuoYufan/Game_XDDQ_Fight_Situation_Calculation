#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

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
			灵脉跟随(self,"成功暴击");
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
			灵脉跟随(self,"成功暴击");
			self->触发了暴击=false;
		}
		return self->道法伤;
	}
	
	if (!strcmp(伤害种类, "紫晴龙狮伤"))
	{
		return self->攻 * self->精怪图鉴->紫晴龙狮 / opponent->血 * self->增伤系数;
	}
	
	if (!strcmp(伤害种类, "附灵术伤"))
	{
		opponent->剩余生命 = 1 - opponent->已损生命;
		float 附灵术掉血伤 = opponent->剩余生命 * self->神通图鉴->附灵术;
		float 附灵术限伤= self->攻 * self->神通图鉴->附灵术_限伤之攻倍 / opponent->血;
		
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