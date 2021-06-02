#include <QtCore>
#include <QtDebug>
#include "imagewidget.h"
double gdblGray[255];//灰階值統計紀錄
double gdblMax;//最多的灰階值
ImageWidget::ImageWidget(QWidget *parent)
	: QWidget(parent)
{
	QDesktopWidget desktop;
	pixmap = QPixmap(desktop.width(), desktop.height());
	intcheckGray=0;
	scale = 1;
	angle = 0;
	bFit = true;
	int i;
	for(i=0;i<255;i++)
	{
		gdblGray[i]=0.0;
	}
    setAcceptDrops(true);
}

void ImageWidget::paintEvent(QPaintEvent *event)
{
	QPaintEvent *event01;
	event01=event;	
	QPainter painter(this);
	if(angle)
	{
	    QPointF center(width()/2.0,height()/2.0);
		painter.translate(center);
		painter.rotate(angle);
		painter.translate(-center);
	}
	if(bFit)
	{
		QPixmap fitPixmap = pixmap.scaled(width(),height(), Qt::KeepAspectRatio);
		painter.drawPixmap(0, 0, fitPixmap);
	}
	else
		painter.drawPixmap(0, 0, pixmap);
}

void ImageWidget::setPixmap(QString fileName)
{
	pixmap.load(fileName);
	image=pixmap.toImage();
	intcheckGray=0;
	update();
}
void ImageWidget::Threshold(int thresh,int mode)
{
	int intW,intH;
	int i,j;
	QColor Color1;
	QRgb value; 
	int intR,intG,intB;
	int intGray;
	intH=imageGray.height();
	intW=imageGray.width();
	if(intcheckGray!=1)
	{
		toGray();
	}
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			Color1.setRgb(imageGray.pixel(i,j));
			intR=Color1.red();
			intG=Color1.green();
			intB=Color1.blue();
			switch(mode)
			{
				case 2:
				if(intR<=thresh)
				{
					intGray=255;
				}
				else
				{
					intGray=0;
				}
				break;
				default:
				if(intR<=thresh)
				{
					intGray=0;
				}
				else
				{
					intGray=255;
				}
				break;
			}
			value=qRgb(intGray, intGray, intGray);
			imageGray.setPixel(i,j,value);
		}
	}
	pixmap=QPixmap::fromImage(imageGray);
	update();
}
void ImageWidget::toGray()
{
	int intW,intH;
	int i,j;
	QColor Color1;
	QRgb value; 
	int intR,intG,intB;
	int intGray;
	imageGray=image;
	intH=imageGray.height();
	intW=imageGray.width();
	for(i=0;i<255;i++)
	{
		gdblGray[i]=0.0;
	}
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			Color1.setRgb(imageGray.pixel(i,j));
			intR=Color1.red();
			intG=Color1.green();
			intB=Color1.blue();
			intGray=(int)(0.299*intR+0.587*intG+0.114*intB);
			gdblGray[(intGray-1)]+=1.0;
			value=qRgb(intGray, intGray, intGray);
			imageGray.setPixel(i,j,value);
		}
	}
	gdblMax=gdblGray[0];
	for(i=1;i<255;i++)
	{
		if(gdblGray[i]>gdblMax)
		{
			gdblMax=gdblGray[i];
		}
	}
	pixmap=QPixmap::fromImage(imageGray);
	intcheckGray=1;
	update();
}
QPixmap ImageWidget::getPixmap()
{
	return pixmap;
}

void ImageWidget::setAngle(qreal rotateAngle)
{
	angle += rotateAngle;
	update();
}

void ImageWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
		QString localFile;
		QRegExp rx("\\.(jpg|bmp|jpeg|png|xpm)$", Qt::CaseInsensitive);
		foreach(QUrl url , event->mimeData()->urls()) {
			localFile = url.toLocalFile();
			if(rx.indexIn(localFile) >= 0) {
				event->accept();
				return;
			}
			else {
			        event->ignore();
			}
		}
    } else {
        event->ignore();
    }
}

void ImageWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasUrls()) {
		QString localFile;
		QRegExp rx("\\.(jpg|bmp|jpeg|png|xpm)$", Qt::CaseInsensitive);
		foreach(QUrl url , event->mimeData()->urls()) {
			localFile = url.toLocalFile();
			if(rx.indexIn(localFile) >= 0) {
				event->accept();
				setPixmap(localFile);
				return;
			}
			else {
			        event->ignore();
			}
		}
    } else {
        event->ignore();
    }
}

void ImageWidget::dragLeaveEvent(QDragLeaveEvent *event)
{
 	event->accept();
}
void ImageWidget::toImR()
{
	int intW,intH;
	int i,j;
	QColor Color1;
	QRgb value; 
	int intR,intG,intB;
	int intGray;
	imageGray=image;
	intH=imageGray.height();
	intW=imageGray.width();
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			Color1.setRgb(imageGray.pixel(i,j));
			intR=Color1.red();
			intG=Color1.green();
			intB=Color1.blue();
			intGray=intR;
			value=qRgb(intGray, 0, 0);
			imageGray.setPixel(i,j,value);
		}
	}
	pixmap=QPixmap::fromImage(imageGray);
	update();
}
void ImageWidget::toImG()
{
	int intW,intH;
	int i,j;
	QColor Color1;
	QRgb value; 
	int intR,intG,intB;
	int intGray;
	imageGray=image;
	intH=imageGray.height();
	intW=imageGray.width();
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			Color1.setRgb(imageGray.pixel(i,j));
			intR=Color1.red();
			intG=Color1.green();
			intB=Color1.blue();
			intGray=intG;
			value=qRgb( 0,intGray, 0);
			imageGray.setPixel(i,j,value);
		}
	}
	pixmap=QPixmap::fromImage(imageGray);
	update();
}
void ImageWidget::toImB() 
{
	int intW,intH;
	int i,j;
	QColor Color1;
	QRgb value; 
	int intR,intG,intB;
	int intGray;
	imageGray=image;
	intH=imageGray.height();
	intW=imageGray.width();
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			Color1.setRgb(imageGray.pixel(i,j));
			intR=Color1.red();
			intG=Color1.green();
			intB=Color1.blue();
			intGray=intB;
			value=qRgb( 0, 0,intGray);
			imageGray.setPixel(i,j,value);
		}
	}
	pixmap=QPixmap::fromImage(imageGray);
	update();	
}
void ImageWidget::toGradient()
{
	toGray();
	int cx[9]={0,0,0,
	0,1,0,
	0,0,-1};
	int cy[9]={0,0,0,
	0,0,1,
	0,-1,0};
	int d[9];
	int i,j;
	float xx,yy,zz;
	int intW,intH;
	QColor Color1;
	QRgb value;
	int intGray;
	intH=imageGray.height();
	intW=imageGray.width();
	for(j=1;j<intH;j++)
	{
		for(i=1;i<intW;i++)
		{
			Color1.setRgb(imageGray.pixel(i-1,j-1));
			d[0]=Color1.red();
			Color1.setRgb(imageGray.pixel(i,j-1));
			d[1]=Color1.red();
			Color1.setRgb(imageGray.pixel(i+1,j-1));
			d[2]=Color1.red();
			Color1.setRgb(imageGray.pixel(i-1,j));
			d[3]=Color1.red();
			Color1.setRgb(imageGray.pixel(i,j));
			d[4]=Color1.red();
			Color1.setRgb(imageGray.pixel(i+1,j));
			d[5]=Color1.red();
			Color1.setRgb(imageGray.pixel(i-1,j+1));
			d[6]=Color1.red();
			Color1.setRgb(imageGray.pixel(i,j+1));
			d[7]=Color1.red();
			Color1.setRgb(imageGray.pixel(i+1,j+1));
			d[8]=Color1.red();
			xx=(float)(cx[0]*d[0]+cx[1]*d[1]+cx[2]*d[2]
			          +cx[3]*d[3]+cx[4]*d[4]+cx[5]*d[5]
			          +cx[6]*d[6]+cx[7]*d[7]+cx[8]*d[8]);
			yy=(float)(cy[0]*d[0]+cy[1]*d[1]+cy[2]*d[2]
			          +cy[3]*d[3]+cy[4]*d[4]+cy[5]*d[5]
			          +cy[6]*d[6]+cy[7]*d[7]+cy[8]*d[8]);
			zz=(float)sqrt(xx*xx+yy*yy);
			intGray=(int)zz;
			value=qRgb( intGray, intGray,intGray);
			imageGray.setPixel(i,j,value);
		}
	}
	pixmap=QPixmap::fromImage(imageGray);
	update();	
}
void ImageWidget::toLaplacian()
{
	toGray();
	int c[9]={-1,-1,-1,
	-1,8,-1,
	-1,-1,-1};
	int d[9];
	int i,j;
	float zz;
	int intW,intH;
	QColor Color1;
	QRgb value;
	int intGray;
	intH=imageGray.height();
	intW=imageGray.width();
	for(j=1;j<intH;j++)
	{
		for(i=1;i<intW;i++)
		{
			Color1.setRgb(imageGray.pixel(i-1,j-1));
			d[0]=Color1.red();
			Color1.setRgb(imageGray.pixel(i,j-1));
			d[1]=Color1.red();
			Color1.setRgb(imageGray.pixel(i+1,j-1));
			d[2]=Color1.red();
			Color1.setRgb(imageGray.pixel(i-1,j));
			d[3]=Color1.red();
			Color1.setRgb(imageGray.pixel(i,j));
			d[4]=Color1.red();
			Color1.setRgb(imageGray.pixel(i+1,j));
			d[5]=Color1.red();
			Color1.setRgb(imageGray.pixel(i-1,j+1));
			d[6]=Color1.red();
			Color1.setRgb(imageGray.pixel(i,j+1));
			d[7]=Color1.red();
			Color1.setRgb(imageGray.pixel(i+1,j+1));
			d[8]=Color1.red();
			zz=(float)(c[0]*d[0]+c[1]*d[1]+c[2]*d[2]
			          +c[3]*d[3]+c[4]*d[4]+c[5]*d[5]
			          +c[6]*d[6]+c[7]*d[7]+c[8]*d[8]);
			intGray=(int)zz;
			if(intGray<0)
				intGray=-intGray;
			if(intGray>255)
				intGray=255;
			value=qRgb( intGray, intGray,intGray);
			imageGray.setPixel(i,j,value);
		}
	}
	pixmap=QPixmap::fromImage(imageGray);
	update();
}
void ImageWidget::toSaveFile(QString StrFileName)
{
	pixmap.save(StrFileName,"BMP");
}