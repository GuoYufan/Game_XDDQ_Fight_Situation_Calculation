#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

void 进行识海钉流血(Fight_info *self, Fight_info * opponent)
{
	char *战况用语= self->识海钉已触发?"正在流血":"触发";
	
	float 识海钉限伤 = self->攻 * self->神通图鉴-> 识海钉_限伤之攻倍 ;
	float 识海钉掉血伤 = self->神通图鉴->识海钉 ;
	
	if (识海钉限伤 < 识海钉掉血伤 * opponent->血)
	{
		识海钉掉血伤 = 识海钉限伤 / opponent->血 ;
	}
			
	printf("❗️%s人物神识神通识海钉%s, 造成%g%%伤害\n",
	 self->哪一方, 战况用语, 识海钉掉血伤*100);
	受伤(opponent, self, 识海钉掉血伤);
}