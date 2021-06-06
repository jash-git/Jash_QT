#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	resize(400,100);//程式過程改變Dialog GUI大小
	Button_Detail->hide();
	connect (&m_cmd, SIGNAL(readyReadStandardOutput()),this, SLOT(outputCommand()));
	connect (&m_cmd, SIGNAL(readyReadStandardError()),this, SLOT(outputCommand()));
 	connect(&m_cmd, SIGNAL(finished(int, QProcess::ExitStatus)),this, SLOT(processFinished(int, QProcess::ExitStatus)));  	
	//label->setGeometry(0, 0, 290, 70);設定元件大小位置
}
void DialogImpl::slotSelect()
{
	QString StrPath_Name = QFileDialog::getOpenFileName(this, "Select Movie","/home", "Movie Files (*.mov *.mp4 *.wmv *.avi)");
	QString	StrPath,StrName;
	int intindex;
	intindex=StrPath_Name.lastIndexOf('/');
	StrPath=StrPath_Name.mid(0,intindex+1);
	StrName=StrPath_Name.mid(intindex+1);
	Edit_Path->setText(StrPath);
	Edit_Name->setText(StrName);
	m_StrPath_Name=StrPath_Name;
	Button_Detail->show();
	resize(400,100);//程式過程改變Dialog GUI大小
}
void DialogImpl::slotDetail()
{
	Button_Detail->hide();
	//ffmpeg -i 11.mp4 2>&1 | grep Stream >stream.txt
	//ffmpeg -i 11.mp4 2>&1 | grep Duration | cut -d, -f1 | cut -d: -f2- >Duration.txt
	const char *data = m_StrPath_Name.toLocal8Bit().data();
	FILE *pf;
	struct stat statbuf;
	pf=fopen("MovieInfor.sh","w");
	fprintf(pf,"ffmpeg -i %s 2>&1 | grep Stream >stream.txt\n",data);
	fprintf(pf,"ffmpeg -i %s 2>&1 | grep Duration | cut -d, -f1 | cut -d: -f2- >Duration.txt\n",data);
	fclose(pf);
	stat("MovieInfor.sh", &statbuf);
	chmod("MovieInfor.sh",(((statbuf.st_mode | S_IXUSR)|S_IXGRP)|S_IXOTH));
	///////////////////////////////////////////////////////////////////////
	QProcess *cmd;
	QString str;
	QString StrCurrentPath;
	QString StrFormat;
	QStringList arguments;
	StrCurrentPath="";
	StrCurrentPath=QDir::currentPath();
	StrCurrentPath=StrCurrentPath+"/";	
	str=StrCurrentPath+"MovieInfor.sh";
	cmd=new QProcess();
	cmd->start(str,arguments);
	while(!cmd->waitForFinished())
	{
		continue;
	}
	delete cmd;
	//////////////////////////////////////////////////////////////////////////
	char chrDuration[20];
	pf=fopen("Duration.txt","r");
	fscanf(pf,"%s",chrDuration);
	fclose(pf);
	Edit_Duration->setText(chrDuration);
	//***********************************
	fstream a;
	char chrStream00[200];
	char chrStream01[200];
	char buf0[50],buf1[50],buf2[50];
	char buf3[50],buf4[50],buf5[50];
	a.open("stream.txt",ios::in);
	a.getline(chrStream00,200);
	a.getline(chrStream01,200);
	a.close();
	sscanf(chrStream00,"%[^','],%[^','],%[^','],",buf0,buf1,buf2);
	sscanf(chrStream01,"%[^','],%[^','],%[^','],",buf3,buf4,buf5);
	Edit_Size->setText(buf2);
	StrFormat=buf0;
	StrFormat=StrFormat+" ; ";
	StrFormat=StrFormat+buf3;
	Edit_Format->setText(StrFormat);
	QFile DeleteFile01("MovieInfor.sh");
	DeleteFile01.remove();
	QFile DeleteFile02("Duration.txt");
	DeleteFile02.remove();
	QFile DeleteFile03("stream.txt");
	DeleteFile03.remove();
	combo_Size->insertItem(0,"400*300");
	combo_Size->insertItem(1,"800*600");
	combo_Size->insertItem(3,"1024*768");
	combo_VideoBitrate->insertItem(0,"300k");
	combo_VideoBitrate->insertItem(1,"400k");
	combo_VideoBitrate->insertItem(2,"600k");
	combo_VideoBitrate->insertItem(3,"1024k");
	combo_CPU->insertItem(0,"1");
	combo_CPU->insertItem(1,"2");
	combo_CPU->insertItem(2,"3");
	combo_CPU->insertItem(3,"4");
	combo_CPU->insertItem(4,"5");
	combo_CPU->insertItem(5,"6");
	combo_CPU->insertItem(6,"7");
	this->resize(400,544);//程式過程改變Dialog GUI大小
}
void DialogImpl::slotRun()
{
	Button_Select->setEnabled(false);
	Button_Run->setEnabled(false);
	Edit_Path->setEnabled(false);
	Edit_Name->setEnabled(false);
	Edit_Format->setEnabled(false);
	Edit_Size->setEnabled(false);
	Edit_Duration->setEnabled(false);
	combo_CPU->setEnabled(false);
	combo_VideoBitrate->setEnabled(false);
	combo_Size->setEnabled(false);
	///////////////////////////////////////////////////////////////////////////
	m_StrCUP="-threads "+combo_CPU->itemText(combo_CPU->currentIndex());
	//QMessageBox::warning(this, "Warning",m_StrCUP,QMessageBox::Yes, QMessageBox::Yes);
	m_StrAudioFormat="-acodec "+label_AudioFormat->text();
	//QMessageBox::warning(this, "Warning",m_StrAudioFormat,QMessageBox::Yes, QMessageBox::Yes);
	m_StrVideoFormat="-vcodec "+label_VideoFormat->text();
	//QMessageBox::warning(this, "Warning",m_StrVideoFormat,QMessageBox::Yes, QMessageBox::Yes);
	m_StrAudioSample="-ar "+label_AudioSample->text();
	//QMessageBox::warning(this, "Warning",m_StrAudioSample,QMessageBox::Yes, QMessageBox::Yes);
	m_StrAudioBitrate="-ab "+label_AudioBitrate->text();
	//QMessageBox::warning(this, "Warning",m_StrAudioBitrate,QMessageBox::Yes, QMessageBox::Yes);
	m_StrVideoFsp="-r "+label_VideoFsp->text();
	//QMessageBox::warning(this, "Warning",m_StrVideoFsp,QMessageBox::Yes, QMessageBox::Yes);
	m_StrVideoBitrate="-b "+combo_VideoBitrate->itemText(combo_VideoBitrate->currentIndex());
	//QMessageBox::warning(this, "Warning",m_StrVideoBitrate,QMessageBox::Yes, QMessageBox::Yes);
	m_StrSize="-s "+combo_Size->itemText(combo_Size->currentIndex());
	//QMessageBox::warning(this, "Warning",m_StrSize,QMessageBox::Yes, QMessageBox::Yes);
	///////////////////////////////////////////////////////////////////////////
	QString Str01;
	Str01="#!/bin/bash";
	Str01+="\n";
	Str01+="#tmpfile=\"video_tmp.mp4\"";
	Str01+="\n";
	Str01+="options=\" ";
	Str01+=m_StrVideoFormat;
	Str01+=" ";
	Str01+=m_StrVideoBitrate;
	Str01+=" -flags +loop+mv4 -cmp 256 \\";
	Str01+="\n";
	Str01+="   -partitions +parti4x4+parti8x8+partp4x4+partp8x8+partb8x8 \\";
	Str01+="\n";	
	Str01+="   -me_method hex -subq 7 -trellis 1 -refs 5 -bf 0 \\";
	Str01+="\n";	
	Str01+="   -flags2 +mixed_refs -coder 0 -me_range 16 \\";
	Str01+="\n";	
	Str01+="   -g 250 ";
	Str01+=m_StrVideoFsp;
	Str01+=" -keyint_min 25 -sc_threshold 40 -i_qfactor 0.71 -qmin 10\\";
	Str01+="\n";	
	Str01+="   -qmax 51 -qdiff 4 ";
	Str01+=m_StrSize;
	Str01+="\"";
	Str01+="\n";
	Str01+="\n";
	Str01+="ffmpeg -y -i \"$1\" -an -pass 1 ";
	Str01+=m_StrCUP;
	Str01+=" $options \"$2\"";
	Str01+="\n";
	Str01+="ffmpeg -y -i \"$1\" ";
	Str01+=m_StrAudioFormat;
	Str01+=" -ac 2 ";
	Str01+=m_StrAudioSample;
	Str01+=" ";
	Str01+=m_StrAudioBitrate;
	Str01+=" -pass 2 ";
	Str01+=m_StrCUP; 
	Str01+=" $options \"$2\"";
	QByteArray byte = Str01.toAscii();
	QFile destFile("AnyMovie2mp4.sh");
	if (destFile.open(QIODevice::WriteOnly))
	{
		struct stat statbuf;
		destFile.write(byte);
		destFile.close();
		stat("AnyMovie2mp4.sh", &statbuf);
		chmod("AnyMovie2mp4.sh",(((statbuf.st_mode | S_IXUSR)|S_IXGRP)|S_IXOTH));
	}
	////////////////////////////////////////////////////////////////////////////
	QString StrEndPath;
	QString StrEndBuf;
	int intindex;
	StrEndPath=Edit_Path->text();
	StrEndBuf=Edit_Name->text();
	intindex=StrEndBuf.lastIndexOf('.');	
	StrEndBuf=StrEndBuf.mid(0,intindex);
	StrEndBuf+="_";
	StrEndBuf+=combo_VideoBitrate->itemText(combo_VideoBitrate->currentIndex());
	StrEndBuf+=".mp4";
	StrEndPath+=StrEndBuf;
	
	QString str;
	QString StrCurrentPath;
	QString StrFormat;
	QStringList arguments;
	arguments <<m_StrPath_Name;
	arguments <<StrEndPath;	
	StrCurrentPath="";
	StrCurrentPath=QDir::currentPath();
	StrCurrentPath=StrCurrentPath+"/";	
	str=StrCurrentPath+"AnyMovie2mp4.sh";
	m_cmd.start(str,arguments);
	/*
	while(!m_cmd.waitForFinished())
	{
		continue;
	}
	*/
	//delete cmd;	
}
void DialogImpl::outputCommand()
{
	QByteArray cmdoutput = m_cmd.readAllStandardOutput();
	QString txtoutput = cmdoutput;
	textBrowser->append(txtoutput);
	cmdoutput = m_cmd.readAllStandardError();
	txtoutput = cmdoutput;
	textBrowser->append(txtoutput);
}
void DialogImpl::processFinished(int exitCode,QProcess::ExitStatus exitStatus)  
{
	///////////////////////////////////////////////////////////////////////////
	Button_Select->setEnabled(true);
	Button_Run->setEnabled(true);
	Edit_Path->setEnabled(true);
	Edit_Name->setEnabled(true);
	Edit_Format->setEnabled(true);
	Edit_Size->setEnabled(true);
	Edit_Duration->setEnabled(true);
	combo_CPU->setEnabled(true);
	combo_VideoBitrate->setEnabled(true);
	combo_Size->setEnabled(true);
	///////////////////////////////////////////////////////////////////////////
	QMessageBox::information(this, "Information","已完成轉檔",QMessageBox::Yes, QMessageBox::Yes);	 
}
//
