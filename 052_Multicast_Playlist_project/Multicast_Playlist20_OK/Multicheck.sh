#! /bin/bash

./mrec 224.8.8.3 1239> /home/jash/bin04.txt &
sleep 10
pkill mrec
temp04=`lsof|head -1 /home/jash/bin04.txt|awk '{print $1}'`
echo $temp04
pid041=`ps -ef|grep jash|grep Multicast_Playlist04|awk '{print $2}'`
echo $pid041
pid042=`ps -ef|grep jash|grep "bin04/VLCOutputBash.sh"|awk '{print $2}'`
echo $pid042
pid043=`ps -ef|grep vlc|grep "224.8.8.3:1239"|awk '{print $2}'`
echo $pid043
pid044=`ps -ef|grep vlc|grep "dst=127.0.0.1:1239"|awk '{print $2}'`
echo $pid044
if [ $temp04 !="Received" ]
then
kill -9 $pid041 $pid042 $pid043 $pid044
fi

./mrec 224.8.8.1 1234> /home/jash/bin01.txt &
sleep 10
pkill mrec
temp01=`lsof|head -1 /home/jash/bin01.txt|awk '{print $1}'`
echo $temp01
pid011=`ps -ef|grep jash|grep Multicast_Playlist01|awk '{print $2}'`
echo $pid011
pid012=`ps -ef|grep jash|grep "bin01/VLCOutputBash.sh"|awk '{print $2}'`
echo $pid012
pid013=`ps -ef|grep vlc|grep "224.8.8.1:1234"|awk '{print $2}'`
echo $pid013
pid014=`ps -ef|grep vlc|grep "dst=127.0.0.1:1231"|awk '{print $2}'`
echo $pid014
if [ $temp01 !="Received" ]
then
kill -9 $pid011 $pid012 $pid013 $pid014
fi

./mrec 224.8.8.2 1234> /home/jash/bin02.txt &
sleep 10
pkill mrec
temp02=`lsof|head -1 /home/jash/bin02.txt|awk '{print $1}'`
echo $temp02
pid021=`ps -ef|grep jash|grep Multicast_Playlist02|awk '{print $2}'`
echo $pid021
pid022=`ps -ef|grep jash|grep "bin02/VLCOutputBash.sh"|awk '{print $2}'`
echo $pid022
pid023=`ps -ef|grep vlc|grep "224.8.8.2:1234"|awk '{print $2}'`
echo $pid023
pid024=`ps -ef|grep vlc|grep "dst=127.0.0.1:1232"|awk '{print $2}'`
echo $pid024
if [ $temp02 !="Received" ]
then
kill -9 $pid021 $pid022 $pid023 $pid024
fi

./mrec 224.8.8.3 1234> /home/jash/bin03.txt &
sleep 10
pkill mrec
temp03=`lsof|head -1 /home/jash/bin03.txt|awk '{print $1}'`
echo $temp03
pid031=`ps -ef|grep jash|grep Multicast_Playlist03|awk '{print $2}'`
echo $pid031
pid032=`ps -ef|grep jash|grep "bin03/VLCOutputBash.sh"|awk '{print $2}'`
echo $pid032
pid033=`ps -ef|grep vlc|grep "224.8.8.3:1234"|awk '{print $2}'`
echo $pid033
pid034=`ps -ef|grep vlc|grep "dst=127.0.0.1:1233"|awk '{print $2}'`
echo $pid034
if [ $temp03 !="Received" ]
then
kill -9 $pid031 $pid032 $pid033 $pid034
fi

#./mrec 235.2.1.169 3233> /home/charles/x.txt &
#sleep 10
#pkill mrec
#xtemp=`lsof|head -1 /home/charles/x.txt|awk '{print $1}'`
#xpid=`ps -ef|grep vlc|grep "235.2.1.169:3233"|awk '{print $2}'`
#if [ $xtemp !="Received" ]
#then
#kill -9 $xpid
#fi

#./mrec 235.1.1.156 1233> /home/noc/z.txt &
#sleep 10
#pkill mrec
#ztemp=`lsof|head -1 /home/noc/z.txt|awk '{print $1}'`
#zpid=`ps -ef|grep vlc|grep "235.1.1.156:1233"|awk '{print $2}'`
#if [ $ztemp !="Received" ]
#then
#kill -9 $zpid
#fi

