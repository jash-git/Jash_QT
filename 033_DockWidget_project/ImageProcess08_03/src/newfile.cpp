#include "newfile.h"
newfile::newfile( QWidget * parent) 
	: QWidget( parent)
{
	ui.setupUi(this);
}
void newfile::slot1()
{
	QMessageBox mb;
	mb.setText("test");
	mb.exec();
}
// place your code here
