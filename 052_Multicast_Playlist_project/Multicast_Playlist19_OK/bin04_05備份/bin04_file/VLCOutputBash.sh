#!/bin/bash
vlc ./jashfifo4 --sout-ts-pid-video=69 --sout-ts-pid-audio=68 --sout-keep --sout '#transcode{acodec=mp2a,alang=eng,ab=128,channels=2,samplerate=48000,audio-sync}:udp{mux=ts,dst=224.8.8.33:3239}'
