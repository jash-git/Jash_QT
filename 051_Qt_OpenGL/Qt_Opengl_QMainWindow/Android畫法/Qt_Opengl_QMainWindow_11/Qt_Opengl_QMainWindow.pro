HEADERS += mainwindow.h glwidget.h GLFun.h
SOURCES += mainwindow.cpp main.cpp glwidget.cpp
QT += script \
 gui \
 xml \
 sql \
 network \
 core \
 opengl
CONFIG += build_all release -lglut
TEMPLATE = app
