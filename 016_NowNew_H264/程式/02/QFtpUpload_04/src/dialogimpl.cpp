#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	pushLogin->setEnabled(true);//step_02
	pushPutFile->setEnabled(false);//step_02
	WebView=webView;
	curStatus=None;//step_02
	slotLogin();//step_01
}
DialogImpl::~DialogImpl()//step_01
{
	FtpClient->close();//step_02
	delete FtpClient;//step_02
}
void DialogImpl::slotLogin()//step_01
{	
	FtpClient=new QFtp();//step_02
	connect(FtpClient,SIGNAL(stateChanged(int)),this,SLOT(slotStateChange(int)));//step_02
	connect(FtpClient,SIGNAL(done(bool)),this,SLOT(slotDone(bool)));//step_02	
	FtpClient->connectToHost("61.67.112.20",21);
	FtpClient->login("jash","jash");//step_02
	curStatus=LOGIN;//step_02
}
void DialogImpl::slotPut()//step_01
{
	QString fileName="list.txt";//step_02
	QFile *remoteFileName=new QFile(fileName);//step_02
	FtpClient->put(remoteFileName, fileName);//step_02
	curStatus=PUT;//step_02
}
void DialogImpl::slotStateChange(int state)//step_01
{
	if(state == QFtp::LoggedIn)//step_02
	{
		pushLogin->setEnabled(false);//step_02
		pushPutFile->setEnabled(true);//step_02
		slotPut();//step_02
	}	
}
void DialogImpl::slotDone(bool error)//step_01
{
	if(error)
	{
		QMessageBox::warning(this,tr("error"),FtpClient->errorString());
		return;
	}
	if(curStatus == LOGIN)
	{
		curStatus=None;
	}	
	if(curStatus == PUT)
	{
		//QMessageBox::information(this,tr("succeed"),tr("Put file succeed!"));
		QString Strurl;
		QUrl url1;
		Strurl="http://www.google.com";
		url1.setUrl(Strurl);
		WebView->load(url1);
		curStatus=None;
	}
	if(curStatus == GET)
	{
		QMessageBox::information(this,tr("succeed"),tr("Get file succeed!"));
		curStatus=None;
	}
}
void DialogImpl::slotwebloaded(bool blncheck)//step_01
{
	QUrl url;
	QString StrUrl;
	url=WebView->url();
	StrUrl=url.toString();
	QMessageBox Mesbox;
	Mesbox.setText(StrUrl);
	//Mesbox.exec();
	if(blncheck && StrUrl=="http://www.google.com.tw/")
	{
		QFile FileDel("list.txt");
		FileDel.remove();
		QApplication::quit();			
	}
}
//
