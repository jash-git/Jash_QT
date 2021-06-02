#include "guiinfoserver.h"
#include "guiinfothread.h"

// place your code here#include "fortunethread.h"

GUIInfoServer::GUIInfoServer(TimeServer *ts1,QObject *parent) : QTcpServer(parent)
{
	ts=ts1;
}

void GUIInfoServer::incomingConnection(int socketDescriptor)
{
	GUIInfoThread *thread = new GUIInfoThread(ts->m_intCount,ts->m_intNowOnline,socketDescriptor, this);
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	thread->start();
}