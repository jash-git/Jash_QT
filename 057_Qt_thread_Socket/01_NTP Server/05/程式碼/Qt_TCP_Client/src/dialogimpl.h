#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QTcpSocket>
#include <QDateTime>
#include <QTimer>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QTcpSocket *tcpSocket;
	QTimer *timer;
	uint time2u;
private slots:
	void readTime();
	void slotTimer();
};
#endif




