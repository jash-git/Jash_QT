#include "dialogimpl.h"
#include "newfile.h"
#include <QString>
#include <QMessageBox>
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	newfile newfile01;
	if(newfile01.exec()==QDialog::Accepted)
	{
		QString Str01;
		Str01=newfile01.lineEdit->text();
		QMessageBox me;
		me.setText(Str01);
		me.exec();
	}
}
//
