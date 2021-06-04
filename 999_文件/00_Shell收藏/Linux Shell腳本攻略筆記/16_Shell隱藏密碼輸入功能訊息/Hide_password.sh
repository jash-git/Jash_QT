#!/bin/bash
#Filename: Hide_password.sh

echo -e "Enter password: " #顯示文字 並換行
stty -echo					#隱藏輸入資訊
read password				#讀取輸入資訊
stty echo					#允許輸出顯示
echo password: $password 	#顯示剛才輸入資訊
