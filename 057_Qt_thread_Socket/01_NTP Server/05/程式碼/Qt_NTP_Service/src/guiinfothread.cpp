#include "guiinfothread.h"

// place your code here
GUIInfoThread::GUIInfoThread(int Count,int NowOnline,int socketDescriptor, QObject *parent) : QThread(parent), socketDescriptor(socketDescriptor)
{
	blockSize = 0;
	m_intCount=Count;
	m_intNowOnline=NowOnline;
}

void GUIInfoThread::run()
{
	tcpSocket = new QTcpSocket;
	if (!tcpSocket->setSocketDescriptor(socketDescriptor))
	{
		emit error(tcpSocket->error());
		return;
	}
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()), Qt::DirectConnection);
	exec();
}

void GUIInfoThread::readMessage()
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
	QString str;
	int intFunction=0;
	
	in >> theString;
	intFunction=theString.toInt();
	switch(intFunction)
	{
		case 1:
			str.append(QString(";intCount=%1").arg(m_intCount));
			break;
		case 2:
			str.append(QString(";intNowOnline=%1").arg(m_intNowOnline));
			break;
		case 4:
			str.append(QString(";intCount=%1;intNowOnline=%2").arg(m_intCount).arg(m_intNowOnline));
			break;
	}
	theString=theString+str;
	blockSize = 0;
	sendMessage();
}

void GUIInfoThread::sendMessage()
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