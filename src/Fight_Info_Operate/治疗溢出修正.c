#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

void 治疗溢出修正(Fight_info * self)
{
	if (self->已损生命<0)
		self->已损生命=0;
}