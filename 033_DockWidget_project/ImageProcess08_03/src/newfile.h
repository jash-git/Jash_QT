#ifndef __NEWFILE_H__
#define __NEWFILE_H__
#include "ui_Histogram.h"
#include <QWidget>
#include <QMessageBox>
class newfile : public QWidget
{
Q_OBJECT
public:
	newfile( QWidget * parent = 0);
 	Ui_Form ui;
private slots:
	void slot1();
};
#endif // __NEWFILE_H__
