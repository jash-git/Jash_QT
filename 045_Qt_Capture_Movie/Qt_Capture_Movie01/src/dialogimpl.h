#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QPixmap>
#include <QDesktopWidget>
#include <QTimer>
#include "ui_MainUI.h"
//
class DialogImpl : public QWidget, public Ui::MainForm
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QPixmap Pixmap_saveimage;
	QTimer *timer01;
private slots:
	void slotCapture01();
	void slotTimer();
};
#endif




