#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QProcess>
#include <QStringList>
#include <QString>
#include <QTextEdit>
#include <QLineEdit>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	~DialogImpl();
	QLineEdit *Ledit1;
	QTextEdit *Tedit1;
	QProcess *cmd;
	QString StrShowBuf;
private slots:
	void showinf();
	void slot1();
};
#endif




