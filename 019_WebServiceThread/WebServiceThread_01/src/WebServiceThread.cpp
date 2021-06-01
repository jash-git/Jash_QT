#include "WebServiceThread.h"
WebServiceThread::WebServiceThread(QLineEdit *linedit,QPushButton *b1,QPushButton *b2)
{
	blnchange=true;
	linedit1=linedit;
	pb1=b1;
	pb2=b2;
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
			pb1->setEnabled(false);
			pb2->setEnabled(true);
			linedit1->setText("1");			
		}
		else
		{
			pb1->setEnabled(true);
			pb2->setEnabled(false);
			linedit1->setText("2");				
		}
		blnchange=!blnchange;
	}
}
// place your code here
