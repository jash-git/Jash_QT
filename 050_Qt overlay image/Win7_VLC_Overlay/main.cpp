#include <QtGui/QApplication>
#include <QTextCodec>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //���餤�Ƥ�kstart
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Big5"));
    //���餤�Ƥ�kend
    Widget w;
    w.show();
    
    return a.exec();
}
