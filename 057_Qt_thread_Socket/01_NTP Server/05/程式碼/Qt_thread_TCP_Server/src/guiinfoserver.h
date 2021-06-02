#ifndef __GUIINFOSERVER_H__
#define __GUIINFOSERVER_H__

// place your code here
#include <QStringList>
#include <QTcpServer>
#include "timeserver.h"
class GUIInfoServer : public QTcpServer
{
    Q_OBJECT
public:
    GUIInfoServer(TimeServer *ts1,QObject *parent = 0);
    TimeServer *ts;
protected:
    void incomingConnection(int socketDescriptor);
private:
    QStringList Info;
};
#endif // __GUIINFOSERVER_H__
