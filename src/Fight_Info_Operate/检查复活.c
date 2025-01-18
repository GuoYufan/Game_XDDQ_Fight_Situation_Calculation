#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

void 检查复活(Fight_info * self, Fight_info * opponent)
{
	Fight_info *先手方=self, *后手方=opponent;

	if (strstr(self->哪一方, "后") != NULL)
	{
		先手方=opponent;
		后手方=self;
	}
	
	if (self->已损生命>=1)
	{
		printf("(目前:先手方%g%% VS 后手方%g%%)\n", 后手方->已损生命*100,
			   先手方->已损生命*100);
		printf("(目前妖气:先手方%g VS 后手方 %g)\n", 先手方->妖气,
			   后手方->妖气);
			   
		if (!self->复活未起身 && self->可复活次数<1)
		{
			printf("(%s方已死，无复活)\n", self->哪一方);
			printf("\n📖\n(%s方告负)\n", self->哪一方);
			
			
			//统一free(self,opponent);
			exit(EXIT_SUCCESS);
		}
		else if (self->处于冰冻状态)
		{
			if (strstr(self->携带神通, "碎心法") == NULL)
			{
				printf("(%s方已死，扶桑被冰冻不能复活)\n", self->哪一方);
				printf("\n📖\n(%s方告负)\n", self->哪一方);
				
				//统一free(self,opponent);
				exit(EXIT_SUCCESS);
			}
		}
				

		printf("(%s方已死，有复活)\n", self->哪一方);
		self->复活未起身=true;
	}

}