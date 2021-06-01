#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
void DialogImpl::slotRun()
{
	//vlc -vvv rtsp://61.67.123.92/live/cctv4_440k.stream --sout '#transcode{venc=x264,vcodec=h254,acodec=mp4a}:udp{mux=ts,dst=224.1.1.1:1234}'
	/*
	QString StrVLC;	
	QString Strdata="test.sh";
	proc=new QProcess();
	Strdata=QDir::currentPath();
	Strdata+="/";
	Strdata+="test.sh";
	proc->start(Strdata);
	//*/
	/*
	proc=new QProcess();
	QString StrVLC;
	StrVLC="vlc";
	arguments <<"-vvv";
	arguments <<"rtsp://61.67.123.92/live/cctv4_440k.stream";
	arguments <<"--sout";
	arguments <<"#transcode{venc=x264,vcodec=h254,acodec=mp4a}:udp{mux=ts,dst=224.1.1.1:1234}";
	proc->start(StrVLC,arguments);
	//*/
	QString Strdata="vlc -vvv rtsp://61.67.123.92/live/cctv4_440k.stream --sout '#transcode{venc=x264,vcodec=h254,acodec=mp4a}:udp{mux=ts,dst=224.1.1.1:1234}'";
	Strdata=Strdata.replace("vlc ","");
	Strdata=Strdata.replace("'","");
	proc=new QProcess();
	QString StrVLC;
	StrVLC="vlc";
	arguments=Strdata.split(" ");
	proc->start(StrVLC,arguments);
}
void DialogImpl::slotClose()
{
	//int n_pid = proc->pid();//sh pid [ vlc pid =sh pid+1 ]
	//kill((n_pid+1), SIGINT);//kill vlc
	proc->kill();//kill sh
	delete proc;
}
//
