import os,sys

here=__file__
#当设置为1 为回退到最底层目录
回退到上几级目录=6
for i in range(回退到上几级目录):
    here=os.path.dirname(here)
del 回退到上几级目录,i
#input(here)

import sys
sys.path.append(
	here+
 os.sep.join("/[Python]/common/modules/GYF/".split("/"))
)
del os,sys

from 切换工作目录 import browse_directory
from 选择多个文件 import select_multiple_files
from setBuiltInTypes import *
import os
os.chdir(os.path.dirname(__file__))


def 文件指针从头移到指定行(文件, 移到第几行):
    if 文件.tell():文件.seek(0)
    for i in range(移到第几行-1):
        文件.readline()
    print(文件.tell())

@sign(str,"find_non_blank_pos")
def find_non_blank_pos(word):
    for index, _ in enumerate(word):
        if not _==" ":return index
    
@sign(str,"lstrip_precise")
def lstrip_precise(word, number):
    word_no_leading_blank = word.lstrip()
    number_of_updated_word_leading_blank=word.find_non_blank_pos()-number
    if number_of_updated_word_leading_blank<=0:return word_no_leading_blank
    return " " * number_of_updated_word_leading_blank + word_no_leading_blank
    
# 暂只支持指定行区间，不支持指定单独行
def 自动对指定行区间文本缩进指定数量空(被修改的行区间=[0, None], 缩进多少空=4):
    browse_directory("❓要对指定行区间文本缩进指定数量空的文件在哪个目录下？")
    selected_files=select_multiple_files(os.listdir())
    with open(selected_files[0],'r+') as f:
        文件指针从头移到指定行(f,被修改的行区间[0])
        original_content=f.readlines()[:被修改的行区间[1]]
        for line in original_content:print(line)
        input("\n⚡️从需要被修改的首行至需要被修改的末行之间的内容已经收集完毕")
        
        
        # 对需要修改的指定行区间内的原文本内容进行缩进的修改
        文件指针从头移到指定行(f,被修改的行区间[0])
        
        for number,line in enumerate(original_content):
            updated_line=line.lstrip_precise(缩进多少空)
            f.write(updated_line.rstrip()+"\n")
         
         # 显示缩进后的需要修改的指定行区间内的新文本内容   
        文件指针从头移到指定行(f,被修改的行区间[0])
        latest_content=f.readlines()
        for line in latest_content:print(line)
        
        print("\n✅从需要被修改的首行到需要被修改末行之间已缩进完毕！")


def main():
    自动对指定行区间文本缩进指定数量空(缩进多少空=4)
    
if __name__=="__main__":main()


# updated: 2025.1.18
# 《自动对指定行区间文本缩进全部空》v1.0.0-alpha

# 12:58
# 升级为可以缩进指定数量空格
# v1.0.0-alpha.1

# note:
# 目前的问题是：当对全文进行修改，可正常覆盖文本原位置。
# 但是一旦减少需要修改的行数，就变成追加写入。