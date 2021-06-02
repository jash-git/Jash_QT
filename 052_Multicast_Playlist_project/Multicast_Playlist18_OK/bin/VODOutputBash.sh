#!/bin/bash
vlc -vvv ./Base.mp4 --sout-ffmpeg-interlace --sout-keep --sout '#transcode{fps=29.97,venc=ffmpeg{keyint=3},vcodec=mp2v,vb=4000,width=704,height=480,acodec=mp2a,alang=eng,ab=128,channels=2,samplerate=48000}:udp{mux=ts,dst=127.0.0.1:1239}'
