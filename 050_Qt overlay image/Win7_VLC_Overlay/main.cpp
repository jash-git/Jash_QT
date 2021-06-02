#include <QtGui/QApplication>
#include <QTextCodec>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //整體中化方法start
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Big5"));
    //整體中化方法end
    Widget w;
    w.show();
    
    return a.exec();
}
