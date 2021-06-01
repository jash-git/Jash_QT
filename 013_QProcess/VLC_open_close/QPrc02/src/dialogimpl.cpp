#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
void DialogImpl::slotRun()
{
/*
	proc=new QProcess();
	proc->start("./test.sh");
*/
	QString Strdata="ffmpeg -i /home/jash/11.mp4 -f mpegts -vcodec libx264 -vpre medium -vpre baseline -acodec libfaac -ac 2 -ab 128k -s 400x300 -r 30 -re -b 200k -threads 2 udp://@127.0.0.1:1233?pkt_size=1316";
	Strdata=Strdata.replace("ffmpeg ","");
	Strdata=Strdata.replace("'","");
	proc=new QProcess();
	QString StrVLC;
	StrVLC="ffmpeg";
	arguments=Strdata.split(" ");
	proc->start(StrVLC,arguments);
	//proc->start(Strdata);
}
void DialogImpl::slotClose()
{
	//int n_pid = proc->pid();//sh pid [ vlc pid =sh pid+1 ]
	//kill((n_pid+1), SIGINT);//kill vlc
	proc->kill();//kill sh
	delete proc;
}
//
