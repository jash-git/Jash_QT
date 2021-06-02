#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	timer=new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(slotTimer()));
}
void DialogImpl::slotStart()
{
	m_TD.addData("One");
	m_TD.addData("Two");
	m_TD.addData("Three");
	m_TD.addData("Four");
	cp01=new CallProcess(5,1,&m_TD);
	cp02=new CallProcess(15,2,&m_TD);
	cp01->start();
	cp02->start();
	timer->start(100);
}
void DialogImpl::slotTimer()
{
	QString StrBuf;
	StrBuf=StrBuf.number(m_TD.m_index);
	lineEdit->setText(StrBuf);
	if(m_TD.m_index==m_TD.m_size)
	{
		QMessageBox::information(this, "Information","thread finish...",QMessageBox::Yes, QMessageBox::Yes);	
		QApplication::quit();
	}
}
//
