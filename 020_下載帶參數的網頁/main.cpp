#include <QtCore>
#include <iostream>

#include "httpget.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QStringList args = app.arguments();

    if (args.count() != 2) {
        cerr << "Usage: httpget url" << endl
             << "Example:" << endl
             << "    httpget http://doc.trolltech.com/qq/index.html"
             << endl;
        return 1;
    }

    HttpGet getter;
    if (!getter.getFile(QUrl(args[1])))
        return 1;

    QObject::connect(&getter, SIGNAL(done()), &app, SLOT(quit()));

    return app.exec();
}
