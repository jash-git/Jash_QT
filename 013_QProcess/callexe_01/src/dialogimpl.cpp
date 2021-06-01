#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	cmd=new QProcess();
	QString str;
	timer=new QTimer(this);
	str="/home/jash/Hello_Qt";
	connect(timer,SIGNAL(timeout()),this,SLOT(slot1()));
	cmd->start(str);
	timer->start(1000);
}
DialogImpl::~DialogImpl()
{
	delete cmd;
}
void DialogImpl::slot1()
{
	if(cmd->waitForFinished())
	{
		QApplication::quit();
	}
}
//
