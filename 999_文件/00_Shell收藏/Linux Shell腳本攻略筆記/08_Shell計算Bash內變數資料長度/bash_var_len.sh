#!/bin/bash
#Filename:bash_var_len.sh

#宣告變數
var01=1234567890
var02="jash.liao"

#echo輸出
echo $var01
echo "var01 len= ${#var01}" 
echo $var02
echo "var02 len= ${#var02}" 

#printf輸出
printf "var01=%s\n var01 len=%s\n" $var01 ${#var01}
printf "var02=%s\n var02 len=%s\n" $var02 ${#var02}
