#ifndef __THRESHDIALOG_H__
#define __THRESHDIALOG_H__
#include <QDialog>
#include "ui_ThreshDialog.h"
// place your code here
class ThreshDialog : public QDialog, public Ui::Dialog01
{
Q_OBJECT
public:
	ThreshDialog( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:	
};
#endif // __THRESHDIALOG_H__
