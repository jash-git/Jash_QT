#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
void DialogImpl::slotButton()
{
	int intindex=0;	
	QString StrFind="_";
	QString StrData00="test";
	QString StrData01="test_200K";
	QString StrData02="test_400K";
	QString StrAns="";
	QMessageBox ms00;
	intindex=StrData00.indexOf(StrFind);
	if(intindex>0)
	{
		StrAns=StrData00.mid(intindex+1);
	}
	else
	{
		StrAns="NO Find";
	}
	ms00.setText(StrAns);
	ms00.exec();
	intindex=StrData01.indexOf(StrFind);
	if(intindex)
	{
		StrAns=StrData01.mid(intindex+1);
	}
	else
	{
		StrAns="NO Find";
	}
	QMessageBox ms01;
	ms01.setText(StrAns);
	ms01.exec();
	intindex=StrData02.indexOf(StrFind);
	if(intindex)
	{
		StrAns=StrData02.mid(intindex+1);
	}
	else
	{
		StrAns="NO Find";
	}
	QMessageBox ms02;
	ms02.setText(StrAns);
	ms02.exec();
}
//
