#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	InitGUI();
	
	timer=new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(slotTimer()));
	
	ReadConfig();
	ClearDB();
	
	CreateLiveOutputBash();
	CreateDownloadListBash();
	DownloadXML2Txt();

	initDB();
	Txt2DB();
	SQLiteOpenReadAll();
	CreateVLCOutputBash();
	RunVLCOutputBash();
	
	timer->start(100);

}
DialogImpl::~DialogImpl()
{
	int n_pid = procOutput->pid();//sh pid [ vlc pid =sh pid+1 ]
	kill((n_pid+1), SIGINT);//kill vlc
	procOutput->terminate();//kill sh
	delete procOutput;
	
	if(blnredo==true)
	{
		//int n_pid = procInput->pid();//sh pid [ vlc pid =sh pid+1 ]
		//kill((n_pid+1), SIGINT);//kill vlc
		procInput->terminate();//kill sh
		delete procInput;		
	}
	db.close();
}
void DialogImpl::InitGUI()
{
	QString StrPath;
	StrPath=QDir::currentPath();
	StrPath+="/";
	this->setWindowTitle(StrPath);
	
	TableWidget=tableWidget;
	//設定顯示表格的相關參數
	TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改內容
	//TableWidget->setRowCount(10);
	TableWidget->setRowCount(0);
	TableWidget->setColumnCount(5);
	TableWidget->setColumnWidth(0,50);//設定寬度-id
	TableWidget->setColumnWidth(1,130);//Date
	TableWidget->setColumnWidth(2,200);//設定寬度-Start time
	TableWidget->setColumnWidth(3,300);//設定寬度-Work
	TableWidget->setColumnWidth(4,80);//設定寬度-Switch
	TableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//設置選擇模式，選擇單行
	TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //設置選擇行為，以行為單位
	header.append("id");
	header.append("Date");
	header.append("Start time");
	header.append("Work");
	header.append("Switch");
	TableWidget->setHorizontalHeaderLabels(header);
	
	fltAfterTime=0;
	blnDelayCheck=false;
	blnredo=false;
}
void DialogImpl::SQLiteOpenReadAll()
{
	//QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	//QFile FilecheckDB("playlist.db");
	//bool blncheckDB=false;
	//blncheckDB=FilecheckDB.exists();//判斷檔案是否存在
	//FilecheckDB.close();
	//db.setDatabaseName("playlist.db");//設定開啟的DB
	if (!blnDBOpen)
	{
		QMessageBox::warning(0, QObject::tr("Database Error"),db.lastError().text());
	}
	else
	{
		/*
		if(!blncheckDB)//如果DB不存在，則重新建立
		{
			QSqlQuery rs(db);
			rs.exec("CREATE TABLE Calendar (id INTEGER PRIMARY KEY,Date varchar(20), Start_Time varchar(10), Work varchar(500), Switch varchar(10))");
			QString StrBuf;
			StrBuf=QString("insert into Calendar(id,Date,Start_Time,Work,Switch) values(null,'%1', '%2', '%3', '%4')") .arg("YYYY-MM-DD") .arg("hhmmss") .arg("sample") .arg("off");
			QByteArray strSql=StrBuf.toAscii();
			QTextCodec *codec = QTextCodec::codecForName("UTF-8");
			QString string = codec->toUnicode(strSql);
			rs.exec(string);		
		}
		*/
		//***
		//取得DB資料
		QSqlQueryModel *model = new QSqlQueryModel;
		model->setQuery("SELECT * FROM Calendar");
		//***
		//將DB資料顯示出來
		TableWidget->clear();
		TableWidget->setRowCount(model->rowCount());
		TableWidget->setColumnCount(5);
		TableWidget->setHorizontalHeaderLabels(header);
		QString Strid,StrDate,StrTime,StrWork,StrSwitch;
		for (int i = 0; i < model->rowCount(); ++i)
		{
			QSqlRecord record = model->record(i);
			Strid = record.value(0).toString();
			StrDate = record.value(1).toString();
			StrTime = record.value(2).toString();
			StrWork = record.value(3).toString();
			StrSwitch = record.value(4).toString();
			QTableWidgetItem *itemid=new QTableWidgetItem("");
			QTableWidgetItem *itemDate=new QTableWidgetItem("");
			QTableWidgetItem *itemTime=new QTableWidgetItem("");
			QTableWidgetItem *itemWork=new QTableWidgetItem("");
			QTableWidgetItem *itemSwitch=new QTableWidgetItem("");
			itemid->setText(Strid);
			itemDate->setText(StrDate);
			itemTime->setText(StrTime);
			itemWork->setText(StrWork);
			itemSwitch->setText(StrSwitch);
			TableWidget->setItem(i, 0, itemid);
			TableWidget->setItem(i, 1, itemDate);
			TableWidget->setItem(i, 2, itemTime);
			TableWidget->setItem(i, 3, itemWork);
			TableWidget->setItem(i, 4, itemSwitch);
		}
		//***
		//db.close();
	}
}
void DialogImpl::ClearDB()
{
	QFile DelFile("playlist.db");
	DelFile.remove();	
}
void DialogImpl::ReadConfig()
{
	m_StrPlayListUrl="";
	m_StrLiveMulticastUrl="";
	m_StrMulticastPar01="";
	m_StrMulticastPar02="";
	m_StrLivePar="";
	m_StrLiveProcess="";
	m_StrMultiProcess="";
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
					m_StrLiveMulticastUrl=StrData;
					break;
				case 2:
					m_StrMulticastPar01=StrData;
					break;
				case 3:
					m_StrMulticastPar02=StrData;
					break;
				case 4:
					m_StrBaseUrl=StrData;
					break;
				case 5:
					m_StrLivePar=StrData;
					break;
				case 6:
					m_StrLiveProcess=StrData;
					break;
				case 7:
					m_StrMultiProcess=StrData;
					break;
			}
			intcount++;
		}
		docNode=docNode.nextSibling();
	}
	filelog.close();
	
	line_PlayListUrl->setText(m_StrPlayListUrl);
	line_LiveMulticastUrl->setText(m_StrLiveMulticastUrl);	
	line_MulticastPar01->setText(m_StrMulticastPar01);
	line_MulticastPar02->setText(m_StrMulticastPar02);
	
	delete doc;
}
void DialogImpl::CreateLiveOutputBash()
{
	QString StrFileName;
	QString StrData;
	QString StrBuf;
	
	StrFileName="LiveOutputBash.sh";
	m_argumentsLive.clear();
	
	StrData="#!/bin/bash";
	StrData+="\n";
	StrData+= "vlc -vvv ";
	if(m_StrLiveProcess!="ffmpeg")
	{
		StrBuf="-vvv ";
	}
	else
	{
		StrBuf="-i ";
	}
	
	StrData+=m_StrLiveMulticastUrl;
	StrBuf+=m_StrLiveMulticastUrl;
	
	StrData+= " ";
	StrBuf+=" ";
	
	StrData+=m_StrLivePar;
	StrBuf+=m_StrLivePar;
	
	StrData+="\n";
	StrBuf.replace("'","");
	
	m_argumentsLive=StrBuf.split(" ");
	//QByteArray byte = StrData.toAscii();
	QByteArray byte = StrBuf.toAscii();
	
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
void DialogImpl::CreateVLCOutputBash()
{
	QString StrFileName;
	QString StrData;
	
	StrFileName="VLCOutputBash.sh";
	
	StrData="#!/bin/bash";
	StrData+="\n";
	StrData+=m_StrMulticastPar02;
	StrData+="\n";
	
	QByteArray byte = StrData.toAscii();
	
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
void DialogImpl::CreateDownloadListBash()
{
	QString StrFileName;
	QString StrData;
	
	StrFileName="DownloadListBash.sh";
	
	StrData="#!/bin/bash";
	StrData+="\n";
	StrData+="wget \"";
	StrData+=m_StrPlayListUrl;
	StrData+="\"";
	StrData+=" -O list.xml";
	StrData+="\n";
	
	QByteArray byte = StrData.toAscii();
	
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
void  DialogImpl::CreateVODOutputBash(QString StrVODPath)
{
	QString StrFileName;
	QString StrData;
	QString StrBuf;
	StrFileName="VODOutputBash.sh";
	m_argumentsVOD.clear();
	m_StrMP4Path="";//2012-09-26 
	
	StrData="#!/bin/bash";
	StrData+="\n";
	StrData+="vlc -vvv ";
	///*
	if(m_StrMultiProcess!="ffmpeg")
	{
		StrBuf="-vvv ";
	}
	else
	{
		StrBuf="-i ";
	}
	//*/
	StrData+=StrVODPath;
	StrBuf+=StrVODPath;
	m_StrMP4Path=StrVODPath;//2012-09-26 
	
	StrData+=" ";
	StrBuf+=" ";
	
	StrData+=m_StrMulticastPar01;
	StrBuf+=m_StrMulticastPar01;
	
	StrData+="\n";
	StrBuf.replace("'","");
	
	m_argumentsVOD=StrBuf.split(" ");
	QByteArray byte = StrData.toAscii();
	
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
void DialogImpl::DownloadXML2Txt()
{
	QString Strshfile;
	QString StrPath;
	
	procXml2Txt=new QProcess();
	StrPath=QDir::currentPath();
	Strshfile=StrPath;
	Strshfile+="/";
	Strshfile+="DownloadListBash.sh";
	
	procXml2Txt->start(Strshfile);
	
	while(!procXml2Txt->waitForFinished())
	{
		continue;
	}
	delete procXml2Txt;
	
	docXml2Txt=new QDomDocument("list");
	QFile file("list.xml");
	QFile filelog("listlog.txt");
	StrPath=QDir::currentPath();
	filelog.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream TextStreamOut(&filelog);
	//TextStreamOut << "currentPath:"<< "\t" << StrPath <<"/" <<endl;
	
	if(!file.open(QIODevice::ReadOnly))
	{
		file.close();
		CreateBaseList();
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
		CreateBaseList();
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
				/*
				StrData=docElement.tagName();
				TextStreamOut << StrData << "\t";
				StrData=docElement.text();
				TextStreamOut << StrData << endl;
				*/
				switch(k)
				{
					case 0://file
						StrData=docElement.text();
						StrData.toLower();
						StrData.replace("5tv-m1/","/home/jash/m1/");
						StrData.replace("5tv-m2/","/home/jash/m2/");
						StrData.replace("5tv-m3/","/home/jash/m3/");
						StrData.replace("5tv-m4/","/home/jash/m4/");
						StrData.replace("smooth/","/m5/");//StrData.replace("smooth/","/m2/smooth/");
						StrData.replace("c:\\Base_1240k.mp4","./Base.mp4");
						StrData.replace("base",m_StrBaseUrl);
						break;
					case 2://date
						StrData+=",";
						StrData+=docElement.text();
						break;
					case 3://time
						StrData+=",";
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
void DialogImpl::Txt2DB()
{
	QDate date = QDate::currentDate();//取得目前日期
	QTime time = QTime::currentTime();//取得目前時間
	
	float fltTime;
	int intHour,intMinute,intSecond;//存放目前時間
	float fltDate;
	int intYear,intMonth,intDay;//存放目前日期
	date.getDate(&intYear,&intMonth,&intDay);
	fltDate=((intYear%100)*10000)+(intMonth*100)+intDay;
	
	intHour=time.hour();
	intMinute=time.minute();
	intSecond=time.second();
	fltTime=(intHour*10000)+(intMinute*100)+intSecond;

	//QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	//QFile FilecheckDB("playlist.db");
	//bool blncheckDB=false;
	//blncheckDB=FilecheckDB.exists();//判斷檔案是否存在
	//FilecheckDB.close();
	//db.setDatabaseName("playlist.db");//設定開啟的DB
	if (!blnDBOpen)
	{
		QMessageBox::warning(0, QObject::tr("Database Error"),db.lastError().text());
	}
	else
	{
		/*
		if(!blncheckDB)//如果DB不存在，則重新建立
		{
			QSqlQuery rs(db);
			rs.exec("CREATE TABLE Calendar (id INTEGER PRIMARY KEY,Date varchar(20), Start_Time varchar(10), Work varchar(500), Switch varchar(10))");
			QString StrBuf;
			StrBuf=QString("insert into Calendar(id,Date,Start_Time,Work,Switch) values(null,'%1', '%2', '%3', '%4')") .arg("YYYY-MM-DD") .arg("hhmmss") .arg("sample") .arg("off");
			QByteArray strSql=StrBuf.toAscii();
			QTextCodec *codec = QTextCodec::codecForName("UTF-8");
			QString string = codec->toUnicode(strSql);
			rs.exec(string);			
		}
		*/	
	}
	QString StrWork,StrDate,StrTime;
	char chrAll[350],chrWork[300],chrDate[10],chrTime[10];
	char chrBeforeAll[350],chrBeforeWork[300],chrBeforeDate[10],chrBeforeTime[10];
	bool blnadd=false;
	fstream a;
	FILE *pfTxt2DBlog;
	pfTxt2DBlog=fopen("Txt2DBlog.txt","w");
	float fltBuf01,fltBuf02;
	QString Str2flt;
	a.open("listlog.txt",ios::in);
	while(!a.eof())
	{
		a.getline(chrAll,350);
		sscanf(chrAll,"%[^','],%[^','],%[^','],",chrWork,chrDate,chrTime);
		
		fltBuf01=0.0;
		fltBuf02=0.0;
		Str2flt=chrDate;
		Str2flt=Str2flt.mid(2,8);
		fltBuf01=Str2flt.toFloat();
		Str2flt=chrTime;
		Str2flt=Str2flt.mid(0,6);
		fltBuf02=Str2flt.toFloat();
		
		if( (fltBuf01==fltDate) && (fltBuf02>=fltTime) )
		{
			if( (fltBuf02>fltTime) && (blnadd==false) )
			{
				blnadd=true;
				fprintf(pfTxt2DBlog,"%s\n",chrBeforeAll);
				
				QSqlQuery rs1(db);
				QString StrBuf1;
				StrBuf1=QString("insert into Calendar(id,Date,Start_Time,Work,Switch) values(null,'%1', '%2', '%3', '%4')") .arg(chrBeforeDate) .arg(chrBeforeTime) .arg(chrBeforeWork) .arg("on");
				QByteArray strSql1=StrBuf1.toAscii();
				QTextCodec *codec1 = QTextCodec::codecForName("UTF-8");
				QString string1 = codec1->toUnicode(strSql1);
				rs1.exec(string1);
			}
			fprintf(pfTxt2DBlog,"%s\n",chrAll);
			QSqlQuery rs2(db);
			QString StrBuf2;
			StrBuf2=QString("insert into Calendar(id,Date,Start_Time,Work,Switch) values(null,'%1', '%2', '%3', '%4')") .arg(chrDate) .arg(chrTime) .arg(chrWork) .arg("on");
			QByteArray strSql2=StrBuf2.toAscii();
			QTextCodec *codec2 = QTextCodec::codecForName("UTF-8");
			QString string2 = codec2->toUnicode(strSql2);
			rs2.exec(string2);
		}
		else
		{
			if(fltBuf01>fltDate)
			{
				/*
				fltBuf01=0.0;
				fltBuf02=0.0;
				Str2flt=chrDate;
				Str2flt=Str2flt.mid(2,8);
				fltBuf01=Str2flt.toInt();
				Str2flt=chrTime;
				Str2flt=Str2flt.mid(0,6);
				fltBuf02=Str2flt.toInt();
				*/
				QSqlQuery rs3(db);
				QString StrBuf3;
				StrBuf3=QString("insert into Calendar(id,Date,Start_Time,Work,Switch) values(null,'%1', '%2', '%3', '%4')") .arg(chrDate) .arg(chrTime) .arg(chrWork) .arg("on");
				QByteArray strSql3=StrBuf3.toAscii();
				QTextCodec *codec3 = QTextCodec::codecForName("UTF-8");
				QString string3 = codec3->toUnicode(strSql3);
				rs3.exec(string3);	
				fprintf(pfTxt2DBlog,"%s\n",chrAll);
			}
		}
		strcpy(chrBeforeAll,chrAll);
		strcpy(chrBeforeWork,chrWork);
		strcpy(chrBeforeDate,chrDate);
		strcpy(chrBeforeTime,chrTime);
		chrAll[0]='\0';
		chrWork[0]='\0';
		chrDate[0]='\0';
		chrTime[0]='\0';
	}
	fclose(pfTxt2DBlog);
	//db.close();
}
void DialogImpl::RunVLCOutputBash()
{
	QString Strshfile;
	QString StrPath;
	
	procOutput=new QProcess();
	StrPath=QDir::currentPath();
	Strshfile=StrPath;
	Strshfile+="/";
	Strshfile+="VLCOutputBash.sh";
	
	procOutput->start(Strshfile);
}
void DialogImpl::RunVLCInputBash(int intswitch)
{
	if(blnredo==true)
	{
		//int n_pid = procInput->pid();//sh pid [ vlc pid =sh pid+1 ]
		//kill((n_pid+1), SIGINT);//kill vlc
		procInput->kill();//kill sh
		delete procInput;	
	}
	blnredo=true;
	QString Strshfile;
	QString StrPath;
	QString StrVLC;
	
	procInput=new QProcess();
	StrPath=QDir::currentPath();
	Strshfile=StrPath;
	Strshfile+="/";
	StrVLC="vlc";
	//system("sleep 3");
	switch(intswitch)
	{
		case 0://VOD
			Strshfile+="ffmpeg_vlc.sh";//2012-09-26
			//StrVLC=m_StrMultiProcess;
			//procInput->start(StrVLC,m_argumentsVOD);
			m_argumentsVOD.clear();//2012-09-26
			m_argumentsVOD<<m_StrMP4Path;//2012-09-26
			procInput->start(Strshfile,m_argumentsVOD);//2012-09-26
			break;
		case 1://LIVE
			//Strshfile+="LiveOutputBash.sh";
			StrVLC=m_StrLiveProcess;
			procInput->start(StrVLC,m_argumentsLive);
			break;
	}
	//procInput->start(Strshfile);
	
}
void  DialogImpl::initDB()
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	QFile FilecheckDB("playlist.db");
	blncheckDB=false;
	blncheckDB=FilecheckDB.exists();//判斷檔案是否存在
	FilecheckDB.close();
	db.setDatabaseName("playlist.db");//設定開啟的DB	
	if (!db.open())
	{
		blnDBOpen=false;
		QMessageBox::warning(0, QObject::tr("Database Error"),db.lastError().text());
	}
	else
	{
		blnDBOpen=true;
		if(!blncheckDB)//如果DB不存在，則重新建立
		{
			QSqlQuery rs(db);
			rs.exec("CREATE TABLE Calendar (id INTEGER PRIMARY KEY,Date varchar(20), Start_Time varchar(10), Work varchar(500), Switch varchar(10))");
			QString StrBuf;
			StrBuf=QString("insert into Calendar(id,Date,Start_Time,Work,Switch) values(null,'%1', '%2', '%3', '%4')") .arg("YYYYMMDD") .arg("hhmmss") .arg("sample") .arg("off");
			QByteArray strSql=StrBuf.toAscii();
			QTextCodec *codec = QTextCodec::codecForName("UTF-8");
			QString string = codec->toUnicode(strSql);
			rs.exec(string);		
		}
	}
}
void DialogImpl::CreateBaseList()
{	
	QString StrBuf,StrData;
	QDate date = QDate::currentDate();//取得目前日期
	QFile filelog("listlog.txt");
	filelog.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream TextStreamOut(&filelog);
	int i,j;
	for(i=0;i<24;i++)
	{
		for(j=0;j<2;j++)
		{
			StrBuf="./Base.mp4,";
			StrData=StrBuf;
			StrBuf=date.toString("yyyyMMdd,");
			StrData+=StrBuf;
			//*
			if(j!=1)
			{
				StrBuf.sprintf( "%02d0000,", i);
			}
			else
			{
				StrBuf.sprintf( "%02d3000,", i);
			}
			//*/
			StrData+=StrBuf;
			TextStreamOut << StrData << endl;
		}
		StrData="";
	}
	filelog.close();
}
void DialogImpl::slotTimer()
{
	int intDBCount;
	QDate date = QDate::currentDate();//取得目前日期
	QTime time = QTime::currentTime();//取得目前時間
	lab_Date->setText(date.toString("yyyy-MM-dd"));
	lab_Time->setText(time.toString("hh:mm:ss"));
	
	float fltTime;
	int intHour,intMinute,intSecond;//存放目前時間
	float fltDate;
	int intYear,intMonth,intDay;//存放目前日期
	date.getDate(&intYear,&intMonth,&intDay);
	fltDate=((intYear%100)*10000)+(intMonth*100)+intDay;
	
	intHour=time.hour();
	intMinute=time.minute();
	intSecond=time.second();
	fltTime=(intHour*10000)+(intMinute*100)+intSecond;
	
	if(blnDelayCheck==true)
	{
		if(fltTime < fltAfterTime)
		{
			return;
		}

	}
	
	blnDelayCheck=false;
	bool blncheckDate=false;
	bool blncheckTime=false;
	//QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	//QFile FilecheckDB("playlist.db");
	//bool blncheckDB=false;
	//blncheckDB=FilecheckDB.exists();//判斷檔案是否存在
	//FilecheckDB.close();
	//db.setDatabaseName("playlist.db");//設定開啟的DB
	if (!blnDBOpen)
	{
		QMessageBox::warning(0, QObject::tr("Database Error"),db.lastError().text());
	}
	else
	{
		//***
		//取得DB資料
		FILE *pf;
		pf=fopen("Timerlog.txt","a");
		QSqlQueryModel *model = new QSqlQueryModel;
		model->setQuery("SELECT * FROM Calendar Where Switch='on'");
		//***
		//將SQL之後的資料顯示出來
		QString Strid,StrDate,StrTime,StrWork,StrSwitch;
		QByteArray Arrid,ArrDate,ArrTime,ArrWork,ArrSwitch;//strSql=StrBuf.toAscii();
		int intid;
		float fltDB_Date,fltDB_Time;
		
		intDBCount=model->rowCount();
		if(intDBCount==0)
		{
			timer->stop();
			db.close();
			QApplication::exit();
			ClearDB();
			return;
		}
		for (int i = 0; i < model->rowCount(); ++i)
		{
    		QSqlRecord record = model->record(i);
			Strid = record.value(0).toString();
			Arrid=Strid.toAscii();
			
			StrDate = record.value(1).toString();
			ArrDate=StrDate.toAscii();

			StrTime = record.value(2).toString();
			ArrTime = StrTime.toAscii();
			
			StrWork = record.value(3).toString();
			ArrWork=StrWork.toAscii();
			
			StrSwitch = record.value(5).toString();
			ArrSwitch=StrSwitch.toAscii();
			
			intid=Strid.toInt();
			blncheckDate=false;
			blncheckTime=false;
			
			StrDate=StrDate.mid(2,8);
			fltDB_Date=StrDate.toFloat();
			
			fltDB_Time=StrTime.toFloat();

			if(fltDB_Time <= fltTime)
			{
				blncheckTime=true;
			}
			if(fltDB_Date<=fltDate)
			{
				blncheckDate=true;
			}
			if((intid!=1) && (blncheckDate==true) && (blncheckTime==true))
			{
				QSqlQuery rs(db);
				blncheckDate=false;
				blncheckTime=false;
				QString StrSQLBuf=QString("update Calendar set Switch='off' where id='%1'").arg(Strid);
				QByteArray strSql=StrSQLBuf.toAscii();
				QTextCodec *codec = QTextCodec::codecForName("UTF-8");
				QString string = codec->toUnicode(strSql);
				rs.exec(string);
				//QMessageBox::warning(0, QObject::tr("You have a Note..."),StrWork);
				fprintf(pf,"%s,%s,%s,%s,%s\n",Arrid.data(),ArrDate.data(),ArrTime.data(),ArrWork.data(),ArrSwitch.data());
				if(StrWork!="live")
				{
					CreateVODOutputBash(StrWork);
					RunVLCInputBash(0);//VOD
				}
				else
				{
					RunVLCInputBash(1);//LIVE
				}
				blnDelayCheck=true;
			}
			else
			{
				fltAfterTime=fltDB_Time;
				QString StrAfterTime;
				StrAfterTime = QString::number(fltAfterTime);
				lab_AfterTime->setText(StrAfterTime);
				break;
			}
		}
		fclose(pf);
		//***
		//db.close();
		SQLiteOpenReadAll();
	}	
}
//
