#ifndef __SETSCALE_H__
#define __SETSCALE_H__
#include <QDialog>
#include "ui_SetScaleDlg.h"
// place your code here
class SetScale : public QDialog, public Ui::SetScaleDlg
{
Q_OBJECT
public:
	SetScale( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:		
};
#endif // __SETSCALE_H__
