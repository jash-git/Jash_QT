# -------------------------------------------------
# Project created by QtCreator 2010-04-20T14:55:42
# -------------------------------------------------
QT += network \
    webkit
TARGET = WebKitJS
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    sampleobject.cpp
HEADERS += mainwindow.h \
    sampleqobject.h
FORMS += mainwindow.ui
RESOURCES += resources.qrc
OTHER_FILES += view.html \
    slot.js \
    jquery.js
