#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QString>//step_01
#include <QMessageBox>//step_01
#include <QUrl>//step_01
#include <QFile>//step_01
#include <QDir>//step_01
#include <QFtp>//step_01
#include <QApplication>//step_01
#include <QWebView>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	~DialogImpl();//step_01
    enum STATUS{None,LOGIN,PUT,GET};//step_01
    STATUS curStatus;//step_01	
	QFile *Filelocal;//step_01
	QFtp *FtpClient;//step_01
	QWebView *WebView;
private slots:
	void slotLogin();//step_01
	void slotPut();//step_01
	void slotStateChange(int state);//step_01
	void slotDone(bool error);//step_01
	void slotwebloaded(bool blncheck);//step_01
};
#endif




