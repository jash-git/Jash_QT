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
void MainWindowImpl::slotDynamicThresh(int value)
{
	int intThresh;
	intThresh=value;
	QString Strvalue;
	Strvalue.setNum(value);
	LineEdit01->setText(Strvalue);
	imageWidget->toGray();
	imageWidget->Threshold(intThresh,2);	
}
void MainWindowImpl::slotDockWidget()
{
	showDockWidget();
}
void MainWindowImpl::showDockWidget()
{
	shapDockWidget = new QDockWidget("動態調整門閥值");
	shapDockWidget->setObjectName("attribute");
	shapDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
	w=new QWidget(shapDockWidget);
	w->setMinimumSize(400, 140);
	w->setMaximumSize(400, 140);
	nameLabel = new QLabel("門閥值");
	slider = new QSlider(Qt::Horizontal, w);
	slider->setRange(0, 255);
	slider->setValue(0);
	LineEdit01=new QLineEdit(w);
	nameLayout = new QGridLayout(w);
	nameLayout->addWidget(nameLabel,0,0);
	nameLayout->addWidget(LineEdit01,0,1);
	nameLayout->addWidget(slider,1,1);
	
	w->setLayout(nameLayout);
	shapDockWidget->setWidget(w);
	addDockWidget(Qt::RightDockWidgetArea,shapDockWidget);	
	QObject::connect(slider, SIGNAL(valueChanged(int)),this, SLOT(slotDynamicThresh(int)));
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
	ThreshDialog ThreshDlg;
	if(ThreshDlg.exec()==QDialog::Accepted)
	{
		int intThresh;
		QString Str01;
		Str01=ThreshDlg.lineEdit->text();
		intThresh=Str01.toInt();
		imageWidget->toGray();
		imageWidget->Threshold(intThresh,2);
	}
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
