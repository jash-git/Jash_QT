#ifndef __GUIINFOSERVER_H__
#define __GUIINFOSERVER_H__

// place your code here
#include <QStringList>
#include <QTcpServer>

class GUIInfoServer : public QTcpServer
{
    Q_OBJECT
public:
    GUIInfoServer(QObject *parent = 0);
    int m_intCount,m_intNowOnline;
protected:
    void incomingConnection(int socketDescriptor);
private:
    QStringList Info;
};
#endif // __GUIINFOSERVER_H__
