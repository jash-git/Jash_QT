TEMPLATE = app
QT = gui core
CONFIG += qt warn_on console release
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui \
 ui/SetThresholdDlg.ui \
 ui/ShowHistogramDlg.ui \
 ui/SetTranslationDlg.ui \
 ui/SetScaleDlg.ui
HEADERS = src/mainwindowimpl.h \
 src/imagewidget.h \
 src/SetThresholdDlg.h \
 src/ShowHistogram.h \
 src/SetTranslation.h \
 src/SetScale.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/imagewidget.cpp \
 src/SetThresholdDlg.cpp \
 src/ShowHistogram.cpp \
 src/SetTranslation.cpp \
 src/SetScale.cpp
