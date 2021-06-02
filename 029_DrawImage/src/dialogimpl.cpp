#include "dialogimpl.h"

//
//DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) : QWidget(parent, f)
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) : QDialog(parent, f)
{
	setupUi(this);
	DrawLabel=label;
	intW=DrawLabel->width();
	intH=DrawLabel->height();
	pixmap=new QPixmap(intW,intH);
	pixmap->fill();
}
DialogImpl::~DialogImpl()
{
	delete pixmap;
}
void DialogImpl::slotButton()
{
	QPainter painter(pixmap);
	painter.setPen( QPen(Qt::blue, 3));
	painter.drawLine(0, 0, intW,intH);
	painter.drawLine(0, intH, intW,0);
	DrawLabel->setPixmap(*pixmap);
}

//
