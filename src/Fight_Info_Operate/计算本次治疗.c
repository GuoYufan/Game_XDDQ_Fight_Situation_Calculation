#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

void 计算本次治疗(Fight_info *self, Fight_info *opponent, char *治疗种类)
{
	self->本次治疗 = 重新计算指定治疗(self, opponent, 治疗种类);
}