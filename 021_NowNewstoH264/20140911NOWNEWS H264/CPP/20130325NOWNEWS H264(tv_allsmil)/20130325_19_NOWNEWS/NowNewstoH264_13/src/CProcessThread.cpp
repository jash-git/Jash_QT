#include "CProcessThread.h"

// place your code here
CProcessThread::CProcessThread()
{
	m_StrUID="";
	m_StrFileName="";
}
CProcessThread::CProcessThread(QString StrUID,QString StrFileName,QString StrSP,QString StrDP,struct ConfigData Config,long *m_lngmp4Size)
{
	m_StrUID=StrUID;
	m_StrFileName=StrFileName;
	m_ConfigDataBuf.StrEndPath=Config.StrEndPath;
	m_ConfigDataBuf.StrNetEndPath=Config.StrNetEndPath;
	m_ConfigDataBuf.StrNetStartPath=Config.StrNetStartPath;
	m_ConfigDataBuf.StrScriptPath=Config.StrScriptPath;
	m_ConfigDataBuf.StrStartPath=Config.StrStartPath;
	m_StrSP=StrSP;
	m_StrDP=StrDP;
	m_lngmp4FileSize=m_lngmp4Size;
}
void CProcessThread::setvalue(QString StrUID,QString StrFileName,QString StrSP,QString StrDP,struct ConfigData Config,long *m_lngmp4Size)
{
	m_StrUID=StrUID;
	m_StrFileName=StrFileName;
	m_ConfigDataBuf.StrEndPath=Config.StrEndPath;
	m_ConfigDataBuf.StrNetEndPath=Config.StrNetEndPath;
	m_ConfigDataBuf.StrNetStartPath=Config.StrNetStartPath;
	m_ConfigDataBuf.StrScriptPath=Config.StrScriptPath;
	m_ConfigDataBuf.StrStartPath=Config.StrStartPath;
	m_StrSP=StrSP;
	m_StrDP=StrDP;
	m_lngmp4FileSize=m_lngmp4Size;
}
void CProcessThread::run()
{
	bool blncopy,blndelete;
	QString StrBuf,StrBuf01,StrSrc,StrDec,StrStrScript;
	QStringList arguments;
	QString StrStrScript01;
	QStringList arguments01;
	QString StrStrScript02;
	QStringList arguments02;
	QString StrStrScript03;
	QStringList arguments03;
	QString StrStrScript04;
	QStringList arguments04;
	QString StrStrScript05;
	QStringList arguments05;
	QString StrStrScript06;
	QStringList arguments06;
	QString StrSmilName;
	QProcess *proc;
	QProcess *proc01;
	QProcess *proc02;
	QProcess *proc03;
	QProcess *proc04;
	QProcess *proc05;
	QProcess *proc06;	
	StrBuf=m_StrUID;
	StrBuf=m_StrFileName;
	StrBuf01=StrBuf;
	StrBuf=m_ConfigDataBuf.StrNetStartPath;
	StrSrc=StrBuf;
	StrSrc+=m_StrSP;
	StrSrc+=StrBuf01;
	StrBuf=m_ConfigDataBuf.StrStartPath;
	StrDec=StrBuf;
	StrDec+=StrBuf01;
	blncopy=QFile::copy(StrSrc,StrDec);
	//blncopy=true;//模擬用
	if(blncopy)
	{
		/////////////////////////////////////////////////////////
		//set bash_file	 by jash at 2010-09-07
		StrBuf=m_ConfigDataBuf.StrScriptPath;
		StrStrScript=StrBuf;
		StrStrScript=StrStrScript.mid(0,(StrStrScript.length()-3));
		StrStrScript=StrStrScript+"_24k.sh";
		//*******************************************************
		StrStrScript01=m_ConfigDataBuf.StrScriptPath;
		StrStrScript01=StrStrScript01.mid(0,(StrStrScript01.length()-3));
		StrStrScript01=StrStrScript01+"_110k.sh";
		//*******************************************************
		StrStrScript02=m_ConfigDataBuf.StrScriptPath;
		StrStrScript02=StrStrScript02.mid(0,(StrStrScript02.length()-3));
		StrStrScript02=StrStrScript02+"_200k.sh";
		//*******************************************************
		StrStrScript03=m_ConfigDataBuf.StrScriptPath;
		StrStrScript03=StrStrScript03.mid(0,(StrStrScript03.length()-3));
		StrStrScript03=StrStrScript03+"_400k.sh";
		//*******************************************************
		StrStrScript04=m_ConfigDataBuf.StrScriptPath;
		StrStrScript04=StrStrScript04.mid(0,(StrStrScript04.length()-3));
		StrStrScript04=StrStrScript04+"_600k.sh";
		//*******************************************************
		StrStrScript05=m_ConfigDataBuf.StrScriptPath;
		StrStrScript05=StrStrScript05.mid(0,(StrStrScript05.length()-3));
		StrStrScript05=StrStrScript05+"_800k.sh";
		//*******************************************************
		StrStrScript06=m_ConfigDataBuf.StrScriptPath;
		StrStrScript06=StrStrScript06.mid(0,(StrStrScript06.length()-3));
		StrStrScript06=StrStrScript06+"_1200k.sh";
		/////////////////////////////////////////////////////
		//create 64k mp4
		StrSrc=StrDec;
		//*************
		StrBuf=m_ConfigDataBuf.StrEndPath;
		StrDec=StrBuf;
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+=".mp4";
		//*************
		arguments << StrSrc;
		arguments << StrDec;
		///*
		proc=new QProcess();
		proc->start(StrStrScript,arguments);
		while(!proc->waitForFinished())
		{
			continue;
		}
		delete proc;
		//*/
		//**********
		StrSrc=StrDec;
		StrBuf=m_ConfigDataBuf.StrNetEndPath;
		StrDec=StrBuf;
		StrDec+=m_StrDP;
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+=".mp4";
		//blncopy=QFile::copy(StrSrc,StrDec);
		//************************************
		StrBuf=m_ConfigDataBuf.StrNetEndPath;
		StrDec=StrBuf;
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_64k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		
		StrDec="/home/chst01/avdata2/smooth/";
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_64k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		//***********
		blndelete=false;
		QFile FileSize(StrDec);
		*m_lngmp4FileSize=FileSize.size();
		blndelete=QFile::remove(StrSrc);
		/////////////////////////////////////////////
		//create 150k mp4
		StrBuf=m_ConfigDataBuf.StrStartPath;
		StrSrc=StrBuf;
		StrSrc+=StrBuf01;
		arguments01 << StrSrc;
		StrBuf=m_ConfigDataBuf.StrEndPath;
		StrDec=StrBuf;
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_150k.mp4";
		arguments01 << StrDec;
		///*
		proc01=new QProcess();
		proc01->start(StrStrScript01,arguments01);
		while(!proc01->waitForFinished())
		{
			continue;
		}
		delete proc01;
		StrSrc=StrDec;
		//************************************
		StrBuf=m_ConfigDataBuf.StrNetEndPath;
		StrDec=StrBuf;
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_150k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		
		StrDec="/home/chst01/avdata2/smooth/";
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_150k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		//************************************
		blndelete=false;
		blndelete=QFile::remove(StrSrc);
		/////////////////////////////////////////////
		//create 240k mp4
		StrBuf=m_ConfigDataBuf.StrStartPath;
		StrSrc=StrBuf;
		StrSrc+=StrBuf01;
		arguments02 << StrSrc;
		StrBuf=m_ConfigDataBuf.StrEndPath;
		StrDec=StrBuf;
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_240k.mp4";
		arguments02 << StrDec;
		///*
		proc02=new QProcess();
		proc02->start(StrStrScript02,arguments02);
		while(!proc02->waitForFinished())
		{
			continue;
		}
		delete proc02;
		StrSrc=StrDec;
		//************************************
		StrBuf=m_ConfigDataBuf.StrNetEndPath;
		StrDec=StrBuf;
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_240k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		
		StrDec="/home/chst01/avdata2/smooth/";
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_240k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		//************************************
		blndelete=false;
		blndelete=QFile::remove(StrSrc);
		/////////////////////////////////////////////
		//create 440k mp4
		StrBuf=m_ConfigDataBuf.StrStartPath;
		StrSrc=StrBuf;
		StrSrc+=StrBuf01;
		arguments03 << StrSrc;
		StrBuf=m_ConfigDataBuf.StrEndPath;
		StrDec=StrBuf;
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_440k.mp4";
		arguments03 << StrDec;
		///*
		proc03=new QProcess();
		proc03->start(StrStrScript03,arguments03);
		while(!proc03->waitForFinished())
		{
			continue;
		}
		delete proc03;
		StrSrc=StrDec;
		//************************************
		StrBuf=m_ConfigDataBuf.StrNetEndPath;
		StrDec=StrBuf;
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_440k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		
		StrDec="/home/chst01/avdata2/smooth/";
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_440k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		//************************************
		blndelete=false;
		blndelete=QFile::remove(StrSrc);
		/////////////////////////////////////////////
		//create 640k mp4
		StrBuf=m_ConfigDataBuf.StrStartPath;
		StrSrc=StrBuf;
		StrSrc+=StrBuf01;
		arguments04 << StrSrc;
		StrBuf=m_ConfigDataBuf.StrEndPath;
		StrDec=StrBuf;
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_640k.mp4";
		arguments04 << StrDec;
		///*
		proc04=new QProcess();
		proc04->start(StrStrScript04,arguments04);
		while(!proc04->waitForFinished())
		{
			continue;
		}
		delete proc04;
		StrSrc=StrDec;
		//************************************
		StrBuf=m_ConfigDataBuf.StrNetEndPath;
		StrDec=StrBuf;
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_640k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		
		StrDec="/home/chst01/avdata2/smooth/";
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_640k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		//************************************
		blndelete=false;
		blndelete=QFile::remove(StrSrc);
		/////////////////////////////////////////////
		//create 840k mp4
		StrBuf=m_ConfigDataBuf.StrStartPath;
		StrSrc=StrBuf;
		StrSrc+=StrBuf01;
		arguments05 << StrSrc;
		StrBuf=m_ConfigDataBuf.StrEndPath;
		StrDec=StrBuf;
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_840k.mp4";
		arguments05 << StrDec;
		///*
		proc05=new QProcess();
		proc05->start(StrStrScript05,arguments05);
		while(!proc05->waitForFinished())
		{
			continue;
		}
		delete proc05;
		StrSrc=StrDec;
		//************************************
		StrBuf=m_ConfigDataBuf.StrNetEndPath;
		StrDec=StrBuf;
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_840k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		
		StrDec="/home/chst01/avdata2/smooth/";
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_840k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		//************************************
		blndelete=false;
		blndelete=QFile::remove(StrSrc);
		/////////////////////////////////////////////
		//create 1240k mp4
		StrBuf=m_ConfigDataBuf.StrStartPath;
		StrSrc=StrBuf;
		StrSrc+=StrBuf01;
		arguments06 << StrSrc;
		StrBuf=m_ConfigDataBuf.StrEndPath;
		StrDec=StrBuf;
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_1240k.mp4";
		arguments06 << StrDec;
		///*
		proc06=new QProcess();
		proc06->start(StrStrScript06,arguments06);
		while(!proc06->waitForFinished())
		{
			continue;
		}
		delete proc06;
		StrSrc=StrDec;
		//************************************
		StrBuf=m_ConfigDataBuf.StrNetEndPath;
		StrDec=StrBuf;
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_1240k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		
		StrDec="/home/chst01/avdata2/smooth/";
		StrDec+=m_StrDP;
		StrDec+="videos/";
		StrDec+=StrBuf01.mid(0,(StrBuf01.length()-4));
		StrDec+="_1240k.mp4";
		blncopy=QFile::copy(StrSrc,StrDec);
		//************************************
		blndelete=false;
		blndelete=QFile::remove(StrSrc);
		/////////////////////////////////////////////
		//*/
		StrSmilName=m_ConfigDataBuf.StrNetEndPath;
		StrSmilName+=m_StrDP;
		//StrSmilName+="smil/";//base on wowza2.0
		StrSmilName+=StrBuf01.mid(0,(StrBuf01.length()-4));
		CreateSmilFile(StrSmilName,StrBuf01.mid(0,(StrBuf01.length()-4)));
		
		StrSmilName="/home/chst01/avdata2/smooth/";
		StrSmilName+=m_StrDP;
		//StrSmilName+="smil/";//base on wowza2.0
		StrSmilName+=StrBuf01.mid(0,(StrBuf01.length()-4));
		CreateSmilFile(StrSmilName,StrBuf01.mid(0,(StrBuf01.length()-4)));
		//************************************************
		StrBuf=m_ConfigDataBuf.StrStartPath;
		StrDec=StrBuf;
		StrDec+=StrBuf01;
		blndelete=false;
		blndelete=QFile::remove(StrDec);	
	}
	//sleep(30);//模擬用
}
void CProcessThread::CreateSmilFile(QString StrSmilName,QString FileName)
{
	QString StrSmilName01,StrSmilName02,StrSmilName03;
	QString StrSmilName04,StrSmilName05,StrSmilName06,StrSmilName07;
	QString StrSmilName08,StrSmilName09,StrSmilName10;
	StrSmilName01=StrSmilName+"_iphone_all.smil";
	StrSmilName02=StrSmilName+"_iphone_cell.smil";
	StrSmilName03=StrSmilName+"_iphone_wifi.smil";
	StrSmilName04=StrSmilName+"_ipad_cell.smil";
	StrSmilName05=StrSmilName+"_ipad_wifi.smil";
	StrSmilName06=StrSmilName+"_ipad_all.smil";
	StrSmilName07=StrSmilName+"_tv_sd.smil";
	StrSmilName08=StrSmilName+"_tv_all.smil";
	StrSmilName09=StrSmilName+"_usb.smil";
	StrSmilName10=StrSmilName+"_oui.smil";
	QString StrBuf,StrName,Strbitrate;
	QFile FileOut01(StrSmilName01);
	if(FileOut01.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
	{
		QTextStream out01(&FileOut01);
		out01.setCodec("UTF-8");
		StrBuf="<smil>\r\n";
		out01<<StrBuf;
		StrBuf="\t<head>\r\n";
		out01<<StrBuf;
		StrBuf="\t</head>\r\n";
		out01<<StrBuf;
		StrBuf="\t<body>\r\n";
		out01<<StrBuf;
		StrBuf="\t\t<switch>\r\n";
		out01<<StrBuf;
		///////////////////////
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_64k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="64000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out01<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_150k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="150000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out01<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_240k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="240000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out01<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_440k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="440000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out01<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_640k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="640000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out01<<StrBuf;
		//////////////////////////
		StrBuf="\t\t</switch>\r\n";
		out01<<StrBuf;
		StrBuf="\t</body>\r\n";
		out01<<StrBuf;
		StrBuf="</smil>\r\n";
		out01<<StrBuf;
		FileOut01.close();
	}	
	QFile FileOut02(StrSmilName02);
	if(FileOut02.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
	{
		QTextStream out02(&FileOut02);
		out02.setCodec("UTF-8");
		StrBuf="<smil>\r\n";
		out02<<StrBuf;
		StrBuf="\t<head>\r\n";
		out02<<StrBuf;
		StrBuf="\t</head>\r\n";
		out02<<StrBuf;
		StrBuf="\t<body>\r\n";
		out02<<StrBuf;
		StrBuf="\t\t<switch>\r\n";
		out02<<StrBuf;
		///////////////////////
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_64k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="64000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out02<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_150k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="150000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out02<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_240k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="240000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out02<<StrBuf;
		//////////////////////////
		StrBuf="\t\t</switch>\r\n";
		out02<<StrBuf;
		StrBuf="\t</body>\r\n";
		out02<<StrBuf;
		StrBuf="</smil>\r\n";
		out02<<StrBuf;
		FileOut02.close();
	}
	QFile FileOut03(StrSmilName03);
	if(FileOut03.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
	{
		QTextStream out03(&FileOut03);
		out03.setCodec("UTF-8");
		StrBuf="<smil>\r\n";
		out03<<StrBuf;
		StrBuf="\t<head>\r\n";
		out03<<StrBuf;
		StrBuf="\t</head>\r\n";
		out03<<StrBuf;
		StrBuf="\t<body>\r\n";
		out03<<StrBuf;
		StrBuf="\t\t<switch>\r\n";
		out03<<StrBuf;
		///////////////////////
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_440k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="440000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out03<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_640k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="640000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out03<<StrBuf;
		//////////////////////////
		StrBuf="\t\t</switch>\r\n";
		out03<<StrBuf;
		StrBuf="\t</body>\r\n";
		out03<<StrBuf;
		StrBuf="</smil>\r\n";
		out03<<StrBuf;
		FileOut03.close();
	}
	QFile FileOut04(StrSmilName04);
	if(FileOut04.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
	{
		QTextStream out04(&FileOut04);
		out04.setCodec("UTF-8");
		StrBuf="<smil>\r\n";
		out04<<StrBuf;
		StrBuf="\t<head>\r\n";
		out04<<StrBuf;
		StrBuf="\t</head>\r\n";
		out04<<StrBuf;
		StrBuf="\t<body>\r\n";
		out04<<StrBuf;
		StrBuf="\t\t<switch>\r\n";
		out04<<StrBuf;
		///////////////////////
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_150k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="150000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out04<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_240k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="240000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out04<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_440k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="440000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out04<<StrBuf;
		//////////////////////////
		StrBuf="\t\t</switch>\r\n";
		out04<<StrBuf;
		StrBuf="\t</body>\r\n";
		out04<<StrBuf;
		StrBuf="</smil>\r\n";
		out04<<StrBuf;
		FileOut04.close();
	}
	QFile FileOut05(StrSmilName05);
	if(FileOut05.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
	{
		QTextStream out05(&FileOut05);
		out05.setCodec("UTF-8");
		StrBuf="<smil>\r\n";
		out05<<StrBuf;
		StrBuf="\t<head>\r\n";
		out05<<StrBuf;
		StrBuf="\t</head>\r\n";
		out05<<StrBuf;
		StrBuf="\t<body>\r\n";
		out05<<StrBuf;
		StrBuf="\t\t<switch>\r\n";
		out05<<StrBuf;
		///////////////////////
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_640k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="640000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out05<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_840k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="840000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out05<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_1240k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="1240000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out05<<StrBuf;
		//////////////////////////
		StrBuf="\t\t</switch>\r\n";
		out05<<StrBuf;
		StrBuf="\t</body>\r\n";
		out05<<StrBuf;
		StrBuf="</smil>\r\n";
		out05<<StrBuf;
		FileOut05.close();
	}
	QFile FileOut06(StrSmilName06);
	if(FileOut06.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
	{
		QTextStream out06(&FileOut06);
		out06.setCodec("UTF-8");
		StrBuf="<smil>\r\n";
		out06<<StrBuf;
		StrBuf="\t<head>\r\n";
		out06<<StrBuf;
		StrBuf="\t</head>\r\n";
		out06<<StrBuf;
		StrBuf="\t<body>\r\n";
		out06<<StrBuf;
		StrBuf="\t\t<switch>\r\n";
		out06<<StrBuf;
		///////////////////////
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_64k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="64000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out06<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_150k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="150000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out06<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_240k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="240000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out06<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_440k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="440000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out06<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_640k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="640000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out06<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_840k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="840000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out06<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_1240k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="1240000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out06<<StrBuf;
		//////////////////////////
		StrBuf="\t\t</switch>\r\n";
		out06<<StrBuf;
		StrBuf="\t</body>\r\n";
		out06<<StrBuf;
		StrBuf="</smil>\r\n";
		out06<<StrBuf;
		FileOut06.close();
	}
	QFile FileOut07(StrSmilName07);
	if(FileOut07.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
	{
		QTextStream out07(&FileOut07);
		out07.setCodec("UTF-8");
		StrBuf="<smil>\r\n";
		out07<<StrBuf;
		StrBuf="\t<head>\r\n";
		out07<<StrBuf;
		StrBuf="\t</head>\r\n";
		out07<<StrBuf;
		StrBuf="\t<body>\r\n";
		out07<<StrBuf;
		StrBuf="\t\t<switch>\r\n";
		out07<<StrBuf;
		///////////////////////
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_640k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="640000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out07<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_840k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="840000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out07<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_1240k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="1240000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out07<<StrBuf;
		//////////////////////////
		StrBuf="\t\t</switch>\r\n";
		out07<<StrBuf;
		StrBuf="\t</body>\r\n";
		out07<<StrBuf;
		StrBuf="</smil>\r\n";
		out07<<StrBuf;
		FileOut07.close();
	}
	QFile FileOut08(StrSmilName08);
	if(FileOut08.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
	{
		QTextStream out08(&FileOut08);
		out08.setCodec("UTF-8");
		StrBuf="<smil>\r\n";
		out08<<StrBuf;
		StrBuf="\t<head>\r\n";
		out08<<StrBuf;
		StrBuf="\t</head>\r\n";
		out08<<StrBuf;
		StrBuf="\t<body>\r\n";
		out08<<StrBuf;
		StrBuf="\t\t<switch>\r\n";
		out08<<StrBuf;
		///////////////////////
		/*
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_64k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="64000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out08<<StrBuf;
		*/
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_150k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="150000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out08<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_240k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="240000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out08<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_440k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="440000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out08<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_640k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="640000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out08<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_840k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="840000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out08<<StrBuf;
		//*********
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_1240k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="1240000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out08<<StrBuf;
		//////////////////////////
		StrBuf="\t\t</switch>\r\n";
		out08<<StrBuf;
		StrBuf="\t</body>\r\n";
		out08<<StrBuf;
		StrBuf="</smil>\r\n";
		out08<<StrBuf;
		FileOut08.close();
	}
	QFile FileOut09(StrSmilName09);
	if(FileOut09.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
	{
		QTextStream out09(&FileOut09);
		out09.setCodec("UTF-8");
		StrBuf="<smil>\r\n";
		out09<<StrBuf;
		StrBuf="\t<head>\r\n";
		out09<<StrBuf;
		StrBuf="\t</head>\r\n";
		out09<<StrBuf;
		StrBuf="\t<body>\r\n";
		out09<<StrBuf;
		StrBuf="\t\t<switch>\r\n";
		out09<<StrBuf;
		//////////////////////////
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_640k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="640000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out09<<StrBuf;
		//////////////////////////
		StrBuf="\t\t</switch>\r\n";
		out09<<StrBuf;
		StrBuf="\t</body>\r\n";
		out09<<StrBuf;
		StrBuf="</smil>\r\n";
		out09<<StrBuf;
		FileOut09.close();
	}
	QFile FileOut10(StrSmilName10);
	if(FileOut10.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
	{
		QTextStream out10(&FileOut10);
		out10.setCodec("UTF-8");
		StrBuf="<smil>\r\n";
		out10<<StrBuf;
		StrBuf="\t<head>\r\n";
		out10<<StrBuf;
		StrBuf="\t</head>\r\n";
		out10<<StrBuf;
		StrBuf="\t<body>\r\n";
		out10<<StrBuf;
		StrBuf="\t\t<switch>\r\n";
		out10<<StrBuf;
		//////////////////////////
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="videos/";
		StrName+=FileName;
		StrName+="_1240k.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="1200000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out10<<StrBuf;
		//////////////////////////
		StrBuf="\t\t</switch>\r\n";
		out10<<StrBuf;
		StrBuf="\t</body>\r\n";
		out10<<StrBuf;
		StrBuf="</smil>\r\n";
		out10<<StrBuf;
		FileOut10.close();
	}
}