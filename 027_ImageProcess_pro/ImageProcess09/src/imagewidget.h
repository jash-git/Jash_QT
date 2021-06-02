#ifndef IMAGEWIDGET_H_
#define IMAGEWIDGET_H_

#include <QtGui>
#include <QPixmap>
#include <QImage>
#include <QColor>
class ImageWidget : public QWidget
{
	Q_OBJECT
	
public:
	bool bFit;
	qreal scale;
	int intcheckGray;
public:
	ImageWidget(QWidget *parent = 0);
	void setPixmap(QString fileName);
	void toGray();
	QPixmap getPixmap();
	void setAngle(qreal rotateAngle);
	void Threshold(int thresh,int mode);
	    
protected:
	void paintEvent(QPaintEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);
	void dragLeaveEvent(QDragLeaveEvent *event);

private:
	QPixmap pixmap;
	QImage image;
	QImage imageGray; 
	qreal angle;
};

#endif /*IMAGEWIDGET_H_*/
