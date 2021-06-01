#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	m_date = QDate::currentDate();//取得目前日期
	blnone=false;
	timer=new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(slotTimer()));
	timer->start(100);
}
void DialogImpl::slotTimer()
{
	QDate date = QDate::currentDate();//取得目前日期
	QTime time = QTime::currentTime();//取得目前時間
	
	double dblTime;
	int intHour,intMinute,intSecond;//存放目前時間
	double dblDate;
	int intYear,intMonth,intDay;//存放目前日期
	date.getDate(&intYear,&intMonth,&intDay);
	dblDate=((intYear%100)*10000)+(intMonth*100)+intDay;
	intHour=time.hour();
	intMinute=time.minute();
	intSecond=time.second();
	dblTime=(intHour*10000)+(intMinute*100)+intSecond;
	QString format = "yyyy.MM.dd";
	lab_old->setText(m_date.toString(format));
	lab_now->setText(date.toString(format));
	//*
	if(intHour==4 && blnone==false)	
	{
		QString Strshfile;
		QString StrPath;
	
		proc=new QProcess();
		StrPath=QDir::currentPath();
		Strshfile=StrPath;
		Strshfile+="/";
		Strshfile+="work.sh";
	
		proc->start(Strshfile);
		blnone=true;
	}
	if(date!=m_date)
	{
		blnone=false;
		m_date=date;
		proc->terminate();//kill sh
		delete proc;
	}
	//*/

}
//
