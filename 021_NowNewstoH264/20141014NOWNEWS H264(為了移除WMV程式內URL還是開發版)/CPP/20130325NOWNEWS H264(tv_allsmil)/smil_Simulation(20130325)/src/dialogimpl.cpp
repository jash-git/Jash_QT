#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
void DialogImpl::slot1()
{
	CreateSmilFile("23184","23184");
}
void DialogImpl::CreateSmilFile(QString StrSmilName,QString FileName)
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
//
