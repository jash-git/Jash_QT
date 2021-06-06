#ifndef __SETROTATE_H__
#define __SETROTATE_H__
#include <QDialog>
#include "ui_SetRotateDlg.h"
// place your code here
class SetRotate : public QDialog, public Ui::SetRotateDlg
{
Q_OBJECT
public:
	SetRotate( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:		
};
#endif // __SETROTATE_H__
