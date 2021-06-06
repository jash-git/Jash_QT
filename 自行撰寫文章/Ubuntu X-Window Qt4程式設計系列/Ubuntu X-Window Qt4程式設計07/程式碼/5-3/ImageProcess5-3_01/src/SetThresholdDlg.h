#ifndef __SETTHRESHOLDDLG_H__
#define __SETTHRESHOLDDLG_H__
#include <QDialog>
#include "ui_SetThresholdDlg.h"
// place your code here
class SetThresholdDlg : public QDialog, public Ui::SetThreshold
{
Q_OBJECT
public:
	SetThresholdDlg( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:		
};
#endif // __SETTHRESHOLDDLG_H__
