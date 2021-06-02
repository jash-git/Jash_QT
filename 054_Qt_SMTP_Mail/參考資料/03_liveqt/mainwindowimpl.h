#ifndef _MAINWINDOW_IMPL_H
#define _MAINWINDOW_IMPL_H

#if USE_QPE
#include <qpeapplication.h>
#else
#include <qapplication.h>
#endif

#include "mainwindow.h"
#include "login.h"
#include "ljinterface.h"

class MainWindowImpl : public Main_Window {
	Q_OBJECT

	public:
		void showEvent(QShowEvent*);
		void closeEvent(QCloseEvent*);
		void customEvent(QCustomEvent*);

		MainWindowImpl(QWidget* parent = 0, const char* name = 0, 
						WFlags fl = 0 );

		~MainWindowImpl();

	public slots:
		void post_comment();
		void login_accept();
		void login_cancel();
		void user_changed(const QString&);

	signals:
		void timeToDieSignal();

	private:
		LoginDialog *ld;
		LJInterface interface;
		bool loginUser();
		bool timeToDie;
};
#endif
