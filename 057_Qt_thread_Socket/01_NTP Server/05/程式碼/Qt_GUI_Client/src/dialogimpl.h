#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QtNetwork>
#include <QMessageBox>
#include <QTimer>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QTcpSocket *tcpClient;
	QTimer *timer;
	int m_count;
	quint16 blockSize;
	QString sendString;
	QString readString;
	void sendMessage();
	public slots:
		void displayError(QAbstractSocket::SocketError socketError);
		void readMessage();
		void slotTimer();
};
#endif




