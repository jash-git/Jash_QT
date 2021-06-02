#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QMessageBox>
#include <QString>
#include "timeserver.h"
#include "guiinfoserver.h"
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	TimeServer *timeserver;
	GUIInfoServer *guiinfoserver;
	QLabel *labShow;
private slots:
	void slotExit();
};
#endif




