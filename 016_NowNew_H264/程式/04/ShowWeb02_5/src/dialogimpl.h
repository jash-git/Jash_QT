#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QMessageBox>
#include <QStringList>
#include <QString>
#include <QWebView>
#include <QWebPage>
#include <QWebFrame>
#include <QUrl>
#include <QFile>
#include <QApplication>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QWebView *WView;
	QWebPage *WPage;
	QWebFrame *WFrame;
	QString evalJS(const QString &js);
	bool blncount;
	int intCount;
private slots:
	void slotwebloaded();
	void slot1();
};
#endif




