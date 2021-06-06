#!/bin/bash
ffmpeg -i /home/jash/33.mp4 -f mpegts -vcodec libx264 -vpre medium -vpre baseline -acodec libfaac -ac 2 -ab 128k -s 400x300 -r 30 -re -b 200k -threads 2 udp://127.0.0.1:1234
ffmpeg -i /home/jash/44.mp4 -f mpegts -vcodec libx264 -vpre medium -vpre baseline -acodec libfaac -ac 2 -ab 128k -s 400x300 -r 30 -re -b 200k -threads 2 udp://127.0.0.1:1234
