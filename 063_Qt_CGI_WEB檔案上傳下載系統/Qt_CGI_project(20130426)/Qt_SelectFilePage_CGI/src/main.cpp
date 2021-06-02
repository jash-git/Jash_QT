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
<html><head><meta content="text/html; charset=UTF8" http-equiv="content-type"><title>Qt_CGI 檔案上傳頁面</title></head>
	<body>
		<div style="text-align: center;"><span style="color: rgb(51, 102, 255); font-family: 'Times New Roman'; font-size: xx-large; font-style: normal; font-variant: normal; font-weight: normal; letter-spacing: normal; line-height: normal; text-align: center; text-indent: 0px; text-transform: none; white-space: normal; word-spacing: 0px; display: inline ! important; float: none;">Qt_CGI 檔案上傳頁面</span></div>		
		<div style="text-align: center;">
		<form enctype="multipart/form-data" action="/cgi-bin/uploadfile.cgi" method="post">
			<p><font size="+1"><span style="color: rgb(51, 102, 255);">File:</span> <input name="userfile" type="file"></font></p>
			<p><font size="+1"><input value="Upload" type="submit"></font></p>
		</form>
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
	
	//========
	printf("<html><head><meta content=\"text/html; charset=UTF8\" http-equiv=\"content-type\"><title>Qt_CGI 檔案上傳頁面</title></head>\r\n\r\n");
	printf("	<body>\r\n\r\n");
	printf("		<div style=\"text-align: center;\"><span style=\"color: rgb(51, 102, 255); font-family: 'Times New Roman'; font-size: xx-large; font-style: normal; font-variant: normal; font-weight: normal; letter-spacing: normal; line-height: normal; text-align: center; text-indent: 0px; text-transform: none; white-space: normal; word-spacing: 0px; display: inline ! important; float: none;\">Qt_CGI 檔案上傳頁面</span></div>\r\n\r\n");
	printf("		<div style=\"text-align: center;\">\r\n\r\n");
	printf("			<form enctype=\"multipart/form-data\" action=\"/cgi-bin/uploadfile.cgi\" method=\"post\">\r\n\r\n");
	printf("				<p><font size=\"+1\"><span style=\"color: rgb(51, 102, 255);\">File:</span> <input name=\"userfile\" type=\"file\"></font></p>\r\n\r\n");
    printf("				<p><font size=\"+1\"><input value=\"Upload\" type=\"submit\"></font></p>\r\n\r\n");
    printf("			</form>\r\n\r\n");
	printf("		</div>\r\n\r\n");
	printf("	</body>\r\n\r\n");
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