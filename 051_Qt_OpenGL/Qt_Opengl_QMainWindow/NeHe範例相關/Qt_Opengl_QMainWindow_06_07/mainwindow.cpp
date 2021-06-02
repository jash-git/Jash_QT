#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	w=new GLWidget(this);//建立中心Qt畫布
	setCentralWidget(w);

	QMenu *fileMenu = new QMenu("&File");
	fileMenu->addAction("&Close", qApp, SLOT(quit()), Qt::CTRL + Qt::Key_Q);
	menuBar()->addMenu(fileMenu);
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
			w->filter += 1;
			if ( w->filter > 2 ) 
			{
				w->filter = 0;
			}
			w->updateGL();
		break; 
		case Qt::Key_PageUp:
			w->zoom -= 0.2; 
			w->updateGL();
		break;
		case Qt::Key_PageDown:
			w->zoom += 0.2; 
			w->updateGL();
		break;
		case Qt::Key_Up:
			w->xSpeed -= 0.01; 
			w->updateGL();
		break;
		case Qt::Key_Down:
			w->xSpeed += 0.01; 
			w->updateGL();
		break;
		case Qt::Key_Right:
			w->ySpeed -= 0.01; 
			w->updateGL();
		break;
		case Qt::Key_Left:
			w->ySpeed += 0.01; 
			w->updateGL();
		break;
	}
}

