#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QFile>
#include "ui_dialog.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QString CreateBashScript(QString Strkeyframe,QString Strframe_rate,QString Straudio_sample_rate,QString Strvidio,QString Straudio,QString Strdimension);
private slots:
	void slot_but();
};
#endif




