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
	QProcess *proc;
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
		StrBuf=m_ConfigDataBuf.StrScriptPath;
		StrStrScript=StrBuf;
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
		blncopy=QFile::copy(StrSrc,StrDec);
		blndelete=false;
		QFile FileSize(StrDec);
		*m_lngmp4FileSize=FileSize.size();
		blndelete=QFile::remove(StrSrc);
		//***********
		StrBuf=m_ConfigDataBuf.StrStartPath;
		StrDec=StrBuf;
		StrDec+=StrBuf01;
		blndelete=false;
		blndelete=QFile::remove(StrDec);	
	}
	//sleep(30);//模擬用
}