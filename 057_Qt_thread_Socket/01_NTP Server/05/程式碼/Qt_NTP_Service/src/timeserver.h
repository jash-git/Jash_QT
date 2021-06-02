#ifndef __TIMESERVER_H__
#define __TIMESERVER_H__

// place your code here
#include <QTcpServer>

//class Dialog;
class TimeServer : public QTcpServer
{
	Q_OBJECT

	public:
		TimeServer(QObject *parent = 0);
		int m_intCount;
		int m_intNowOnline;
	protected:
		void incomingConnection(int socketDescriptor);
	private:
private slots:
	void slotOnline();
		//Dialog *dlg;
};
#endif // __TIMESERVER_H__
