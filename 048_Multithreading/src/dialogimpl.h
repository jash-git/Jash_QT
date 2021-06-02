#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QMessageBox>
#include <QTimer>
#include "ui_dialog.h"
#include "ThreadData.h"
#include "CallProcess.h"
//

class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	ThreadData m_TD;
	CallProcess *cp01;
	CallProcess *cp02;
	QTimer *timer;
private slots:
	void slotStart();
	void slotTimer();
};
#endif




