#!/bin/bash 
#Filename: sleep_sec.sh
Sec="$1"
echo -n count:
tput sc

count=0;
while true;
do
  if [ $count -lt $Sec ]
  then let count++;
       sleep 1;
       tput rc
       tput ed
       echo -n $count;
  else exit 0;
  fi
done

