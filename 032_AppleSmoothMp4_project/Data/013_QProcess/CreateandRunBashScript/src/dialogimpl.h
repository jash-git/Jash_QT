#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QProcess>
#include <QFile>
#include <QDir>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QPushButton *CreateButton;
	QPushButton *RunButton;
private slots:
	void slotCreate();
	void slotRun();
};
#endif




