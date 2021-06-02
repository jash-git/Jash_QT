#include "guiinfoserver.h"
#include "guiinfothread.h"

// place your code here#include "fortunethread.h"
extern int exintCount;
extern int exintNowOnline;
GUIInfoServer::GUIInfoServer(QObject *parent) : QTcpServer(parent)
{
	m_intCount=-1;
	m_intNowOnline=-1;
}

void GUIInfoServer::incomingConnection(int socketDescriptor)
{
	m_intCount=exintCount;
	m_intNowOnline=exintNowOnline;
	GUIInfoThread *thread = new GUIInfoThread(m_intCount,m_intNowOnline,socketDescriptor, this);
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	thread->start();
}