#!/bin/bash 
#Filename: bash_printf.sh 格式化輸出

printf  "%-5s %-10s %-4s\n" No Name  Mark		#-向左對齊符號,s代表字串,f代表浮點數
printf  "%-5s %-10s %-4.2f\n" 1 Sarath 80.3456 
printf  "%-5s %-10s %-4.2f\n" 2 James 90.9989 
printf  "%-5s %-10s %-4.2f\n" 3 Jeff 77.564

printf  "%5s\t%10s\t%4s\n" No Name  Mark 
printf  "%5s\t%10s\t%4.2f\n" 1 Sarath 80.3456 
printf  "%5s\t%10s\t%4.2f\n" 2 James 90.9989 
printf  "%5s\t%10s\t%4.2f\n" 3 Jeff 77.564

###########################################
#輸出顏色控制
printf  "\e[1;31m %5s\t \e[1;32m %10s\t \e[1;33m %4s \e[0m \n" No Name  Mark 
printf  "\e[1;34m %5s\t \e[1;35m %10s\t \e[1;36m %4.2f \e[0m \n" 1 Sarath 80.3456 
printf  "\e[1;37m %5s\t \e[1;38m %10s\t \e[1;39m %4.2f \e[0m \n" 2 James 90.9989 
printf  "\e[1;40m %5s\t \e[1;41m %10s\t \e[1;42m %4.2f \e[0m \n" 3 Jeff 77.564


