#include "HistogramWidget.h"
extern double gdblGray[255];
HistogramWidget::HistogramWidget( QWidget * parent, Qt::WFlags f) : QDialog(parent, f)
{
	setupUi(this);
	DrawLabel=label;
	intW=DrawLabel->width();
	intH=DrawLabel->height();
	pixmap=new QPixmap(intW,intH);
	pixmap->fill();
	////////////////////////////////////
	int i=0;
	double j;
	int intdata;
	QPainter painter(pixmap);
	painter.setPen( QPen(Qt::blue, 3));
	for(i=0;i<255;i++)
	{
		j= gdblGray[i];
		intdata=j/5;
		painter.drawLine(i+1, intH, i+1,intH-intdata);	
	}
	//painter.drawLine(0, intH, intW,0);
	DrawLabel->setPixmap(*pixmap);	
}
HistogramWidget::~HistogramWidget()
{
	delete pixmap;
}
// place your code here
