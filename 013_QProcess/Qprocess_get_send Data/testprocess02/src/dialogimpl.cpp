#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	LineEdit=lineEdit;
}
void DialogImpl::slotbutt()
{
	QString strprogram="/home/jash/VLMtelnet.sh";
	testping=new QProcess();
	connect(testping, SIGNAL(readyReadStandardOutput()),this, SLOT(catchOutput()));
	testping->start(strprogram);
}
void DialogImpl::catchOutput()
{
	QString strBuf;
	char chrdata[200]="\0";	
	testping->read(chrdata,200);
	strBuf=chrdata;
	QMessageBox msg;
	msg.setText(strBuf);
	msg.exec();
}
void DialogImpl::slotsend()
{
	QString strbuf;
	strbuf=LineEdit->text();
	strbuf=strbuf+"\n";
	testping->write(strbuf.toAscii().data());
}
//
