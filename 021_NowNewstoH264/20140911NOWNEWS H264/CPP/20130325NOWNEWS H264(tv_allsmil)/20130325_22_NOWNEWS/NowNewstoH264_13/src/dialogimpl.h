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
#include <QLineEdit>
#include <QApplication>
#include <QByteArray>
#include <stdio.h>
#include "HttpGet.h"
#include "SleeperThread.h"
#include "CProcessThread.h"
//#include "ui_dialog.h"
#include "ui_Form.h"
//
//class DialogImpl : public QDialog, public Ui::Dialog
class DialogImpl : public QWidget, public Ui::Form
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	~DialogImpl();
	CHttpGet *HttpGetObj;
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
	bool m_blnkeeplive;
	int m_intStep;
	long m_lngWMVCount;
	long m_lngWMVAmount;
	long m_lngKeepLiveCount;
	long m_lngmp4Size;//防呆
	struct ConfigData m_ConfigDataBuf;
	CSleeperThread sleepthread;
	QDomDocument *doc1;
	QDomDocument *configdoc;
	CProcessThread ProThread;
	QTimer *timer1;
	QStringList StrListid,StrListFileName,StrListFileSize,StrListSP,StrListDP;
	void KeepLiveFun();
	void UpdateDBFun(QString StrId,int intfun);
	void UpdateNOCFun();
	void ReadConfigXml();
private slots:
	void slotReadNodeList();
	void slotTimer1();
};
#endif




