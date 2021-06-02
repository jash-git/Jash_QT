#!/bin/bash
#tmpfile="video_tmp.mp4"
options="-vcodec libx264 -b 10000K -flags +loop+mv4 -cmp 256 \
   -partitions +parti4x4+parti8x8+partp4x4+partp8x8+partb8x8 \
   -me_method hex -subq 7 -trellis 2 -refs 3 -bf 3 -subq 6\
   -flags2 +mixed_refs -coder 0 -me_range 16 -qscale 1 \
   -rc_init_occupancy 100 -r 20000 -g 1000 -keyint_min 25 \
   -i_qfactor 0.71 -qmin 1 -qmax 51 -qdiff 4 -level 40 -s 1000x10"

ffmpeg -y -i "$1" -an -pass 1 -threads 0 $options "$2"
ffmpeg -y -i "$1" -acodec libfaac -ac 2 -ar 300000 -ab 40000 -pass 2 -threads 0 $options "$2"

