#define bool short
#define true 1
#define false 0

typedef struct 战斗信息 Fight_info;
typedef struct 上次状态保存 Save;
typedef struct 已触发次数记载 Trigger_count;
typedef struct 精怪图鉴 Creature_handbook;
typedef struct 灵兽图鉴 Beast_handbook;
typedef struct 神通图鉴 Avator_handbook;


// Fight_info
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
	float 妖气;
	short 已完成补气;
	float 增伤系数;
	float 强灵系数;
	char **精怪分组;
	short 精怪数量;
	char **神通分组;
	short 神通数量;
	float 本次伤害, 本次治疗;
	float 击晕率;
	bool 触发了暴击;
	float 暴伤系数;
	float 暴击率;
	float 强疗系数;


	// 精怪状态
	short 小龙女已触发;
	short 山泽精已触发;
	short 大树妖层数;
	short 雷公层数;
	short 精怪被冰冻;
	short 皇帝已触发;
	bool 虞美人已触发;
	
	// 神通状态
	bool 金刚不坏已触发;
	short 拘神层数;
	short 识海钉已触发;

	// 人物状态
	short 处于被晕状态;
	short 被晕的需要失去几次行动;
	bool 复活未起身;
	short 被冰冻的需要失去几次行动;
	bool 处于冰冻状态;
	short 免疫冰冻燃烧回合数;
	
	// 回合状态
	short 第几回合;
	
	// 存档
	Save *存档;
	
	// 触发计数
	Trigger_count *触发计数;
	
	
	// 结果统计
	short *参赛次数;
	short 获胜次数;
	char *who;
	short 统计本场_协同灵兽出手;
	
	// --- 输 入 ---
	
	// 输入人物信息
	float 道法伤倍率_乘在攻, 道法回血倍率_乘在攻;
	char *道法名称;
	float 主灵兽伤倍率_乘在攻, 主灵兽回血倍率_乘在攻;
	short 主灵兽出手频率;
	char *主灵兽名称;
	float 协同灵兽伤倍率_乘在攻, 协同灵兽回血倍率_乘在攻;
	short 协同灵兽出手频率;
	float 协同灵兽出手概率;
	char *协同灵兽名称;
	char *携带神通;
	char *携带精怪;
	float 战斗属性之击晕, 战斗抗性之抗晕;
	short 朱雀灵脉层数;
	bool 百分百闪避;
	short 勾陈灵脉层数;
	float 战斗属性之暴击, 战斗抗性之抗暴;
	float 无视战斗属性, 无视战斗抗性;
	short 青龙灵脉层数;
	
	// 输入精怪图鉴
	Creature_handbook *精怪图鉴;
	
	// 输入灵兽图鉴
	Beast_handbook *灵兽图鉴;
	
	// 输入神通图鉴
	Avator_handbook *神通图鉴;
	
	
	// 操控对局
	short 漏晕几次;
	float 自行设置额外伤;
	short 额外伤限定回合数;
	bool 除了设置漏晕以外的皆必晕;
};


// Save
struct 上次状态保存
{
	short 被晕的需要失去几次行动;
	short 复活未起身;
	short 被冰冻的需要失去几次行动;
	short 识海钉已触发;
};


// Trigger_count
struct 已触发次数记载
{
	short 回春;
	short 兽灵体;
	short 大魔邪身;
	short 勾陈灵脉;
	short 煌气;
};

// Creature_handbook
struct 精怪图鉴
{
	// 皇帝
	float 皇帝_攻倍;
	
	// 大明王
	short 大明王_满层, 大明王_战斗属性之暴击加成;
	short 大明王_层数;
	
	float 破阵书生;
	
	float 紫晴龙狮;
	
	float 小龙女_血线, 小龙女_减伤;
	float 山泽精_血线, 山泽精_治疗;
	
	short 大树妖_满层, 大树妖_层数;
	float 大树妖_强灵加成;
	
	float 干饭人_治疗;
};


// Beast_handbook
struct 灵兽图鉴
{
	// 青龙
	short 青龙_满层, 青龙_战斗属性之暴击加成;
	short 青龙_层数;
};


// Avator_handbook
struct 神通图鉴
{
	// --- 躯 体 神 通 ---
	
	// 化羽
	float 化羽;
	
	// 铜皮铁骨
	float 铜皮铁骨;
	
	// 飘渺身
	short 飘渺身_减伤, 飘渺身_持续回合数, 飘渺身_剩余回合数;

	// 金刚不坏
	float 金刚不坏_血线, 金刚不坏_限伤;
	short 金刚不坏_持续回合数, 金刚不坏_剩余回合数; 

	
	// --- 驭 兽 神 通 ---
	
	// 碎心法/扶桑
	short 碎心法_次数, 扶桑_次数;
	float 碎心法_回血量, 扶桑_回血量;
	
	// 煌气
	float 煌气_回血量;
	short 煌气_免疫冰冻燃烧持续回合数, 煌气_始于第几回合;


	// --- 神 识 神 通 ---
	
	// 识海钉
	float 识海钉, 识海钉_限伤之攻倍;
	
	// 附灵术
	float 附灵术, 附灵术_限伤之攻倍;
};