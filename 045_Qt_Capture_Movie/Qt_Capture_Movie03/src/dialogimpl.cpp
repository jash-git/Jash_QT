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
		m_intTimerSwitch=2;
		this->setWindowState(Qt::WindowMinimized);
		mapButVideo->setText("Stop Video");
		timer01->start(3);
	}
	else
	{
		timer01->stop();
		mapButVideo->setText("Start Video");
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
	}	
}
//
