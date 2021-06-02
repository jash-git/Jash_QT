#!/bin/bash
vlc -vvv udp://@235.1.1.55:1231?fifo_size=1000000&overrun_nonfatal=1 -y -f mpegts -vcodec libx264 -s 704x480 -r 30 -b:v 3000k ./jashfifo4
