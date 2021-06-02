#include "consoletimer.h"
consoletimer::consoletimer(QObject *parent):QObject(parent)
{
	timer=new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(slotTimer()));
	timer->start(1000);
}
consoletimer::~consoletimer()
{
};
void consoletimer::slotTimer()
{
	system("clear");
	QDate date = QDate::currentDate();//¨ú±o¥Ø«e¤é´Á
	QTime time = QTime::currentTime();//¨ú±o¥Ø«e®É¶¡
	QString StrDate=date.toString("yyyyMMdd");//QString StrDate=date.toString("yyyy-MM-dd");
	QString StrTime=time.toString("hhmmss");//QString StrTime=time.toString("hh:mm:ss");
	QByteArray ArrDate,ArrTime;
	ArrDate=StrDate.toAscii();
	ArrTime=StrTime.toAscii();
	cout<<"Now Time:"<<ArrDate.data()<<"\t"<<ArrTime.data()<<endl;
	FILE *pf;
	pf=fopen("time.log","a");
	fprintf(pf,"%s%s\n",ArrDate.data(),ArrTime.data());
	fclose(pf);	
}
// place your code here

