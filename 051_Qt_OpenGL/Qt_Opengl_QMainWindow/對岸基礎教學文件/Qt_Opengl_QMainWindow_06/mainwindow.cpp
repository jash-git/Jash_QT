#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	w=new GLWidget(this);//建立中心Qt畫布
	setCentralWidget(w);

	QMenu *fileMenu = new QMenu("&File");
	fileMenu->addAction("&Close", qApp, SLOT(quit()), Qt::CTRL + Qt::Key_Q);
	menuBar()->addMenu(fileMenu);
	timer=new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(Timer_slot()));
	timer->start(500);
}
void MainWindow::Timer_slot()
{
	w->updateGL();
}
MainWindow::~MainWindow()
{

}

