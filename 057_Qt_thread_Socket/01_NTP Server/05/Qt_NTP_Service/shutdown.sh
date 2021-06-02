# this is a simple shutdown
# and will be saved as shutdown.sh in the system
echo Qt_NTP_Service is shutting down
echo done shutting down Qt_NTP_Service
kill -9 `ps aux | grep Qt_NTP_Service | awk '{print $2}'`
