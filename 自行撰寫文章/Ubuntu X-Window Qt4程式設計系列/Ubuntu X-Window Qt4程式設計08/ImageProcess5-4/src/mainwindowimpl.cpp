#include "mainwindowimpl.h"
#include <QApplication>
#include "SetThresholdDlg.h"//5-2 by jash
#include "ShowHistogram.h"//5-3 by jash
#include "SetTranslation.h"//5-3 by jash
#include "SetScale.h"//5-3 by jash
#include "SetRotate.h"//5-3 by jash
#include <QMessageBox>//5-3 by jash
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
	QString StrFilePath;
	StrFilePath=QFileDialog::getOpenFileName(this,"Select File","/home/","(*.*)");
	imageWidget->setPixmap(StrFilePath);
}
void MainWindowImpl::slotClose()
{
	QApplication::quit();
}
void MainWindowImpl::slotGray()//5-2 by jash
{
	//5-3 by jash
	/*錯誤寫法
	ShowHistogramDlg ShowHistogram;
	imageWidget->toGray();
	ShowHistogram.exec();
	*/
	///*
	imageWidget->toGray();
	ShowHistogramDlg ShowHistogram;//5-3 by jash
	ShowHistogram.exec();//5-3 by jash
	//*/
}
void MainWindowImpl::slotSource()//5-2 by jash
{
	imageWidget->toSource();
}
void MainWindowImpl::slotFixedThreshold()//5-2 by jash
{
	SetThresholdDlg SetThreshold;
	int intThresh=0;
	QString Str01;
	if(SetThreshold.exec()==QDialog::Accepted)
	{
		Str01=SetThreshold.lineEdit->text();
		intThresh=Str01.toInt();
	}
	imageWidget->toGray();
	imageWidget->toThreshold(intThresh);
}
void MainWindowImpl::slotOTSUThreshold()
{
	int intThresh=0;
	imageWidget->toGray();
	intThresh=imageWidget->toOTSU();
	QMessageBox MesBox;//5-3 by jash
	QString StrOTSUThreshold,StrMessage;
	StrOTSUThreshold.setNum(intThresh);
	StrMessage="OTSU Threshold = "+StrOTSUThreshold;
	MesBox.setText(StrMessage);
	MesBox.exec();
	imageWidget->toThreshold(intThresh);
}
void MainWindowImpl::slotHistogram()//5-3 by jash
{
	ShowHistogramDlg ShowHistogram;
	ShowHistogram.exec();
}
void MainWindowImpl::slotEqualize()//5-3 by jash
{
	imageWidget->toEqualize();
	ShowHistogramDlg ShowHistogram;
	ShowHistogram.exec();
}
void MainWindowImpl::slotSaveFile()//5-3 by jash
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"/home/image.bmp",tr("Images (*.bmp *.png *.xpm *.jpg)"));
	imageWidget->toSaveFile(fileName);
}
void MainWindowImpl::slotTranslation()//5-3 by jash
{
	SetTranslation SetTranslation01;
	int intX=0;
	int intY=0;
	QString StrX;
	QString StrY;
	if(SetTranslation01.exec()==QDialog::Accepted)
	{
		StrX=SetTranslation01.lineEdit_1->text();
		StrY=SetTranslation01.lineEdit_2->text();
		intX=StrX.toInt();
		intY=StrY.toInt();
		imageWidget->toTranslation(intX,intY);
	}
}
void MainWindowImpl::slotHorMirror()//5-3 by jash
{
	imageWidget->toHorMirror();
}
void  MainWindowImpl::slotVerMirror()//5-3 by jash
{
	imageWidget->toVerMirror();
}
void MainWindowImpl::slotTranspose()//5-3 by jash
{
	imageWidget->toTranspose();
}
void MainWindowImpl::slotScale()//5-3 by jash
{
	SetScale SetScale01;
	double dblSetScale=0;
	QString Str01;
	if(SetScale01.exec()==QDialog::Accepted)
	{
		Str01=SetScale01.lineEdit->text();
		dblSetScale=Str01.toDouble();
	}
	imageWidget->toScale(dblSetScale);
}
void MainWindowImpl::slotRotate()//5-3 by jash
{
	SetRotate SetRotate01;
	double dblRotate=0;
	QString Str01;
	if(SetRotate01.exec()==QDialog::Accepted)
	{
		Str01=SetRotate01.lineEdit->text();
		dblRotate=Str01.toDouble();
	}
	imageWidget->toRotate(dblRotate);
}
void MainWindowImpl::slotSobel()//5-4 by jash
{
	imageWidget->toSobel();
}
void MainWindowImpl::slotRoberts()//5-4 by jash
{
	imageWidget->toRoberts();
}
void MainWindowImpl::slotLaplacian()//5-4 by jash
{
	imageWidget->toLaplacian();
}
void MainWindowImpl::slotPrewitt()//5-4 by jash
{
	imageWidget->toPrewitt();
}
void MainWindowImpl::slotThinning()//5-4 by jash
{
	imageWidget->toThinning();
}
//
