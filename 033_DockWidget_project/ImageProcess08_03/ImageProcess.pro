TEMPLATE = app
QT = gui core
CONFIG += qt release warn_on console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/HistogramDialog.ui ui/Histogram.ui
HEADERS = src/mainwindowimpl.h \
 src/imagewidget.h \
 src/HistogramWidget.h \
 src/ShapDockWidget.h \
 src/newfile.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/imagewidget.cpp \
 src/HistogramWidget.cpp \
 src/ShapDockWidget.cpp \
 src/newfile.cpp
RESOURCES += src/ImageProcess.qrc
