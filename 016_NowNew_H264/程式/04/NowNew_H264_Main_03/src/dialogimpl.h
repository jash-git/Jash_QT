#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QProcess>
#include <QStringList>
#include <QString>
#include <QTimer>
#include <QFile>
#include <QDir>
#include <QWebView>
#include <QUrl>
#include <QWebPage>
#include <QWebFrame>
#include <QMessageBox>
#include "ui_dialog.h"
#include "WebServiceThread.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	~DialogImpl();
	QString StrPath;
	QTimer *timer1;
	QProcess *cmd;
	QLineEdit *edit1;
	QWebView *WebView;
	QLineEdit *linedit1;
	WebServiceThread *WSThread; 
	bool blnTimerStep;
	void callExe();
private slots:
	void Timerslot();
	void slot1();
	void slot2();
	void slot3(QString);
};
#endif




