#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QtXml>
#include <QMessageBox>
#include <QTimer>
#include <QStringList>
#include <QWebView>
#include <QWebPage>
#include <QWebFrame>
#include <QUrl>
#include <QDate>
#include <QTime>
#include <QLineEdit>
#include <QApplication>
#include <QTextStream>
#include <QTextEdit>
#include <QtGlobal>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
#include "ui_MainWidget.h"
#include "CProcessThread.h"
struct encodeData
{
	QString Strsource_path;
	QString Strsource_filename;
	QString Strdimension;
	QString Strvideo_bitrate;
	QString Straudio_bitrate;
	QString Strdestination_path;
	QString Strdestination_filename;
	QString Straudio_sample_rate;
	QString Strframe_rate;
	QString Strkeyframe;
};
struct smilData
{
	QString Strsmildestination_path;
	QString Strsmildestination_filename;
	QStringList StrListvideoname;
};

//
class DialogImpl : public QWidget, public Ui::Form
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	~DialogImpl();
	struct ConfigData m_ConfigDataBuf;
	CProcessThread ProThread;
	QTimer *timer1;
	int m_intStep;
	long m_lngWMVAmount;
	long m_lngWMVCount;
	qint64 m_lngmp4Size;
	long m_lngsmilCount;
	long m_timercount;
	QString m_Strsource_path;
	QString m_Strsource_filename;
	QString m_Strsmildestination_path;
	QString m_Strsmildestination_filename;
	QString m_Strsmildvideoname;
	QString m_Strwork_id;
	QString m_StrHostType;
	QWebView *WView00;
	QWebView *WView01;
	QWebPage *WPage00;
	QWebPage *WPage01;
	QWebFrame *WFrame00;
	QWebFrame *WFrame01;
	QLineEdit *LineEdit00;
	QLineEdit *LineEdit01;
	QLineEdit *LineEdit02;
	QLineEdit *LineEdit03;
	QLineEdit *LineEdit04;
	QTextEdit *TextEdit;
	struct encodeData *encodeData01;
	struct smilData *smilData01; 
	void ReadConfigXml();
	QString CreateBashScript(QString Strkeyframe,QString Strframe_rate,QString Straudio_sample_rate,QString Strvidio,QString Straudio,QString Strdimension);
	void CreateSmilFile();
private slots:
	void slotTimer1();
	void slotReadNodeList();
};
#endif




