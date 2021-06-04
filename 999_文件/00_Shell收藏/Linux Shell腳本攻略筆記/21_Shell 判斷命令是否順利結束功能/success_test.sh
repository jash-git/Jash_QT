#!/bin/bash 
#Filename: success_test.sh

CMD="ls -lt"
status
$CMD
if [ $? -eq 0 ];
then
	printf "%s executed successfully" $CMD
else
	printf "%s executed unsuccessfully" $CMD
fi

printf "\n"
