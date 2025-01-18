#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

void 受伤(Fight_info * self, Fight_info * opponent, float 本次掉血多少 )
{
	float 被妖气计算的掉血量=本次掉血多少;
	
	if (self->已损生命+被妖气计算的掉血量>1)
	{
		被妖气计算的掉血量=1-self->已损生命;
	}
	
	self->已损生命+=本次掉血多少;
	妖气变化(self, 被妖气计算的掉血量);
	检查复活(self, opponent);
	if (!self->复活未起身)
	{
		神通跟随(self, opponent, "");
		精怪跟随(self, opponent, "");
	}
}