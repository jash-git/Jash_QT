#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QWebView>
#include <QUrl>
#include <QString>
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
	QWebView *WebView;
	QPushButton *pb1,*pb2;
	QLineEdit *linedit1;
	WebServiceThread *WSThread; 
private slots:
	void slot1();
	void slot2();
	void slot3(QString);
};
#endif




