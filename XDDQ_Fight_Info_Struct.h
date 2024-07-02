#define bool short
#define true 1
#define false 0

typedef struct 战斗信息 Fight_info;
typedef struct 上次状态保存 Save;
typedef struct 已触发次数记载 Trigger_count;


struct 战斗信息
{
	// 输出战斗信息
	float 攻, 血, 防, 敏;
	float 剩余生命, 已损生命;
	float 无视防御伤;
	float 有视防御伤;
	float 道法伤, 道法回血;
	float 主灵兽伤, 主灵兽回血;
	float 协同灵兽伤, 协同灵兽回血;
	char *哪一方;
	short 可复活次数;
	short 妖气;
	short 已完成补气;
	float 增伤系数;
	float 强灵系数;
	char **精怪分组;
	short 精怪数量;
	char **神通分组;
	short 神通数量;
	float 本次伤害, 本次治疗;
	float 击晕率;


	// 精怪状态
	short 小龙女已触发;
	short 山泽精已触发;
	short 大树妖层数;
	short 雷公层数;
	short 精怪被冰冻;
	short 皇帝已触发;
	
	// 神通状态
	short 金刚不坏已触发;
	short 金刚不坏剩余回合数;
	short 飘渺身剩余回合数;
	short 拘神层数;
	short 识海钉已触发;

	// 人物状态
	short 处于被晕状态;
	short 被晕的需要失去几次行动;
	short 复活未起身;
	short 被冰冻的需要失去几次行动;
	bool 处于冰冻状态;
	
	
	// 存档
	Save *存档;
	
	
	// 输入战斗信息
	float 道法伤倍率_乘在攻, 道法回血倍率_乘在攻;
	char *道法名称;
	float 主灵兽伤倍率_乘在攻, 主灵兽回血倍率_乘在攻;
	short 主灵兽出手频率;
	char *主灵兽名称;
	float 协同灵兽伤倍率_乘在攻, 协同灵兽回血倍率_乘在攻;
	short 协同灵兽出手频率;
	char *协同灵兽名称;
	char *携带神通;
	char *携带精怪;
	float 碎心法回血,扶桑回血;
	float 识海钉掉血伤;
	float 战斗属性之击晕, 战斗抗性之抗晕;
	short 朱雀灵脉层数;
	
	// 操控对局
	short 漏晕几次;
	float 自行设置额外伤;
	short 额外伤限定回合数;
	bool 除了设置漏晕以外的皆必晕;
};


struct 已触发次数记载
{
	short 回春;
	short 兽灵体;
	short 大魔邪身;
};

struct 上次状态保存
{
	short 被晕的需要失去几次行动;
	short 复活未起身;
	short 被冰冻的需要失去几次行动;
	short 识海钉已触发;
	Trigger_count *触发计数;
};