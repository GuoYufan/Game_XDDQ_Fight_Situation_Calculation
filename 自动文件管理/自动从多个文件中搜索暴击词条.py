import os,re

from 切换工作目录 import browse_directory
from 选择多个文件 import select_multiple_files

# --- 文 本 搜 索 器 （从多个文件搜索指定文本） ---
def search_in_files():
    browse_directory("❓从哪个目录的多个文件中搜索指定文本？",os.getcwd())
    
    # 工作目录下的所有文件名
    src_files = [f for f in os.listdir(os.getcwd()) if os.path.isfile(os.path.relpath(f))]
    # 选中的多个文件
    # 切片[:]而不是直接赋值可以避免两个对象绑定，改变其一另一也改变，造成非预期发生。
    selected_files=select_multiple_files(src_files)

    # 标记已显示过的，使不重复显示。避免为了搜索体验（更多的线索帮助找到文本所在处）而增加的前后两行的显示造成重复。
    printed_lines = set()
    
    # 让用户输入需要搜索的文本
    find_content = input("\n请输入要从多个文件中搜索的文本:")
    # 在连续匹配到结果的过程中是否出现中断
    broken=True
    for selected_file in selected_files:
        # 修复上个版本v1.0.0的问题：每搜索完一个文件，到下一个文件开始搜索之前清空“打印过的行”集合对象。
        printed_lines.clear()
        with open(selected_file,'r') as f:
            # 读取原文的全部行
            original_content=f.readlines()
        for number,line in enumerate(original_content):
            # 如果需要查找的文本出现于这一行
            if find_content in line:
                if broken:
                    print(f"<at 第{number}行 in {selected_file}>:")
                    broken=False
                # 用str.strip()比直接打印line更美观
                # 采纳chatgpt的建议，增加前后两行的显示以提升搜索体验
                if not (number-1 in printed_lines or number-1<0):
                    print(original_content[number-1].strip())
                    printed_lines.add(number-1)
                if not number in printed_lines:
                    print(line.strip())
                    printed_lines.add(number)
                if not (number+1 in printed_lines or number+1>len(original_content)-1):
                    print(original_content[number+1].strip())
                    printed_lines.add(number+1)
                print()
            else:broken=True
    print("\n✅搜索完毕!")

            
if __name__=="__main__":
    os.chdir(os.path.dirname(__file__))
    while True:
        search_in_files()
        input("按任意键继续...\n")
        
# updated:2025.1.17
# 《自动从多个文件中搜索“暴击”文本》v1.0.0-beta版本

# updated:2025.1.17 8:23~12:32
# 经过了chatgpt的指导，升级到v1.0.0正式版

# note:2025.1.20 11:21
# 发现问题。由于不是在单个文件中搜索而是在多个文件中搜索，而目前“多打印上下文的同时不打印重复行“显然是根据单个文件中搜索的逻辑来的。
# 从而造成了问题。问题会在“当处于这个行号会搜索到指定文本”不只在单个文件中发生时发生。
# 造成只有一个文件在这个行号搜索到指定文本会打印上下文，其他文件在这个行号搜索到再多次也不打印出来，看不见。

# fixed:2025.1.20 11:27
# 《自动从多个文件中搜索“暴击”文本》v1.0.1

# updated:2025.1.22 17:11
# 优化了搜索完一遍之后，使得不会重置到本文件所在目录，而是能够停留在最近的工作目录，从而不像之前那么不方便
