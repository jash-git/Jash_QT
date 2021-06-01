#include "WebServiceThread.h"
WebServiceThread::WebServiceThread(QLineEdit *linedit)
{
	blnchange=true;
	linedit1=linedit;
}
void WebServiceThread::run()
{
	QUrl url1;
	QString StrUrl;
	while(true)
	{
		sleep(30);
		if(blnchange)
		{
			linedit1->setText("1");			
		}
		else
		{
			linedit1->setText("2");				
		}
		blnchange=!blnchange;
	}
}
// place your code here
