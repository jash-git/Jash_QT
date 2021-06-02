#include "timeserver.h"
#include "timethread.h"
//#include "dialog.h"
int exintCount;
int exintNowOnline;
TimeServer::TimeServer(QObject *parent) : QTcpServer(parent)
{
		//Label=label;//dlg = (Dialog*)parent;
		//Label->setText("資訊：服務已經開始服務...\n");
		m_intCount=0;
		m_intNowOnline=0;
		exintCount=m_intCount;
		exintNowOnline=m_intNowOnline;
}

void TimeServer::incomingConnection(int socketDescriptor)
{
	TimeThread *thread = new TimeThread(socketDescriptor,this);
	m_intNowOnline++;
	m_intCount++;
	connect(thread, SIGNAL(finished()), this, SLOT(slotOnline()));
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	thread->start();
}
void TimeServer::slotOnline()
{
	m_intNowOnline--;
	exintCount=m_intCount;
	exintNowOnline=m_intNowOnline;
}