#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QProcess>
#include <QStringList>
#include <QString>
#include <QTimer>
#include <QApplication>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	~DialogImpl();
	QProcess *cmd;
	QTimer *timer;
private slots:
	void slot1();
};
#endif




