#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	TextEdit=textEdit;
}
void DialogImpl::slotBut01()
{
	QString Strbuf,StrData;
	Strbuf=TextEdit->toPlainText();
	StrData="data\n";
	Strbuf+=StrData;
	TextEdit->setText(Strbuf);
	
}
//
