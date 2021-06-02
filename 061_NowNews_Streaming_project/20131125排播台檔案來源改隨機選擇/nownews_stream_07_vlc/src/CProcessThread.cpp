#include "CProcessThread.h"

// place your code here
CProcessThread::CProcessThread()
{
	
}
void CProcessThread::run()
{
	QProcess *proc;
	QString StrPath;
	proc=new QProcess();
	StrPath=QDir::currentPath();
	StrPath+="/nownews.sh";
	proc->start(StrPath);
	while(!proc->waitForFinished())
	{
		continue;
	}
	delete proc;	
}