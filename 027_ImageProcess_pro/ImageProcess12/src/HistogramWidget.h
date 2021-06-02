#ifndef __HISTOGRAMWIDGET_H__
#define __HISTOGRAMWIDGET_H__
//
#include <QDialog>
#include "ui_HistogramDialog.h"
#include <QLabel>
#include <QPainter>
#include <QString>
#include <QColor>
#include <QPixmap>

//
// place your code here
class HistogramWidget: public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	HistogramWidget( QWidget * parent = 0, Qt::WFlags f = 0 );
	~HistogramWidget();
	int intW,intH;
	QLabel *DrawLabel;
	QPixmap *pixmap;
private slots:
};
#endif // __HISTOGRAMWIDGET_H__
