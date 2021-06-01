#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QFileDialog>
#include <QProcess>
#include <QStringList>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	~DialogImpl();
	QProcess *cmd;
	QString m_StrShowBuf;
private slots:
	void slotsource();
	void slottarget();
	void slotRun();

};
#endif




