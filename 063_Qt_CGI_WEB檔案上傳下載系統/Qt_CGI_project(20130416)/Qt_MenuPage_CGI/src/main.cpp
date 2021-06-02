// place your code here
#include <QCoreApplication>
#include <QTextCodec>
#include<QDateTime>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
<html>
<head>
<meta content="text/html; charset=UTF8" http-equiv="content-type">
<title>menu</title>
</head>

<body>
<a href="introduction.htm" target="Main">01.&#31777;&#20171;&#35498;&#26126;</a>
<br>

</body>

</html>
 */
int main(int argc, char *argv[])
{
	//QCoreApplication app(argc, argv);
	QTextCodec ::setCodecForTr(QTextCodec ::codecForName("UTF-8"));
	QTextCodec ::setCodecForCStrings(QTextCodec ::codecForName("UTF-8"));
	//========
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	QDateTime dateTime = QDateTime::currentDateTime();
	//========
	printf("Content-type:text/html\r\n\r\n");
	
	//========
	printf("<html>\r\n");
	printf("<head>\r\n");
	printf("<meta content=\"text/html; charset=UTF8\" http-equiv=\"content-type\">\r\n");
	printf("<title>menu</title>\r\n");
	printf("</head>\r\n");
	printf("<body>\r\n");
	printf("<a href=\"/cgi-bin/introduction.cgi\" target=\"Main\">01.&#31777;&#20171;&#35498;&#26126;</a>\r\n");
	printf("<br>\r\n");
	printf("</body>\r\n");
	printf("</html>\r\n");
	//========
	FILE *pf;
	char *postdata='\0';
	pf=fopen("lasttime.log","w");
	fprintf(pf,"Now Time: %d-%d-%d %d:%d:%d",(now->tm_year + 1900),(now->tm_mon + 1),now->tm_mday,now->tm_hour,now->tm_min,now->tm_sec);
	postdata = getenv("QUERY_STRING"); 
	if(postdata !='\0')
	{
		fprintf(pf,"\tdata=%s",postdata);
	}
	fclose(pf);	
	//======== 
	return 0;
	//return app.exec();
}
