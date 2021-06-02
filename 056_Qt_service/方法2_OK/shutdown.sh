# this is a simple shutdown
# and will be saved as shutdown.sh in the system
echo qt_service_main is shutting down
echo done shutting down qt_service_main
echo "asd700502" |sudo -S kill -9 `ps aux | grep qt_service_main | awk '{print $2}'`
