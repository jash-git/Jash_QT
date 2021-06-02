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
	void slotGray();//5-2 by jash
	void slotSource();//5-2 by jash
	void slotFixedThreshold();//5-2 by jash
	void slotOTSUThreshold();//5-2 by jash
	void slotHistogram();//5-3 by jash
	void slotEqualize();//5-3 by jash
	void slotSaveFile();//5-3 by jash
	void slotTranslation();//5-3 by jash
	void slotHorMirror();//5-3 by jash
	void slotVerMirror();//5-3 by jash
	void slotTranspose();//5-3 by jash
	void slotScale();//5-3 by jash
	void slotRotate();//5-3 by jash
	void slotSobel();//5-4 by jash
	void slotRoberts();//5-4 by jash
	void slotLaplacian();//5-4 by jash
	void slotPrewitt();//5-4 by jash
	void slotThinning();//5-4 by jash
	void slotOverlayImage();//5-5 by jash
	void slotOverlayText();//5-5 by jash
protected:
	void resizeEvent(QResizeEvent * event);
};
#endif




