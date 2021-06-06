#!/bin/bash
cvlc -vvv /home/jash/05_Wowza_ALLVLC/Lion11.mp4 --sout '#transcode{venc=x264,vcodec=h254,acodec=mp4a}:udp{mux=ts,dst=224.1.1.1:1233}' vlc://quit
cvlc -vvv /home/jash/05_Wowza_ALLVLC/Lion22.mp4 --sout '#transcode{venc=x264,vcodec=h254,acodec=mp4a}:udp{mux=ts,dst=224.1.1.1:1233}' vlc://quit
cvlc -vvv /home/jash/05_Wowza_ALLVLC/Lion33.mp4 --sout '#transcode{venc=x264,vcodec=h254,acodec=mp4a}:udp{mux=ts,dst=224.1.1.1:1233}' vlc://quit
cvlc -vvv /home/jash/05_Wowza_ALLVLC/Lion44.mp4 --sout '#transcode{venc=x264,vcodec=h254,acodec=mp4a}:udp{mux=ts,dst=224.1.1.1:1233}' vlc://quit
#http://www.wowzamedia.com/forums/content.php?213-FFmpeg-with-Wowza-Server-(MPEG-TS)
