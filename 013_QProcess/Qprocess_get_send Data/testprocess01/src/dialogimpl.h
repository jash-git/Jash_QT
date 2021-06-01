#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QString>
#include <QStringList>
#include <QProcess>
#include <QMessageBox>

#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QProcess *testping;
private slots:
	void slotbutt();
	void catchOutput();
};
#endif




