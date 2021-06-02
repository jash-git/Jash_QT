HEADERS += mainwindow.h glwidget.h GLFun.h
SOURCES += mainwindow.cpp main.cpp glwidget.cpp
QT += script \
 gui \
 xml \
 sql \
 network \
 core \
 opengl
CONFIG += release build_all -lglut
TEMPLATE = app
