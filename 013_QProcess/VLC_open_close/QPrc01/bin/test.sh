#!/bin/bash
vlc -vvv rtsp://61.67.123.92/live/cctv4_440k.stream --sout '#transcode{venc=x264,vcodec=h254,acodec=mp4a}:udp{mux=ts,dst=224.1.1.1:1234}'
