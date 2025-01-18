#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"

// 使用奇技淫巧
void 重新计算全部伤害(Fight_info *self, Fight_info *opponent)
{
	// 双方无视防御伤
	self->无视防御伤=self->攻/opponent->血;
	opponent->无视防御伤=opponent->攻/self->血;

	// 标准关系中，防御代表的掉血伤固定为1.66%（准确值1/6）
	// 奇技淫巧：有视防御伤=无视防御伤-防御代表的掉血伤
	self->有视防御伤=self->无视防御伤-opponent->防/opponent->血;

	opponent->有视防御伤=opponent->无视防御伤-self->防/self->血;

	// 双方道法伤或道法回血
	// 奇技淫巧：道法加成（加在有视防御上）=无视防御伤*(道法倍率-1)
	self->道法伤=self->有视防御伤+self->无视防御伤*(self->道法伤倍率_乘在攻-1);
	self->道法回血=self->攻*self->
		道法回血倍率_乘在攻/self->血;
	opponent->道法伤=opponent->有视防御伤+opponent->无视防御伤*(opponent->道法伤倍率_乘在攻-1);


	// 双方主灵兽
	// 奇技淫巧：主灵兽掉血伤=(主灵兽倍率/对手倍数*10)%
	self->主灵兽伤=self->无视防御伤*self->主灵兽伤倍率_乘在攻;
	opponent->主灵兽伤=opponent->无视防御伤*opponent->主灵兽伤倍率_乘在攻;

	self->主灵兽回血=self->攻*self->
		主灵兽回血倍率_乘在攻/self->血;
	opponent->主灵兽回血=opponent->攻*opponent->
		主灵兽回血倍率_乘在攻/opponent->血;
		
	// 双方协同灵兽
	self->协同灵兽伤=self->无视防御伤*self->
		协同灵兽伤倍率_乘在攻;
	opponent->协同灵兽伤=opponent->无视防御伤*opponent->
		协同灵兽伤倍率_乘在攻;

	self->协同灵兽回血=self->攻*self->
		协同灵兽回血倍率_乘在攻/self->血;
	opponent->协同灵兽回血=opponent->攻*opponent->
		协同灵兽回血倍率_乘在攻/opponent->血;

	计算实际暴击率(self,opponent);
	计算实际暴击率(opponent,self);
	计算实际击晕率(self,opponent);
	计算实际击晕率(opponent,self);
}

