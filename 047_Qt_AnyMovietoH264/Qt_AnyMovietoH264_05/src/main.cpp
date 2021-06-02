#include <QApplication>
#include <QDesktopWidget>
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
	QSize size = app.desktop()->size();//取得桌面大小
	//win.move(size.width() / 2,size.height()/2); 
	win.move(0,0);//設定視窗起始顯示位置
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
