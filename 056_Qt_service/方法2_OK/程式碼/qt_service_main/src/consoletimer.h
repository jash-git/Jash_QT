#ifndef __CONSOLETIMER_H__
#define __CONSOLETIMER_H__
#include <QTextCodec>
#include <QTimer>
#include <QDate>
#include <QTime>
#include <QByteArray>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
// place your code here
class consoletimer:public QObject
{
	Q_OBJECT
public:
	consoletimer(QObject *parent=0);
	~consoletimer();
	QTimer *timer;
	int messageNO;
	void start();
private slots:
	void slotTimer();
};
#endif // __CONSOLETIMER_H__