#include "dialogimpl.h"
#include <QProcess>
#include <QStringList>
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
void DialogImpl::slotpb1()
{
	QProcess *proc;
	fstream fs;
	QByteArray procOutPut;
	QString Strshfile;
	QStringList arguments;
	time_t timedata01,timedata02;
	proc=new QProcess();
	Strshfile="/home/jash/test.sh";
	arguments <<"/home/jash/mv011.wmv";
	arguments <<"/home/jash/mv011.mp4";
	proc->start(Strshfile,arguments);
	fs.open("log.txt",ios::in|ios::out|ios::trunc);
	timedata01=time(NULL); 
	fs << "start:" <<"\t" << timedata01 << endl;
	while(!proc->waitForFinished())
	{
		continue;
	}
	timedata02=time(NULL);
	fs << "end:" << "\t" << timedata02 << endl;
	fs << "diff:" << "\t" << difftime(timedata02,timedata01) << endl;
	fs.close();
	this->close();
}
//
