//fortunethread.cpp
#include "fortunethread.h"

FortuneThread::FortuneThread(int socketDescriptor, QObject *parent)
    : QThread(parent), socketDescriptor(socketDescriptor)
{
	blockSize = 0;
	
}

void FortuneThread::run()
{
	tcpSocket = new QTcpSocket;
	if (!tcpSocket->setSocketDescriptor(socketDescriptor))
	{
		emit error(tcpSocket->error());
		return;
	}
	connect(tcpSocket, SIGNAL(readyRead()), this, 
		SLOT(readMessage()), Qt::DirectConnection);
	exec();
}

void FortuneThread::readMessage()
{
	QDataStream in(tcpSocket);
	in.setVersion(QDataStream::Qt_4_0);
	if (blockSize == 0)
	{
		if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
			return;
		in >> blockSize;
	}
	if (tcpSocket->bytesAvailable() < blockSize)
		return;

	in >> theString;
	blockSize = 0;
	sendMessage();
}

void FortuneThread::sendMessage()
{
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_0);

	out << (quint16)0;
	out << theString;
	out.device()->seek(0);
	out << (quint16)(block.size() - sizeof(quint16));

	tcpSocket->write(block);
}