/*
 * The HTTP interface for the LiveJournal client.  Yes, I know Qt provides a QHttp
 * network protocol, but it's not included in the qte library provided with the zaurus
 *
 * There's no qt_thread support on the zaurus either, so we have to do this
 * synchronously.  arg.  spinlocks.
 *
 * Copyright(c) 2002 Robert M Diamond.  All rights reserved.
 */

#include <qsocket.h>
#include <qstring.h>
#include <qdict.h>
#include <qurl.h>
#include <qmap.h>

#if USE_QPE
#include <qpeapplication.h>
#else
#include <qapplication.h>
#endif

class LJHttp : public QObject { 
	Q_OBJECT
	
	private:
		QSocket mySocket;
		QUrl baseURL;
		QString requestBuf;
		bool requestWaiting;
		enum { TimeOut };
		int status;
		QString inputBuf;
		QDict<QString>* postResults;

	public slots:
		// when QSocket emits the connected() signal, send our request
		void sendPostRequest();
		
		// when QSocket emits the readyRead() signal, read the data sent
		void receivePostData();
		
		// when QSocket emits the connectionClosed() signal, parse the data into lines
		void parsePostData();
		
		// if QSocket indicates an error occurred, catch that too
		void error(int);

		void bytesWritten(int bytes);
		
	public:
		LJHttp(QUrl);
		LJHttp();
		void init();
		~LJHttp();
		
		// sends a POST request to the server and return a map of values that were returned
		bool sendRequest(QString URL, QMap<QString, QString>& request, QDict<QString>& response);
		bool sendRequest(QMap<QString, QString>& request, QDict<QString>& response);
};
