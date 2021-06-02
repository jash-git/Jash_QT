#include "dialogimpl.h"
//
//DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
//	: QDialog(parent, f)
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f)
	: QWidget(parent, f)
{
	setupUi(this);
	timer1=new QTimer(this);
	HttpGetObj=new CHttpGet();
	m_blnkeeplive=false;
	WView00=webView00;
	WView01=webView01;
	LineEdit00=lineEdit00;
	LineEdit01=lineEdit01;
	LineEdit02=lineEdit02;
	LineEdit03=lineEdit03;
	LineEdit04=lineEdit04;
	WPage00=WView00->page();
	WFrame00=WPage00->mainFrame();
	ReadConfigXml();
	m_intStep=0;
	m_lngmp4Size=0;
	QObject::connect(HttpGetObj, SIGNAL(done()), this, SLOT(slotReadNodeList()));
	QObject::connect(timer1,SIGNAL(timeout()),this,SLOT(slotTimer1()));
	timer1->start(3000);//程式進入點
}
//
DialogImpl::~DialogImpl()
{
	delete timer1;
	delete doc1;
}
void DialogImpl::slotTimer1()
{
	QString StrBuf;
	QString StrDateBuf;
	QString StrDateBuf1;
	QString StrDataBuf;
	QString StrUID;
	QString StrSP;
	QString StrDP;	
	QString StrFileName;
	QUrl url1;
	QDate DateNow;
	switch(m_intStep)
	{
		case 0:
			LineEdit00->setText("0:下載清單,KeepLive");
			LineEdit01->setText("0");
			timer1->stop();
			DateNow=QDate::currentDate();
			StrDateBuf.sprintf( "%4d-",DateNow.year());//DateNow.month()-DateNow.day()
			StrDateBuf1="";	
			if(DateNow.month()>9)
			{
				StrDateBuf1.sprintf( "%2d-",DateNow.month());
			}
			else
			{
				StrDateBuf1.sprintf( "0%d-",DateNow.month());
			}
			StrDateBuf=StrDateBuf+StrDateBuf1;
			StrDateBuf1="";
			if(DateNow.day()>9)
			{
				StrDateBuf1.sprintf( "%2d",DateNow.day());
			}
			else
			{
				StrDateBuf1.sprintf( "0%d",DateNow.day());
			}
			StrDateBuf=StrDateBuf+StrDateBuf1;
			//QMessageBox::information(0,"Read NodeList",StrDateBuf);  
			//StrBuf="http://xpe5tv.tw-airnet.net/cgi-php/media_transform2.php?op=get_nownews&media_type=h264&datetime=";
			StrBuf="http://xpe5tv.5tv.pri/cgi-php/media_transform2.php?op=get_nownews&media_type=h264&datetime=";
			StrBuf=StrBuf+StrDateBuf;
			url1.setUrl(StrBuf);
			WView00->load(url1);
			KeepLiveFun();
			break;
		case 1:
			timer1->stop();
			LineEdit00->setText("1:建立執行序,執行轉檔...");
			StrDataBuf.sprintf("%ld",m_lngWMVAmount);
			LineEdit01->setText(StrDataBuf);
			StrDataBuf.sprintf("%ld",(m_lngWMVCount+1));
			LineEdit02->setText(StrDataBuf);
			StrUID=StrListid.at(m_lngWMVCount);
			LineEdit03->setText(StrUID);
			StrFileName=StrListFileName.at(m_lngWMVCount);
			StrSP=StrListSP.at(m_lngWMVCount);
			StrDP=StrListDP.at(m_lngWMVCount);
			LineEdit04->setText(StrFileName);
			ProThread.setvalue(StrUID,StrFileName,StrSP,StrDP,m_ConfigDataBuf,&m_lngmp4Size);
			m_intStep=2;
			ProThread.start();
			timer1->start(3000);
			break;
		case 2:
			timer1->stop();
			LineEdit00->setText("2：KeepLive,等待轉檔...");
			if(ProThread.isRunning())
			{
				m_intStep=2;
				m_lngKeepLiveCount++;
				if(m_lngKeepLiveCount>30)
				{
					KeepLiveFun();
					m_lngKeepLiveCount=0;
				}
			}
			else
			{
				m_intStep=3;
				m_lngKeepLiveCount=0;
			}
			timer1->start(1000);
			break;
		case 3:
			timer1->stop();
			LineEdit00->setText("3：回報轉檔結果...");
			m_intStep=4;
			//KeepLiveFun();
			StrUID=StrListid.at(m_lngWMVCount);
			if(m_lngmp4Size>0)
			{
				UpdateDBFun(StrUID);
				m_lngmp4Size=0;
			}
			timer1->start(3000);
			break;
		case 4:
			timer1->stop();
			LineEdit00->setText("4：判斷有無下一部轉檔...");
			m_lngWMVCount++;
			if(m_lngWMVCount < m_lngWMVAmount)
			{
				m_intStep=1;
			}
			else
			{
				m_intStep=0;
				UpdateNOCFun();
				//QApplication::quit();//模擬用
			}
			timer1->start(3000);
			break;
	}
    	
}
void DialogImpl::UpdateNOCFun()
{
	QString StrBuf,StrCount;
	QUrl url1;
	StrCount.setNum(m_lngWMVAmount);
	StrBuf="http://noc.tw-airnet.net/monitor/wService.aspx?OP=SetServiceStatusByID&ServiceID=325&Status=0&Value=";
	StrBuf=StrBuf+StrCount;
	StrBuf=StrBuf+"&Memo=TESTTEST";
	url1.setUrl(StrBuf);
	WView01->setUrl(url1);	
}
void DialogImpl::KeepLiveFun()
{
	QUrl url1;
	QString StrUrl;
	if(!m_blnkeeplive)
	{
		StrUrl="http://noc.tw-airnet.net/monitor/wService.aspx?OP=KeepaLive&ServiceID=325";
		url1.setUrl(StrUrl);
	}
	else
	{
		StrUrl="http://noc.tw-airnet.net/monitor/wService.aspx?OP=GetServiceStatusByID&ServiceID=325";
		url1.setUrl(StrUrl);		
	}
	WView01->setUrl(url1);
	m_blnkeeplive=!m_blnkeeplive;
}
void DialogImpl::UpdateDBFun(QString StrId)
{
	QUrl url1;
	QString StrUrl;
	//StrUrl="http://xpe5tv.tw-airnet.net/cgi-php/media_transform2.php?op=nownews_write2db&media_type=h264&mi_id=";
	StrUrl="http://xpe5tv.5tv.pri/cgi-php/media_transform2.php?op=nownews_write2db&media_type=h264&mi_id=";
	StrUrl+=StrId;
	url1.setUrl(StrUrl);
	WView01->setUrl(url1);
}
void DialogImpl::ReadConfigXml()
{
	QString StrCurrentPath;
	StrCurrentPath=QDir::currentPath();
	StrCurrentPath=StrCurrentPath+"/";
	QFile FileXml("Config.xml");
	FileXml.open(QIODevice::ReadOnly);
	configdoc=new QDomDocument("Config");
	configdoc->setContent(&FileXml);
	FileXml.close();
	QDomElement domElem=configdoc->documentElement();
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
					m_ConfigDataBuf.StrScriptPath=StrCurrentPath+StrData;
					break;
				case 2:
					m_ConfigDataBuf.StrNetEndPath=StrData;
					break;
				case 3:
					m_ConfigDataBuf.StrNetStartPath=StrData;
					break;
				case 4:
					m_ConfigDataBuf.StrStartPath=StrData;
					break;
				case 5:
					m_ConfigDataBuf.StrEndPath=StrData;
					break;
			};
		}
		domNode=domNode.nextSibling();
	}
}
void DialogImpl::slotReadNodeList()
{
	//sleepthread.msleep(10000);
	///*//因模擬,先暫停下載存檔
	QString StrWebBuf=WFrame00->toHtml();
	QFile filexml("123.xml");
	filexml.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream Textxml(&filexml);
	Textxml << StrWebBuf;
	filexml.close();
	//*/
	StrListid.clear();
	StrListFileName.clear();
	StrListFileSize.clear();
	doc1=new QDomDocument("123");
	QFile file("123.xml");

	QString StrPath;
	StrPath=QDir::currentPath();
	if(doc1->setContent(&file))
	{
		file.close();
	}
	QString StrBuf;
	StrBuf="Items";
	int i,j;
	int k,l;
	i=0;
	k=0;
	QDomElement docElem=doc1->documentElement();
	QDomNode docNoderoot=docElem.firstChild();
	QDomNode docNode1;
	QDomNode docNode2;
	QDomNodeList docNodeList2;
	QDomElement docElement;
	QString StrData;
	j=0;
	while(!docNoderoot.isNull())
	{
		//docNode1=docNodeList1.at(i);
		j++;
		docNodeList2=docNoderoot.childNodes();//docNode1.childNodes();
		k=0;
		l=docNodeList2.count();
		for(k=0;k<l;k++)
		{
			docNode2=docNodeList2.at(k);
			docElement=docNode2.toElement();
			if(!docElement.isNull())
			{
				StrData=docElement.tagName();
				//TextStreamOut << StrData << "\t";
				StrData=docElement.text();
				//TextStreamOut << StrData << endl;
				if(k==0)
				{
					// StrListid,StrListFileName,StrListFileSize
					StrListid << StrData;
				}
				if(k==2)
				{
					//StrListSP,StrListDP
					StrListSP << StrData;
				}
				if(k==3)
				{
					// StrListid,StrListFileName,StrListFileSize
					StrListFileName << StrData;
				}
				if(k==4)
				{
					// StrListid,StrListFileName,StrListFileSize
					StrListFileSize << StrData;
				}
				if(k==7)
				{
					//StrListSP,StrListDP
					StrListDP << StrData;
				}
			}
		}
		docNoderoot=docNoderoot.nextSibling();
		//TextStreamOut << "///////////////////////////" << endl;
	}
	//QMessageBox::information(0,"",QString("%1").arg(j));
	//filelog.close();
	//////////////////////////
	QFile fileListlog("321.txt");
	fileListlog.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream TextStreamListlog(&fileListlog);
	i=0;
	j=StrListFileSize.size(); 
	for(i=0;i<j;i++)
	{
		//StrListid,StrListFileName,StrListFileSize
		 StrData=StrListid.at(i);
		 TextStreamListlog << StrData << "\t";
		 StrData=StrListFileName.at(i);
		 TextStreamListlog << StrData << "\t";
		 StrData=StrListFileSize.at(i);
		 TextStreamListlog << StrData << "\n";
	}
	fileListlog.close();
	m_lngWMVAmount=0;
	m_lngWMVCount=0;
	m_lngKeepLiveCount=0;
	if(j>0)
	{
		m_lngWMVAmount=j;
		m_intStep=1;
	}
	else
	{
		m_lngWMVAmount=0;
		m_intStep=0;
	}
	timer1->start(3000);	
	//QMessageBox::information(0,"Read NodeList","OK");
}
