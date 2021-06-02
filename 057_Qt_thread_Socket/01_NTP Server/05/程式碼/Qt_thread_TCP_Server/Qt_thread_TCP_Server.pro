TEMPLATE = app
QT = gui core network
CONFIG += qt release warn_on console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/dialog.ui
HEADERS = src/dialogimpl.h \
 src/timethread.h \
 src/timeserver.h \
 src/guiinfoserver.h \
 src/guiinfothread.h
SOURCES = src/dialogimpl.cpp \
 src/main.cpp \
 src/timethread.cpp \
 src/timeserver.cpp \
 src/guiinfoserver.cpp \
 src/guiinfothread.cpp
