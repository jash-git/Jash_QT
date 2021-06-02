#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QScrollArea>
#include <QString>
#include <QFileDialog>
#include <QMessageBox> 
#include "ui_mainwindow.h"
#include "imagewidget.h"
#include "HistogramWidget.h"
#include "ThreshDialog.h"
//
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	ImageWidget *imageWidget;
	QScrollArea *scrollArea;
private slots:
	void slotOpenFile();
	void slotClose();
	void slotGray();
	void slotHistgram();
	void slotThresh();
protected:
	void resizeEvent(QResizeEvent * event);
};
#endif




