#include <QtCore>
#include <QtDebug>
#include "imagewidget.h"

ImageWidget::ImageWidget(QWidget *parent)
	: QWidget(parent)
{
	QDesktopWidget desktop;
	pixmap = QPixmap(desktop.width(), desktop.height());
	scale = 1;
	angle = 0;
	bFit = true;

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
	intH=image.height();
	intW=image.width();
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			Color1.setRgb(image.pixel(i,j));
			intR=Color1.red();
			intG=Color1.green();
			intB=Color1.blue();
			intGray=(int)(0.299*intR+0.587*intG+0.114*intB);
			value=qRgb(intGray, intGray, intGray);
			image.setPixel(i,j,value);
		}
	}
	pixmap=QPixmap::fromImage(image);
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

