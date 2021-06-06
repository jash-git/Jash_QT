#!/bin/bash
vlc udp://@127.0.0.1:1239 --sout-keep --sout '#udp{mux=ts,dst=224.8.8.3:1239}'
