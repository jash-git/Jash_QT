#!/bin/bash
file="$1"
offset="$2"
kill -9 `ps -ef|grep vlc|grep 224.8.8.253:25301|awk '{print $2}'`
echo $file
echo $offset
ffmpeg -y -ss $offset -i $file -f mpegts -vcodec libx264 -s 640x480 -r 30 -b:v 3000k -acodec copy -threads 0 - |cvlc - --sout-ts-pid-video=69 --sout-ts-pid-audio=68 --sout-transcode-alang=eng --logo-file /home/chst01/5TVLOGO.png --logo-x=50 --logo-y=370 --sout '#transcode{sfilter=logo,fps=0,hurry-up,open-gop=normal,udp-caching=0,venc=x264{keyint=24,vqscale=1,vqmin=1,profile=main,partition=i4x4,level=3.1,bframes=4,subme=7,ref=4,qpmax=51,qpmin=1,me=hex,trellis=1},vcodec=h264,vb=1200,vbv-maxrate=1200,vbv-bufsize=1500,vbv-init=100,width=640,height=480,deblock=1,2,2,deinterlace{bob},acodec=aac,ab=48,samplerate=48000}:standard{mux=ts,access="udp",dst="224.8.8.253:25301"}'
