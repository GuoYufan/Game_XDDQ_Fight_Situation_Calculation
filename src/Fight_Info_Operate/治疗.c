#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

void 治疗(Fight_info *self)
{
	self->已损生命-=self->本次治疗;
	治疗溢出修正(self);
}