// place your code here
#include <QCoreApplication>
#include <QTextCodec>
#include <QDebug>
#include <iostream>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <signal.h>
#include<sys/param.h>
#include<sys/types.h>
#include<sys/stat.h>
#include "guiinfoserver.h"
#include "timeserver.h"
//#include "consoletimer.h"
using namespace std;
void init_daemon(void)
{
	int pid;
	int i;
	if(pid=fork())
		exit(0);
	else if(pid<0)
		exit(1);
	//是第一子歷程
	setsid();//第一子歷程成為新的會話組長和歷程組長, 並與節制終端分手
	if(pid=fork())
		exit(0);//竣事第一子歷程
	else if(pid< 0)
	exit(1);
	//第二子歷程不再是會話組長
	for(i=0;i< NOFILE;++i)//封鎖打開的文件描述符
	close(i);
	chdir("/");//改變工作目錄到/
	umask(0);//重設文件建樹掩模
	return;
}
int main(int argc, char *argv[])
{
	signal(SIGCHLD, SIG_IGN); /* 忽略子進程結束信號，防止出現僵屍進程 */ 
	init_daemon();
	
	QCoreApplication app(argc, argv);
	QTextCodec ::setCodecForTr(QTextCodec ::codecForName("UTF-8"));
	QTextCodec ::setCodecForCStrings(QTextCodec ::codecForName("UTF-8"));
	TimeServer *timeserver;
	GUIInfoServer *guiinfoserver;
	timeserver = new TimeServer(&app);
	if (!timeserver->listen(QHostAddress::Any,7052))
	{

		return 0;
	}
	guiinfoserver= new GUIInfoServer(&app);
	if (!guiinfoserver->listen(QHostAddress::Any,2507))
	{

		return 0;
	}	
	return app.exec();
}
