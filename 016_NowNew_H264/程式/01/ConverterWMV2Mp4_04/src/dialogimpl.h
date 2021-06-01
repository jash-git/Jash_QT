#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QtXml>
#include <QFile>
#include <QDir>
#include <QStringList>
#include <QMessageBox>
#include <QTimer>
#include <QApplication>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QLineEdit *edit01;
	QLineEdit *edit02;
	QLineEdit *edit03;
	QLineEdit *edit04;
	QLineEdit *edit05;
	QLineEdit *edit06;
	QLineEdit *edit07;
	QTimer *timer;
protected:
	QString StrCurrentPath;
	QString StrSHScript1;//wmv2mp4
	QString StrSHScript2;
	QString StrWMVFileList;
	QString StrSourcePath;
	QString StrEndPath;
	///////////////////
	QDomDocument *doc;
	///////////////////
private slots:
	void slot1();
};
#endif




