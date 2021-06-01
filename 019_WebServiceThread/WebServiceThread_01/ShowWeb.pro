TEMPLATE = app
QT = gui \
 core \
 network \
 webkit \
 xml
CONFIG += qt release warn_on console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/dialog.ui
HEADERS = src/dialogimpl.h src/WebServiceThread.h
SOURCES = src/dialogimpl.cpp src/main.cpp src/WebServiceThread.cpp
