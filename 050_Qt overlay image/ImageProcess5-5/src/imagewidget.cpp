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
void ImageWidget::toRotate(double dblRotate)
{
	int i,j;
	int u,v;
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
			u=int(i*cos(dblRotate*3.14159/180)+j*sin(dblRotate*3.14159/180)+0.5);
			v=int(j*cos(dblRotate*3.14159/180)-i*sin(dblRotate*3.14159/180)+0.5);
			if((u<intW) && (v<intH) && u>=0 && v>=0)
			{
				imageActive.setPixel(i,j,imageScreen.pixel(u,v));
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
void ImageWidget::toSobel()//5-4 by jash
{
	int cx[9]= {0, 0, 0,
				0, 1,-1,
				0, 0, 0};
	int cy[9]= {0, 0, 0,
				0, 1, 0,
				0,-1, 0};
	int d[9];
	int dat;
	float xx,yy,zz;
	int intW,intH;
	int i,j;
	QColor Color[9];
	QRgb value; 
	int X_Size,Y_Size;
	QImage imageScreen;
	imageScreen=pixmap.toImage();
	imageActive=imageScreen;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度
	X_Size=intW-1;
	Y_Size=intH-1;
	for(i=1;i<X_Size;i++)
	{
		for(j=1;j<Y_Size;j++)
		{
			Color[0].setRgb(imageActive.pixel(i-1,j-1));
			Color[1].setRgb(imageActive.pixel(i-1,j));
			Color[2].setRgb(imageActive.pixel(i-1,j+1));
			Color[3].setRgb(imageActive.pixel(i,j-1));
			Color[4].setRgb(imageActive.pixel(i,j));
			Color[5].setRgb(imageActive.pixel(i,j+1));
			Color[6].setRgb(imageActive.pixel(i+1,j-1));
			Color[7].setRgb(imageActive.pixel(i+1,j));
			Color[8].setRgb(imageActive.pixel(i+1,j+1));
			d[0]=Color[0].red();
			d[1]=Color[1].red();
			d[2]=Color[2].red();
			d[3]=Color[3].red();
			d[4]=Color[4].red();
			d[5]=Color[5].red();
			d[6]=Color[6].red();
			d[7]=Color[7].red();
			d[8]=Color[8].red();
			xx=(float)(cx[0]*d[0]+cx[1]*d[1]+cx[2]*d[2]
					+  cx[3]*d[3]+cx[4]*d[4]+cx[5]*d[5]
					+  cx[6]*d[6]+cx[7]*d[7]+cx[8]*d[8]);
			yy=(float)(cy[0]*d[0]+cy[1]*d[1]+cy[2]*d[2]
					+  cy[3]*d[3]+cy[4]*d[4]+cy[5]*d[5]
					+  cy[6]*d[6]+cy[7]*d[7]+cy[8]*d[8]);
			zz=(float)(1*sqrt(xx*xx+yy*yy));
			dat=(int)zz;
			if(dat>=255)
				dat=255;
			else
				dat=0;
			value=qRgb(dat, dat, dat);
			imageActive.setPixel(i,j,value);
		}
	}
	pixmap=QPixmap::fromImage(imageActive);
	update();
}
void ImageWidget::toRoberts()//5-4 by jash
{
	int cx[9]= {0, 0, 0,
				0, 1, 0,
				0, 0,-1};
	int cy[9]= {0, 0, 0,
				0, 0, 1,
				0,-1, 0};
	int d[9];
	int dat;
	float xx,yy,zz;
	int intW,intH;
	int i,j;
	QColor Color[9];
	QRgb value; 
	int X_Size,Y_Size;
	QImage imageScreen;
	imageScreen=pixmap.toImage();
	imageActive=imageScreen;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度
	X_Size=intW-1;
	Y_Size=intH-1;
	for(i=1;i<X_Size;i++)
	{
		for(j=1;j<Y_Size;j++)
		{
			Color[0].setRgb(imageActive.pixel(i-1,j-1));
			Color[1].setRgb(imageActive.pixel(i-1,j));
			Color[2].setRgb(imageActive.pixel(i-1,j+1));
			Color[3].setRgb(imageActive.pixel(i,j-1));
			Color[4].setRgb(imageActive.pixel(i,j));
			Color[5].setRgb(imageActive.pixel(i,j+1));
			Color[6].setRgb(imageActive.pixel(i+1,j-1));
			Color[7].setRgb(imageActive.pixel(i+1,j));
			Color[8].setRgb(imageActive.pixel(i+1,j+1));
			d[0]=Color[0].red();
			d[1]=Color[1].red();
			d[2]=Color[2].red();
			d[3]=Color[3].red();
			d[4]=Color[4].red();
			d[5]=Color[5].red();
			d[6]=Color[6].red();
			d[7]=Color[7].red();
			d[8]=Color[8].red();
			xx=(float)(cx[0]*d[0]+cx[1]*d[1]+cx[2]*d[2]
					+  cx[3]*d[3]+cx[4]*d[4]+cx[5]*d[5]
					+  cx[6]*d[6]+cx[7]*d[7]+cx[8]*d[8]);
			yy=(float)(cy[0]*d[0]+cy[1]*d[1]+cy[2]*d[2]
					+  cy[3]*d[3]+cy[4]*d[4]+cy[5]*d[5]
					+  cy[6]*d[6]+cy[7]*d[7]+cy[8]*d[8]);
			zz=(float)(1*sqrt(xx*xx+yy*yy));
			dat=(int)zz;
			if(dat>=255)
				dat=255;
			else
				dat=0;
			value=qRgb(dat, dat, dat);
			imageActive.setPixel(i,j,value);
		}
	}
	pixmap=QPixmap::fromImage(imageActive);
	update();		
}
void ImageWidget::toLaplacian()//5-4 by jash
{
	int c[9]=  { 0,-1, 0,
				-1, 4,-1,
				 0,-1, 0};
	int d[9];
	int dat;
	float zz,z;
	int intW,intH;
	int i,j;
	QColor Color[9];
	QRgb value; 
	int X_Size,Y_Size;
	QImage imageScreen;
	imageScreen=pixmap.toImage();
	imageActive=imageScreen;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度
	X_Size=intW-1;
	Y_Size=intH-1;
	for(j=1;j<Y_Size;j++)
	{
		for(i=1;i<X_Size;i++)
		{
			Color[0].setRgb(imageActive.pixel(i-1,j-1));
			Color[1].setRgb(imageActive.pixel(i,j-1));
			Color[2].setRgb(imageActive.pixel(i+1,j-1));
			Color[3].setRgb(imageActive.pixel(i-1,j));
			Color[4].setRgb(imageActive.pixel(i,j));
			Color[5].setRgb(imageActive.pixel(i+1,j));
			Color[6].setRgb(imageActive.pixel(i-1,j+1));
			Color[7].setRgb(imageActive.pixel(i,j+1));
			Color[8].setRgb(imageActive.pixel(i+1,j+1));
			d[0]=Color[0].red();
			d[1]=Color[1].red();
			d[2]=Color[2].red();
			d[3]=Color[3].red();
			d[4]=Color[4].red();
			d[5]=Color[5].red();
			d[6]=Color[6].red();
			d[7]=Color[7].red();
			d[8]=Color[8].red();
			z=(float)(c[0]*d[0]+c[1]*d[1]+c[2]*d[2]
					+ c[3]*d[3]+c[4]*d[4]+c[5]*d[5]
					+ c[6]*d[6]+c[7]*d[7]+c[8]*d[8]);
			zz=(float)(10*z);
			dat=(int)zz;
			if(dat < 0)
				dat=-dat;
			if(dat>255)
				dat=255;

			value=qRgb(dat, dat, dat);
			imageActive.setPixel(i,j,value);
		}
	}
	pixmap=QPixmap::fromImage(imageActive);
	update();			
}
void ImageWidget::toPrewitt()//5-4 by jash
{
	int d[9],m[8];
	int dat;
	float zz,max;
	int intW,intH;
	int i,j,k;
	QColor Color[9];
	QRgb value; 
	int X_Size,Y_Size;
	QImage imageScreen;
	imageScreen=pixmap.toImage();
	imageActive=imageScreen;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度
	X_Size=intW-1;
	Y_Size=intH-1;
	for(i=1;i<X_Size;i++)
	{
		for(j=1;j<Y_Size;j++)
		{
			Color[0].setRgb(imageActive.pixel(i-1,j-1));
			Color[1].setRgb(imageActive.pixel(i-1,j));
			Color[2].setRgb(imageActive.pixel(i-1,j+1));
			Color[3].setRgb(imageActive.pixel(i,j-1));
			Color[4].setRgb(imageActive.pixel(i,j));
			Color[5].setRgb(imageActive.pixel(i,j+1));
			Color[6].setRgb(imageActive.pixel(i+1,j-1));
			Color[7].setRgb(imageActive.pixel(i+1,j));
			Color[8].setRgb(imageActive.pixel(i+1,j+1));
			d[0]=Color[0].red();
			d[1]=Color[1].red();
			d[2]=Color[2].red();
			d[3]=Color[3].red();
			d[4]=Color[4].red();
			d[5]=Color[5].red();
			d[6]=Color[6].red();
			d[7]=Color[7].red();
			d[8]=Color[8].red();
			m[0]= d[0]+d[1]+d[2]+d[3]-2*d[4]+d[5]-d[6]-d[7]-d[8];
			m[1]= d[0]+d[1]+d[2]+d[3]-2*d[4]-d[5]+d[6]-d[7]-d[8];
			m[2]= d[0]+d[1]-d[2]+d[3]-2*d[4]-d[5]+d[6]+d[7]-d[8];
			m[3]= d[0]-d[1]-d[2]+d[3]-2*d[4]-d[5]+d[6]+d[7]+d[8];
			m[4]=-d[0]-d[1]-d[2]+d[3]-2*d[4]+d[5]+d[6]+d[7]+d[8];
			m[5]=-d[0]-d[1]+d[2]-d[3]-2*d[4]+d[5]+d[6]+d[7]+d[8];
			m[6]=-d[0]+d[1]+d[2]-d[3]-2*d[4]+d[5]-d[6]+d[7]+d[8];
			m[7]= d[0]+d[1]+d[2]-d[3]-2*d[4]+d[5]-d[6]-d[7]+d[8];
			max=0;
			for(k=0;k<8;k++)
				if(max<m[k])
					max=m[k];
			zz=(float)(1*max);
			dat=(int)zz;
			if(dat>=255)
				dat=255;
			else
				dat=0;
			value=qRgb(dat, dat, dat);
			imageActive.setPixel(i,j,value);
		}
	}
	pixmap=QPixmap::fromImage(imageActive);
	update();
}
int ImageWidget::cconc(int inb[9])//5-4 by jash	
{
	int i,icn;
	icn=0;
	for(i=0;i<8;i+=2)
		if(inb[i]==0)
			if(inb[i+1]==255||inb[i+2]==255)
				icn++;
	return icn;
}
void ImageWidget::toThinning()//5-4 by jash
{
	int ia[9],ic[9];
	int dat;
	int intW,intH;
	int i,ix,iy,m,ir,iv,iw;
	QColor Color[9];
	QRgb value; 
	int X_Size,Y_Size;
	QImage imageScreen;
	imageScreen=pixmap.toImage();
	imageActive=imageScreen;
	intH=imageActive.height();//取得影像高度
	intW=imageActive.width();//取得影像寬度
	X_Size=intW-1;
	Y_Size=intH-1;
	m=100;
	ir=1;
	while(ir!=0)
	{
		ir=0;
		for(ix=1;ix<X_Size;ix++)
		{
			for(iy=1;iy<Y_Size;iy++)
			{
				Color[0].setRgb(imageActive.pixel(ix-1,iy-1));//(-1,-1
				Color[1].setRgb(imageActive.pixel(ix-1,iy));//(-1,0
				Color[2].setRgb(imageActive.pixel(ix-1,iy+1));//(-1,1
				Color[3].setRgb(imageActive.pixel(ix,iy-1));//(0,-1
				Color[4].setRgb(imageActive.pixel(ix,iy));//(0,0
				Color[5].setRgb(imageActive.pixel(ix,iy+1));//(0,1
				Color[6].setRgb(imageActive.pixel(ix+1,iy-1));//(1,-1
				Color[7].setRgb(imageActive.pixel(ix+1,iy));//(1,0
				Color[8].setRgb(imageActive.pixel(ix+1,iy+1));//(1,1
				ia[0]=Color[5].red();
				ia[1]=Color[2].red();
				ia[2]=Color[1].red();
				ia[3]=Color[0].red();
				ia[4]=Color[3].red();
				ia[5]=Color[6].red();
				ia[6]=Color[7].red();
				ia[7]=Color[8].red();
				ia[8]=Color[4].red();
				if(ia[8]!=255)
					continue;
				for(i=0;i<8;i++)
				{
					if(ia[i]==m)
					{
						ia[i]=255;
						ic[i]=0;
					}
					else
					{
						if(ia[i]<255)
							ia[i]=0;
						ic[i]=ia[i];
					}
				}
				ia[8]=ia[0];
				ic[8]=ic[0];
				if(ia[0]+ia[2]+ia[4]+ia[6]==255*4)
					continue;
				for(i=0,iv=0,iw=0;i<8;i++)
				{
					if(ia[i]==255)
						iv++;
					if(ic[i]==255)
						iw++;	
				}
				if(iv<=1)
					continue;
				if(iw==0)
					continue;
				if(cconc(ia)!=1)
					continue;
				if(Color[1].red()==m)
				{
					ia[2]=0;
					if(cconc(ia)!=1)
						continue;
					ia[2]=255;
				}
				if(Color[3].red()==m)
				{
					ia[4]=0;
					if(cconc(ia)!=1)
						continue;
					ia[4]=255;
				}
				dat=m;
				ir++;
				value=qRgb(dat, dat, dat);
				imageActive.setPixel(ix,iy,value);
			}
		}
		m++;
	}//while
	for(ix=0;ix<X_Size;ix++)
	{
		for(iy=0;iy<Y_Size;iy++)
		{
			Color[4].setRgb(imageActive.pixel(ix,iy));//(0,0
			if(Color[4].red()<255)
			{
				value=qRgb(0, 0, 0);
				imageActive.setPixel(ix,iy,value);
			}
		}
	}
	pixmap=QPixmap::fromImage(imageActive);
	update();	
}
void ImageWidget::toOverlayImage(QString StrFileName)//5-5 by jash
{
	QImage sourceImage;
	QImage destinationImage;
	QImage resultImage;
	
	sourceImage=pixmap.toImage();
	destinationImage.load(StrFileName);
	resultImage= QImage(sourceImage.size(),QImage::Format_ARGB32_Premultiplied);
	
	QPainter::CompositionMode mode = QPainter::CompositionMode_Overlay;

	QPainter painter(&resultImage);
	painter.setCompositionMode(QPainter::CompositionMode_Source);
	painter.fillRect(resultImage.rect(), Qt::transparent);
	painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
	painter.drawImage(0, 0, destinationImage);
	painter.setCompositionMode(mode);
	painter.drawImage(0, 0, sourceImage);
	painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
	painter.fillRect(resultImage.rect(), Qt::white);
	painter.end();
	
	pixmap=QPixmap::fromImage(resultImage);
	update();	
	//resultLabel->setPixmap(QPixmap::fromImage(resultImage));	
}
void ImageWidget::toOverlayText(QString StrText)//5-5 by jash
{
	QImage sourceImage;
	QImage resultImage;
	
	sourceImage=pixmap.toImage();
	resultImage= QImage(sourceImage.size(),QImage::Format_ARGB32_Premultiplied);
	
	QPainter::CompositionMode mode = QPainter::CompositionMode_Overlay;

	QPainter painter(&resultImage);
	painter.setCompositionMode(QPainter::CompositionMode_Source);
	painter.fillRect(resultImage.rect(), Qt::transparent);
	painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
	//painter.drawImage(0, 0, destinationImage);
	const int px_text = 20;
	const int py_text = 20;
	painter.drawText(px_text, py_text, StrText);
	painter.setCompositionMode(mode);
	painter.drawImage(0, 0, sourceImage);
	painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
	painter.fillRect(resultImage.rect(), Qt::white);
	painter.end();
	
	pixmap=QPixmap::fromImage(resultImage);
	update();		
}