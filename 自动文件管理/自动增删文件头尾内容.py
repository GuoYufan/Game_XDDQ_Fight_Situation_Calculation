import os,sys

from 自动从多个文件中搜索暴击词条 import browse_directory

def 危险操作之前询问(prompt):
    answer=input(prompt)
    if not answer:
        return False
    return True
        
def 自动添加文件头内容():
    # 打开并读取原始文件内容
    for src in src_files:
        if 	particular_only and not [p for p in particulars[particular_use_number]["files"] if src in p]:
            continue
        with open(src, 'r') as f:
            original_content = f.read()

        # 将新内容与原始内容拼接
        if not particular_only:
            updated_content = header_content + original_content
        else:updated_content=particulars[particular_use_number]["header_content"]+ original_content
        
        # 将拼接后的内容写回文件
        with open(src, 'w') as f:
            f.write(updated_content)
            
    print("✅添加文件头内容完成！")
    
def 自动删除文件头内容():
    for src in src_files:
        if 	particular_only and not [p for p in particulars[particular_use_number]["files"] if src in p]:
            continue
        with open(src, 'r') as f:
            if not 	particular_only:
                updated_content = f.readlines()[第几行之前:]
            else:updated_content = f.readlines()[particulars[particular_use_number]["第几行之前"]:]

        # 将拼接后的内容写回文件
        with open(src, 'w') as f:
            for line in updated_content:
                f.write(line)
    print("✅删除文件头内容完成！\n")


header_content ='''#include <stdio.h>
#include <stdlib.h>
#include "../../include/Fight_Info_Struct.h"
#include "../../include/Fight_Info_Operate.h"
'''
    
第几行之前=4
    
particulars=list()
particulars.append(dict())
particulars[0]["files"]=["检查神通.c","轮序到人物或灵兽.c"]
particulars[0]["第几行之前"]=5
particulars[0]["header_content"]=header_content+\
'''#include "../../include/双方初始信息.h"
'''
    
particulars.append(dict())
particulars[1]["files"]=["战斗属性的触发概率计算与判定及相关经过.c"]
particulars[1]["第几行之前"]=5
particulars[1]["header_content"]=header_content+\
'''#include "../../../../Common/GYF/include/GYF.h"
'''
    
# 开关之是否仅特殊组参与
# 记得每次操作之前检查这个开关
particular_only=True
    
# 选择之参与的特殊组是哪一组
particular_use_number=1
    
# 开关之是否启用删除
delete_enabled=True
    
    
while True:
    browse_directory("❓增删哪里的文件头内容？")
    
    src_files = [f for f in os.listdir() if f.endswith('.c')]
    
    answer=input("❗️确定增删"+("(删除后添加)" if delete_enabled else "(仅添加)")+"这里的文件头内容吗？(Enter:否并继续切换工作目录|Q/q:否并退出)\n")
    if not answer:continue
    elif answer.lower()=="q":sys.exit()
    else:break
        

    
def main():
    if delete_enabled:自动删除文件头内容()
    if not 危险操作之前询问("❗️确定增删(仅添加)这里的文件头内容吗？(Enter:否并退出)\n"):return
    自动添加文件头内容()
    
    

if __name__=="__main__":main()

# updated:2025.1.18
# 《自动增删文件头内容》v1.0.0-beta.1
