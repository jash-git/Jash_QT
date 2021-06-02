#!/bin/bash
kill -9 `ps -ef|grep vlc|grep 224.8.8.130:13011|awk '{print $2}'`
