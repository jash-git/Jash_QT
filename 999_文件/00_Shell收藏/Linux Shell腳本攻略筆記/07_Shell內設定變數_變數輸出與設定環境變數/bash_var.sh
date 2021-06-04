#!/bin/bash
#Filename:bash_var.sh

#宣告變數
var="value"
fruit="apple"
count=5

#echo 輸出變數
echo "var=" $var
echo "var=" ${var}
echo "I have $count ${fruit} (s)"

#printf輸出變數
printf "var=%s\n" $var
printf "var=%s\n" ${var}
printf "I have %s %s (s)\n" $count,${fruit}

#設定環境變數
echo $PATH
export PATH="$PATH:/home/jash"
echo $PATH
