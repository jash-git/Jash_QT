#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QTextStream>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
	void slotUTF8();
	void slotANSI();
};
#endif




