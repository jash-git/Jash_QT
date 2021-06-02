#!/bin/bash
vlc -vvv udp://@235.1.1.55:1233 --sout-keep --sout '#udp{mux=ts,dst=224.8.8.3:1239}'
