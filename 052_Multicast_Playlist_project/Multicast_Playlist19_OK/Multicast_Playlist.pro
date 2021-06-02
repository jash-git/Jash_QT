TEMPLATE = app
QT = gui \
 core \
 xml \
 sql \
 network
CONFIG += qt \
 warn_on \
 console \
 build_all \
 release
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/dialog.ui
HEADERS = src/dialogimpl.h
SOURCES = src/dialogimpl.cpp src/main.cpp
