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
#include <QTimer>
#include <QtSql>
#include <QStringList>
using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
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
	//---------------
	void ReadConfig();
	QString m_StrPlayListUrl;
	QString m_StrXMLFolderPath;
	QString m_StrChangeFolderPath;
	QByteArray m_ArrPlayListUrl;
	QByteArray m_ArrXMLFolderPath;
	QByteArray m_ArrChangeFolderPath;
	//----------------
	int m_intStep;
	//----------------
	//XML to Txt Block
	QDomDocument *docXml2Txt;
	QProcess *procXml2Txt;
	void DownloadXML2Txt();
	//----------------
	void FilterListData();
	QStringList m_StrPathArray;
	QStringList m_StrStartArray;
	QStringList m_StrEndArray;
	QStringList m_StrStartTimeArray;
	QStringList m_StrEndTimeArray;
	//----------------
	int m_intListIndex;
	QString m_StrMediaPath;
	QString m_StrStartPoint;
	QString m_StrEndPoint;
	QString m_StrStartTime;
	QString m_StrEndTime;
	QProcess *m_proc;
	QStringList m_arguments;
	//----------------
private slots:
	void slotTimer();
};
#endif // __CONSOLETIMER_H__
