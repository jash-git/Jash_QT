#ifndef __TIMETHREAD_H__
#define __TIMETHREAD_H__

// place your code here
#include <QThread>
#include <QTcpSocket>

class TimeThread : public QThread
{
	Q_OBJECT

	public:
		TimeThread(int socketDescriptor, QObject *parent);
		void run();
	signals:
		void error(QTcpSocket::SocketError socketError);
	private:
		int socketDescriptor;
};

#endif // __TIMETHREAD_H__
