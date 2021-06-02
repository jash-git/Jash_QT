#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QWidget(parent, f)
{
	setupUi(this);
	timer01=new QTimer(this);
	connect(timer01,SIGNAL(timeout()),this,SLOT(slotTimer()));
}
void DialogImpl::slotCapture01()
{
	this->setWindowState(Qt::WindowMinimized);
	timer01->start(1000);
}
void DialogImpl::slotTimer()
{
	timer01->stop();
	Pixmap_saveimage= QPixmap::grabWindow(QApplication::desktop()->winId());
	Pixmap_saveimage.save("0.png", "PNG");
	this->setWindowState(Qt::WindowActive);		
}
//
