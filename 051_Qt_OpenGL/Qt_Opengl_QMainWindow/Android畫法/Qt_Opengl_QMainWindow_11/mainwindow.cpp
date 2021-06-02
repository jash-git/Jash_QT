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
	w->lightAngleGreen+=45;//轉動綠燈
	w->lightAngleRed+=45;//轉動紅燈
	w->updateGL();
}
MainWindow::~MainWindow()
{

}

void MainWindow::keyPressEvent( QKeyEvent *e )
{
	switch ( e->key() )
	{
		case Qt::Key_L:
			w->light = !w->light; 
			if ( !w->light )
			{
				glDisable( GL_LIGHTING ); 
			}
			else
			{
				glEnable( GL_LIGHTING );
			}
			w->updateGL();
		break;
		case Qt::Key_F:
			/*
			w->filter += 1;
			if ( w->filter > 2 ) 
			{
				w->filter = 0;
			}
			w->updateGL();
			*/
		break; 
		case Qt::Key_PageUp:
			w->zoom -= 2.0; 
			w->updateGL();
		break;
		case Qt::Key_PageDown:
			w->zoom += 2.0; 
			w->updateGL();
		break;
		case Qt::Key_Up:
			w->xRot -= 1.0; 
			w->updateGL();
		break;
		case Qt::Key_Down:
			w->xRot += 1.0; 
			w->updateGL();
		break;
		case Qt::Key_Right:
			w->yRot-= 1.0; 
			w->updateGL();
		break;
		case Qt::Key_Left:
			w->yRot+= 1.0; 
			w->updateGL();
		break;
	}
}