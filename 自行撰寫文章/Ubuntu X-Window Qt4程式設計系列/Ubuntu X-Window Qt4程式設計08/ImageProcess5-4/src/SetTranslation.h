#ifndef __SETTRANSLATION_H__
#define __SETTRANSLATION_H__
#include <QDialog>
#include "ui_SetTranslationDlg.h"
// place your code here
class SetTranslation : public QDialog, public Ui::SetTranslationDlg
{
Q_OBJECT
public:
	SetTranslation( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:		
};
#endif // __SETTRANSLATION_H__
