#!/bin/bash
#Filename: tput_stty.sh

# 取出行列數
tput cols
tput lines

# 顯示當前終端機名稱
tput longname

#移動游標
tput cup 3 3

#設定終端機背景色
tput setb 0 #0~7

#設定終端機前景色
tput setf 7 #0~7

printf "text out"
