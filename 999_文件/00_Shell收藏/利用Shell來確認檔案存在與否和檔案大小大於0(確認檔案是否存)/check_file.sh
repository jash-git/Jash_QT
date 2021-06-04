#!/bin/bash
#http://www.cyberciti.biz/faq/unix-linux-test-existence-of-file-in-bash/

#test -e /home/jash/wmv_20141020/s14019602.mp4
#test -s /home/jash/wmv_20141020/s14019602.mp4

file="/home/jash/wmv_20141020/s141019601.mp4"
if [ -e "$file" ]
then
	echo "$file found."
else
	echo "$file not found."
fi
if [ -s "$file" ]
then
	echo "$file size >0."
else
	echo "$file size <=0."
fi
