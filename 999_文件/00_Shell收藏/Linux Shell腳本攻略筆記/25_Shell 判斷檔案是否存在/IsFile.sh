#!/bin/bash 
#Filename: IsFile.sh

filepath="/home/jash/IsFile.sh"
if [ -e $filepath ];then
	echo $filepath exists
else
	echo $filepath does not exist
fi