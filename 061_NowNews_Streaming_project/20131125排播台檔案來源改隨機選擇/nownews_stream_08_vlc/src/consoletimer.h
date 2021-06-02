#ifndef __CONSOLETIMER_H__
#define __CONSOLETIMER_H__
#include <QTextCodec>
#include <QTimer>
#include <QDate>
#include <QTime>
#include <QByteArray>
#include <QtXml>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QString>
#include <QProcess>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
#include <time.h> 
#include <string.h>
#include "CProcessThread.h"
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
//----------------------------
//__ReadConfig_start
	QString m_StrPlayListUrl;
	QString m_StrMp4Path;
	QString m_Strffmpeg_vlc01;
	QString m_Strffmpeg_vlc02;
	QDomDocument *doc;
	void ReadConfig();
//__ReadConfig_end
//----------------------------
	
	void CreateWgetSh();
	void RunWgetSh();

//----------------------------
//__Xml2Txt_start
	QDomDocument *docXml2Txt;
	void Xml2Txt();
//__Xml2Txt_end
//----------------------------
	CProcessThread ProThread;
	
	QString m_StrMainFileName;	
	int m_intrand;
	int m_intStep;//狀態控制變數
private slots:
	void slotTimer();
};
#endif // __CONSOLETIMER_H__
