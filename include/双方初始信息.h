void Fight_info_show(Fight_info *);
void Fight_info_init(Fight_info *, char *);

// 1:必须正确输入
// 0:允许使用默认值
// int _Settings_input_mode=0;
void Fight_info_input(Fight_info *, const char *);


// PK双方信息录入
void 将人物能力置为默认值(Fight_info *, float );
void 青龙流(Fight_info *, float );
void 应龙流(Fight_info *, float );
void 鸾鸟流(Fight_info *, float, short );
void 蜂翁流(Fight_info *, float, short );

void 双方初始信息的开头统一部分以及先行初始化(Fight_info *);
void 双方初始信息的结尾统一部分(Fight_info *);

void 当前对手(Fight_info *, char *);
void 当前对手_另一个号反暴的(Fight_info *, char *);
void 当前对手_97亿越战140亿(Fight_info *, char *);
void 当前对手_反暴号_回归斗法打1点6倍对手(Fight_info *, char *);
void 当前对手_新区炼气之前(Fight_info *, char *);
void 当前对手_击晕号_六道(Fight_info *, char *);


// 触发计数操作
void Trigger_count_init(Fight_info *);

// 存档操作
void Save_init(Fight_info *);
bool Save_hasChanged(Fight_info *, char *);
void Save_update(Fight_info *, char *);

// 图鉴操作
void Creature_handbook_init(Fight_info *, char *);
void Beast_handbook_init(Fight_info *, char *);
void Avator_handbook_init(Fight_info *, char *);
void Creature_handbook_common(Fight_info *);
void Avator_handbook_common(Fight_info *);