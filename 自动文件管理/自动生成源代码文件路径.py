import os,re

from 自动从多个文件中搜索暴击词条 import browse_directory

def 自动生成源代码文件相对路径():
    browse_directory("❓main源文件所在目录在哪？")
    main_path = os.getcwd()

    while True:
        browse_directory("❓下一批其他源文件所在目录在哪？")
        src_path = os.getcwd()
        # src_dir = re.search(re.escape(main_path)+os.sep+"(.+)",src_path).group(1)
        # src_dir = src_path.replace(main_path+os.sep,"")
        # src_dir = src_path.split(main_path+os.sep)[1]
        src_dir = os.path.relpath(src_path,main_path)
        #input(src_dir)

        src_files = [f for f in os.listdir() if os.path.isfile(os.sep.join((src_path,f))) and f.endswith('.c')]
        browse_directory("❓将生成的含有源代码文件相对路径的txt文件保存在哪？")
        if not input("❓确定开始生成或续写该txt文件?(Enter:否并退出)"):
            break
        with open('源代码文件相对路径.txt', 'a') as f:
            for src in src_files:
                f.write(os.sep.join((src_dir,src))+' ')
        print("✅生成源代码文件相对路径完成!\n")
        if input("❓是否继续?(Q/q:退出|Enter:继续)\n").lower()=="q":
            break
    
def main():
    自动生成源代码文件相对路径()
    
if __name__=="__main__":main()

# updated:2025.1.18
# 《自动生成源代码文件相对路径》v1.0.0正式版
