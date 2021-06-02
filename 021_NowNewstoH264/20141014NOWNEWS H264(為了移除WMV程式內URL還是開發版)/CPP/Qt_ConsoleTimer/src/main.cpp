// place your code here
#include <QCoreApplication>
#include <QTextCodec>
#include <QDebug>
#include <iostream>
#include <unistd.h>
#include "consoletimer.h"
using namespace std;
int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	QTextCodec ::setCodecForTr(QTextCodec ::codecForName("UTF-8"));
	QTextCodec ::setCodecForCStrings(QTextCodec ::codecForName("UTF-8"));
	cout<<"programe start..."<<endl;
	sleep(1);
	consoletimer ct;
	return app.exec();
}