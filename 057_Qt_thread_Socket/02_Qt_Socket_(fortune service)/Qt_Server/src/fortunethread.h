//fortunethread.h
#ifndef FORTUNETHREAD_H
#define FORTUNETHREAD_H

#include <QThread>
#include <QTcpSocket>

class FortuneThread : public QThread
{
    Q_OBJECT
public:
    FortuneThread(int socketDescriptor, QObject *parent);
    void run();
private:
    int socketDescriptor;
    QString theString;
	QTcpSocket *tcpSocket;
	qint16 blockSize;

	public slots:
		void readMessage();
		void sendMessage();
signals:
		void error(QTcpSocket::SocketError socketError);
};

#endif