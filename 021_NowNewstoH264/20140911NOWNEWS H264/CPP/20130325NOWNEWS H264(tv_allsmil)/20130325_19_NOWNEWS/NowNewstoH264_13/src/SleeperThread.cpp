#include "SleeperThread.h"
CSleeperThread::CSleeperThread()
{
	
}
void CSleeperThread::msleep(unsigned long msecs)
{
	QThread::msleep(msecs);
}
// place your code here
