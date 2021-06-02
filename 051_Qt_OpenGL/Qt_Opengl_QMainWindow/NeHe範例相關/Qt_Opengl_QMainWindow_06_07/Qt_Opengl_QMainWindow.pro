TEMPLATE = app
HEADERS += mainwindow.h glwidget.h
SOURCES += mainwindow.cpp main.cpp glwidget.cpp
QT += script \
 gui \
 xml \
 sql \
 network \
 core \
 opengl
CONFIG += release build_all
