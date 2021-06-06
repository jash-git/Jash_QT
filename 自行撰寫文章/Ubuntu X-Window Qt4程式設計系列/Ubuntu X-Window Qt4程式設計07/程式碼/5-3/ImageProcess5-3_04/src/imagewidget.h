#ifndef IMAGEWIDGET_H_
#define IMAGEWIDGET_H_

#include <QtGui>
#include <QPixmap>
class ImageWidget : public QWidget
{
	Q_OBJECT
	
public:
	bool bFit;
	qreal scale;

public:
	ImageWidget(QWidget *parent = 0);
	void setPixmap(QString fileName);
	QPixmap getPixmap();
	void setAngle(qreal rotateAngle);
	void toGray();//進行灰階運算並顯示運算結果//5-2 by jash
	void toSource();//顯示原始圖檔//5-2 by jash
	void toThreshold(int intValue);//接收門閥值進行二值化//5-2 by jash
	int toOTSU();//OTSU演算法//5-2 by jash
	void toEqualize();//5-3 by jash
	void toSaveFile(QString StrFileName);//5-3 by jash
	void toTranslation(int intXoffset,int intYoffset);//5-3 by jash
	void toHorMirror();//5-3 by jash
	void toVerMirror();//5-3 by jash
	void toTranspose();//5-3 by jash
	void toScale(double dblScale);//5-3 by jash
	

protected:
	void paintEvent(QPaintEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);
	void dragLeaveEvent(QDragLeaveEvent *event);

private:
	QPixmap pixmap;
	QImage imageSource;//存放原始圖檔影像資料//5-2 by jash
	QImage imageActive;//存放運算後圖檔影像資料//5-2 by jash 
	qreal angle;
};

#endif /*IMAGEWIDGET_H_*/
