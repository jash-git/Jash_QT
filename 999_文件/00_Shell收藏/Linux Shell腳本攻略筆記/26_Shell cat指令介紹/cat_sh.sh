#!/bin/bash 
#Filename: cat_sh.sh

#cat指令介紹

#顯示檔案內容
echo 'cat file.txt'
cat file.txt
echo '/////////////////'
#壓縮空白行
echo 'cat -s file.txt'
cat -s file.txt
echo '/////////////////'
#移除空白行
echo "cat file.txt | tr -s '\n'"
cat file.txt | tr -s '\n'
echo '/////////////////'
#顯示行號
echo "cat  -n file.txt"
cat  -n file.txt
echo '/////////////////'
