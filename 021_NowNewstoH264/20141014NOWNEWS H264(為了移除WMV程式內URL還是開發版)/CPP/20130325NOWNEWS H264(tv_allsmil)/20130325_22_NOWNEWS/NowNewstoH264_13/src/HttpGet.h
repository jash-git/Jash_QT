#ifndef __HTTPGET_H__
#define __HTTPGET_H__
#include <QtCore>
#include <QObject>
#include <QString>
#include <QUrl>
#include <QHttp>
#include <QFile>
#include <QtNetwork>
#include <QList>
#include <QPair>
#include <iostream>
using namespace std;
class CHttpGet : public QObject
{
Q_OBJECT
public:
	CHttpGet(QObject *parent = 0);
	~CHttpGet();
	bool getFile(const QUrl &url,QString StrName);
signals:
	void done();
private slots:
	void httpDone(bool error);
	void httpReqDone(int i,bool error);
private:
	int http_request_id;
	QHttp http;
	QFile file;
	QFile rssfile;
};
#endif // __HTTPGET_H__
