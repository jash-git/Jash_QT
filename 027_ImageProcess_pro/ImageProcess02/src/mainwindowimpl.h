#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QScrollArea>
#include <QString>
 #include <QFileDialog>
#include "ui_mainwindow.h"
#include "imagewidget.h"
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
protected:
	void resizeEvent(QResizeEvent * event);
};
#endif




