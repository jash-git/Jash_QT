#!/bin/bash
file="$1"
kill -9 `ps -ef|grep vlc|grep 224.8.8.13|awk '{print $2}'`
echo $file
ffmpeg -y -i $file -f mpegts -vcodec libx264 -s 704x480 -r 30 -b:v 3000k -acodec copy -threads 0 - |cvlc - --sout-ts-pid-video=69 --sout-ts-pid-audio=68 --sout-transcode-alang=eng --sout-keep --sout '#transcode{fps=29.97,venc=x264{keyint=90,profile=main,level=3,bframes=0,no-cabac,ref=1,no-mbtree,partitions=none,no-weightb,weightp=0,me=hex,subme=0,no-mixed-refs,no-8x8dct,trellis=0},vcodec=h264,vb=1200,width=704,height=480,deinterlace,acodec=mp2a,alang=eng,ab=128,channels=2,samplerate=48000}:udp{mux=ts,dst=224.8.8.13:1238}'
