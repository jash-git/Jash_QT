# this is a simple startup
# and will be saved as startup.sh in the system
echo qt_service_main is starting
echo done starting qt_service_main

kill -9 `ps aux | grep qt_service_main | awk '{print $2}'`

cd /home/jash/Qt_service
./qt_service_main
