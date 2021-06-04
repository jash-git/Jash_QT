#!/bin/bash 
#Filename: if_then.sh
#數字比較的關鍵符號：
#-gt 大於
#-eq 等於
#-ne 不等於
#-lt 小於
#-ge 大於或等於
#-le 小於或等於

#if有二種寫法

#if 命令為真
#then
#   命令1
#   命令2
#   .....
#fi
if [ 3 -gt 12 ]
then
   echo ' 3 > 12 '
else
   echo ' 3 < 12  '
fi

#if 命令為真; then
#   命令1
#   命令2
#   .....
#fi
if [ 4 -gt 12 ]; then
   echo ' 4 > 12 '
else
   echo ' 4 < 12  '
fi

a=100
b=20
if [ "$a" -gt "$b" ]; then
	echo "$a > $b" 
else
	echo "$a < $b "
fi






