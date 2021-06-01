#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	//init_start
	StrCurrentPath="";
	StrSHScript1="";//wmv2mp4
	StrSHScript2="";
	StrWMVFileList="";
	StrSourcePath="";
	StrEndPath="";
	QString StrFind="_";
	int intindex=0;	
	StrKName="";
	edit01=lineEdit01;
	edit02=lineEdit02;
	edit03=lineEdit03;
	edit04=lineEdit04;
	edit05=lineEdit05;
	edit06=lineEdit06;
	edit07=lineEdit07;
	//init end
	StrCurrentPath=QDir::currentPath();
	StrCurrentPath=StrCurrentPath+"/";
	//Get Xml start
	QFile FileXml("Config.xml");
	FileXml.open(QIODevice::ReadOnly);
	doc=new QDomDocument("Config");
	doc->setContent(&FileXml);
	FileXml.close();
	QDomElement domElem=doc->documentElement();
	QDomNode domNode=domElem.firstChild();
	FileXml.close();
	QString StrData;
	QDomElement domElement;
	int intcount=0;
	while(!domNode.isNull())
	{
		domElement=domNode.toElement();
		if(!domElement.isNull())
		{
			intcount++;
			StrData=domElement.text();
			switch(intcount)
			{
				case 1:
					intindex=StrData.indexOf(StrFind);
					if(intindex>0)
					{
						StrKName=StrData.mid(intindex,5);
					}
					else
					{
						StrKName="";
					}
					StrSHScript1=StrCurrentPath+StrData;//wmv2mp4
					break;
				case 2:
					StrSHScript2=StrCurrentPath+StrData;
					break;
				case 3:
					StrWMVFileList=StrCurrentPath+StrData;
					break;
				case 4:
					StrSourcePath=StrData;
					break;
				case 5:
					StrEndPath=StrData;
					break;
			};
		}
		domNode=domNode.nextSibling();
	}
	//Get Xml end
	//show Xml Data start
	edit01->setText(StrCurrentPath);
	edit02->setText(StrSHScript1);//wmv2mp4
	edit03->setText(StrSHScript2);
	edit04->setText(StrWMVFileList);
	edit05->setText(StrSourcePath);
	edit06->setText(StrEndPath);
	//show Xml Data end
	/*
	//Run ls2file.sh start
	QStringList StrListls2file;
	QProcess *procls2file;
	procls2file=new QProcess();
	StrListls2file << StrSourcePath;
	StrListls2file << StrWMVFileList;
	procls2file->start(StrSHScript2,StrListls2file);
	while(!procls2file->waitForFinished())
	{
		continue;
	}
	//Run ls2file.sh end
	*/
	timer=new QTimer(this);
	//timer->setSingleShot(true);
	connect(timer, SIGNAL(timeout()), this, SLOT(slot1()));
	timer->start(1000);
}
void DialogImpl::slot1()
{
	//Read listfile start
	timer->stop();
	int intcount=0;
	QString StrCount;
	QStringList StrListWMVFile;
	QString StrFileName;
	QString StrBuff;
	QString StrBuff1;
	QString StrWMVPath;
	QString StrMp4Path;
	char chrBuff[2048];
	QFile FileList(StrWMVFileList);
	FileList.open(QFile::ReadOnly);
	while(!FileList.atEnd())
	{
		intcount++;
		StrCount.setNum(intcount);
		edit07->setText(StrCount);
		FileList.readLine(chrBuff,sizeof(chrBuff));
		StrFileName=chrBuff;
		//StrWMVPath=StrSourcePath;
		//StrWMVPath=StrWMVPath+StrFileName.mid(0,(StrFileName.length()-5));
		StrWMVPath=StrFileName.mid(0,(StrFileName.length()-5));
		StrWMVPath=StrWMVPath+".wmv";
		////////////////////////////////////////////
		int i,j;
		j=StrFileName.length();
		StrBuff1="";
		for(i=j;i>0;i--)
		{
			StrBuff=StrFileName.mid(i,1);
			if(StrBuff!="/")
			{
				StrBuff1=StrBuff+StrBuff1;
			}
			else
			{
				break;
			}
		}
		StrMp4Path=StrEndPath;
		StrMp4Path=StrMp4Path+StrBuff1.mid(0,(StrBuff1.length()-5));
		StrMp4Path=StrMp4Path+StrKName;
		StrMp4Path=StrMp4Path+".mp4";
		QProcess *proc;
		QStringList arguments;
		proc=new QProcess();
		arguments <<StrWMVPath;
		arguments <<StrMp4Path;
		proc->start(StrSHScript1,arguments);
		while(!proc->waitForFinished())
		{
			continue;
		}
		delete proc;
		//wmv 2 mp4 end
		//Delete WMV start
		//QFile DeleteFile(StrWMVPath);
		//DeleteFile.remove();
		//Delete WMV end
	}
	//Read listfile end
	//callExe();
	QMessageBox msg;
	msg.setText("OK");
	msg.exec();
	QApplication::quit();	
}
void DialogImpl::callExe()
{
	QString StrPath;
	QProcess *cmd;
	StrPath=QDir::currentPath();
	StrPath=StrPath+"/";
	cmd=new QProcess();
	QString StrExeName;
	StrExeName=StrPath+"ShowWeb";
	cmd->start(StrExeName);
	while(!cmd->waitForFinished())
	{
		continue;	
	}
	delete cmd;	
}
//
