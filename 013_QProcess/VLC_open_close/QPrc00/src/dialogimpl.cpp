#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
void DialogImpl::slotRun()
{
	QString StrVLC;	
	proc=new QProcess();
	StrVLC="vlc";
	arguments <<"/home/jash/11.mp4";
	proc->start(StrVLC,arguments);
}
void DialogImpl::slotClose()
{
	proc->close();
	delete proc;
}
//
