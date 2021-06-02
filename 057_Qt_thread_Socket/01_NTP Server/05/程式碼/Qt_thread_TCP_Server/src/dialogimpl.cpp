#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	labShow=label;
	timeserver = new TimeServer(labShow,this);
	label->setText("資訊：服務正在啟動中...");
	if (!timeserver->listen(QHostAddress::Any,7052))
	{
		close();
		return;
	}
	guiinfoserver= new GUIInfoServer(timeserver,this);
	if (!guiinfoserver->listen(QHostAddress::Any,2507))
	{
		close();
		return;
	}	
	label->setText("資訊：服務已經開始服務...\n");
}
void DialogImpl::slotExit()
{
	close();
}

//
