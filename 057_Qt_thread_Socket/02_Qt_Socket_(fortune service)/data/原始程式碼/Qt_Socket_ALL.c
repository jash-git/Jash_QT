//¦øªA¾¹ºÝ
//dialog.h
#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui>
#include <QtNetwork>
#include "fortuneserver.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);

private:
    QLabel *statusLabel;
    QPushButton *quitButton;
    FortuneServer server;
};

#endif



//fortuneserver.h
#ifndef FORTUNESERVER_H
#define FORTUNESERVER_H

#include <QStringList>
#include <QTcpServer>

class FortuneServer : public QTcpServer
{
    Q_OBJECT
public:
    FortuneServer(QObject *parent = 0);
protected:
    void incomingConnection(int socketDescriptor);
private:
    QStringList fortunes;
};

#endif



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



//dialog.cpp
#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    statusLabel = new QLabel;
    quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);

    if (!server.listen(QHostAddress::Any, 8888)) 
	{
        QMessageBox::critical(this, tr("Threaded Fortune Server"),
                              tr("Unable to start the server: %1.")
                              .arg(server.errorString()));
        close();
        return;
    }

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Fortune Client example now.")
                         .arg(ipAddress).arg(server.serverPort()));

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Threaded Fortune Server"));
}



//fortuneserver.cpp
#include "fortuneserver.h"
#include "fortunethread.h"

FortuneServer::FortuneServer(QObject *parent)
    : QTcpServer(parent)
{
}

void FortuneServer::incomingConnection(int socketDescriptor)
{
    FortuneThread *thread = new FortuneThread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}



//fortunethread.cpp
#include "fortunethread.h"

FortuneThread::FortuneThread(int socketDescriptor, QObject *parent)
    : QThread(parent), socketDescriptor(socketDescriptor)
{
	blockSize = 0;
	
}

void FortuneThread::run()
{
	tcpSocket = new QTcpSocket;
	if (!tcpSocket->setSocketDescriptor(socketDescriptor))
	{
		emit error(tcpSocket->error());
		return;
	}
	connect(tcpSocket, SIGNAL(readyRead()), this, 
		SLOT(readMessage()), Qt::DirectConnection);
	exec();
}

void FortuneThread::readMessage()
{
	QDataStream in(tcpSocket);
	in.setVersion(QDataStream::Qt_4_0);
	if (blockSize == 0)
	{
		if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
			return;
		in >> blockSize;
	}
	if (tcpSocket->bytesAvailable() < blockSize)
		return;

	in >> theString;
	blockSize = 0;
	sendMessage();
}

void FortuneThread::sendMessage()
{
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_0);

	out << (quint16)0;
	out << theString;
	out.device()->seek(0);
	out << (quint16)(block.size() - sizeof(quint16));

	tcpSocket->write(block);
}


//main.cpp
#include <QApplication>
#include <QtCore>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog dialog;
    dialog.show();
    return dialog.exec();
}






//¥Î¤áºÝ
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


//client.cpp
#include "client.h"
#include <QtGui/QMessageBox>
#include <QtGui/QHBoxLayout>
#include <QtEvents>

Client::Client()
{
	setWindowTitle("Client");
	resize(300, 100);

	serverIpEdit = new QLineEdit("127.0.0.1");
	startButton = new QPushButton("start");
	strEdit = new QLineEdit;
	label = new QLabel("Emtpy");
	isConnected = false;

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(serverIpEdit);
	layout->addWidget(label);
	layout->addWidget(strEdit);
	layout->addWidget(startButton);
	setLayout(layout);

	tcpClient = new QTcpSocket(this);
	connect(startButton, SIGNAL(clicked()), this, SLOT(newConnect()));
	connect(tcpClient, SIGNAL(connected()), this, SLOT(sendMessage()));
	connect(tcpClient, SIGNAL(readyRead()), this, SLOT(readMessage()));
	connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)),
		this, SLOT(displayError(QAbstractSocket::SocketError)));
}

Client::~Client()
{

}

void Client::newConnect()
{
	blockSize = 0;
	if(!isConnected)
	{
		tcpClient->abort();
		tcpClient->connectToHost(serverIpEdit->text(), 8888);
		isConnected = true;
	}
	else
		sendMessage();
}

void Client::sendMessage()
{
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_0);

	sendString = strEdit->text();
	out << (quint16)0;
	out << sendString;
	out.device()->seek(0);
	out << (quint16)(block.size() - sizeof(quint16));

	tcpClient->write(block);
}

void Client::readMessage()
{
	QDataStream in(tcpClient);
	in.setVersion(QDataStream::Qt_4_0);

	if (blockSize == 0)
	{
		if (tcpClient->bytesAvailable() < (int)sizeof(quint16))
			return;
		in >> blockSize;
	}
	if (tcpClient->bytesAvailable() < blockSize)
		return;

	in >> readString;
	label->setText(readString);
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
	switch (socketError) {
	case QAbstractSocket::RemoteHostClosedError:
		break;
	case QAbstractSocket::HostNotFoundError:
		QMessageBox::information(this, tr("Fortune Client"),
			tr("The host was not found. Please check the "
			"host name and port settings."));
		break;
	case QAbstractSocket::ConnectionRefusedError:
		QMessageBox::information(this, tr("Fortune Client"),
			tr("The connection was refused by the peer. "
			"Make sure the fortune server is running, "
			"and check that the host name and port "
			"settings are correct."));
		break;
	default:
		QMessageBox::information(this, tr("Fortune Client"),
			tr("The following error occurred: %1.")
			.arg(tcpClient->errorString()));
	}
}


//main.cpp
#include "client.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Client w;
	w.show();
	return a.exec();
}
