#include "ShowHistogram.h"
#include <stdio.h>
extern double gdblGray[256];
extern double gdblMax;
extern int gintGrayMin;
extern int gintGrayMax;
ShowHistogramDlg::ShowHistogramDlg( QWidget * parent, Qt::WFlags f) : QDialog(parent, f)
{
	FILE *pf;
	setupUi(this);
	DrawLabel=label;
	QString StrGrayMin,StrGrayMax;
	MaxLineEdit=lineEdit_Max;
	MinLineEdit=lineEdit_Min;
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
	for(i=0;i<256;i++)
	{
		j= gdblGray[i];
		intdata=j/(gdblMax/intH);
		painter.drawLine((i*2), intH, (i*2),(intH-intdata));
		fprintf(pf,"%d\t%f\r\n",i, gdblGray[i]);	
	}
	fclose(pf);
	StrGrayMin.setNum(gintGrayMin);
	MinLineEdit->setText(StrGrayMin);
	StrGrayMax.setNum(gintGrayMax);
	MaxLineEdit->setText(StrGrayMax);
	//painter.drawLine(0, intH, intW,0);
	DrawLabel->setPixmap(*pixmap);	
}
ShowHistogramDlg::~ShowHistogramDlg()
{
	delete pixmap;
}
// place your code here
