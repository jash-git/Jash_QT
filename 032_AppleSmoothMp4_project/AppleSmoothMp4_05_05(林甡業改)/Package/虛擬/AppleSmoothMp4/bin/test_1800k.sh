#!/bin/bash
#tmpfile="video_tmp.mp4"
options="-vcodec libx264 -b 1800k -flags +loop+mv4 -cmp 256 \
   -partitions +parti4x4+parti8x8+partp4x4+partp8x8+partb8x8 \
   -me_method hex -subq 7 -trellis 1 -refs 5 -bf 0 \
   -flags2 +mixed_refs -coder 0 -me_range 16 \
   -g 90 -r 29.97 -keyint_min 25 -sc_threshold 40 -i_qfactor 0.71 -qmin 10\
   -qmax 51 -qdiff 4 -s 1280x720"

ffmpeg -y -i "$1" -an -pass 1 -threads 0 $options "$2"
ffmpeg -y -i "$1" -acodec libfaac -ac 2 -ar 44100 -ab 64k -pass 2 -threads 0 $options "$2"