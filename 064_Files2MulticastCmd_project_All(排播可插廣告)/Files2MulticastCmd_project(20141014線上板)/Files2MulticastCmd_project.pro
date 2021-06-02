TEMPLATE = app
SOURCES += src/consoletimer.cpp src/main.cpp src/CProcessThread.cpp
HEADERS += src/consoletimer.h src/CProcessThread.h
QT += core \
 network \
 sql \
 xml \
 script
CONFIG += release build_all
