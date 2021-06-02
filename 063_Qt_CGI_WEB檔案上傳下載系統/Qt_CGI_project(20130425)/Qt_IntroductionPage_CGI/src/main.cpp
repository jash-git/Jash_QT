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
<title>introduction</title>
</head>
<body>
<div style="text-align: center; color: rgb(51, 153, 153);"><font size="+3">&#31777;&#20171;&#35498;&#26126;:</font><br>
<br>
<font size="+1">&#26412;&#31995;&#32113;&#26159;&#26550;&#27083;&#22312;UBUNTU+Apache&#19978;&#65292;&#21033;&#29992;Qt+cgicc&#31561;&#20989;&#24335;&#24235;&#20358;&#23436;&#25104;&#25972;&#20491;&#31777;&#26131;&#30340;&#27284;&#26696;&#19978;&#20659;/&#19979;&#36617;&#30340;WEB&#31995;&#32113;</font><br>
<br>
<img style="width: 640px; height: 480px;" alt="UBUNTU_QT_Penguin" src="UBUNTU_QT_Penguin.jpg"><br>
<font size="-1">&#21478;&#22806;&#19978;&#22294;&#26159;&#20316;&#32773;&#65306;Jash.Liao &#33258;&#24049;&#21033;&#29992;&#23567;&#30059;&#23478;&#32362;&#35069;&#65292;&#24847;&#32681;&#26159;&#20316;&#32773;(&#21574;&#21574;&#20225;&#40285;)&#25645;&#33879;</font><font size="-1">UBUNTU&#23567;&#33337;&#21644;&#22806;&#21152;Qt&#25937;&#29983;&#22280;&#33287;&#21010;&#27123;&#38358;&#34153;&#26377;&#22914;&#22823;&#28023;&#30340;&#36039;&#35338;&#19990;&#30028;</font>
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
	printf("<html>\r\n\r\n");
	printf("<head>\r\n\r\n");
	printf("<meta content=\"text/html; charset=UTF8\" http-equiv=\"content-type\">\r\n\r\n");
	printf("<title>introduction</title>\r\n\r\n");
	printf("</head>\r\n\r\n");
	printf("<body>\r\n\r\n");
	printf("<div style=\"text-align: center; color: rgb(51, 153, 153);\"><font size=\"+3\">&#31777;&#20171;&#35498;&#26126;:</font><br>\r\n\r\n");
	printf("<br>\r\n\r\n");
	printf("<font size=\"+1\">&#26412;&#31995;&#32113;&#26159;&#26550;&#27083;&#22312;UBUNTU+Apache&#19978;&#65292;&#21033;&#29992;Qt+cgicc&#31561;&#20989;&#24335;&#24235;&#20358;&#23436;&#25104;&#25972;&#20491;&#31777;&#26131;&#30340;&#27284;&#26696;&#19978;&#20659;/&#19979;&#36617;&#30340;WEB&#31995;&#32113;</font><br>\r\n\r\n");
	printf("<br>\r\n\r\n");
	printf("<img style=\"width: 640px; height: 480px;\" alt=\"UBUNTU_QT_Penguin\" src=\"./images/UBUNTU_QT_Penguin.jpg\"><br>\r\n\r\n");
	printf("<font size=\"-1\">&#21478;&#22806;&#19978;&#22294;&#26159;&#20316;&#32773;&#65306;Jash.Liao &#33258;&#24049;&#21033;&#29992;&#23567;&#30059;&#23478;&#32362;&#35069;&#65292;&#24847;&#32681;&#26159;&#20316;&#32773;(&#21574;&#21574;&#20225;&#40285;)&#25645;&#33879;</font><font size=\"-1\">UBUNTU&#23567;&#33337;&#21644;&#22806;&#21152;Qt&#25937;&#29983;&#22280;&#33287;&#21010;&#27123;&#38358;&#34153;&#26377;&#22914;&#22823;&#28023;&#30340;&#36039;&#35338;&#19990;&#30028;</font>\r\n\r\n");
	printf("</div>\r\n\r\n");
	printf("</body>\r\n\r\n");
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