#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QThread>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QStringList>
#include <QProcess>
#include <QTextStream>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	void CreateSmilFile(QString StrSmilName,QString FileName);
private slots:
	void slot1();
};
#endif




