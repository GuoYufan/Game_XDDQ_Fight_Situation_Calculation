#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEBUG printf("---debug位置---\n行号:%d\n文件名:<%s>",__LINE__,__FILE__);getchar();
#include <include/Fight_Info_Struct.h>
#include <include/双方初始信息.h>
#include <include/Fight_Info_Operate.h>

// 击晕流的用法：通过更改敏捷度切换先手晕和后手晕，看后手晕有多险，万一被暴击呢？
// 以及设置漏晕次数高达20次，从而达到全程漏晕，达到完全抗晕，等于无晕。用来收集无晕情况下的战况。
// 比如对比同样后手无晕，应龙、鸾鸟、青龙谁更强。

// 支持设置必晕。把漏晕次数设置为0，同时把「除了设置漏晕以外的皆必晕」设置为true即可必晕。

// 支持百分百闪避和勾陈灵脉。（不支持概率闪避。）

// 支持暴击和暴伤系数和青龙灵脉。

/*
   v1.0.1版本概要：
   从尝试解决上一版本的遗留问题——蚀魂咒问题——入手。
   成功模拟了一场打1.6倍有必复活（扶桑+煌气免疫冰冻所以必然复活）有治疗（煌气）有锁血（金刚不坏）的对手，战况准度极高。
   并且在这场通过使赌可赌的运气强制为不需要赌快速（不需要运行那么多次）复现了与实战中完全相同的100%胜率方法。
   */

// 支持协同灵兽行动。

short main()
{
	srand(time(NULL));
	// printf("%d\n",sizeof (Fight_info)); getchar();
	
	Fight_info *我=(Fight_info *) malloc(sizeof(Fight_info));
	Fight_info *敌=(Fight_info *) malloc(sizeof(Fight_info));
	
	if (我==NULL || 敌==NULL)
	{
		fprintf(stderr,"❌内存分配失败!");
		exit(EXIT_FAILURE);
	}

	// 初始化双方战斗信息
	Fight_info_init(我, "我");
	Fight_info_init(敌, "敌");
	
	// 载入神通与精怪
	载入神通与精怪(我, 敌);
	载入神通与精怪(敌, 我);
	
	// 显示战斗中的攻血防敏
	Fight_info_show(我);
	Fight_info_show(敌);
	

	// 分出先后手方
	Fight_info *先手方=NULL, *后手方=NULL;
	先手方=敌->敏>我->敏? 敌 : 我;
	后手方=先手方==敌? 我 : 敌;
	先手方->哪一方="先手";
	后手方->哪一方="后手";

	// 不受影响的计算与显示
	不受影响的计算与显示(先手方, 后手方);
	

	// 进入战斗
	puts("\n📝\n---《进入战斗》---");
	putchar(10);
	for (short i = 0; i < 20; i++)
	{
		printf("第%d回合\n", i + 1);
		printf("~~~~~~~\n");
		
		///*强制使可赌的这部分运气不需要赌
		if (i+1==1)
		{
			// 赌对手协同灵兽玄武不行动
			敌->协同灵兽出手概率=0;
			
			// 协同灵兽青龙补伤害（赌协同灵兽出手一次即可）
			// 我->协同灵兽出手概率=0;
			// 敌->已损生命+=0.0374252*1;
			
			// 稳暴击（赌暴击一次不落）
			// 我->战斗属性之暴击+=(100-(我->战斗属性之暴击-敌->战斗抗性之抗暴));
		}
		///*
		
		先手方->第几回合=后手方->第几回合=i+1;
		
		// 灵脉
		灵脉跟随(先手方, "回合开始时");
		灵脉跟随(后手方, "回合开始时");
		
		//Segmentation fault
		//getchar();
		// 精怪
		精怪跟随(先手方, 后手方, "回合开始时");
		精怪跟随(后手方, 先手方, "回合开始时");
		
		
		// 神通
		神通跟随(先手方, 后手方, "回合开始时");
		神通跟随(后手方, 先手方, "回合开始时");
		
		//getchar();
		// 灵兽
		轮序到灵兽(先手方, 后手方);
		精怪跟随(先手方, 后手方, "");
		精怪跟随(后手方, 先手方, "");

		轮序到灵兽(后手方, 先手方);
		精怪跟随(先手方, 后手方, "");
		精怪跟随(后手方, 先手方, "");


		// 被晕状态
		检查人物受控状态是否可恢复(先手方);
		检查人物受控状态是否可恢复(后手方);
		
				
		// 人物
		轮序到人物(先手方, 后手方);
		轮序到人物(后手方, 先手方);
		
	
		// 回合结束时（对一些效果回合数进行回退）
		神通跟随(先手方, 后手方, "回合结束时");
		神通跟随(后手方, 先手方, "回合结束时");
		
		// 实时战况反馈
		printf("(目前:先手方%g%% VS 后手方%g%%)\n", 后手方->已损生命*100,
			   先手方->已损生命*100);
		printf("(目前妖气:先手方%g VS 后手方 %g)\n", 先手方->妖气,
			   后手方->妖气);
		putchar(10);
	}
	
	return 0;
}

/* 
   42+318+5.8+4238

 */


/* 
   ​25+229+4.4+3917 ​27+270+4.7+4137 ​ ​1.08~1.17~1.06 ​
   ​[先手方有视防御9.86%|后手方有视防御7.51%]
   ​[先手方无视防御11.79%|后手方无视防御9.25%]
   ​[先手方道法冰封千里16.94%|后手方道法回生回血12.11%]
   ​ ​[先手方应龙58.95%|后手方应龙46.29%]
   ​[后手方协同白虎11.11%] ​ ​[先手方青龙7.07%]
   ​[先手方霸王2.82%]

 */