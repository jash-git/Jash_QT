/*
 * The HTTP interface for the LiveJournal client.  Yes, I know Qt provides a QHttp
 * network protocol, but it's not included in the qte library provided with the zaurus
 *
 * Copyright(c) 2002 Robert M Diamond.  All rights reserved.
 */

#include <unistd.h>
#include <qtextstream.h>
#include "ljhttp.h"

QString urlEncode(QString string) {
	QString result;
	
	for (unsigned int i=0; i < string.length(); i++) {
		QChar c = string[i];
		if (c.isLetterOrNumber()) {
			result += c;
		} else if (c.isSpace()) {
			result += '+';
		} else {
			result += '%';
			result += QString::number(c.unicode(), 16);
		}
	}

	return result;
}

// when QSocket emits the connected() signal, send our request
void LJHttp::sendPostRequest() {
	printf("in sendPostRequest\n");
	QString headerBuf;
	headerBuf = QString("POST %1 HTTP/1.0\r\n").arg(baseURL.path(true));
	headerBuf += QString("Host: %1\r\n").arg(baseURL.host());
	headerBuf += "User-Agent: liveQt/0.1\r\n";
	headerBuf += "Content-type: application/x-www-form-urlencoded\r\n";
	headerBuf += QString("Content-length: %1\r\n\r\n").arg(requestBuf.length()-2);

	printf("RMD: writing header \n%s", headerBuf.ascii());
	int realBytes = mySocket.writeBlock(headerBuf.ascii(), headerBuf.length());
	//printf("RMD: wrote %d bytes\n", realBytes);
	
	printf("RMD: writing request \n%s\n", requestBuf.ascii());
	realBytes = mySocket.writeBlock(requestBuf.ascii(), requestBuf.length());
	//printf("RMD: wrote %d bytes\n", realBytes);

	mySocket.flush();

	//printf("socket flags are %x\n", mySocket.flags());
	//printf("socket status is %x\n", mySocket.status());
	inputBuf.truncate(0);
}
		
// when QSocket emits the readyRead() signal, read the data sent
void LJHttp::receivePostData() {
	printf("in receivePostData\n");
	int bufSize = mySocket.bytesAvailable();
	char *buf = new char[bufSize+1];
	int bytesRead = mySocket.readBlock(buf, bufSize);
	if (bytesRead == -1) {
		emit error(QSocket::ErrSocketRead);
	}

	buf[bytesRead] = '\0';

	// this is inefficient because it makes another copy of buf
	// TODO: implement using a QArray
	QString tempbuf = buf;
	inputBuf += tempbuf;
	delete [] buf;
}

void LJHttp::parsePostData() {
	printf("in parsePostData\n");
	QString key, value;
	int status;
	
	QTextIStream iStream(&inputBuf);
	// first the header
	while (!iStream.atEnd()) {
		QString line = iStream.readLine();
		//printf ("got header line %s\n", line.ascii());
		if (line.startsWith("HTTP")) {
			int idx = line.find(' ');
			status = line.mid(idx).toInt();
			printf("status %d\n", status);
		}
		if (line.stripWhiteSpace().isEmpty())
			break;
	}

	// then the data - each value is two lines name\nvalue\n
	postResults->clear();
	while (!iStream.atEnd()) {
		key = iStream.readLine();
		printf ("got key line %s\n", key.ascii());
		value = iStream.readLine();
		printf ("got value line %s\n", value.ascii());
		postResults->insert(key, new QString(value));
	}

	// process is done - let the waiters know
	requestWaiting = false;
	status = 0;
}

// if QSocket indicates an error occurred, catch that too
void LJHttp::error(int code) {
	status = code;
	requestWaiting = false;
}

void LJHttp::bytesWritten(int /*bytes*/) {
	//printf("RMD: wrote %d bytes\n");
}

LJHttp::LJHttp(QUrl URL) : mySocket(this), baseURL(URL), requestWaiting(false) {
	init();
}

LJHttp::LJHttp() : mySocket(this), requestWaiting(false) {
	init();
}

void LJHttp::init() {
	printf("in http init\n");
	connect(&mySocket, SIGNAL(connected()), this, SLOT(sendPostRequest()));
	connect(&mySocket, SIGNAL(readyRead()), this, SLOT(receivePostData()));
	connect(&mySocket, SIGNAL(connectionClosed()), this, SLOT(parsePostData()));
	connect(&mySocket, SIGNAL(bytesWritten(int)), this, SLOT(bytesWritten(int)));
	connect(&mySocket, SIGNAL(error(int)), this, SLOT(error(int)));
}

LJHttp::~LJHttp() {
}

// sends a POST request to the server and return a map of values that were returned
bool LJHttp::sendRequest(QString URL, QMap<QString, QString>& request, QDict<QString>& response) {
	baseURL = URL;
	return sendRequest(request, response);
}

bool LJHttp::sendRequest(QMap<QString, QString>& request, QDict<QString>& response) {
	// initialize the return dictionary
	response.setAutoDelete(false);
	response.clear();
	postResults = &response;

	// make sure we have a URL, and that any existing requests have been sent
	if (!baseURL.isValid()) {
		return false;
	}
	
	if (requestWaiting) {
		return false;
	}

	requestWaiting = true;
	
	// package the request as a POST 
	QMap<QString, QString>::Iterator it;
	requestBuf.truncate(0);
	for (it = request.begin(); it != request.end(); it++) {
		QString frag = "%1=%2";

		QString key = it.key();
		QString data = urlEncode(it.data());
		frag = frag.arg(key).arg(data);

		if (requestBuf.length() > 0)
			requestBuf += "&";
		requestBuf += frag;
	}
	requestBuf += '\n';
	requestBuf += '\r';
	status = 0;

	printf("host %s port %d\n", baseURL.host().ascii(), baseURL.port());
	mySocket.connectToHost(baseURL.host(), 
				baseURL.port() != -1 ? baseURL.port() : 80);
	
	while (requestWaiting) {
		qApp->processEvents(100);
	}

	//printf("requestWaiting set to false status is %d\n",status);

	// okay we've sent and received data now.  Fortunately QDict does a light
	// copy, so creating the temp object won't be too awful and saves us a 
	// lot of memory management.
	return true;
}
