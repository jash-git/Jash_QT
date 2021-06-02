#!/bin/bash
ffmpeg -i /home/jash/11.mp4 -ss 00:20:00 -vcodec copy -acodec copy /home/jash/22.mp4
ffmpeg -i /home/jash/11.mp4 -ss 00:30:00 -vcodec copy -acodec copy /home/jash/33.mp4
ffmpeg -i /home/jash/11.mp4 -ss 00:40:00 -vcodec copy -acodec copy /home/jash/44.mp4
ffmpeg -i /home/jash/11.mp4 -ss 00:50:00 -vcodec copy -acodec copy /home/jash/55.mp4
