# -*- coding: utf-8 -*-
"""
Created on Thu May 31 10:42:33 2018

@author: Yaolinjun
"""

import cv2  
import os
import zipfile
import tarfile
import datetime
import pickle 
import struct
#遍历文件夹下的文件并创建record的txt文件
def walkfunc(folder,recordFile):  
    f=open(recordFile,'w')
    folderscount=0  
    filescount=0  
    currentOffset=0
    lastFileSize=0
    fileinfo=""
    for parent,dirs,filenames in os.walk(folder):  
        for filename in filenames:
            pathfile = os.path.join(parent, filename)
            fileSize=os.path.getsize(pathfile)
            currentOffset=currentOffset+lastFileSize
            lastFileSize=fileSize
            print(filename+" fileSize is "+str(fileSize))
            print("current offset is "+str(currentOffset))
            fileinfo=(pathfile+" "+str(fileSize)+" "+str(currentOffset)+'\n')
            f.write(fileinfo)
            print(fileinfo)
        folderscount+=len(dirs)  
        print("folderscoount"+str(folderscount))
        filescount+=len(filenames)  
        print("filescoount"+str(filescount))
        f.close()
    return folderscount,filescount  

#读取记录文件
def readRecordFile(fileName):
    f=open(fileName)
    lines=f.readlines()
    
    print("打印record中的数据")
    for line in lines:
        fileInfo=line.split(sep=" ",maxsplit=2)
        fileName=fileInfo[0]
        fileSize=fileInfo[1]
        fileOffset=fileInfo[2]
        print(line)
        
    f.close()

def readAllFileTime(fileName):
    
    starttime = datetime.datetime.now()
    totalContent=''
    f=open(fileName)
    lines=f.readlines()
    f.close()
    lineCum=0
    for line in lines:
        fileInfo=line.split(sep=" ",maxsplit=2)
        currentfileName=fileInfo[0]
        currentfileSize=fileInfo[1]
        currentfileOffset=fileInfo[2]
        tempFile=open(currentfileName)
        contents=tempFile.readlines()
        for content in contents:
           totalContent+=content
           # print(''.join(content))
        tempFile.close()
        lineCum+=1
    endtime = datetime.datetime.now()
    #print(totalContent)
    print("通过绝对路径读取"+str(lineCum)+"个文件的总时间为")
    print(endtime-starttime)
    return totalContent
def saveFileIntoBinaryFormat(content,fileName):
    fp = open(fileName, 'wb')
    binaryContent=content.encode()
    fp.write(binaryContent)
    fp.flush()
    fp.close()
''' 
#将文件夹打包目录为zip文件（未压缩）
def make_zip(source_dir, output_filename):
  zipf = zipfile.ZipFile(output_filename, 'w')
  pre_len = len(os.path.dirname(source_dir))
  for parent, dirnames, filenames in os.walk(source_dir):
    for filename in filenames:
      pathfile = os.path.join(parent, filename)
      arcname = pathfile[pre_len:].strip(os.path.sep)   #相对路径
      zipf.write(pathfile)
  zipf.close()
#将文件夹打包成zip文件并读取
def zipReadFile(fileName):
    azip = zipfile.ZipFile(fileName)  # ['bb/', 'bb/aa.txt']
    print("读取通过zip打包后的文件")
    print(azip.filename)
    print(azip.namelist())
'''
def readAllBinaryFileTime(recordFileName,binaryFileName):
    recordFile=open(recordFileName)
    lines=recordFile.readlines()
    fileoffsets=[]
    fileSizes=[]
    num=0
    print("打印record中的数据")
    for line in lines:
        fileInfo=line.split(sep=" ",maxsplit=2)
        filesize=int(fileInfo[1])
        fileoffset=int(fileInfo[2])
        fileSizes.append(filesize)
        fileoffsets.append(fileoffset)
        num+=1
    recordFile.close()
    starttime = datetime.datetime.now()
    binaryFile=open("C:/Users/80686/Desktop/binaryContent",'rb')
    for i in range(num):
        binaryFile.seek(fileoffsets[i],0)
        #print(fileoffsets[i])
        #print(fileSizes[i])
        content=binaryFile.read(fileSizes[i])
        #print(content)
    binaryFile.close()
    endtime = datetime.datetime.now()
    #print(totalContent)
    print("读取含有"+str(num)+"子文件的bigfile所有文件信息的时间为")
    print(endtime-starttime)
if __name__ == '__main__':
    allFileContent=''
    #读取test文件并将其路径,size,以及offset保存到record文本文件中
    walkfunc("C:/Users/80686/Desktop/test","record.txt")
    #读取record文本存放的所有路径的内容并将内容返回
    allFileContent= readAllFileTime("record.txt")
    
    #print(allFileContent)
    #读取返回的内容并将内容的二进制保存到指定路径
    saveFileIntoBinaryFormat(allFileContent,"C:/Users/80686/Desktop/binaryContent")
    '''
    fp=open("C:/Users/80686/Desktop/binaryContent",'rb')
    fp.seek(1289,0)
    print("读取的内容")
    content=fp.read(212)
    fp.close()
    print(content)
    '''
    readAllBinaryFileTime("record.txt","C:/Users/80686/Desktop/binaryContent")
    


    
