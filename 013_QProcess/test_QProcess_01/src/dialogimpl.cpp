#include "dialogimpl.h"
#include <QProcess>
#include <QStringList>
#include <QString>
#include <QByteArray>
#include <QDebug>
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
void DialogImpl::slotpb1()
{
	QProcess *proc;
	QString Strshfile;
	QStringList arguments;
	proc=new QProcess();
	Strshfile="mplayer";
	arguments <<"mv011.mp4";
	proc->start(Strshfile,arguments);
}
//
