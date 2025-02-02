#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

void 不受影响的计算与显示(Fight_info * 先手方, Fight_info * 后手方)
{
	// 计算
	重新计算全部伤害(先手方, 后手方);
	
	// 展示信息
	putchar(10);
	printf("[先手方增伤系数%g|后手方增伤系数%g]\n", 先手方->增伤系数,
		   后手方->增伤系数);
	printf("[先手方强灵系数%g|后手方强灵系数%g]\n", 先手方->强灵系数,
		   后手方->强灵系数);
	printf("[先手方是后手方的%g（攻倍）~%g~%g倍对手]\n",
		   先手方->攻/后手方->攻, 先手方->血/后手方->血,
		   先手方->防/后手方->防);
	printf("[后手方是先手方的%g（攻倍）~%g~%g倍对手]\n",
		   后手方->攻/先手方->攻, 后手方->血/先手方->血,
		   后手方->防/先手方->防);

	printf("[先手方有视防御伤%g%%|后手方有视防御伤%g%%]\n",
		   先手方->有视防御伤*100, 后手方->有视防御伤*100);
	printf("[先手方无视防御伤%g%%|后手方无视防御伤%g%%]\n",
		   先手方->无视防御伤*100, 后手方->无视防御伤*100);
	printf
		("[先手方道法%s伤%g%%+回血%g%%|后手方道法%s伤%g%%+回血%g%%]\n",
		 先手方->道法名称, 先手方->道法伤*100, 先手方->道法回血*100,
		 后手方->道法名称, 后手方->道法伤*100, 后手方->道法回血*100);
	printf("[先手方主灵兽%s伤%g%%+回血%g%%|后手方主灵兽%s伤%g%%+回血%g%%]\n",
		   先手方->主灵兽名称, 先手方->主灵兽伤*100, 先手方->主灵兽回血*100,
		   后手方->主灵兽名称, 后手方->主灵兽伤*100,
		   后手方->主灵兽回血*100);
	printf
		("[先手方协同灵兽%s伤%g%%+回血%g%%|后手方协同灵兽%s伤%g%%+回血%g%%]\n",
		 先手方->协同灵兽名称, 先手方->协同灵兽伤*100,
		 先手方->协同灵兽回血*100, 后手方->协同灵兽名称,
		 后手方->协同灵兽伤*100, 后手方->协同灵兽回血*100);
	printf("[先手方精怪%s|后手方精怪%s]\n", 先手方->携带精怪, 后手方->携带精怪);
	printf("[先手方神通%s|后手方神通%s]\n", 先手方->携带神通, 后手方->携带神通);
	printf("[先手方暴击率%g%%+击晕率%g%%|后手方暴击率%g%%+击晕率%g%%]\n", 先手方->暴击率, 先手方->击晕率, 后手方->暴击率, 后手方->击晕率);
}