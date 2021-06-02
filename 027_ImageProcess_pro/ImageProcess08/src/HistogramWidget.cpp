#include "HistogramWidget.h"
#include <stdio.h>
extern double gdblGray[255];
extern double gdblMax;
HistogramWidget::HistogramWidget( QWidget * parent, Qt::WFlags f) : QDialog(parent, f)
{
	FILE *pf;
	setupUi(this);
	DrawLabel=label;
	intW=DrawLabel->width();
	intH=DrawLabel->height();
	pixmap=new QPixmap(intW,intH);
	pixmap->fill();
	////////////////////////////////////
	pf=fopen("ImageGrayDatalog.txt","w");
	int i=0;
	double j;
	int intdata;
	QPainter painter(pixmap);
	painter.setPen( QPen(Qt::blue, 3));
	for(i=0;i<255;i++)
	{
		j= gdblGray[i];
		intdata=j/(gdblMax/intH);
		painter.drawLine((i*2), intH, (i*2),(intH-intdata));
		fprintf(pf,"%d\t%f\r\n",(i+1), gdblGray[i]);	
	}
	fclose(pf);
	//painter.drawLine(0, intH, intW,0);
	DrawLabel->setPixmap(*pixmap);	
}
HistogramWidget::~HistogramWidget()
{
	delete pixmap;
}
// place your code here
