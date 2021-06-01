#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	Ledit1=lineEdit;
	Tedit1=textEdit;
	cmd=new QProcess();
	connect(cmd,SIGNAL(readyRead()),this,SLOT(showinf()));
}
void DialogImpl::showinf()
{
	StrShowBuf+=cmd->readAll();
	Tedit1->setText(StrShowBuf);
}
void DialogImpl::slot1()
{
	QString StrBuf;
	StrBuf=Ledit1->text();
	Ledit1->setText("");
	cmd->start(StrBuf);
}
DialogImpl::~DialogImpl()
{
	delete cmd;
}
//
