#ifndef __WEBSERVICETHREAD_H__
#define __WEBSERVICETHREAD_H__
#include <QThread>
#include <QWebView>
#include <QString>
#include <QUrl>
#include <QPushButton>
#include <QLineEdit>
#include <unistd.h>
// place your code here
class WebServiceThread : public QThread
{
	Q_OBJECT
public:
	WebServiceThread(QLineEdit *linedit,QPushButton *b1,QPushButton *b2);
	QLineEdit *linedit1;
	QPushButton *pb1,*pb2;
	bool blnchange;
protected:
	void run();
};
#endif // __WEBSERVICETHREAD_H__
