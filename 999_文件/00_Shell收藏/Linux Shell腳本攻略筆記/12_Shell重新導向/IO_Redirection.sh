#!/bin/bash
#Filename: IO_Redirection.sh

# Shell重新導向
echo "I/O Redirection test01" > Redirection.txt		#清空Redirection.txt 將字串填入
printf "I/O Redirection test02" >> Redirection.txt	#Redirection.txt 將字串填入

cat  Redirection.txt	#在螢幕上輸出檔案內容

printf "\n"

