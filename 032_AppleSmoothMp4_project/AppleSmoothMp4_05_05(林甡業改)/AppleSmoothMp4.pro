TEMPLATE = app
QT = gui \
 core \
 xml \
 webkit \
 network
CONFIG += qt warn_on console release
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/dialog.ui ui/MainWidget.ui
HEADERS = src/dialogimpl.h src/CProcessThread.h
SOURCES = src/dialogimpl.cpp src/main.cpp src/CProcessThread.cpp
