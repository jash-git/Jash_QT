//client.cpp
#include "client.h"
#include <QtGui/QMessageBox>
#include <QtGui/QHBoxLayout>
#include <QtEvents>

Client::Client()
{
	setWindowTitle("Client");
	resize(300, 100);

	serverIpEdit = new QLineEdit("127.0.0.1");
	startButton = new QPushButton("start");
	strEdit = new QLineEdit;
	label = new QLabel("Emtpy");
	isConnected = false;

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(serverIpEdit);
	layout->addWidget(label);
	layout->addWidget(strEdit);
	layout->addWidget(startButton);
	setLayout(layout);

	tcpClient = new QTcpSocket(this);
	connect(startButton, SIGNAL(clicked()), this, SLOT(newConnect()));
	connect(tcpClient, SIGNAL(connected()), this, SLOT(sendMessage()));
	connect(tcpClient, SIGNAL(readyRead()), this, SLOT(readMessage()));
	connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)),
		this, SLOT(displayError(QAbstractSocket::SocketError)));
}

Client::~Client()
{

}

void Client::newConnect()
{
	blockSize = 0;
	if(!isConnected)
	{
		tcpClient->abort();
		tcpClient->connectToHost(serverIpEdit->text(), 8888);
		isConnected = true;
	}
	else
		sendMessage();
}

void Client::sendMessage()
{
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_0);

	sendString = strEdit->text();
	out << (quint16)0;
	out << sendString;
	out.device()->seek(0);
	out << (quint16)(block.size() - sizeof(quint16));

	tcpClient->write(block);
}

void Client::readMessage()
{
	QDataStream in(tcpClient);
	in.setVersion(QDataStream::Qt_4_0);

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

void Client::displayError(QAbstractSocket::SocketError socketError)
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