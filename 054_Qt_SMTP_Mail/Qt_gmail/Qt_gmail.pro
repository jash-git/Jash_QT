TEMPLATE = app
SOURCES += src/main.cpp \
 src/smtpclient.cpp \
 src/quotedprintable.cpp \
 src/mimetext.cpp \
 src/mimepart.cpp \
 src/mimemultipart.cpp \
 src/mimemessage.cpp \
 src/mimeinlinefile.cpp \
 src/mimehtml.cpp \
 src/mimefile.cpp \
 src/mimecontentformatter.cpp \
 src/mimeattachment.cpp \
 src/emailaddress.cpp
HEADERS += src/smtpclient.h \
 src/quotedprintable.h \
 src/mimetext.h \
 src/mimepart.h \
 src/mimemultipart.h \
 src/mimemessage.h \
 src/mimeinlinefile.h \
 src/mimehtml.h \
 src/mimefile.h \
 src/mimecontentformatter.h \
 src/mimeattachment.h \
 src/emailaddress.h
QT += core network gui xml
