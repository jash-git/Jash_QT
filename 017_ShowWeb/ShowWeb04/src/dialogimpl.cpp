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
	StrBuf="http://xpe5tv.tw-airnet.net/cgi-php/media_transform.php?op=get_nownews&media_type=h264&datetime=2010-05-26";
	url1.setUrl(StrBuf);
	WView->load(url1);
}
void DialogImpl::slotwebloaded()
{
	QUrl urlbuf;
	QString Strbuf;
	urlbuf=WView->url();
	Strbuf=urlbuf.toString();
	QMessageBox mebox;
	mebox.setText(Strbuf);
	mebox.exec();
	QString StrBuf=WFrame->toHtml();
	QFile fileListlog("123.xml");
	fileListlog.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream TextStreamListlog(&fileListlog);
	TextStreamListlog << StrBuf;
	fileListlog.close();
}
void DialogImpl::slot1()
{
	evalJS(QString("document.getElementById('Email').value = \"superjoeliao@yahoo.com.tw\";"));
	evalJS(QString("document.getElementById('Passwd').value = \"asd700502\";"));
	/*
	evalJS(QString("document.getElementById('gaia_loginform').submit();"));
	*/
}
QString DialogImpl::evalJS(const QString &js)
{
	return WFrame->evaluateJavaScript(js).toString();
}

//
