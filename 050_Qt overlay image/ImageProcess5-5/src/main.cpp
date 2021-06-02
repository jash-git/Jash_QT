#include <QApplication>
#include "mainwindowimpl.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	//整體中化方法start
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	//整體中化方法end
	MainWindowImpl win;
	win.show(); 
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
