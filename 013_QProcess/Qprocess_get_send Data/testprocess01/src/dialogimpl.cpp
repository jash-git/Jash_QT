#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
void DialogImpl::slotbutt()
{
	QString strprogram="/home/jash/testping.sh";
	testping=new QProcess();
	connect(testping, SIGNAL(readyReadStandardOutput()),this, SLOT(catchOutput()));
	testping->start(strprogram);
}
void DialogImpl::catchOutput()
{
	QString strBuf;
	char chrdata[200]="\0";	
	testping->read(chrdata,200);
	testping->close();
	strBuf=chrdata;
	QMessageBox msg;
	msg.setText(strBuf);
	msg.exec();
}
//
