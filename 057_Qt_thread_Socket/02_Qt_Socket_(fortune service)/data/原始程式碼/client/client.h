//用戶端
//client.h
#ifndef TRYCLI_H_
#define TRYCLI_H_

#include <QtNetwork>
#include <QtGui>
#include <QtCore>

class Client : public QWidget
{
	Q_OBJECT
private:
	bool isConnected;
	QLineEdit *serverIpEdit;
	QLabel *label;
	QLineEdit *strEdit;
	QPushButton *startButton;

	QTcpSocket *tcpClient;
	quint16 blockSize;
	QString sendString;
	QString readString;

public:
	Client();
	~Client();

	public slots:
		void displayError(QAbstractSocket::SocketError socketError);
		void newConnect();
		void readMessage();
		void sendMessage();

};

#endif