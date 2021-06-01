#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	WView=webView;
	WPage=WView->page();
	WFrame=WPage->mainFrame();
	QString StrBuf;
	QUrl url1;
	StrBuf="http://xpe5tv.tw-airnet.net/cgi-php/get_nownews_h264.php";
	url1.setUrl(StrBuf);
	//WView->setUrl(url1);
	WView->load(url1);
	blncount=false;
}
void DialogImpl::slotwebloaded()
{
	QString str1;
	QUrl url;
	url=WView->url();
	str1=url.toString();
	if(!blncount)
	{
		blncount=!blncount;
	}
	else
	{
		QMessageBox mesbox;
		mesbox.setText("2");
		//mesbox.exec();		
		QApplication::quit();
	}
	if(str1=="http://xpe5tv.tw-airnet.net/cgi-php/get_nownews_h264.php")
	{
		slot1();
		QFile FileDel("list.txt");
		FileDel.remove();
	}
}
void DialogImpl::slot1()
{
	QString str1,str2;
	QFile File("list.txt");
	File.open(QFile::ReadOnly);
	char chrbuf[4096];
	str1="";
	str2="";
	while(!File.atEnd())
	{
		File.readLine(chrbuf,sizeof(chrbuf));
		str2=chrbuf;
		str2=str2.mid(0,(str2.length()-2));
		str2=str2+"\\n";
		str1+=str2;
		str2="";
	}
	File.close();
	//str="123\\n";
	//str+="456";
	evalJS(QString("document.getElementById('mp4_text').value = \"%1\";").arg(str1));
	evalJS(QString("document.getElementById('submit').click();"));
	/*
	evalJS(QString("document.getElementById('gaia_loginform').submit();"));
	*/
}
QString DialogImpl::evalJS(const QString &js)
{
	return WFrame->evaluateJavaScript(js).toString();
}

//
