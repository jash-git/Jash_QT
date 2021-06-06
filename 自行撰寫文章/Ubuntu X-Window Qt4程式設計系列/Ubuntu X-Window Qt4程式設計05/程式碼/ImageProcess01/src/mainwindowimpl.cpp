#include "mainwindowimpl.h"
#include <QApplication>
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);
	imageWidget = new ImageWidget;
    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
 	imageWidget->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    scrollArea->setWidget(imageWidget);
	scrollArea->widget()->setMinimumSize(320, 240);	
    setCentralWidget(scrollArea);
}
void MainWindowImpl::resizeEvent(QResizeEvent * event)
{
	QResizeEvent * event01;
	event01=event;
	QRect childRect = scrollArea->childrenRect();
	imageWidget->resize(childRect.size());
}
void MainWindowImpl::slotOpenFile()
{
	imageWidget->setPixmap("/home/jash/456.bmp");
}
void MainWindowImpl::slotClose()
{
	QApplication::quit();
}
//
