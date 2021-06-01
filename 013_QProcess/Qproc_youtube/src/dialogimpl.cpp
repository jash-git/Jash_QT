#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	proc=new QProcess();
	connect(proc, SIGNAL(readyReadStandardOutput()),this, SLOT(catchOutput()));
}
void DialogImpl::slotDownload()
{
	QString Strshfile;
	QStringList arguments;
	QString StrUrl;
	Strshfile="/usr/bin/youtube-dl";
	StrUrl=line_Input->text();
	arguments <<StrUrl;
	proc->start(Strshfile,arguments);
	lab_Data->setText(StrUrl);
}
void DialogImpl::catchOutput()
{
	lab_Data->setText("reading...");
	QString strBuf;
	char chrdata[2000]="\0";	
	proc->read(chrdata,2000);
	strBuf=chrdata;	
	lab_Data->setText(strBuf);
}
//
