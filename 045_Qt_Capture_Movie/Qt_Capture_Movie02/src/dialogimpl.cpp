#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QWidget(parent, f)
{
	setupUi(this);
	mapButVideo=ButVideo;
	m_intTimerSwitch=0;
	m_intImageCount=-1;
	m_StrFileName="";
	m_blnclick=false;
	timer01=new QTimer(this);
	connect(timer01,SIGNAL(timeout()),this,SLOT(slotTimer()));
}
void DialogImpl::slotCapture01()
{
	this->setWindowState(Qt::WindowMinimized);
	m_intTimerSwitch=1;
	timer01->start(1000);
}
void DialogImpl::slotVideo()
{
	if(!m_blnclick)
	{
		m_intTimerSwitch=2;
		this->setWindowState(Qt::WindowMinimized);
		mapButVideo->setText("Stop Video");
		timer01->start(30);
	}
	else
	{
		timer01->stop();
		mapButVideo->setText("Start Video");
	}
	m_blnclick=!m_blnclick;
}
void DialogImpl::slotTimer()
{
	switch(m_intTimerSwitch)
	{
		case 1:
			timer01->stop();
			Pixmap_saveimage= QPixmap::grabWindow(QApplication::desktop()->winId());
			Pixmap_saveimage.save("0.png", "PNG");
			this->setWindowState(Qt::WindowActive);	
			break;
		case 2:
			m_intImageCount++;
			m_StrFileName=m_StrFileName.setNum(m_intImageCount)+".png";
			Pixmap_saveimage= QPixmap::grabWindow(QApplication::desktop()->winId());
			Pixmap_saveimage.save(m_StrFileName, "PNG");
			break;
	}	
}
//
