#!/bin/bash
vlc -vvv udp://@224.8.8.13:1238?fifo_size=1000000&overrun_nonfatal=1 -y -f mpegts -vcodec libx264 -s 704x480 -r 30 -b:v 3000k -acodec mp2 -ar 44100 -b:a 96k -ac 2 -preset slow -crf 20 -strict -2 ./jashfifo4
