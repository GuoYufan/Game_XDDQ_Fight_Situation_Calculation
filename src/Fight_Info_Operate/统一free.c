#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

void 统一free(Fight_info *self, Fight_info *opponent)
{
	
	for (int i=0; i<self->精怪数量; i++)
		free(self->精怪分组[i]);

	for (int i=0; i<self->神通数量; i++)
		free(self->神通分组[i]);

	for (int i=0; i<opponent->精怪数量; i++)
		free(opponent->精怪分组[i]);

	for (int i=0; i<opponent->神通数量; i++)
		free(opponent->神通分组[i]);
		
	
	
	free(self->精怪分组);
	free(self->神通分组);
	free(opponent->精怪分组);
	free(opponent->神通分组);
	
	free(self->触发计数);
	free(self->存档);
	
	free(self);
	free(opponent);
}