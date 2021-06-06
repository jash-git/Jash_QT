#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QDialog>
#include <QtXml>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QString>
#include <QProcess>
#include <QTimer>
#include <QDateTime>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QtSql>
#include <QByteArray>
#include <QTextCodec>
#include <QMessageBox>
#include <QApplication>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
using namespace std;
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	~DialogImpl();
	/////////////////////////////////
	// init GUI Block
	QTableWidget *TableWidget;
	QStringList header;
	void InitGUI();
	void SQLiteOpenReadAll();
	void ClearDB();
	/////////////////////////////////
	//Read Config Block
	QDomDocument *doc;
	QString m_StrPlayListUrl;
	QString m_StrLiveMulticastUrl;
	QString m_StrMulticastPar01;
	QString m_StrMulticastPar02;
	QString m_StrBaseUrl;
	QString m_StrLivePar;
	QString m_StrLiveProcess;
	QString m_StrMultiProcess;
	void ReadConfig();
	/////////////////////////////////
	//Create Bash Block
	QStringList m_argumentsLive;
	QStringList m_argumentsVOD;
	void CreateLiveOutputBash();
	void CreateVLCOutputBash();
	void CreateDownloadListBash();
	void CreateVODOutputBash(QString StrVODPath);
	////////////////////////////////
	//XML to Txt Block
	QDomDocument *docXml2Txt;
	QProcess *procXml2Txt;
	void DownloadXML2Txt();
	////////////////////////////////
	//Txt to DB Block
	void Txt2DB();
	///////////////////////////////
	//Timer Block
	QTimer *timer;
	float fltAfterTime;
	bool blnDelayCheck;
	//////////////////////////////
	//Run Bash Block
	QProcess *procOutput;
	QProcess *procInput;
	bool blnredo;
	void RunVLCOutputBash();
	void RunVLCInputBash(int intswitch);
	/////////////////////////////
	QSqlDatabase db;
	bool blncheckDB;
	bool blnDBOpen;
	void initDB();
	////////////////////////////
	void CreateBaseList();
private slots:
	void slotTimer();
};
#endif




