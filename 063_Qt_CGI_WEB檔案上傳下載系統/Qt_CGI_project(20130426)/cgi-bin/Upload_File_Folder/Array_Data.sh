#!/bin/bash
#Filename: Array_Data.sh

# 宣告陣列變數
int_array=(1 2 3 4 5 6)
str_array[0]="test0"
str_array[1]="test1"
str_array[2]="test2"
str_array[3]="test3"
str_array[4]="test4"
str_array[5]="test5"

#輸出單一值
printf "int_array[0]=%d\n" ${int_array[0]}
printf "str_array[0]=%s\n" ${str_array[0]}

#輸出完整陣列
printf "str_array=%s\n" ${str_array[*]}

#輸出陣列個數
printf "str_array size=%d\n" ${#str_array[*]}

#
result02=$[ ${int_array[1]} + ${int_array[2]}]
printf "result02 +op=%d\n" $result02

