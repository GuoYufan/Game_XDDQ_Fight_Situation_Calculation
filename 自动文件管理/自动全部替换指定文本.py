import os

from 切换工作目录 import browse_directory


支持的扩展名=('.py','.txt','.c','.cpp', '.h')


browse_directory("❓需要进行文本替换的文件在哪个目录?")
selectable_files=[ _ for _ in os.listdir() if os.path.isfile(_) and [suffix for suffix in 支持的扩展名 if _.endswith(suffix)]]
for number, _ in enumerate(selectable_files):
    print(number, _, sep=":")
while True:
    answer=input("\n❓请选择要进行文本替换的文件:")
    try:answer=int(answer)
    except:
        print("❌序号必须是整数\n")
        continue
    if not 0<=answer<=number:
        print("❌不在可选序号范围内\n")
        continue
    checked_file=selectable_files[answer]
    print(f"被选定将要进行文本替换的文件是:{checked_file}")
    break

        
需要替换的文本='''#include "../../../../Common/GYF/include/GYF.h"
'''

替换成='''#include "Common/GYF/include/GYF.h"
'''

answer=input(f"\n❓请输入需要替换的文本(默认:{需要替换的文本})(Enter:默认):\n")
if not answer:需要替换的文本=需要替换的文本
else:需要替换的文本=answer
answer=input(f"❓请输入替换成(默认:{替换成})(Enter:默认):\n")
if not answer:替换成=替换成
else:替换成=answer

with open(checked_file,"r+") as f:
    original_content=f.read()
    if 需要替换的文本 in original_content:
        updated_content=original_content.replace(需要替换的文本,替换成)
    f.seek(0)
    f.write(updated_content)
print("\n✅已将指定文本全部替换完成！")

# updated:2025.1.19 11:39
# 《自动全部替换》v1.0.0-alpha

# 《自动全部替换》v1.0.0-beta
