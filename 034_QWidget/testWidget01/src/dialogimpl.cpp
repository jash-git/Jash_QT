#include "dialogimpl.h"
#include <QWidget>
#include "ui_newfile.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	
}
void DialogImpl::slot1()
{
	Ui::Form uiForm;
	QWidget *pWidget= new QWidget;
	//pWidget->setWindowModality(Qt::ApplicationModal);
	uiForm.setupUi(pWidget);
	pWidget->setWindowFlags(Qt::Dialog);	
	pWidget->show();
}
//
