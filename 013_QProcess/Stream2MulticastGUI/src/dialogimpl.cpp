#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	cmd=new QProcess();
	killcmd=new QProcess();
}
void DialogImpl::CreateShellFile(QString Shell)
{
	QString StrFileName,StrBuf;
	StrBuf="#!/bin/bash";
	StrBuf+="\n";
	Shell=StrBuf+Shell;
	QByteArray byte = Shell.toAscii();
	StrFileName="Stream2Multicast.sh";
	QFile destFile(StrFileName);
	if (destFile.open(QIODevice::WriteOnly))
	{
		struct stat statbuf;
		destFile.write(byte);
		destFile.close();
		stat(StrFileName.toAscii(), &statbuf);
		//¤@¦¸¥u¯à³]©w¤@­Ó­È
		//©Ò¥H´N³]©w§¹¤@­Ó¦Aor¤@­Ó
		/*
        if(u)  

04         {  

05             if(r)  

06                 *mode|=S_IRUSR;  

07             if(w)  

08                 *mode|=S_IWUSR;  

09             if(x)  

10                 *mode|=S_IXUSR;  

11         }  

12         if(g)  

13         {  

14             if(r)  

15                 *mode|=S_IRGRP;  

16             if(w)  

17                 *mode|=S_IWGRP;  

18             if(x)  

19                 *mode|=S_IXGRP;  

20         }  

21         if(o)  

22         {  

23             if(r)  

24                 *mode|=S_IROTH;  

25             if(w)  

26                 *mode|=S_IWOTH;  

27             if(x)  

28                 *mode|=S_IXOTH;  

 */
		chmod(StrFileName.toAscii(),(((statbuf.st_mode | S_IXUSR)|S_IXGRP)|S_IXOTH));
	}

}
void DialogImpl::slotRunStop()
{
	QString StrBuf,StrShell;
	QString StrCurrentPath;
	QByteArray ByteUrl,ByteRate1,ByteRate2;
	
	StrBuf=Edit_Url->toPlainText();
	ByteUrl=StrBuf.toLocal8Bit ();
	
	StrBuf=EditBitRate1->toPlainText();
	ByteRate1=StrBuf.toLocal8Bit ();
	
	StrBuf=EditBitRate2->toPlainText();
	ByteRate2=StrBuf.toLocal8Bit ();
	
	StrShell.sprintf("cvlc \"%s\" --sout-ts-pid-video=69 --sout-ts-pid-audio=68 --sout-transcode-alang=eng --sout-keep --sout '#duplicate{dst=\"transcode{fps=29.97,venc=x264{keyint=90,profile=main,level=3,bframes=0,no-cabac,ref=1,no-mbtree,partitions=none,no-weightb,weightp=0,me=hex,subme=0,no-mixed-refs,no-8x8dct,trellis=0},vcodec=h264,vb=%s,width=704,height=480,deinterlace,acodec=aac,aenc=ffmpeg{strict=-2},ab=48,channels=2,samplerate=44100}:udp{mux=ts,dst=224.8.8.135:13511}\",dst=\"transcode{fps=29.97,venc=x264{keyint=90,profile=main,level=3,bframes=0,no-cabac,ref=1,no-mbtree,partitions=none,no-weightb,weightp=0,me=hex,subme=0,no-mixed-refs,no-8x8dct,trellis=0},vcodec=h264,vb=%s,width=704,height=480,deinterlace,acodec=aac,aenc=ffmpeg{strict=-2},ab=48,channels=2,samplerate=48000}:udp{mux=ts,dst=224.8.8.135:13521}\"'",ByteUrl.data(),ByteRate1.data(),ByteRate2.data());
	
	StrBuf="Run";
	if(StrBuf==ButtonRunStop->text())//Create (Run) Multicat....
	{
		ButtonRunStop->setText("Stop");
		/*
		//show shell
		QMessageBox box;
		box.setText(StrShell);	
		box.exec();
		//*/
		CreateShellFile(StrShell);
	
		StrCurrentPath="";
		StrCurrentPath=QDir::currentPath();
		StrCurrentPath=StrCurrentPath+"/";
		StrShell=StrCurrentPath+"Stream2Multicast.sh";
		cmd->start(StrShell);
	}
	else
	{
		cmd->kill();
		killcmd->start("killall vlc");
		this->close();
	}

}
//
