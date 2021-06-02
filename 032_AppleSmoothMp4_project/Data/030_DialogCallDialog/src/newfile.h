#ifndef __NEWFILE_H__
#define __NEWFILE_H__
#include <QDialog>
#include "ui_newfile.h"
// place your code here
class newfile : public QDialog, public Ui::Dialog01
{
Q_OBJECT
public:
	newfile( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
};
#endif // __NEWFILE_H__
