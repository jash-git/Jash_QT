#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	tcpSocket = new QTcpSocket(this);
	timer=new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(slotTimer()));
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readTime()));
	connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(displayError(QAbstractSocket::SocketError)));
	timer->start(30000);
}
void DialogImpl::readTime()
{
	QDataStream in(tcpSocket);
	in.setVersion(QDataStream::Qt_4_3);

	if (time2u == 0)
	{
		if (tcpSocket->bytesAvailable() < (int)sizeof(uint))
			return;
		in >> time2u;
	}
	
	QDateTime time=QDateTime::fromTime_t (time2u);
	label->setText(time.toString("yyyy-MM-dd hh:mm:ss"));
}
void DialogImpl::slotTimer()
{
	time2u = 0;
	tcpSocket->abort();
	tcpSocket->connectToHost("127.0.0.1",7052);
}
//
