#include "dialogimpl.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	CreateButton=createButton;
	RunButton=runButton;
}
void DialogImpl::slotCreate()
{
	QString Str01,Str02,Str03,Str04;
	QString StrFileName;
	Str01="#!/bin/bash";
	Str01+="\n";
	Str01+="#tmpfile=\"video_tmp.mp4\"";
	Str01+="\n";
	Str01+="options=\"-vcodec libx264 -b ";
	Str02="200k";
	Str01+=Str02;
	Str01+=" -flags +loop+mv4 -cmp 256 \\";
	Str01+="\n";
	Str01+="   -partitions +parti4x4+parti8x8+partp4x4+partp8x8+partb8x8 \\";
	Str01+="\n";	
	Str01+="   -me_method hex -subq 7 -trellis 1 -refs 5 -bf 0 \\";
	Str01+="\n";	
	Str01+="   -flags2 +mixed_refs -coder 0 -me_range 16 \\";
	Str01+="\n";	
	Str01+="   -g 250 -keyint_min 25 -sc_threshold 40 -i_qfactor 0.71 -qmin 10\\";
	Str01+="\n";	
	Str01+="   -qmax 51 -qdiff 4 -s ";
	Str03="400*300\"";
	Str01+=Str03;
	Str01+="\n";
	Str01+="\n";
	Str01+="ffmpeg -y -i \"$1\" -an -pass 1 -threads 2 $options \"$2\"";
	Str01+="\n";
	Str01+="ffmpeg -y -i \"$1\" -acodec libfaac -ar 44100 -ab ";
	Str04="48K";
	Str01+=Str04;
	Str01+=" -pass 2 -threads 2 $options \"$2\"";
	QByteArray byte = Str01.toAscii();
	StrFileName="test_";
	StrFileName+=Str02;
	StrFileName+=".sh";
	QFile destFile(StrFileName);
	if (destFile.open(QIODevice::WriteOnly))
	{
		struct stat statbuf;
		destFile.write(byte);
		destFile.close();
		stat(StrFileName.toAscii(), &statbuf);
		//一次只能設定一個值
		//所以就設定完一個再or一個
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
	
	QMessageBox mb;
	mb.setText(Str01);
	mb.exec();
}
void DialogImpl::slotRun()
{
	QProcess *cmd;
	QStringList arguments;
	QString str,str01,str02;
	QString StrCurrentPath;
	StrCurrentPath="";
	StrCurrentPath=QDir::currentPath();
	StrCurrentPath=StrCurrentPath+"/";
	str=StrCurrentPath+"test_200k.sh";
	str01=StrCurrentPath+"11.wmv";
	str02=StrCurrentPath+"11_200K.mp4";
	arguments <<str01;
	arguments <<str02;	
	cmd=new QProcess();
	cmd->start(str,arguments);
	while(!cmd->waitForFinished())
	{
		continue;
	}
	delete cmd;
	
}
//
