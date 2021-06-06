// place your code here
#include <QCoreApplication>
#include <QTextCodec>
#include<QDateTime>
#include <iostream>
#include<fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
/*
<html><head><meta content="text/html; charset=UTF8" http-equiv="content-type"><title>filelist</title></head><body>
<div style="text-align: center;"><span style="color: rgb(51, 102, 255); font-family: 'Times New Roman'; font-size: xx-large; font-style: normal; font-variant: normal; font-weight: normal; letter-spacing: normal; line-height: normal; text-align: center; text-indent: 0px; text-transform: none; white-space: normal; word-spacing: 0px; display: inline ! important; float: none;">Qt_CGI 檔案下載頁面<br></span>
	<div style="text-align: left;"><span style="color: rgb(51, 102, 255); font-family: 'Times New Roman'; font-size: xx-large; font-style: normal; font-variant: normal; font-weight: normal; letter-spacing: normal; line-height: normal; text-align: center; text-indent: 0px; text-transform: none; white-space: normal; word-spacing: 0px; display: inline ! important; float: none;"></span>
		<font size="+1">2013-4-26 10:39:35&nbsp;&nbsp;  &nbsp;&nbsp;  &nbsp;&nbsp;  &nbsp;&nbsp;  &nbsp;&nbsp; <a href="/cgi-bin/Upload_File_Folder/Array_Data.sh">/cgi-bin/Upload_File_Folder/Array_Data.sh</a></font><br><br>
		<font size="+1">2013-4-26 10:39:35&nbsp;&nbsp;  &nbsp;&nbsp;  &nbsp;&nbsp;  &nbsp;&nbsp;  &nbsp;&nbsp; <a href="file:///cgi-bin/Upload_File_Folder/Array_Data.sh">/cgi-bin/Upload_File_Folder/Array_Data.sh</a></font><br><br>
	</div>
</div></body></html>
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
	printf("<html><head><meta content=\"text/html; charset=UTF8\" http-equiv=\"content-type\"><title>filelist</title></head><body>\r\n\r\n");
	printf("<div style=\"text-align: center;\"><span style=\"color: rgb(51, 102, 255); font-family: 'Times New Roman'; font-size: xx-large; font-style: normal; font-variant: normal; font-weight: normal; letter-spacing: normal; line-height: normal; text-align: center; text-indent: 0px; text-transform: none; white-space: normal; word-spacing: 0px; display: inline ! important; float: none;\">Qt_CGI 檔案下載頁面<br></span>\r\n\r\n");
	printf("	<div style=\"text-align: left;\"><span style=\"color: rgb(51, 102, 255); font-family: 'Times New Roman'; font-size: xx-large; font-style: normal; font-variant: normal; font-weight: normal; letter-spacing: normal; line-height: normal; text-align: center; text-indent: 0px; text-transform: none; white-space: normal; word-spacing: 0px; display: inline ! important; float: none;\"></span>\r\n\r\n");
	///////////	
	fstream a;
	char fg[700];
	char chrDate[50];
	char chrFilePath[500];
	a.open("uploadlist.log",ios::in);
	while(!a.eof())
	{
		a.getline(fg,700);
		if(strlen(fg)>0)
		{
			sscanf(fg,"%[^','],%[^',']",chrDate,chrFilePath);
			printf("\t\t<font size=\"+1\">%s&nbsp;&nbsp;  &nbsp;&nbsp;  &nbsp;&nbsp;  &nbsp;&nbsp;  &nbsp;&nbsp; <a href=\"%s\">%s</a></font><br><br>\r\n\r\n",chrDate,chrFilePath,chrFilePath);
		}
	}
	a.close();
	///////////
	printf("	</div>\r\n\r\n");
	printf("</div></body></html>\r\n\r\n");	
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
