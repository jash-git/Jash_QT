#!/bin/bash
#Filename:bash_pgrep_cat.sh

echo "show pluma PID"	#秀出指定程式的PID 本範例查 pluma
pgrep pluma

echo "show pluma environ"

cat /proc/$(pgrep pluma)/environ	#秀出指定程式的環境變數（不斷行）
#cat /proc/$(pgrep pluma | awk '{print $0}')/environ

printf "////////////////////////////////////////////////////\n"
echo "show pluma environ"
cat /proc/$(pgrep pluma)/environ | tr '\0' '\n'	#秀出指定程式的環境變數（斷行顯示）
#cat /proc/$(pgrep pluma | awk '{print $0}')/environ | tr '\0' '\n'


