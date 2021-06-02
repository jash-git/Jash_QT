//伺服器端
//dialog.h
#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui>
#include <QtNetwork>
#include "fortuneserver.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);

private:
    QLabel *statusLabel;
    QPushButton *quitButton;
    FortuneServer server;
};

#endif