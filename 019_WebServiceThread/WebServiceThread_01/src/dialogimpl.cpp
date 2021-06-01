#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	WebView=webView;
	pb1=pushButton_1;
	pb2=pushButton_2;
	linedit1=lineEdit;
	WSThread=new WebServiceThread(linedit1,pb1,pb2);
	WSThread->start();
}
void DialogImpl::slot1()
{
	QUrl url1;
	QString StrUrl;
	StrUrl="http://noc.tw-airnet.net/monitor/wService.aspx?OP=KeepaLive&ServiceID=325";
	url1.setUrl(StrUrl);
	WebView->setUrl(url1);
}
void DialogImpl::slot2()
{
	QUrl url1;
	QString StrUrl;
	StrUrl="http://noc.tw-airnet.net/monitor/wService.aspx?OP=GetServiceStatusByID&ServiceID=325";
	url1.setUrl(StrUrl);
	WebView->setUrl(url1);
}
void DialogImpl::slot3(QString str1)
{
	if(str1=="1")
	{
		slot1();	
	}
	if(str1=="2")
	{
		slot2();
	}
}
//
