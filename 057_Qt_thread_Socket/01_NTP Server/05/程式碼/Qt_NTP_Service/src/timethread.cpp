#include "timethread.h"
#include <QtNetwork>
#include <QDateTime>

TimeThread::TimeThread(int socketDescriptor,QObject *parent) : QThread(parent), socketDescriptor(socketDescriptor)
{

}

void TimeThread::run()
{
	QTcpSocket tcpSocket;
	if (!tcpSocket.setSocketDescriptor(socketDescriptor))
	{
		emit error(tcpSocket.error());
		return;
	}
	//-------------
	//save client ip_start

	//get client ip_start
	QString StrClientIP;
	StrClientIP="client ip:";
	StrClientIP=StrClientIP+tcpSocket.peerAddress().toString();
	//get client ip_end
	
	//get current Date Time_start
	QString StrDate;
	StrDate="Date:";
	StrDate=StrDate+QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
	//get current Date Time_end
	
	//write log File_start
	QFile filelog("/home/jash/Qt_NTP_Service/log/connectlog.txt");
	filelog.open(QFile::WriteOnly | QIODevice::Append);
	QTextStream TextStreamOut(&filelog);
	TextStreamOut << StrDate<< "\t";
	TextStreamOut << StrClientIP<< "\n";
	filelog.close();
	//write log File_end
	
	//save client ip_end
	//-------------
	QDateTime time;
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_3);
	uint time2u = QDateTime::currentDateTime().toTime_t();
	out << time2u;
	
	tcpSocket.write(block);
	tcpSocket.disconnectFromHost();
	tcpSocket.waitForDisconnected();
}