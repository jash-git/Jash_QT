#ifndef __CALLPROCESS_H__
#define __CALLPROCESS_H__
#include <QThread>
#include <stdio.h>
#include "ThreadData.h"
// place your code here

class CallProcess : public QThread
{
	Q_OBJECT
public:
	CallProcess(int sleepSec,int id,ThreadData *TD);
protected:
	int m_sleepSec;
	int m_id;
	ThreadData *m_TD;
	QString StrData;
	void run();
};

#endif // __CALLPROCESS_H__
