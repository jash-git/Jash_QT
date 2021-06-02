#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
void DialogImpl::slotUTF8()
{
	QFile FileOut("UTF8.smil");
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
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="Movie01_400K.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="400000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out<<StrBuf;
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
void DialogImpl::slotANSI()
{
	QFile FileOut("ANSI.smil");
	QString StrBuf,StrName,Strbitrate;
	if(FileOut.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
	{
		QTextStream out(&FileOut);
		out.setCodec("ANSI");
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
		StrBuf="\t\t\t<video src=\"mp4:";
		StrName="Movie01_400K.mp4";
		StrBuf+=StrName;
		StrBuf+="\" system-bitrate=\"";
		Strbitrate="400000";
		StrBuf+=Strbitrate;
		StrBuf+="\"/>\r\n";
		out<<StrBuf;
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
//
