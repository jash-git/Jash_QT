#include "dialogimpl.h"

//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
void DialogImpl::slot1()
{
	m_StrAllData="";
	m_StrPath="";
	m_StrName="";
	m_StrAllData=lineEdit->text();
	Analy();
	lineEdit_2->setText(m_StrName);
	lineEdit_3->setText(m_StrPath);
}
void DialogImpl::Analy()
{
	int intnumber,i;
	bool blncheck;
	blncheck=false;
	QString StrBuf;
	intnumber=m_StrAllData.length();
	for(i=(intnumber-1);i>=0;i--)
	{
		StrBuf=m_StrAllData.mid(i,1);
		if((StrBuf=="/") && (!blncheck))
		{
			blncheck=true;
			continue;
		}
		if(blncheck)
		{
			m_StrPath=m_StrAllData.mid(i,1)+m_StrPath;
		}
		else
		{
			m_StrName=m_StrAllData.mid(i,1)+m_StrName;
		}

	}
	m_StrPath+="/";
}
//
