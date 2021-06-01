#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	edit1=lineEdit;
	StrPath=QDir::currentPath();
	StrPath=StrPath+"/";
	timer1=new QTimer();
	blnTimerStep=false;//Not Get a file;
	connect(timer1,SIGNAL(timeout()),SLOT(Timerslot()));
	timer1->start(500);
}
void DialogImpl::callExe()
{
	cmd=new QProcess();
	QString StrExeName;
	StrExeName=StrPath+"ConverterWMV2Mp4";
	cmd->start(StrExeName);
	
}
void DialogImpl::Timerslot()
{
	if(blnTimerStep==false)
	{
		edit1->setText("Step 01");
		QFile Filecheck("check.txt");
		if(Filecheck.open(QFile::ReadOnly))
		{
			QFile FileDel("check.txt");
			FileDel.remove();
			blnTimerStep=true;
			callExe();
		}
		Filecheck.close();
	}
	else
	{
		edit1->setText("Step 02");
		if(cmd->waitForFinished())
		{
			delete cmd;
			blnTimerStep=false;			
		}
	}
}
DialogImpl::~DialogImpl()
{
	delete timer1;
}
//
