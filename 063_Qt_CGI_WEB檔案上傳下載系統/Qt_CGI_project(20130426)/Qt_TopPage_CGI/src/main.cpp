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
		<meta content="text/html; charset=UTF8" http-equiv="content-type"><title>Qt_CGI 檔案上傳/下載系統</title></head><body>
			<div style="text-align: center;">
				<font size="+3"><span style="color: rgb(51, 102, 255); font-family: Times New Roman;">Qt_CGI 檔案上傳/下載系統</span><br></font>
					<span style="color: rgb(51, 153, 153);"><br>開發者 : jash.liao / 部落格 :</span>				
					<a href="http://jashliao.pixnet.net/blog" target="_blank"><span style="color: rgb(51, 153, 153);"> jashliao的部落格</span></a><br style="color: rgb(51, 153, 153);">
					<span style="color: rgb(51, 153, 153);"><br>目前時間 : </span><br>
			</div>
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
	
	printf("<script>\r\n\r\n");
	printf("<!--\r\n\r\n");
	printf("function showtime()\r\n\r\n");
	printf("{\r\n\r\n");
	printf("today = new Date()\r\n\r\n");
	//printf("document.CLOCK.ALARM.value = today.toLocaleString()\r\n\r\n");
	printf("TimerID = setTimeout (\"showtime()\",1000)\r\n\r\n");
	printf("}\r\n\r\n");
	printf("//-->\r\n\r\n");
	printf("</script>\r\n\r\n");
	
	//========
	printf("<html>\r\n\r\n");
	printf("\t<head>\r\n\r\n");
	printf("\t\t<meta http-equiv=\"refresh\" content=\"10;url=/cgi-bin/top.cgi\">\r\n\r\n");
	printf("\t\t<meta content=\"text/html; charset=UTF8\" http-equiv=\"content-type\"><title>Qt_CGI 檔案上傳/下載系統</title></head>\r\n\r\n");
	printf("\t<body onLoad=\"showtime()\">\r\n\r\n");
	printf("\t\t\t<div style=\"text-align: center;\">\r\n\r\n");
	printf("\t\t\t\t<font size=\"+3\"><span style=\"color: rgb(51, 102, 255); font-family: Times New Roman;\">Qt_CGI 檔案上傳/下載系統</span><br></font>");
	printf("\t\t\t\t<span style=\"color: rgb(51, 153, 153);\"><br>開發者 : jash.liao / 部落格 :</span>\r\n\r\n");
	printf("\t\t\t\t<a href=\"http://jashliao.pixnet.net/blog\" target=\"_blank\"><span style=\"color: rgb(51, 153, 153);\"> jashliao的部落格</span></a><br style=\"color: rgb(51, 153, 153);\">\r\n\r\n");
	printf("\t\t\t\t<span style=\"color: rgb(51, 153, 153);\"><br>目前時間 :  %d-%d-%d %d:%d:%d</span><br>\r\n\r\n",dateTime.date().year(),dateTime.date().month(),dateTime.date().day(),dateTime.time().hour(),dateTime.time().minute(),dateTime.time().second());
	printf("\t\t\t</div>\r\n\r\n");
	//printf("		<form NAME=\"CLOCK\">\r\n\r\n");
	//printf("			<font COLOR=\"#000000\"><p>Now Time:</font><input NAME=\"ALARM\" TYPE=\"TEXT\" SIZE=\"50\"> </p>\r\n\r\n");
	//printf("		</form>\r\n\r\n");
	printf("\t</body>\r\n\r\n");
	printf("</html>\r\n\r\n");	
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