#ifndef __GUIINFOTHREAD_H__
#define __GUIINFOTHREAD_H__

// place your code here
#include <QThread>
#include <QTcpSocket>

class GUIInfoThread : public QThread
{
    Q_OBJECT
public:
    GUIInfoThread(int Count,int NowOnline,int socketDescriptor, QObject *parent);
    void run();
private:
    int socketDescriptor;
    QString theString;
	QTcpSocket *tcpSocket;
	qint16 blockSize;
	int m_intCount;
	int m_intNowOnline;
	public slots:
		void readMessage();
		void sendMessage();
signals:
		void error(QTcpSocket::SocketError socketError);
};

#endif // __GUIINFOTHREAD_H__
