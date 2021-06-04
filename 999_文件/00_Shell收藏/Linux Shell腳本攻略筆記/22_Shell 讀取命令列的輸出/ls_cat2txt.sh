#!/bin/bash 
#Filename: ls_cat2txt.sh
# cmd1 | cmd2 | cmd3 
#shell會將 cmd1 的結果給 cmd2 最後將cmd2 的結果給 cmd3

CMD1="ls -lt"
CMD2="cat -n"
printf "ls -lt \n"
$CMD1
printf "ls -lt | cat -n \n"
$CMD1 | $CMD2
printf "ls -lt | cat -n >note.txt \n"
ls -lt | cat -n >note.txt
#cat note.txt