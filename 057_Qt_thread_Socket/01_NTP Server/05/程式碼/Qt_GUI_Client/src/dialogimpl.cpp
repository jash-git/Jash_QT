#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	tcpClient = new QTcpSocket(this);
	timer=new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(slotTimer()));
	connect(tcpClient, SIGNAL(readyRead()), this, SLOT(readMessage()));
	connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(displayError(QAbstractSocket::SocketError)));
	timer->start(3000);
	m_count=0;
}
void DialogImpl::sendMessage()
{
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_3);
	m_count++;
	switch(m_count)
	{
		case 1:
			sendString = "1";
			break;
		case 2:
			sendString = "2";
			break;
		case 3:
			sendString = "4";
			m_count=0;
			break;
	}
	out << (quint16)0;
	out << sendString;
	out.device()->seek(0);
	out << (quint16)(block.size() - sizeof(quint16));

	tcpClient->write(block);
}

void DialogImpl::readMessage()
{
	QDataStream in(tcpClient);
	in.setVersion(QDataStream::Qt_4_3);

	if (blockSize == 0)
	{
		if (tcpClient->bytesAvailable() < (int)sizeof(quint16))
			return;
		in >> blockSize;
	}
	if (tcpClient->bytesAvailable() < blockSize)
		return;

	in >> readString;
	label->setText(readString);
}

void DialogImpl::displayError(QAbstractSocket::SocketError socketError)
{
	switch (socketError) {
	case QAbstractSocket::RemoteHostClosedError:
		break;
	case QAbstractSocket::HostNotFoundError:
		QMessageBox::information(this, tr("Fortune Client"),
			tr("The host was not found. Please check the "
			"host name and port settings."));
		break;
	case QAbstractSocket::ConnectionRefusedError:
		QMessageBox::information(this, tr("Fortune Client"),
			tr("The connection was refused by the peer. "
			"Make sure the fortune server is running, "
			"and check that the host name and port "
			"settings are correct."));
		break;
	default:
		QMessageBox::information(this, tr("Fortune Client"),
			tr("The following error occurred: %1.")
			.arg(tcpClient->errorString()));
	}
}
void DialogImpl::slotTimer()
{
	blockSize = 0;
	tcpClient->abort();
	tcpClient->connectToHost("127.0.0.1", 2507);
	sendMessage();
}
//
