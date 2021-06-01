#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	edit1=lineEdit;
	WebView=webView;
	linedit1=lineEdit_2;
	StrPath=QDir::currentPath();
	StrPath=StrPath+"/";
	timer1=new QTimer();
	blnTimerStep=false;//Not Get a file;
	WSThread=new WebServiceThread(linedit1);
	WSThread->start();	
	connect(timer1,SIGNAL(timeout()),SLOT(Timerslot()));
	timer1->start(500);
}
void DialogImpl::callExe()
{
	cmd=new QProcess();
	QString StrExeName;
	StrExeName=StrPath+"ConverterWMV2Mp4";
	cmd->start(StrExeName);
	
}
void DialogImpl::Timerslot()
{
	if(blnTimerStep==false)
	{
		edit1->setText("Step 01");
		QFile Filecheck("check.txt");
		if(Filecheck.open(QFile::ReadOnly))
		{
			QFile FileRen("check.txt");
			FileRen.rename("list.txt");
			blnTimerStep=true;
			callExe();
		}
		Filecheck.close();
	}
	else
	{
		edit1->setText("Step 02");
		if(cmd->waitForFinished())
		{
			delete cmd;
			blnTimerStep=false;			
		}
	}
}
DialogImpl::~DialogImpl()
{
	delete timer1;
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
//
