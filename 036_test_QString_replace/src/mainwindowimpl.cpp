#include "mainwindowimpl.h"
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);
	QString StrData="c:\\123.txt";
	QString StrBuf01;
	QString StrBuf02;
	QMessageBox mg01;
	mg01.setText(StrData);
	mg01.exec();
	StrBuf01="\\";
	StrBuf02="/";
	StrData=StrData.replace(StrBuf01,StrBuf02);
	QMessageBox mg02;
	mg02.setText(StrData);
	mg02.exec();	
}
//
