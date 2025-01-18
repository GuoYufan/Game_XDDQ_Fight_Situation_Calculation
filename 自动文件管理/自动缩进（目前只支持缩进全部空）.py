import os
os.chdir(os.path.dirname(__file__))

def 文件指针从头移到指定行(文件, 移到第几行):
    if f.tell():f.seek(0)
    for i in range(移到第几行-1):
        f.readline()
    print(f.tell())
    
被修改的首行=81
被修改的末行=89
with open("Beta_v1_自动增删文件头尾内容.py",'r+') as f:
    文件指针从头移到指定行(f,被修改的首行)
    original_content=f.readlines()
    print(f.tell())
    for line in original_content:print(line)
    input("\n从需要被修改的首行至全文结束的内容已经收集完毕")
    
    # 对需要修改的指定行区间内的原文本内容进行缩进的修改
    文件指针从头移到指定行(f,被修改的首行)
    for number,line in enumerate(original_content):
        if number>(被修改的末行-被修改的首行):break
        f.write(line.strip()+"\n")
     
     # 显示缩进后的需要修改的指定行区间内的新文本内容   
    文件指针从头移到指定行(f,被修改的首行)
    latest_content=f.readlines()
    for line in latest_content:print(line)
    
    print("\n从需要被修改的首行到需要被修改末行之间已缩进完毕！")

# updated: 2025.1.18
# 《自动缩进全部》v1.0.0-alpha.1

