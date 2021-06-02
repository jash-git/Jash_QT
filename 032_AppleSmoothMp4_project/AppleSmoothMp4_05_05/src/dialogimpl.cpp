#include "dialogimpl.h"
#include <stdio.h>
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QWidget(parent, f)
{
	setupUi(this);
	WView00=webView00;
	WView01=webView01;
	LineEdit00=lineEdit00;
	LineEdit01=lineEdit01;
	LineEdit02=lineEdit02;
	LineEdit03=lineEdit03;
	LineEdit04=lineEdit04;
	TextEdit=textEdit;
	WPage00=WView00->page();
	WFrame00=WPage00->mainFrame();
	timer1=new QTimer(this);
	m_StrHostType="&";
	ReadConfigXml();
	m_intStep=0;;
	m_lngWMVAmount=0;
	m_lngWMVCount=0;
	m_timercount=0;
	m_Strsource_path="";
	m_Strsource_filename="";
	m_Strsmildestination_path="";
	m_Strsmildestination_filename="";
	QObject::connect(timer1,SIGNAL(timeout()),this,SLOT(slotTimer1()));
	WView01->setVisible(false);
	timer1->start(3000);//程式進入點
}
DialogImpl::~DialogImpl()
{
	delete [] encodeData01;
	delete [] smilData01;
}
void DialogImpl::slotTimer1()
{
	QString StrBuf;
	QString StrDateBuf1;
	QString StrDataBuf;
	QString StrUID;
	QString StrSP;
	QString StrDP;	
	QString StrFileName;
	QString Strvideo;
	long lngvideo;
	QString Straudio;
	long lngaudio;
	QString Strdimension;
	QString Strkeyframe;
	QString Strframe_rate;
	float fltaudio_sample_rate;
	QString Straudio_sample_rate;
	QString StrScriptPath;
	QUrl url1;
	QTime TimeNow;
	QString StrInfor,StrTextEdit;
	QString StrCurrentPath;
	StrCurrentPath=QDir::currentPath();
	StrCurrentPath=StrCurrentPath+"/";
	QString StrRemoveFile;
	QString StrTimeNow;
	TimeNow=QTime::currentTime();
	StrTimeNow=TimeNow.toString("H:m:s a");
	FILE *pf;
	QString Strlog;
	pf=fopen("AppleSmoothMp4.log","a");
	switch(m_intStep)
	{
		case 0:
			LineEdit00->setText("0:下載清單,KeepLive");
			LineEdit01->setText("0");
			timer1->stop();
			//StrBuf="http://encsrv.5tv.pri/enc/encoderSrv.aspx?OP=GetEncodeWork_New&EncType=0";
			StrBuf="http://encsrv.5tv.pri/wEncSrv.aspx?OP=GetEncodeWork&EncType=0";
			StrBuf=StrBuf+m_StrHostType;
			url1.setUrl(StrBuf);
			WView00->load(url1);
			Strlog=StrTimeNow+" - ";
			Strlog+=StrBuf;
			fprintf(pf,"%s\n",Strlog.toAscii().data());
			m_lngmp4Size=0;
			break;
		case 1:
			timer1->stop();
			//StrBuf="http://encsrv.5tv.pri/enc/encoderSrv.aspx?OP=Encoding_New&work_id=";
			StrBuf="http://encsrv.5tv.pri/wEncSrv.aspx?OP=Encoding&work_id=";
			StrBuf+=m_Strwork_id;
			m_lngmp4Size=0;
			url1.setUrl(StrBuf);
			if( m_lngWMVCount == 0)
			{
				WView01->load(url1);
				Strlog=StrTimeNow+" - ";
				Strlog+=StrBuf;
				fprintf(pf,"%s\n",Strlog.toAscii().data());
			}			
			LineEdit00->setText("1:建立執行序,執行轉檔...");
			StrDataBuf.sprintf("%ld",m_lngWMVAmount);
			LineEdit01->setText(StrDataBuf);
			StrDataBuf.sprintf("%ld",(m_lngWMVCount+1));
			LineEdit02->setText(StrDataBuf);
			StrUID.sprintf("%ld",m_lngWMVCount);
			LineEdit03->setText(StrUID);
			LineEdit04->setText(encodeData01[m_lngWMVCount].Strsource_filename);
			Strvideo=encodeData01[m_lngWMVCount].Strvideo_bitrate;
			lngvideo=Strvideo.toInt();
			lngvideo=lngvideo/1000;
			Strvideo.setNum(lngvideo);
			Strvideo=Strvideo+"k";
			Straudio=encodeData01[m_lngWMVCount].Straudio_bitrate;
			lngaudio=Straudio.toInt();
			lngaudio=lngaudio/1000;
			Straudio.setNum(lngaudio);
			Straudio=Straudio+"k";
			Strdimension=encodeData01[m_lngWMVCount].Strdimension;
			Strkeyframe=encodeData01[m_lngWMVCount].Strkeyframe;
			Strframe_rate=encodeData01[m_lngWMVCount].Strframe_rate;
			Straudio_sample_rate=encodeData01[m_lngWMVCount].Straudio_sample_rate;
			fltaudio_sample_rate=Straudio_sample_rate.toFloat();
			fltaudio_sample_rate*=1000;
			Straudio_sample_rate.setNum(fltaudio_sample_rate);
			//CreateBashScript(QString Strkeyframe,QString Strframe_rate,QString Straudio_sample_rate,QString Strvidio,QString Straudio,QString Strdimension)
			StrScriptPath=CreateBashScript(Strkeyframe,Strframe_rate,Straudio_sample_rate,Strvideo,Straudio,Strdimension);
			m_ConfigDataBuf.StrScriptPath=StrCurrentPath+StrScriptPath;
			//setvalue(QString StrSouFolder,QString StrDesFolder,QString StrDesFileName,QString StrSouFileName,struct ConfigData Config,long *m_lngmp4Size)
			ProThread.setvalue(encodeData01[m_lngWMVCount].Strsource_path,encodeData01[m_lngWMVCount].Strdestination_path,encodeData01[m_lngWMVCount].Strdestination_filename,encodeData01[m_lngWMVCount].Strsource_filename,m_ConfigDataBuf,&m_lngmp4Size);
			m_intStep=2;
			StrTextEdit=TextEdit->toPlainText();
			StrInfor="_start : ";
			StrInfor=StrTimeNow+StrInfor;
			StrInfor+=encodeData01[m_lngWMVCount].Strdestination_filename;
			StrInfor+="\n";
			StrTextEdit+=StrInfor;
			Strlog=StrInfor;
			fprintf(pf,"%s\n",Strlog.toAscii().data());			
			TextEdit->setText(StrTextEdit);
			ProThread.start();
			timer1->start(3000);
			break;
		case 2:
			timer1->stop();
			m_timercount++;
			LineEdit00->setText("2：KeepLive,轉檔中...");
			if(ProThread.isRunning())
			{
				m_intStep=2;
				//StrBuf="http://encsrv.5tv.pri/enc/encoderSrv.aspx?OP=KeepEncodeing&work_id=";
				StrBuf="http://encsrv.5tv.pri/wEncSrv.aspx?OP=KeepEncoding&work_id=";
				StrBuf+=m_Strwork_id;
				url1.setUrl(StrBuf);
				if(m_timercount>299)
				{
					WView01->load(url1);
					m_timercount=0;	
					Strlog=StrTimeNow+" - ";
					Strlog+=StrBuf;
					fprintf(pf,"%s\n",Strlog.toAscii().data());
				}
			}
			else
			{
				m_intStep=3;
				QMessageBox msg;
				if(m_lngmp4Size<=0)
				{
					msg.setText("轉檔失敗");
					msg.exec();
					Strlog="轉檔失敗";
					fprintf(pf,"%s\n",Strlog.toAscii().data());
					fclose(pf);
					QApplication::quit();
				}
				//m_lngKeepLiveCount=0;
			}
			timer1->start(1000);
			break;
		case 3:
			timer1->stop();
			LineEdit00->setText("3：判斷有無下一部轉檔...");
			StrTextEdit=TextEdit->toPlainText();
			StrInfor="_end : ";
			StrInfor=StrTimeNow+StrInfor;
			StrInfor+=encodeData01[m_lngWMVCount].Strdestination_filename;
			StrInfor+="\n";
			StrTextEdit+=StrInfor;
			TextEdit->setText(StrTextEdit);
			Strlog=StrInfor;
			fprintf(pf,"%s\n",Strlog.toAscii().data());		
			m_lngWMVCount++;
			if(m_lngWMVCount < m_lngWMVAmount)
			{
				m_intStep=1;
			}
			else
			{
				m_intStep=0;
				/*
 				//5-1版 後產生Smil的工作在web server上
				if(m_lngsmilCount>0)
				{
					CreateSmilFile();
				}
				*/
				StrRemoveFile=m_ConfigDataBuf.StrStartPath+encodeData01[0].Strsource_filename;
				QFile::remove(StrRemoveFile);	
				StrTextEdit="";
				TextEdit->setText(StrTextEdit);
				//StrBuf="http://encsrv.5tv.pri/enc/encoderSrv.aspx?OP=EncodeFinish_New&work_id=";
				StrBuf="http://encsrv.5tv.pri/wEncSrv.aspx?OP=EncodeFinish&work_id=";
				StrBuf+=m_Strwork_id;
				url1.setUrl(StrBuf);
				WView01->load(url1);
				Strlog=StrTimeNow+" - ";
				Strlog+=StrBuf;
				fprintf(pf,"%s\n",Strlog.toAscii().data());	
				//QApplication::quit();//模擬用
			}
			timer1->start(3000);
			break;
	}
	fclose(pf);
}
void DialogImpl::ReadConfigXml()
{
	QDomDocument *configdoc;
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
				case 6:
					m_StrHostType=m_StrHostType+StrData;
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
	StrWebBuf=WFrame00->toPlainText();
	QFile filexml("123.xml");
	filexml.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream Textxml(&filexml);
	Textxml << StrWebBuf;
	filexml.close();
	//////////////////////////////////
	QDomDocument *doc1;
	doc1=new QDomDocument("123");
	QFile file("123.xml");
	QString StrPath;
	StrPath=QDir::currentPath();
	file.open(QIODevice::ReadOnly);
	if(doc1->setContent(&file,true))
	{
		file.close();
	}
	QFile Filelog("123.txt");
	Filelog.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text);
	QTextStream out(&Filelog);
	QDomElement root = doc1->documentElement();
	//***********************************************
	QDomNodeList nodeList01 = root.elementsByTagName("work_id");
	QDomNodeList nodeList02;
	QDomNode DomNode01;
	QDomNode DomNode02;
	QDomElement docElement01;
	QString StrBuf01;
	int i,j;
	int k,l;
	j=nodeList01.count();
	for(i=0;i<j;i++)
	{
		DomNode01=nodeList01.at(i);
		docElement01=DomNode01.toElement();
		StrBuf01=docElement01.text();
		m_Strwork_id=StrBuf01;
		out<<StrBuf01;
		out<<"\n";
	}
	//**********************************************************
	nodeList01 = root.elementsByTagName("source_path");
	j=nodeList01.count();
	for(i=0;i<j;i++)
	{
		DomNode01=nodeList01.at(i);
		docElement01=DomNode01.toElement();
		StrBuf01=docElement01.text();
		StrBuf01=StrBuf01.mid(0,(StrBuf01.size()-1));
		m_Strsource_path=StrBuf01+"/";
		m_Strsource_path=m_Strsource_path.replace("\\","/");
		out<<m_Strsource_path;
		out<<"\n";
	}
	//**********************************************************
	nodeList01 = root.elementsByTagName("source_filename");
	j=nodeList01.count();
	for(i=0;i<j;i++)
	{
		DomNode01=nodeList01.at(i);
		docElement01=DomNode01.toElement();
		StrBuf01=docElement01.text();
		m_Strsource_filename=StrBuf01;
		out<<m_Strsource_filename;
		out<<"\n";
	}
	//**********************************************************
	nodeList01 = root.elementsByTagName("smil");
	j=nodeList01.count();
	m_lngsmilCount=j;
	smilData01=new struct smilData[j];
	for(i=0;i<j;i++)
	{
		m_Strsmildestination_path="";
		m_Strsmildestination_filename="";
		m_Strsmildvideoname="";
		DomNode01=nodeList01.at(i);
		nodeList02=DomNode01.childNodes();
		l=nodeList02.count();
		for(k=0;k<l;k++)
		{
			DomNode02=nodeList02.at(k);
			docElement01=DomNode02.toElement();
			StrBuf01=docElement01.text();
			switch(k)
			{
				case 0:
				StrBuf01=StrBuf01.mid(0,(StrBuf01.size()-1));
				m_Strsmildestination_path=StrBuf01+"/";
				m_Strsmildestination_path=m_Strsmildestination_path.replace("\\","/");
				smilData01[i].Strsmildestination_path=m_Strsmildestination_path;
				break;
				case 1:
				m_Strsmildestination_filename=StrBuf01;
				smilData01[i].Strsmildestination_filename=m_Strsmildestination_filename;
				break;
				default:
				m_Strsmildvideoname=StrBuf01;
				smilData01[i].StrListvideoname << m_Strsmildvideoname;
			}
			out<<StrBuf01;
			out<<"\n";
		}
	}
	out<<"**************\n";
	//**********************************************************
	nodeList01 = root.elementsByTagName("encode");
	j=nodeList01.count();
	m_lngWMVAmount=j;
	encodeData01=new struct encodeData[j];
	for(i=0;i<j;i++)
	{
		encodeData01[i].Strsource_path=m_Strsource_path;
		encodeData01[i].Strsource_filename=m_Strsource_filename;
		//encodeData01[i].Strsmildestination_path=m_Strsmildestination_path;
		//encodeData01[i].Strsmildestination_filename=m_Strsmildestination_filename;
		DomNode01=nodeList01.at(i);
		nodeList02=DomNode01.childNodes();
		l=nodeList02.count();
		for(k=0;k<l;k++)
		{
			DomNode02=nodeList02.at(k);
			docElement01=DomNode02.toElement();
			StrBuf01=docElement01.text();
			switch(k)
			{
				case 0:
				encodeData01[i].Strdimension=StrBuf01;
				break;
				case 1:
				encodeData01[i].Strvideo_bitrate=StrBuf01;
				break;
				case 2:
				encodeData01[i].Straudio_bitrate=StrBuf01;
				break;
				case 3:
				encodeData01[i].Straudio_sample_rate=StrBuf01;
				break;
				case 4:
				encodeData01[i].Strframe_rate=StrBuf01;
				break;
				case 5:
				encodeData01[i].Strkeyframe=StrBuf01;
				break;
				case 6:
				StrBuf01=StrBuf01.mid(0,(StrBuf01.size()-1));
				StrBuf01=StrBuf01+"/";
				StrBuf01=StrBuf01.replace("\\","/");
				encodeData01[i].Strdestination_path=StrBuf01;
				break;
				case 7:
				encodeData01[i].Strdestination_filename=StrBuf01;
				break;
			}
			out<<StrBuf01;
			out<<"\n";
		}
		out<<"**************\n";
	}
	Filelog.close();
	//**********************************************************
	if(m_lngWMVAmount>0)
	{
		
		m_intStep=1;
		m_lngWMVCount=0;
		timer1->start(3000);
	}
	else
	{
		m_lngWMVAmount=0;
		m_lngWMVCount=0;
		m_intStep=0;
		timer1->start(180000);
	}
}
QString DialogImpl::CreateBashScript(QString Strkeyframe,QString Strframe_rate,QString Straudio_sample_rate,QString Strvidio,QString Straudio,QString Strdimension)
{
	QString Str01,Str02,Str03,Str04;
	QString StrFileName;
	fstream a;
	QString StrData;
	char fg[700];
	a.open("SH_sample.dat",ios::in);
	Str02=Strvidio;
	while(!a.eof())
	{
		a.getline(fg,500);
		StrData=fg;
		StrData.replace("JL_vidio",Strvidio);
		StrData.replace("JL_keyframe",Strkeyframe);
		StrData.replace("JL_frame_rate",Strframe_rate);
		StrData.replace("JL_dimension",Strdimension);
		StrData.replace("JL_audio_sample_rate",Straudio_sample_rate);
		StrData.replace("JL_audio",Straudio);
		Str01+=StrData;
		Str01+="\n";
	}
	a.close();
	QByteArray byte = Str01.toAscii();
	StrFileName="test_";
	StrFileName+=Str02;
	StrFileName+=".sh";
	QFile destFile(StrFileName);
	if (destFile.open(QIODevice::WriteOnly))
	{
		struct stat statbuf;
		destFile.write(byte);
		destFile.close();
		stat(StrFileName.toAscii(), &statbuf);
		//¤@¦¸¥u¯à³]©w¤@­Ó­È
		//©Ò¥H´N³]©w§¹¤@­Ó¦Aor¤@­Ó
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
		return StrFileName;
	}
	StrFileName="";
	return StrFileName;
}
void DialogImpl::CreateSmilFile()
{
	int i,j;
	int n;
	QString StrSmilFile;
	QStringList StrListvideoname;
	for(i=0;i<m_lngsmilCount;i++)
	{
		StrSmilFile=m_ConfigDataBuf.StrNetEndPath+smilData01[i].Strsmildestination_path+smilData01[i].Strsmildestination_filename;
		QFile FileOut(StrSmilFile);
		QString StrBuf,StrName,Strbitrate;
		if(FileOut.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
		{
			QTextStream out(&FileOut);
			out.setCodec("UTF-8");
			StrBuf="<smil>\r\n";
			out<<StrBuf;
			StrBuf="\t<head>\r\n";
			out<<StrBuf;
			StrBuf="\t</head>\r\n";
			out<<StrBuf;
			StrBuf="\t<body>\r\n";
			out<<StrBuf;
			StrBuf="\t\t<switch>\r\n";
			out<<StrBuf;
			///////////////////////
			StrListvideoname=smilData01[i].StrListvideoname;
			n=StrListvideoname.size();
			for(j=0;j<n;j++)
			{
				StrBuf="\t\t\t<video "; 
				StrBuf+=StrListvideoname.at(j);
				StrBuf+="/>";
				out<<StrBuf;
				out<<"\r\n";
			}
			//////////////////////////
			StrBuf="\t\t</switch>\r\n";
			out<<StrBuf;
			StrBuf="\t</body>\r\n";
			out<<StrBuf;
			StrBuf="</smil>\r\n";
			out<<StrBuf;
			FileOut.close();
		}		
	}
	
}
//
