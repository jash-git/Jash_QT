#!/bin/bash
#tmpfile="video_tmp.mp4"
options="-vn"

ffmpeg -y -i "$1" -acodec libfaac -ac 2 -ar 44100 -ab 40k -pass 2 -threads 2 $options "$2"
