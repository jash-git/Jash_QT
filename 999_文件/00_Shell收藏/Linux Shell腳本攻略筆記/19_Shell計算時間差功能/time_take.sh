#!/bin/bash 
#Filename: time_take.sh
start_time=$(date +%s)

./sleep_sec.sh 10

end_time=$(date +%s)

diff__time=$[ $end_time - $start_time ]

printf "\n"
printf "Time taken to execute commands is %d (sec)" $diff__time
printf "\n"
