#include "CProcessThread.h"

// place your code here
CProcessThread::CProcessThread()
{
	
}
void CProcessThread::SetValue(QString StrMediaPath,QString StrStartPoint)
{
	m_arguments.clear();
	m_arguments<<StrStartPoint;
	m_arguments<<StrMediaPath;	
}
void CProcessThread::run()
{
	QProcess *proc;
	QString StrPath;
	proc=new QProcess();
	StrPath=QDir::currentPath();
	StrPath+="/OutputSignals.sh";
	proc->start(StrPath,m_arguments);
	while(!proc->waitForFinished())
	{
		continue;
	}
	delete proc;	
}
