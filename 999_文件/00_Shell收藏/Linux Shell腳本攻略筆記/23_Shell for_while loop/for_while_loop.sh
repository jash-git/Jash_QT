#!/bin/bash 
#Filename: for_while_loop

for((i=0;i<10;i++))
{
	echo "for loop $i"
}

#####################

c=1
while [ $c -le 5 ]
do
	echo "Welcone $c times"
	(( c++ ))
done






