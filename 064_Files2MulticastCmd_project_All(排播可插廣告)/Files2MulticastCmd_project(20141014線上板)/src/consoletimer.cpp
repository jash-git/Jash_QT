#include "consoletimer.h"
consoletimer::consoletimer(QObject *parent):QObject(parent)
{
	timer=new QTimer(this);
	
	m_intStep=0;
	ReadConfig();

	m_StrPathArray.clear();
	m_StrStartArray.clear();
	m_StrEndArray.clear();
	m_StrStartTimeArray.clear();
	m_StrEndTimeArray.clear();
	m_proc='\0';
	connect(timer,SIGNAL(timeout()),this,SLOT(slotTimer()));
	timer->start(10);
}
consoletimer::~consoletimer()
{
}
void consoletimer::ReadConfig()
{
	m_StrPlayListUrl="";
	m_StrXMLFolderPath="";
	m_StrChangeFolderPath="";
	QDomDocument *doc=new QDomDocument("Config");
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
					m_ArrPlayListUrl=m_StrPlayListUrl.toAscii();
					break;
				case 1:
					m_StrXMLFolderPath=StrData;
					m_ArrXMLFolderPath=m_StrXMLFolderPath.toAscii();
					break;
				case 2:
					m_StrChangeFolderPath=StrData;
					m_ArrChangeFolderPath=m_StrChangeFolderPath.toAscii();
					break;
			}
			intcount++;
		}
		docNode=docNode.nextSibling();
	}
	filelog.close();
	
	delete doc;
}
void consoletimer::DownloadXML2Txt()
{
	QString Strshfile;
	QString StrPath;
	
	QDate date = QDate::currentDate();//取得目前日期
	QTime time = QTime::currentTime();//取得目前時間
	QString StrDate=date.toString("yyyyMMdd");//QString StrDate=date.toString("yyyy-MM-dd");
	QString StrTime=time.toString("hhmmss");//QString StrTime=time.toString("hh:mm:ss");
	QByteArray ArrDate,ArrTime;
	ArrDate=StrDate.toAscii();
	ArrTime=StrTime.toAscii();
	
	FILE *pfBash='\0';
	pfBash=fopen("DownloadListBash.sh","w");
	fprintf(pfBash,"#!/bin/bash\n");
	fprintf(pfBash,"wget \"%s?date=%s&time=%s\" -O list.xml",m_ArrPlayListUrl.data(),ArrDate.data(),ArrTime.data());
	fclose(pfBash);
	
	procXml2Txt=new QProcess();
	StrPath=QDir::currentPath();
	Strshfile=StrPath;
	Strshfile+="/";
	Strshfile+="DownloadListBash.sh";
	
	struct stat statbuf;
	stat(Strshfile.toAscii(), &statbuf);	
	chmod(Strshfile.toAscii(),(((statbuf.st_mode | S_IXUSR)|S_IXGRP)|S_IXOTH));
	
	procXml2Txt->start(Strshfile);
	
	while(!procXml2Txt->waitForFinished())
	{
		continue;
	}
	delete procXml2Txt;
	
	docXml2Txt=new QDomDocument("list");
	QFile file("list.xml");
	QFile filelog("00_listlog.txt");
	StrPath=QDir::currentPath();
	filelog.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream TextStreamOut(&filelog);
	
	if(!file.open(QIODevice::ReadOnly))
	{
		file.close();
		//CreateBaseList();
		return;	
	}
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
	if(j<=0)
	{
		//CreateBaseList();
		return;	
	}
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
				switch(k)
				{
					case 1://file_path
						StrData=docElement.text();
						StrData.toLower();
						StrData.replace(m_StrXMLFolderPath,m_StrChangeFolderPath);
						break;
					case 2://date
						StrData+=",";
						StrData+=docElement.text();
						StrData+=",";
						break;
					case 3://start_time
					case 4://end_time
					case 5://start_encoding
					case 6://end_encoding
						StrData+=docElement.text();
						StrData+=",";
						break;
					default: 
						continue;
				}
			}
		}
		TextStreamOut << StrData << endl;
	}
	filelog.close();	
}
void consoletimer::FilterListData()
{
	QDate DateNow=QDate::currentDate();//取得目前日期;
	QTime TimeNow = QTime::currentTime();//取得目前時間;
	
	QDate Date;
	QTime StartTime,EndTime;
	char chrPath[250],chrDate[50],chrStartTime[50],chrEndTime[50],chrStart[50],chrEnd[50];
	
	int intAddSec=0;
	bool blnfirstadd=false;
	
	FILE *pflistlog;
	FILE *pffilterlistlog;
	char buf[513];
	pflistlog=fopen("00_listlog.txt","r");
	pffilterlistlog=fopen("01_filterlistlog.txt","w");
	
	m_StrPathArray.clear();
	m_StrStartArray.clear();
	m_StrEndArray.clear();
	m_StrStartTimeArray.clear();
	m_StrEndTimeArray.clear();
	
	while(fgets(buf,512,pflistlog) !='\0')//如果開檔失敗執行這一行會出現segmentation fault (core dumped) 錯誤訊息
	{
		sscanf(buf,"%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],",chrPath,chrDate,chrStartTime,chrEndTime,chrStart,chrEnd);//csv檔案分析
		Date=QDate::fromString(chrDate,"yyyy-MM-dd");
		StartTime=QTime::fromString(chrStartTime,"hh:mm:ss");
		EndTime=QTime::fromString(chrEndTime,"hh:mm:ss");
		if(( (blnfirstadd==true) || (DateNow==Date) && (StartTime<=TimeNow) && (EndTime>TimeNow) ) || (DateNow<Date))
		{
			//現在日期如果等於清單日期+清單起始時間小於或等於現在時間+清單結束時間必須大於現在時間
			//現在日期如果小於清單日期則一律放行
			if(blnfirstadd==false)
			{
				//只有第一筆資料要重新計算切入時間
				if(DateNow==Date)
				{
					intAddSec= (TimeNow.hour()*3600+TimeNow.minute()*60+TimeNow.second())-(StartTime.hour()*3600+StartTime.minute()*60+StartTime.second());
					fprintf(pffilterlistlog,"AddSec01=%d;;",intAddSec);
					intAddSec+=atoi(chrStart);
					fprintf(pffilterlistlog,"AddSec02=%d\n",intAddSec);
					sprintf(chrStart,"%d",intAddSec);//數字轉字串					
				}
				blnfirstadd=true;
			}
			m_StrPathArray<<chrPath;
			sprintf(chrEnd,"%d",(atoi(chrEnd)-atoi(chrStart)));
			m_StrEndArray<<chrEnd;
			m_StrStartArray<<chrStart;
			
			m_StrStartTimeArray<<chrStartTime;
			m_StrEndTimeArray<<chrEndTime;
			/*
			//使用說明
			for (int i = 0; i < fonts.size(); ++i)
				cout << fonts.at(i).toLocal8Bit().constData() << endl;
 			*/
			fprintf(pffilterlistlog,"%s;%s;%s;%s;%s;%s\n",chrPath,chrDate,chrStartTime,chrEndTime,chrStart,chrEnd);
		}
	}
	fclose(pffilterlistlog);
	fclose(pflistlog);
}
void consoletimer::slotTimer()
{
	timer->stop();
	
	system("clear");
	QTime EndTime;
	QDate date = QDate::currentDate();//取得目前日期
	QTime time = QTime::currentTime();//取得目前時間
	QString StrDate=date.toString("yyyy/MM/dd");//QString StrDate=date.toString("yyyy-MM-dd");
	QString StrTime=time.toString("hh:mm:ss");//QString StrTime=time.toString("hh:mm:ss");
	QByteArray ArrDate,ArrTime;
	ArrDate=StrDate.toAscii();
	ArrTime=StrTime.toAscii();
	cout<<"目前時間："<<ArrDate.data()<<"\t"<<ArrTime.data()<<endl;
	FILE *pf;
	pf=fopen("time.log","a");
	fprintf(pf,"%s%s\n",ArrDate.data(),ArrTime.data());
	fclose(pf);

	cout<<"Config_"<<"PlayListUrl: "<<m_ArrPlayListUrl.data()<<"\t"<<endl;
	cout<<"Config_"<<"XMLFolderPath: "<<m_ArrXMLFolderPath.data()<<"\t"<<endl;
	cout<<"Config_"<<"ChangeFolderPath: "<<m_ArrChangeFolderPath.data()<<"\t"<<endl;
	switch(m_intStep)
	{
		case 0://下載清單2txt
			cout<<"Step 0: DownLoad List Xml"<<"\t"<<endl;
			DownloadXML2Txt();
			m_intStep++;//下一個步驟
			break;
		case 1:
			FilterListData();
			cout<<"Step 1: Filter List Data"<<"\t"<<endl;
			if(m_StrPathArray.size()>0)
			{
				m_intStep++;//下一個步驟
				m_intListIndex=0;
				m_StrMediaPath="";
				m_StrStartPoint="";
				m_StrEndPoint="";
				m_StrStartTime="";
				m_StrEndTime="";
			}
			else
			{
				m_intStep=0;//回去重抓
			}
			break;
		case 2:
			cout<<"Step 2: Prepare Output Multicast Signals..."<<"\t"<<endl;
			if(m_intListIndex<m_StrPathArray.size())
			{
				m_StrMediaPath=m_StrPathArray.at(m_intListIndex);
				m_StrStartPoint=m_StrStartArray.at(m_intListIndex);
				m_StrEndPoint=m_StrEndArray.at(m_intListIndex);
				m_StrStartTime=m_StrStartTimeArray.at(m_intListIndex);
				m_StrEndTime=m_StrEndTimeArray.at(m_intListIndex);
				m_intListIndex++;//將旗標移到下一筆，為下次取值作準備
				m_intStep++;//下一個步驟
				//ProThread.SetValue(m_StrMediaPath,m_StrStartPoint);
				//ProThread.start();
				m_arguments.clear();
				//-------------------------------
				/*
				//2014/10/17 shift 4s by jash 
				int intbuf=0;
				intbuf=m_StrStartPoint.toInt();
				if( (intbuf)>0 && (m_intListIndex>0) )
				{
					intbuf=intbuf-4;
					if(intbuf<0)
					{
						intbuf=0;
					}
					m_StrStartPoint=QString::number(intbuf);
				}
				*/
				//------------------------------
				m_arguments<<m_StrStartPoint;
				m_arguments<<m_StrEndPoint;
				m_arguments<<m_StrMediaPath;	
				m_proc=new QProcess();
				QString StrBashPath;
				StrBashPath=QDir::currentPath();
				StrBashPath+="/OutputSignals.sh";
				m_proc->start(StrBashPath,m_arguments);
			}
			else
			{
				m_intStep=0;//回去重抓
			}
			break;
		case 3:
			QByteArray ba00(m_StrMediaPath.toAscii());
			QByteArray ba01(m_StrStartTime.toAscii());
			QByteArray ba02(m_StrEndTime.toAscii());
			EndTime=QTime::fromString(m_StrEndTime,"hh:mm:ss");
			cout<<"Step 3_Start encode: "<<ba00.data()<<"...\t"<<"Start time "<<ba01.data()<<"\t"<<"End time "<<ba02.data()<<endl;
			cout<<"m_intListIndex="<<(m_intListIndex-1)<<endl;
			///*
			if(EndTime.toString("hh:mm:ss")== time.toString("hh:mm:ss"))//if(ProThread.isRunning())
			{
				//ProThread.quit();
				QString StrBashPath1;
				StrBashPath1=QDir::currentPath();
				StrBashPath1+="/Stop.sh";
				QProcess proc_stop;
				proc_stop.start(StrBashPath1);
				
				m_proc->kill();
				delete m_proc;
				m_proc='\0';
				QString buf;
				buf=EndTime.toString("hh:mm:ss");
				QByteArray ba03(buf.toAscii());
				buf= time.toString("hh:mm:ss");
				QByteArray ba04(buf.toAscii());
				cout<<"EndTime:"<<ba03.data()<<" == time:"<<ba04.data()<<endl;
				m_intStep=2;//Step 2: Prepare Output Multicast Signal
			}
			else
			{
				QString buf;
				buf=EndTime.toString("hh:mm:ss");
				QByteArray ba03(buf.toAscii());
				buf= time.toString("hh:mm:ss");
				QByteArray ba04(buf.toAscii());
				cout<<"EndTime:"<<ba03.data()<<" != time:"<<ba04.data()<<endl;
				m_intStep=3;
			}
			//*/
			break;
	}
	timer->start(10);
}
// place your code here

