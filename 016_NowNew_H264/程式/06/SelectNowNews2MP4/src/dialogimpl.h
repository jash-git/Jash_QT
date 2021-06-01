#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QProcess>
#include <stdio.h>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QLineEdit *LineEditFile;
	QListWidget *ListWidgetFile; 
	QPushButton *PushButAdd;
	QPushButton *PushButExe;
	QPushButton *PushButSelect;
	QString m_StrCurrentPath;
	QProcess *m_cmd; 
private slots:
	void slotAdd();
	void slotExe();
	void slotSelect();
	void slotSelectAdd();
};
#endif




