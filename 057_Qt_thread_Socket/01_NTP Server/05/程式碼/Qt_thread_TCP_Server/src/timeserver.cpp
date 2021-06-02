#include "timeserver.h"
#include "timethread.h"
//#include "dialog.h"
TimeServer::TimeServer(QLabel *label,QObject *parent) : QTcpServer(parent)
{
		Label=label;//dlg = (Dialog*)parent;
		Label->setText("資訊：服務已經開始服務...\n");
		m_intCount=0;
		m_intNowOnline=0;
}

void TimeServer::incomingConnection(int socketDescriptor)
{
	TimeThread *thread = new TimeThread(socketDescriptor,this);
	QString str = QString("第%1位查詢資料").arg(++m_intCount);
	Label->setText(str);
	m_intNowOnline++;
	connect(thread, SIGNAL(finished()), this, SLOT(slotOnline()));
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	thread->start();
}
void TimeServer::slotOnline()
{
	m_intNowOnline--;
}