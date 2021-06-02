#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QScrollArea>
#include <QString>
#include <QFileDialog>
#include <QDockWidget>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QSlider>
#include <QLineEdit>
#include <QGridLayout>
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
	QDockWidget *shapDockWidget;
	QWidget *w;
	QLabel *nameLabel;
	QSlider *slider;
	QGridLayout *nameLayout;
	void showDockWidget();
	QScrollArea *scrollArea;
	QLineEdit *LineEdit01;
private slots:
	void slotOpenFile();
	void slotSaveFile();
	void slotClose();
	void slotGray();
	void slotHistgram();
	void slotThresh();
	void slotDockWidget();
	void slotDynamicThresh(int);
	void slotImR();
	void slotImG();
	void slotImB();
	void slotGradient();
	void slotLaplacian();
protected:
	void resizeEvent(QResizeEvent * event);
};
#endif




