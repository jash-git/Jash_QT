#include <qapplication.h>

#include "cube.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (!QGLFormat::hasOpenGL())
        qFatal("This system has no OpenGL support");
	 //QHBox *hbox=new QHBox(0);
    //hbox->setCaption(QObject::tr("Cube"));
	 //hbox->resize(400, 400);
    Cube *cube;
	 cube=new Cube(0);
    cube->resize(300, 300);
    //app.setMainWidget(Cube);
    //hbox->show();
    cube->show();
    return app.exec();
}

