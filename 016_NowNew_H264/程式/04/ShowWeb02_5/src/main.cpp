#include <QApplication>
#include <QTextCodec>
#include "dialogimpl.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	//整體中化方法start
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	//整體中化方法end
	DialogImpl win;
	win.show(); 
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
