#!/bin/bash
#Filename: Is_Root.sh

#檢查$UID值，若為0則為root
printf "UID=%d\n" $UID

if [ $UID -eq 0 ]; # UID==0 ->true
then
	printf "Root user\n"
else
	echo "Not root user"
fi
printf "\n"



data=$(($UID-2000))
printf "UID-2000=%d\n" $data

if [ $data -eq 0 ]; # data==0 ->true
then
	printf "Root user\n"
else
	echo "Not root user"
fi

