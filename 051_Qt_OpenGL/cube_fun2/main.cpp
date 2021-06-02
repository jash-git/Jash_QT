#include <qapplication.h>

#include "cube.h"


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	if (!QGLFormat::hasOpenGL())
		qFatal("This system has no OpenGL support");

	Cube *cube;
	cube=new Cube(0);
	cube->resize(640, 480);
	cube->show();
	return app.exec();
}

