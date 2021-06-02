#include "HttpGet.h"
CHttpGet::CHttpGet(QObject *parent): QObject(parent)
{
	connect(&http, SIGNAL(done(bool)), this, SLOT(httpDone(bool)));
	connect(&http, SIGNAL(requestFinished(int,bool)), this, SLOT(httpReqDone(int,bool)));
}
CHttpGet::~CHttpGet()
{
	file.close();
}
bool CHttpGet::getFile(const QUrl &url,QString StrName)
{
	if (!url.isValid())
	{
		cerr << "Error: Invalid URL" << endl;
		return false;
	}
	if (url.scheme() != "http")
	{
		cerr << "Error: URL must start with 'http:'" << endl;
		return false;
	}
	if (url.path().isEmpty())
	{
	cerr << "Error: URL has no path" << endl;
	return false;
	}
	QString localFileName = StrName;
	if (localFileName.isEmpty())
	{
		localFileName = "httpget.xml";		
	}
	file.setFileName(localFileName);
	if (!file.open(QIODevice::WriteOnly))
	{
		cerr << "Error: Cannot open " << qPrintable(file.fileName()) << " for writing: " << qPrintable(file.errorString()) << endl;
		return false;
	}
	QList<QPair<QByteArray, QByteArray> > querylist;
	querylist=url.encodedQueryItems();
	if(querylist.size()!=0) 
	{
		QByteArray querydata; 
		querydata.append(querylist[0].first);
		querydata.append('=');
		querydata.append(querylist[0].second);
		for (int i = 1; i < querylist.size(); ++i)
		{
			querydata.append('&');
			querydata.append(querylist[i].first);
			querydata.append('=');
			querydata.append(querylist[i].second);
		}
		QHttpRequestHeader header("POST", url.path());
		header.setValue("Content-Type", "application/x-www-form-urlencoded");
		header.setValue("Host", url.host());
		http.setHost(url.host());
		http_request_id=http.request(header,querydata,&file);
		qDebug()<<querydata;
		http.close();
	}
	else
	{
		http.setHost(url.host(), url.port(80));
		http.get(url.path(), &file);
		http_request_id=0;
		http.close();
	}
	return true;
}
void CHttpGet::httpReqDone(int id,bool error)
{
	if (error)
	{
		cerr << "id:"<<id<<"Error: " << qPrintable(http.errorString()) << endl;
		return;
	} 
	if(id==http_request_id)
	{
		emit done();
		cout<<"id is"<<id<<"\n";
		cout<<"hello request done\n";
	}
}

void CHttpGet::httpDone(bool error)
{
	if (error)
	{
		cerr << "Error: " << qPrintable(http.errorString()) << endl;
		return;
	} 
	if(http_request_id==0)
	{
		cout<<"hello http::get() done\n";
		emit done();
	}
}