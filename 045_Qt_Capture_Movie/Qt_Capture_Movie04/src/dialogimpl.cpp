#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QWidget(parent, f)
{
	setupUi(this);
	mapButVideo=ButVideo;
	m_intTimerSwitch=0;
	m_intImageCount=-1;
	m_StrFileName="";
	m_blnclick=false;
	timer01=new QTimer(this);
	m_StrCurrentPath=QDir::currentPath();
	
	QString Strpath;
	Strpath=m_StrCurrentPath+"/png";
	DeleteDirectory(Strpath);
	
	QDir Dirmkr(Strpath);
	Dirmkr.mkpath(Strpath);
	connect(timer01,SIGNAL(timeout()),this,SLOT(slotTimer()));
}
void DialogImpl::slotCapture01()
{
	this->setWindowState(Qt::WindowMinimized);
	m_intTimerSwitch=1;
	timer01->start(1000);
}
void DialogImpl::slotVideo()
{
	if(!m_blnclick)
	{
		QString Strpath;
		Strpath=m_StrCurrentPath+"/png";
		DeleteDirectory(Strpath);
		
		QDir Dirmkr(Strpath);
		Dirmkr.mkpath(Strpath);
	
		m_intTimerSwitch=2;
		this->setWindowState(Qt::WindowMinimized);
		mapButVideo->setText("Stop Video");
		m_intImageCount=-1;
		timer01->start(3);
	}
	else
	{
		mapButVideo->setEnabled(false);
		m_intTimerSwitch=3;
		timer01->stop();
		CreateRunBash();
		mapButVideo->setText("Waiting...");
	}
	m_blnclick=!m_blnclick;
}
bool DialogImpl::CopyDirectory(const QString source, const QString destination, const bool override) 
{
 
	QDir directory(source);
	bool error = false;
 
	if (!directory.exists()) 
	{
		return false;
	}
 
 
	QStringList files = directory.entryList(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden);
 
 
	QList<QString>::iterator f = files.begin();
 
 
	for (; f != files.end(); ++f) 
	{
		QString filePath = QDir::convertSeparators(directory.path() + '/' + (*f));
		QString dPath = destination + "/" + directory.relativeFilePath(filePath);
		QFileInfo fi(filePath);
		if (fi.isFile() || fi.isSymLink())
		{
			if (override)
			{
				QFile::setPermissions(dPath, QFile::WriteOwner);
			}
			QFile::copy(filePath, dPath);
 
 
		}
		else if (fi.isDir())
		{
 
			QDir ddir(dPath);
			ddir.mkpath(dPath);
			if (!CopyDirectory(filePath, dPath, override))
			{
				error = true;
			}
		}
 
 
	}
 
 
	return !error;
}
bool DialogImpl::DeleteDirectory(QString StrPath)
{
	QDir directory(StrPath);
 
	if (!directory.exists()) 
	{
		return true;
	}
	QStringList files = directory.entryList(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden);
	QList<QString>::iterator f = files.begin();	
	bool error = false; 
	for (; f != files.end(); ++f) 
	{
		QString filePath = QDir::convertSeparators(directory.path() + '/' + (*f));
		QFileInfo fi(filePath);
		if (fi.isFile() || fi.isSymLink())
		{
			QFile::setPermissions(filePath, QFile::WriteOwner);
			if (!QFile::remove(filePath)) 
			{
				error = true;
			}
		}
		else if (fi.isDir())
		{
			if (!DeleteDirectory(filePath));
			{
				error = true;
			}
		}
	}
	if(!directory.rmdir(QDir::convertSeparators(directory.path()))) 
	{

		error = true;
	} 
	return !error;	
}
void DialogImpl::CreateRunBash()
{
	QString Str01;
	QString StrFileName;
	QDate date=QDate::currentDate();
	QTime time = QTime::currentTime();
	QString StrBuf;
	StrFileName=m_StrCurrentPath+"/callffmpeg.sh";
	QFile destFile(StrFileName);
	StrBuf="/"+date.toString("yyyyMMdd")+time.toString("hhmmss");
	StrBuf+=".avi";
	//Str01="ffmpeg -r 3 -f image2 -i /path/to/image/directory/prefix%d.jpg /path/to/destination.avi"
	Str01="ffmpeg -r 3 -f image2 -i ";
	Str01+=m_StrCurrentPath+"/png/";
	Str01+="%d.png ";
	Str01+=m_StrCurrentPath;
	Str01+=StrBuf;
	QByteArray byte = Str01.toAscii();
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
	m_cmd=new QProcess();
	m_cmd->start(StrFileName);
	timer01->start(1000);
}
void DialogImpl::slotTimer()
{
	m_StrFileName=m_StrCurrentPath+"/png/";
	QString StrNumBuf;
	switch(m_intTimerSwitch)
	{
		case 1:
			timer01->stop();
			m_StrFileName=m_StrFileName+"0.png";
			Pixmap_saveimage= QPixmap::grabWindow(QApplication::desktop()->winId());
			Pixmap_saveimage.save(m_StrFileName, "PNG");
			this->setWindowState(Qt::WindowActive);	
			break;
		case 2:
			//timer01->stop();
			m_intImageCount++;
			m_StrFileName=m_StrFileName+StrNumBuf.setNum(m_intImageCount);
			m_StrFileName=m_StrFileName+".png";
			Pixmap_saveimage= QPixmap::grabWindow(QApplication::desktop()->winId());
			Pixmap_saveimage.save(m_StrFileName, "PNG");
			//timer01->start(3);
			break;
		case 3:
			if(m_cmd->waitForFinished())
			{
				timer01->stop();
				delete m_cmd;
				mapButVideo->setText("Start Video");
				mapButVideo->setEnabled(true);
			}
			break;
	}	
}
//
