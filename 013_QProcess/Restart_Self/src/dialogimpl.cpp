#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
void DialogImpl::slotReStart()
{
	qApp->quit();
	QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}
//
