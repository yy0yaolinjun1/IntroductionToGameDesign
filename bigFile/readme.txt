题目:读取一个文件夹下的多个文件，保存其offset以及size并将其信息存储到一个record中,然后将这些文件的所有信息宝
保存在一个二进制大文件中,通过读取record的offset以及一个一个文件通过路径读取比较两者的速度

1文件需要是文本文件

2所有子file的名字不能带有其他空格比如”record - 副本.txt ”，
这种直接拷贝复制的就会出错
因此多数文件时请不要直接复制emmmmm

3请使用支持Python3的IDE运行

4main函数中请修改文件的文本路径比如图0test的文件的绝对路径

*******************请修改以下参数******************

5walkfuncwalkfunc("读取的文件夹绝对路径","保存record文件后的绝对路径")

6readAllFileTime("record文件的绝对路径")

7saveFileIntoBinaryFormat(xxx,"保存的binary大文件的绝对路径")

8readAllBinaryFileTime("record文件的绝对路径","binary大文件的绝对路径"
