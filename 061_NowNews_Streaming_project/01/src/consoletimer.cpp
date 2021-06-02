#include "consoletimer.h"
consoletimer::consoletimer(QObject *parent):QObject(parent)
{
//----------------------------
//__init_start
	ReadConfig();
	CreateWgetSh();
	RunWgetSh();
	Xml2Txt();
	m_intStep=1;
//__init_end
//----------------------------
	timer=new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(slotTimer()));
	timer->start(100);
}
consoletimer::~consoletimer()
{
};

//============================================================
//
//函數說明
//讀取程式設定檔
//============================================================
void consoletimer::ReadConfig()
{
	m_StrPlayListUrl="";
	doc=new QDomDocument("Config");
	QFile file("Config.xml");
	QFile filelog("Configlog.txt");
	QString StrPath;
	StrPath=QDir::currentPath();
	filelog.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream TextStreamOut(&filelog);
	TextStreamOut << "currentPath:"<< "\t" << StrPath <<"/" <<endl;
	if(!file.open(QIODevice::ReadOnly))
	{
		file.close();
		return;	
	}
	if(doc->setContent(&file))
	{
		file.close();
	}
	QDomElement docElem=doc->documentElement();
	QDomNode docNode=docElem.firstChild();
	QDomElement docElement;
	QString StrData;
	int intcount=0;
	while(!docNode.isNull())
	{
		docElement=docNode.toElement();
		if(!docElement.isNull())
		{
			StrData=docElement.tagName();
			TextStreamOut << StrData << "\t";
			StrData=docElement.text();
			TextStreamOut << StrData << endl;
			switch(intcount)
			{
				case 0:
					m_StrPlayListUrl=StrData;
					break;
				case 1:
					m_StrMp4Path=StrData;
					break;
				case 2:
					m_Strffmpeg_vlc01=StrData;
					break;
				case 3:
					m_Strffmpeg_vlc02=StrData;
					break;
				case 4:
					//m_StrBaseUrl=StrData;
					break;
				case 5:
					//m_StrLivePar=StrData;
					break;
				case 6:
					//m_StrLiveProcess=StrData;
					break;
				case 7:
					//m_StrMultiProcess=StrData;
					break;
			}
			intcount++;
		}
		docNode=docNode.nextSibling();
	}
	filelog.close();

	delete doc;	
}
//============================================================
//
//函數說明
//下載清單SH建立
//============================================================
void consoletimer::CreateWgetSh()
{
	QString StrFileName;
	QString StrData;
	StrData="#!/bin/bash";
	StrData+="\n";
	StrData+="wget ";
	StrData+=m_StrPlayListUrl;
	StrData+=" -O nownews.xml";
	QByteArray byte = StrData.toAscii();
	
	StrFileName="wgetnownews.sh";
	QFile destFile(StrFileName);
	if (destFile.open(QIODevice::WriteOnly))
	{
		struct stat statbuf;
		destFile.write(byte);
		destFile.close();
		stat(StrFileName.toAscii(), &statbuf);
		chmod(StrFileName.toAscii(),(((statbuf.st_mode | S_IXUSR)|S_IXGRP)|S_IXOTH));
	}
}
//============================================================
//
//函數說明
//執行下載清單SH
//============================================================
void consoletimer::RunWgetSh()
{
	QProcess *cmd;
	QString StrCurrentPath;
	QString StrCmd;
	StrCurrentPath="";
	StrCurrentPath=QDir::currentPath();
	StrCurrentPath=StrCurrentPath+"/";
	StrCmd=StrCurrentPath+"wgetnownews.sh";
	cmd=new QProcess();
	cmd->start(StrCmd);
	while(!cmd->waitForFinished())
	{
		continue;
	}
	delete cmd;	
}
//============================================================
//
//函數說明
//將清單資料從XML轉成TXT(SH)
//============================================================
void consoletimer::Xml2Txt()
{
	QString StrPath;
	QString StrFileName="nownews.sh";
	docXml2Txt=new QDomDocument("nownews");
	QFile file("nownews.xml");
	QFile filelog("nownews.sh");
	StrPath=QDir::currentPath();
	filelog.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream TextStreamOut(&filelog);
	
	if(docXml2Txt->setContent(&file))
	{
		file.close();
	}

	QString StrBuf;
	StrBuf="encodingitem";
	int i,j;
	int k,l;
	i=0;
	k=0;
	QDomElement docElem=docXml2Txt->documentElement();
	QDomNodeList docNodeList1=docElem.elementsByTagName(StrBuf);
	j=docNodeList1.count();

	TextStreamOut << "#!/bin/bash" << endl;
	if(j>0)
	{		
		QDomNode docNode1;
		QDomNode docNode2;
		QDomNodeList docNodeList2;
		QDomElement docElement;
		QString StrData;
		for(i=0;i<j;i++)
		{
			docNode1=docNodeList1.at(i);
			docNodeList2=docNode1.childNodes();
			k=0;
			l=docNodeList2.count();
			for(k=0;k<l;k++)
			{
				docNode2=docNodeList2.at(k);
				docElement=docNode2.toElement();
				if(!docElement.isNull())
				{
					/*
					StrData=docElement.tagName();
					TextStreamOut << StrData << "\t";
					StrData=docElement.text();
					TextStreamOut << StrData << endl;
					*/
					switch(k)
					{
						case 0://videoname
							break;
						case 1://filename
							break;
						case 2://filepath
							StrData+="ffmpeg -y -i ";
							StrData+=m_StrMp4Path;
							StrData+=docElement.text();
							StrData+=m_Strffmpeg_vlc02;
							break;
						case 3://online_time
							break;
						default: 
							continue;
					}//switch(k)
				}//if(!docElement.isNull())
			}//for(k=0;k<l;k++)
		TextStreamOut << StrData << endl;
		StrData="";
		}//for(i=0;i<j;i++)
		filelog.close();
	}//if(j>0)
	
	struct stat statbuf;
	stat(StrFileName.toAscii(), &statbuf);
	chmod(StrFileName.toAscii(),(((statbuf.st_mode | S_IXUSR)|S_IXGRP)|S_IXOTH));	
}
void consoletimer::slotTimer()
{
	timer->stop();
	
	system("clear");
	QDate date = QDate::currentDate();//取得目前日期
	QTime time = QTime::currentTime();//取得目前時間
	QString StrDate=date.toString("yyyy-MM-dd");
	QString StrTime=time.toString("hh:mm:ss");
	
	QByteArray ArrDate,ArrTime;
	QByteArray ArrPlayListUrl,ArrMp4Path;
	QByteArray Arrffmpeg_vlc01,Arrffmpeg_vlc02;
	ArrDate=StrDate.toAscii();
	ArrTime=StrTime.toAscii();
	ArrPlayListUrl=m_StrPlayListUrl.toAscii();
	ArrMp4Path=m_StrMp4Path.toAscii();
	Arrffmpeg_vlc01=m_Strffmpeg_vlc01.toAscii();
	Arrffmpeg_vlc02=m_Strffmpeg_vlc02.toAscii();
	
	cout<<"NowNews_Streaming"<<endl;
	cout<<"目前時間："<<ArrDate.data()<<"\t"<<ArrTime.data()<<endl;
	cout<<"m_StrPlayListUrl參數值＝"<<ArrPlayListUrl.data()<<endl;
	cout<<"m_StrMp4Path參數值＝"<<ArrMp4Path.data()<<endl;
	cout<<"m_Strffmpeg_vlc01參數值＝"<<Arrffmpeg_vlc01.data()<<endl;
	cout<<"m_Strffmpeg_vlc02參數值＝"<<Arrffmpeg_vlc02.data()<<endl;
	cout<<endl;
	cout<<"-------------------------------------------------"<<endl;
	
	QFile FileDel01("Configlog.txt");
	QFile FileDel02("nownews.sh");
	QFile FileDel03("wgetnownews.sh");
	QFile FileDel04("nownews.xml");	
	
	switch(m_intStep)
	{
		case 0://init
			ReadConfig();
			CreateWgetSh();
			RunWgetSh();
			Xml2Txt();
			cout<<"程式狀態 0：清單初始化"<<endl;
			m_intStep=1;
			break;
		case 1://run
			ProThread.start();
			cout<<"程式狀態 1：執行發送 Stream"<<endl;
			m_intStep=2;
			break;
		case 2://wait
			if(ProThread.isRunning())
			{
				m_intStep=2;
				cout<<"程式狀態 2：執行發送 Stream中 並 開始等待"<<endl;
			}
			else
			{
				FileDel01.remove();
				FileDel02.remove();
				FileDel03.remove();
				FileDel04.remove();
				m_intStep=0;
			}
			break;
	}
	
	timer->start(100);
}
// place your code here
