#if USE_QPE
#include <qpeapplication.h>
#else
#include <qapplication.h>
#endif
#include "mainwindowimpl.h"

#include <signal.h>
void doquit(int);

#if USE_QPE
    QPEApplication *app;
#else
    QApplication *app;
#endif

int main( int argc, char ** argv )
{
#if USE_QPE
    QPEApplication a( argc, argv );
#else
    QApplication a( argc, argv );
#endif

	//signal(SIGHUP, doquit);
	signal(SIGINT, doquit);
	//signal(SIGQUIT, doquit);

    MainWindowImpl *w = new MainWindowImpl(NULL, "Post LiveJournal Comment"/* , 
					QWidget::WStyle_Customize | QWidget::WStyle_NoBorder*/);
	
    //QPEApplication::setInputMethodHint( &mw, QPEApplication::AlwaysOff );
    // w->show();
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );

#if USE_QPE
	a.showMainWidget(w);
#else
	w->show();
	a.setMainWidget(w);
#endif
    int ret = a.exec();
	return ret;
}

void doquit(int) {
	qApp->closeAllWindows();
}
