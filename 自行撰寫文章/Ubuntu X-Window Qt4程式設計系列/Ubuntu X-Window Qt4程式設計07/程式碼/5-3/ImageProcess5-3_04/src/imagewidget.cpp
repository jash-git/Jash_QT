#include <QtCore>
#include <QtDebug>
#include <math.h>
#include "imagewidget.h"
double gdblGray[256];//灰階值統計紀錄//5-2 by jash
double gdblMax;//5-3 by jash
int gintGrayMin;//5-3 by jash
int gintGrayMax;//5-3 by jash
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
	imageSource=pixmap.toImage();//將圖形資料存放到指定變數//5-2 by jash
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
void ImageWidget::toGray()//5-2 by jash
{
	int intW,intH;
	int i,j;
	QColor Color1;
	QRgb value; 
	int intR,intG,intB;
	int intGray;
	bool blnfindMin=false;//5-3 by jash
	imageActive=pixmap.toImage();//5-3 by jash
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度
	for(i=0;i<256;i++)//清空紀錄灰階值方圖變數
	{
		gdblGray[i]=0.0;
	}
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			Color1.setRgb(imageActive.pixel(i,j));//依序取出每個像素的資料
			intR=Color1.red();//取出紅色的成份
			intG=Color1.green();//取出綠色成份
			intB=Color1.blue();//取出藍色的成份
			intGray=(int)(0.299*intR+0.587*intG+0.114*intB);//計算灰階值
			gdblGray[intGray]+=1.0;//紀錄灰階值方圖
			value=qRgb(intGray, intGray, intGray);//產生像素變數
			imageActive.setPixel(i,j,value);//設定像素
		}
	}
	/////////////////////
	//5-3 by jash
	gdblMax=gdblGray[0];
	if(gdblMax>0)
	{
		blnfindMin=true;
		gintGrayMin=0;
	}
	for(i=1;i<255;i++)
	{
		if(gdblGray[i]>0)
		{
			if(!blnfindMin)
			{
				blnfindMin=true;
				gintGrayMin=i;	
			}
			gintGrayMax=i;
		}
		if(gdblGray[i]>gdblMax)
		{
			gdblMax=gdblGray[i];
		}
	}
	/////////////////////
	pixmap=QPixmap::fromImage(imageActive);
	update();
}
void ImageWidget::toSource()//5-2 by jash
{
	pixmap=QPixmap::fromImage(imageSource);
	update();	
}
void ImageWidget::toThreshold(int intValue)//5-2 by jash
{
	int intW,intH;
	int i,j;
	QColor Color1;
	QRgb value; 
	int intR,intG,intB;
	int intGray;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度	
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			Color1.setRgb(imageActive.pixel(i,j));
			intR=Color1.red();
			intG=Color1.green();
			intB=Color1.blue();
			if(intR<=intValue)
			{
				intGray=0;
			}
			else
			{
				intGray=255;
			}
			value=qRgb(intGray, intGray, intGray);
			imageActive.setPixel(i,j,value);
		}
	}
	pixmap=QPixmap::fromImage(imageActive);
	update();
}
int ImageWidget::toOTSU()//5-2 by jash
{
	double N,P[256],Sum_Pi[256],Sum_Pi_i[256];
	double W1,W2,U1,U2;
	double Sigma_1_square,Sigma_2_square,Sigma_w_square;
	double MinVariance=(double)(1.7e+308);
	int intW,intH;
	int T_optimal = 0;
	int i,T;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度	
	N =intW*intH;//總像素
	for(i=0;i<256;i++)
	{
		P[i]=gdblGray[i]/N;//計算每一灰階值出現的機率
	}
	Sum_Pi[0]=P[0];
	Sum_Pi_i[0]=0;
	for(i=1;i<256;i++)
	{
		Sum_Pi[i]=Sum_Pi[i-1]+P[i];
		Sum_Pi_i[i]=Sum_Pi_i[i-1]+P[i]*i;
	}
	for(T=1;T<=254;T++)
	{
		W1=Sum_Pi[T];
		if(fabs(W1) < 1e-9)
		{
			W1 = 1e-9;
		}
		W2=1-W1;
		if(fabs(W2) < 1e-9)
		{
			W2 = 1e-9;
		}
		U1=Sum_Pi_i[T]/W1;
		U2=(Sum_Pi_i[255]-Sum_Pi_i[T])/W2;
		Sigma_1_square=0;
		for(i=0;i<=T;i++)
		{
			Sigma_1_square+=((double)i-U1)*((double)i-U1)*P[i];
		}
		Sigma_1_square=Sigma_1_square/W1;
		Sigma_2_square=0;
		for(i=T+1;i<=255;i++)
		{
			Sigma_2_square+=((double)i-U2)*((double)i-U2)*P[i];
		}
		Sigma_2_square=Sigma_2_square/W2;
		Sigma_w_square=W1*Sigma_1_square+W2*Sigma_2_square;
		if(Sigma_w_square<MinVariance)
		{
			MinVariance=Sigma_w_square;
			T_optimal=T;
		}
	}
	return T_optimal;
}
void ImageWidget::toEqualize()//5-3 by jash
{
	double dblMap[256];
	int i=0;
	int j=0;
	long lngTemp=0;
	int intW,intH;
	int intGray;
	QColor Color1;
	QRgb value;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度	
	//toGray();
	for(i=0;i<256;i++)
	{
		dblMap[i]=0.0;
	}
	for(i=0;i<256;i++)
	{
		lngTemp=0;
		for(j=0;j<=i;j++)
		{
			lngTemp+=gdblGray[j];
		}
		dblMap[i]=lngTemp*255/intW/intH;
	}
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			Color1.setRgb(imageActive.pixel(i,j));//依序取出每個像素的資料
			intGray=Color1.red();//取出灰階的成份
			value=qRgb(dblMap[intGray], dblMap[intGray], dblMap[intGray]);//產生像素變數
			imageActive.setPixel(i,j,value);//設定像素
		}
	}

	//imageEqualize=imageActive;
	bool blnfindMin=false;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度
	for(i=0;i<256;i++)//清空紀錄灰階值方圖變數
	{
		gdblGray[i]=0.0;
	}
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			Color1.setRgb(imageActive.pixel(i,j));//依序取出每個像素的資料
			intGray=Color1.red();//取出紅色的成份			
			gdblGray[intGray]+=1.0;//紀錄灰階值方圖
		}
	}
	/////////////////////
	gdblMax=gdblGray[0];
	if(gdblMax>0)
	{
		blnfindMin=true;
		gintGrayMin=0;
	}
	for(i=1;i<255;i++)
	{
		if(gdblGray[i]>0)
		{
			if(!blnfindMin)
			{
				blnfindMin=true;
				gintGrayMin=i;	
			}
			gintGrayMax=i;
		}
		if(gdblGray[i]>gdblMax)
		{
			gdblMax=gdblGray[i];
		}
	}
	/////////////////////
	pixmap=QPixmap::fromImage(imageActive);
	update();
}
void ImageWidget::toSaveFile(QString StrFileName)
{
	pixmap.save(StrFileName,"BMP");
}
void ImageWidget::toTranslation(int intXoffset,int intYoffset)
{
	int i,j;
	int intX,intY;
	int intW,intH;
	QRgb value1;  
	intX=intXoffset;
	intY=intYoffset;
	QImage imageScreen;
	imageScreen=pixmap.toImage();
	imageActive=imageSource;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			if((i-intX>0) && (i-intX<intW) && (j-intY>0) && (j-intY<intH))
			{
				imageActive.setPixel(i,j,imageScreen.pixel(i-intX,j-intY));//設定像素
			}
			else
			{
				value1=qRgb(255, 255, 255);
				imageActive.setPixel(i,j,value1);//設定像素
			}
		}
	}
	pixmap=QPixmap::fromImage(imageActive);
	update();
}
void ImageWidget::toHorMirror()//5-3 by jash
{
	int i,j;
	int u;
	int intW,intH;
	QImage imageScreen;
	imageScreen=pixmap.toImage();
	imageActive=imageSource;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度
	for(i=0;i<intW;i++)
	{
		u=intW-i-1;
		for(j=0;j<intH;j++)
		{
			imageActive.setPixel(i,j,imageScreen.pixel(u,j));		
		}
	}
	pixmap=QPixmap::fromImage(imageActive);
	update();
}
void ImageWidget::toVerMirror()//5-3 by jash
{
	int i,j;
	int u;
	int intW,intH;
	QImage imageScreen;
	imageScreen=pixmap.toImage();
	imageActive=imageSource;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			u=intH-j-1;
			imageActive.setPixel(i,j,imageScreen.pixel(i,u));
		}
	}
	pixmap=QPixmap::fromImage(imageActive);
	update();
}
void ImageWidget::toTranspose()
{
	int i,j;
	int intW,intH;
	QRgb value;
	QImage imageScreen;
	imageScreen=pixmap.toImage();
	imageActive=imageSource;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			if((j<intW) && (i<intH))
			{
				imageActive.setPixel(i,j,imageScreen.pixel(j,i));
			}
			else
			{
				value=qRgb(255, 255, 255);
				imageActive.setPixel(i,j,value);//設定像素
			}
			
		}
	}
	pixmap=QPixmap::fromImage(imageActive);
	update();	
}
void ImageWidget::toScale(double dblScale)
{
	int i,j;
	int intW,intH;
	QRgb value;
	QImage imageScreen;
	imageScreen=pixmap.toImage();
	imageActive=imageSource;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度
	for(i=0;i<intW;i++)
	{
		for(j=0;j<intH;j++)
		{
			if((int(i*1/dblScale+0.5)<intW) && (int(j*1/dblScale+0.5)<intH))
			{
				imageActive.setPixel(i,j,imageScreen.pixel(int(i*1/dblScale+0.5),int(j*1/dblScale+0.5)));
			}
			else
			{
				value=qRgb(255, 255, 255);
				imageActive.setPixel(i,j,value);//設定像素
			}
			
		}
	}
	pixmap=QPixmap::fromImage(imageActive);
	update();	
}