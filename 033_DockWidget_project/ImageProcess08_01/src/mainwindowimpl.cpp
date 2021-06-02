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
	QDockWidget *shapDockWidget = new QDockWidget(tr("Attribute"));
	shapDockWidget->setObjectName("attribute");
	shapDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
	QWidget *w=new QWidget(shapDockWidget);
	QLabel *nameLabel = new QLabel("name");
	QTextEdit *nameEdit = new QTextEdit();
	QHBoxLayout *nameLayout = new QHBoxLayout(w);
	nameLayout->addWidget(nameLabel);
	nameLayout->addWidget(nameEdit);
	w->setLayout(nameLayout);
	shapDockWidget->setWidget(w);
	addDockWidget(Qt::RightDockWidgetArea,shapDockWidget);
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
	QString StrFilePath;
	StrFilePath=QFileDialog::getOpenFileName(this,"Select File","/home/","(*.*)");
	imageWidget->setPixmap(StrFilePath);
}
void MainWindowImpl::slotClose()
{
	QApplication::quit();
}
void MainWindowImpl::slotGray()
{
	imageWidget->toGray();
}
void MainWindowImpl::slotThresh()
{
	imageWidget->Threshold(128,2);
}
void  MainWindowImpl::slotHistgram()
{
	if(imageWidget->intcheckGray!=1)
	{
		imageWidget->toGray();
	}
	HistogramWidget HistogramWidget01;
	HistogramWidget01.exec();

}
//
