#ifndef __SHOWHISTOGRAMDLG_H__
#define __SHOWHISTOGRAMDLG_H__
//
#include <QDialog>
#include "ui_ShowHistogramDlg.h"
#include <QLabel>
#include <QPainter>
#include <QString>
#include <QColor>
#include <QPixmap>
#include <QLineEdit>
//
// place your code here
class ShowHistogramDlg: public QDialog, public Ui::ShowHistogram
{
Q_OBJECT
public:
	ShowHistogramDlg( QWidget * parent = 0, Qt::WFlags f = 0 );
	~ShowHistogramDlg();
	int intW,intH;
	QLabel *DrawLabel;
	QLineEdit *MaxLineEdit,*MinLineEdit;
	QPixmap *pixmap;
private slots:
};
#endif // __SHOWHISTOGRAMDLG_H__

