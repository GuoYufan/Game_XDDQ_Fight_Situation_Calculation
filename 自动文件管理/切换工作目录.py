import os,re

# --- 目 录 浏 览 器 （切换工作目录） ---
def browse_directory(prompt="❓where?", chdir_at_startup=os.path.dirname(__file__)):
    # pre_chdir: 先行切换到的工作目录
    os.chdir(chdir_at_startup)
    print(os.getcwd())
    print()
    
    重新选择=False
    while True:
        if not 重新选择:
            for current_directory in os.listdir(os.getcwd()):print(current_directory)
        重新选择=False
        # 让用户输入去哪（以哪里作为工作目录）？（去上层目录或去下层目录或选定就在当前目录）
        where=input("\n"+prompt+"\n(..:去上层|输入名称(可精确、可模糊)(模糊通配符*):去下层|Enter:就在这)\n")
        # 如果输入..，表示去上层目录
        if where=="..":
            try:os.chdir(os.path.dirname(os.getcwd()))
            except:
                # 上层一般来说都能去，不会出现错误。除非是到了最顶层。
                print("❌无法进入\n")
                重新选择=True
                continue
            print()
            continue
        # 如果啥也不输入，就确定在这（往往是按Enter键，这个按键符合用户“选好了，就想要在这”的心理）
        elif not where:break
        # 如果非模糊输入，就直接完全按照输入的文本尝试进入
        elif not "*" in where:
            try:os.chdir(os.getcwd()+os.sep+where)
            except:
                # 下层就不一样，不得不考虑进不去的情况。
                print("❌无法进入\n")
                # 没有选好，重新选择时，避免重复列出工作目录所有目录及文件，占用输出行
                重新选择=True
                continue
            print()
        # 如果是模糊输入，则列出相匹配的目录名。必须是匹配到完整的目录名才视为有效匹配。如果只是匹配到目录名的一部分也视作无效匹配。
        # 比如输入"*Im"，在不用[... if re.fullmatch()]而用[... if re.search()]的情况下，会匹配到"XDDQ_Im"，而完整目录名是“XDDQ_Implementation"。目录名不完整却匹配到，却不视为无效，这样是不符预期。因为用户想要进入目录，凡是只匹配到一部分目录名就开始咋呼都是浪费时间，因为进入不了目录。
        elif "*" in where:
            # 注意转义
            if [_ for _ in "[]" if _ in where]:
                for char in "[]":
                    where=where.replace(char,"\\"+char)
            # 把符合用户习惯输入的模糊匹配符替换成Python的re能够识别的起作用的进行模糊匹配操作
            where=where.replace("*",".*")
            # 将匹配到的子目录收集进来
            subdirectorys=[re.search(where,name).group() for name in os.listdir(os.getcwd()) if re.fullmatch(where,name)]
            #input(subdirectorys)
            if not subdirectorys:
                print("❌没有这个名称的目录或文件\n")
                重新选择=True
                continue
            # 如果匹配到有且仅有一个，无需选择，直接进入
            if len(subdirectorys)==1:
                try:os.chdir(os.getcwd()+os.sep+subdirectorys[0])
                except:
                    print("❌无法进入\n")
                    重新选择=True
                    continue
            else:
                # 如果匹配到多个，则列出每个的序号和名称以供选择（序号用于在模糊匹配到多个目录时供用户选择唯一目录，这个序号可以给subdirectorys列表使用）
                for number,subdirectory in enumerate(subdirectorys):
                    print(number,":",subdirectory,sep=str())
            
                while True:
                    choice=input("请选择:")
                    if not choice:
                        重新选择=True
                        break
                    try:choice=int(choice)
                    except:
                        print("❌序号必须是整数")
                        continue
                    # 选择的序号需要在范围内，范围从列表的第一个索引号也就是0开始
                    if not 0<=choice<=number:
                        print("❌不在可选序号范围内")
                        continue
                    break
                if 重新选择:continue
                
                try:os.chdir(os.getcwd()+os.sep+subdirectorys[choice])
                except:
                    print("❌无法进入\n")
                    重新选择=True
                    continue
                print()


if __name__=="__main__":
    while True:
        browse_directory()
        input("按任意键继续...\n")

        
# updated:2025.1.17
# 《自动从多个文件中搜索“暴击”文本》v1.0.0-beta版本

# updated:2025.1.17 8:23~12:32
# 经过了chatgpt的指导，升级到v1.0.0正式版

# updated:2025.1.20
# 《切换工作目录》v1.0.0
