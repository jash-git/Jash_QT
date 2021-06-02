#include "CallProcess.h"
CallProcess::CallProcess(int sleepSec,int id,ThreadData *TD)
{
	m_sleepSec=sleepSec;
	m_id=id;
	m_TD=TD;
}
void CallProcess::run()
{
	bool blnget;
	QString Strbuf;
	FILE *pf;
	do
	{
		blnget=m_TD->GetData(&StrData);
		if(blnget)
		{
			Strbuf = Strbuf.setNum(m_id);
			Strbuf="thread"+Strbuf;
			Strbuf+=" :";
			Strbuf+=StrData;
			pf=fopen("Write.txt","a");
			fprintf(pf,"%s\n",Strbuf.toAscii().data());
			fclose(pf);
			QThread::msleep(m_sleepSec*1000);
		}
	
	}while(blnget);

}
// place your code here
