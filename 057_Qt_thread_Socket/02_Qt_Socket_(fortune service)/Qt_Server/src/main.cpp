﻿//main.cpp
#include <QApplication>
#include <QtCore>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog dialog;
    dialog.show();
    return dialog.exec();
}