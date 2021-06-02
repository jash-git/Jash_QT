#!/bin/bash
vlc -vvv /m5/cf/2012/videos/cf280_1240k.mp4 -y -f mpegts -vcodec libx264 -s 704x480 -r 30 -b:v 3000k -acodec copy -threads 0 ./jashfifo5
