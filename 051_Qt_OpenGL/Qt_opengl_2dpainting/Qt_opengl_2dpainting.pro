TEMPLATE = app
HEADERS += window.h widget.h helper.h glwidget.h
SOURCES += window.cpp \
 widget.cpp \
 main.cpp \
 helper.cpp \
 glwidget.cpp
QT += opengl \
 core \
 gui \
 xml \
 sql \
 network \
 script \
 webkit \
 xmlpatterns \
 qt3support
CONFIG += release
