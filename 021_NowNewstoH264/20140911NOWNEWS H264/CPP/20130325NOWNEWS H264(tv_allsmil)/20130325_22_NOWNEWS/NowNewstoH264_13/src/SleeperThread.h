#ifndef __SLEEPERTHREAD_H__
#define __SLEEPERTHREAD_H__

// place your code here
#include <QThread>
class CSleeperThread : public QThread
{
public:
	CSleeperThread();
	static void msleep(unsigned long msecs);
};
#endif // __SLEEPERTHREAD_H__
