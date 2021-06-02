#include "consoletimer.h"
consoletimer::consoletimer(QObject *parent):QObject(parent)
{
	timer=new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(slotTimer()));
	timer->start(10000);
}
consoletimer::~consoletimer()
{
};
void consoletimer::slotTimer()
{
	//system("clear");
	QDate date = QDate::currentDate();//取得目前日期
	QTime time = QTime::currentTime();//取得目前時間
	QString StrDate=date.toString("yyyy-MM-dd");
	QString StrTime=time.toString("hh:mm:ss");
	QByteArray ArrDate,ArrTime;
	ArrDate=StrDate.toAscii();
	ArrTime=StrTime.toAscii();
	QString StrPath;
	StrPath=QDir::currentPath();
	StrPath=StrPath+"/log/qt_service_main.log";
	QFile filelog(StrPath);
	filelog.open(QFile::Append);
	QTextStream TextStreamOut(&filelog);
	TextStreamOut<<"now time"<<ArrDate.data()<<"\t"<<ArrTime.data()<<endl;
	filelog.close();
	//cout<<"目前時間："<<ArrDate.data()<<"\t"<<ArrTime.data()<<endl;
		
}
// place your code here