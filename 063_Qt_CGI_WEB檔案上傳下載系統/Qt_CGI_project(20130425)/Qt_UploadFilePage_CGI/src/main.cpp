// place your code here
#include <QCoreApplication>
#include <QTextCodec>
#include<QDateTime>
#include<QString>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>
using namespace std;
using namespace cgicc;

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
	Cgicc cgi;
	//========
	printf("Content-type:text/html\r\n\r\n");
	
	//========
	printf("<HTML>\r\n\r\n");
	printf("<HEAD>\r\n\r\n");
	printf("<title>File Upload in CGI</title>\r\n\r\n");
	printf("</HEAD>\r\n\r\n");
	printf("<body>\r\n\r\n");
	// get list of files to be uploaded
	const_file_iterator file = cgi.getFile("userfile");
	if(file != cgi.getFiles().end())
	{
		/*
		// send data type at cout.
		cout << HTTPContentHeader(file->getDataType());
		// write content at cout.
		file->writeToStream(cout);
		*/
		QString StrPath;
		std::string strName;
		strName=file->getFilename();
		StrPath="/var/www/cgi-bin/Upload_File_Folder/";
		StrPath+=strName.c_str();;
		ofstream output; 
		output.open(StrPath.toLocal8Bit().data()); 
		output.write(file->getData().c_str(),file->getDataLength()); 
		output.close();
		printf("Upload the %s file OK\r\n\r\n",strName.c_str());	
	}
	printf("</body>\r\n\r\n");
	printf("</HTML>\r\n\r\n");	
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