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
	WebServiceThread(QLineEdit *linedit);
	QLineEdit *linedit1;
	bool blnchange;
protected:
	void run();
};
#endif // __WEBSERVICETHREAD_H__
