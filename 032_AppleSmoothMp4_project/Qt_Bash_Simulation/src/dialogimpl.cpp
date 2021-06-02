#include "dialogimpl.h"

//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
void DialogImpl::slot_but()
{
	CreateBashScript("1000","20000","300000","10000K","40000","1000x10");
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
		return StrFileName;
	}
	StrFileName="";
	return StrFileName;
}
//
