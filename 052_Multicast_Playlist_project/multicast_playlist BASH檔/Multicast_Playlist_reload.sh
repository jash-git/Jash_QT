#!/bin/bash
sleep 30
echo "1234567" | sudo -S ./mount.sh
echo "1234567" | sudo -S route add -net 224.8.8.0 netmask 255.255.255.0 dev eth1
sleep 5
cd /home/jash/Multicast_Playlist/bin01
./Multicast_Playlist&
sleep 10
cd /home/jash/Multicast_Playlist/bin02
./Multicast_Playlist&
