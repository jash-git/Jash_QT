#include "CProcessThread.h"

// place your code here
CProcessThread::CProcessThread()
{
	m_StrDesFileName="";
	m_StrSouFileName="";
	m_StrDesFolder="";
	m_StrSouFolder="";
}
CProcessThread::CProcessThread(QString StrSouFolder,QString StrDesFolder,QString StrDesFileName,QString StrSouFileName,struct ConfigData Config,qint64 *m_lngmp4Size)
{
	m_StrSouFolder=StrSouFolder;
	m_StrDesFolder=StrDesFolder;
	m_StrDesFileName=StrDesFileName;
	m_StrSouFileName=StrSouFileName;
	m_ConfigDataBuf.StrEndPath=Config.StrEndPath;
	m_ConfigDataBuf.StrNetEndPath=Config.StrNetEndPath;
	m_ConfigDataBuf.StrNetStartPath=Config.StrNetStartPath;
	m_ConfigDataBuf.StrScriptPath=Config.StrScriptPath;
	m_ConfigDataBuf.StrStartPath=Config.StrStartPath;
	m_lngmp4FileSize=m_lngmp4Size;
}
void CProcessThread::setvalue(QString StrSouFolder,QString StrDesFolder,QString StrDesFileName,QString StrSouFileName,struct ConfigData Config,qint64 *m_lngmp4Size)
{
	m_StrSouFolder=StrSouFolder;
	m_StrDesFolder=StrDesFolder;
	m_StrDesFileName=StrDesFileName;
	m_StrSouFileName=StrSouFileName;
	m_ConfigDataBuf.StrEndPath=Config.StrEndPath;
	m_ConfigDataBuf.StrNetEndPath=Config.StrNetEndPath;
	m_ConfigDataBuf.StrNetStartPath=Config.StrNetStartPath;
	m_ConfigDataBuf.StrScriptPath=Config.StrScriptPath;
	m_ConfigDataBuf.StrStartPath=Config.StrStartPath;
	m_lngmp4FileSize=m_lngmp4Size;
}
void CProcessThread::run()
{
	bool blncopy,blndelete;
	QString StrBuf,StrBuf01,StrSrc,StrDec,StrStrScript;
	QStringList arguments;
	QProcess *proc;
	StrSrc=m_ConfigDataBuf.StrNetStartPath+m_StrSouFolder+m_StrSouFileName;
	StrDec=m_ConfigDataBuf.StrStartPath+m_StrSouFileName;
	QFile Filecheck;
	Filecheck.setFileName(StrDec);
	if(Filecheck.exists())
	{
		blncopy=true;
	}
	else
	{
		blncopy=QFile::copy(StrSrc,StrDec);
	}
	//blncopy=true;//模擬用
	if(blncopy)
	{
		StrBuf=m_ConfigDataBuf.StrScriptPath;
		StrStrScript=StrBuf;
		StrSrc=StrDec;
		//*************
		StrDec=m_ConfigDataBuf.StrEndPath+m_StrDesFileName;
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
		QString StrDir;
		StrDir=m_ConfigDataBuf.StrNetEndPath+m_StrDesFolder;
		QDir DirFolder(StrDir);
		if(!DirFolder.exists())
		{
			DirFolder.mkpath(StrDir);
		}
		StrDec=m_ConfigDataBuf.StrNetEndPath+m_StrDesFolder+m_StrDesFileName;
		blndelete=QFile::remove(StrDec);
		blncopy=QFile::copy(StrSrc,StrDec);
		blndelete=false;
		QFile FileSize(StrDec);
		*m_lngmp4FileSize=FileSize.size();
		blndelete=QFile::remove(StrSrc);
		//***********
		//StrDec=m_ConfigDataBuf.StrStartPath+m_StrSouFileName;
		//blndelete=false;
		//blndelete=QFile::remove(StrDec);	
	}
	else
	{
		*m_lngmp4FileSize=-1;
	}
	//sleep(30);//模擬用
}