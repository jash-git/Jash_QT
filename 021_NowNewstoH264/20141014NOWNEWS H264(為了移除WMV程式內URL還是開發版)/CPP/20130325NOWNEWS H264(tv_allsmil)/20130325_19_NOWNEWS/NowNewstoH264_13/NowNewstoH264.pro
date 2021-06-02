TEMPLATE = app
QT = gui \
 core \
 xml \
 network \
 webkit
CONFIG += qt warn_on console release
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/dialog.ui ui/Form.ui
HEADERS = src/dialogimpl.h src/HttpGet.h src/SleeperThread.h src/CProcessThread.h
SOURCES = src/dialogimpl.cpp \
 src/main.cpp \
 src/HttpGet.cpp \
 src/SleeperThread.cpp \
 src/CProcessThread.cpp
