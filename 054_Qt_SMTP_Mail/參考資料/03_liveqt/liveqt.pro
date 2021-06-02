TEMPLATE	= app
CONFIG		= qt warn_on release
TMAKE_CFLAGS		+= -g -fno-default-inline -fbounds-check
TMAKE_CXXFLAGS		+= -g -fno-default-inline -fbounds-check
TMAKE_LFLAGS		+= -g -fno-default-inline -fbounds-check
HEADERS		= ljinterface.h ljhttp.h ljconfigparser.h md5.h mainwindowimpl.h
SOURCES		= main.cpp ljinterface.cpp ljhttp.cpp ljconfigparser.cpp md5.c \
				mainwindowimpl.cpp
INTERFACES	= mainwindow.ui login.ui
REQUIRES	= network
linux-arm-g++:INCLUDEPATH	+= $(HOME)/qpe-1.4.0/library
linux-arm-g++:LIBS		+= -lqpe
linux-arm-g++:DEFINES	+= USE_QPE
