void 本场战斗之战况预览();
// void 统一free(Fight_info *, Fight_info *);

// --- 受 伤 与 治 疗 ---
void 载入神通与精怪(Fight_info *, Fight_info *);
void 不受影响的计算与显示(Fight_info *, Fight_info *);
void 检查复活(Fight_info *, Fight_info *);
void 妖气变化(Fight_info *, float);
void 受伤(Fight_info *, Fight_info *, float );
void 计算本次伤害(Fight_info *, Fight_info *, char *);
void 重新计算全部伤害(Fight_info *, Fight_info *);
float 重新计算指定伤害(Fight_info *, Fight_info *, char *);
void 治疗(Fight_info *self);
void 治疗溢出修正(Fight_info *);
void 计算本次治疗(Fight_info *self, Fight_info *, char *);
float 重新计算指定治疗(Fight_info *self, Fight_info *, char *);
void 检查精怪(Fight_info *, Fight_info *, char *, char *);
void 精怪跟随(Fight_info *, Fight_info *, char *);
void 进行识海钉流血(Fight_info *, Fight_info *);
void 检查神通(Fight_info *, Fight_info *, char *, char *);
void 神通跟随(Fight_info *, Fight_info *, char *);
void 灵脉跟随(Fight_info *, char *);

// --- 概 率 触 发 ---
void 战斗属性_setter(Fight_info *, Fight_info *, char *, float );
void 计算实际击晕率(Fight_info *, Fight_info *);
void 计算实际暴击率(Fight_info *, Fight_info *);
bool 击晕率是否足够(Fight_info *, Fight_info *);
bool 暴击率是否足够(Fight_info *, Fight_info *);
void 被击晕(Fight_info *);
void 击晕判定及相关经过(Fight_info *, Fight_info *);
void 暴击判定及相关经过(Fight_info *, Fight_info *);

// --- 轮 序 ---
void 释放道法(Fight_info *, Fight_info *);
void 进行普攻(Fight_info *, Fight_info *);
void 解复活未起身(Fight_info *, Fight_info *);
void 检查人物受控状态是否可恢复(Fight_info *);
void 轮序到人物(Fight_info *, Fight_info *);
void 灵兽效果(Fight_info *, Fight_info *, char *);
void 轮序到灵兽(Fight_info *, Fight_info *);