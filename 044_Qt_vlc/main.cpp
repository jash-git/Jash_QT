/* libVLC and Qt sample code
 * Copyright ? 2009 Alexander Maringer <maringer@maringer-it.de>
 */
#include "vlc_on_qt.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Player p;
    p.resize(640,480);
    p.playFile("/mnt/nfs/resource/panda.mpg"); // Replace with what you want to
    p.show();
    return a.exec();
}
