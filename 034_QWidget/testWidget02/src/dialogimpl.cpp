#include "dialogimpl.h"
#include "newfile.h"

//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	
}
void DialogImpl::slot1()
{
	newfile *nf=new newfile;
	nf->setWindowFlags(Qt::Dialog);	
	nf->show();
}
//
