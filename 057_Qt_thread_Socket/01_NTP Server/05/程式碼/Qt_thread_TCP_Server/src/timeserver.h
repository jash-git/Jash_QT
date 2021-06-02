#ifndef __TIMESERVER_H__
#define __TIMESERVER_H__

// place your code here
#include <QTcpServer>
#include <QLabel>
//class Dialog;
class TimeServer : public QTcpServer
{
	Q_OBJECT

	public:
		TimeServer(QLabel *label,QObject *parent = 0);
		QLabel *Label;
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
