#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QPixmap>
#include <QDesktopWidget>
#include <QTimer>
#include <QString>

#include "ui_MainUI.h"
//
class DialogImpl : public QWidget, public Ui::MainForm
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QPixmap Pixmap_saveimage;
	QTimer *timer01;
	int m_intTimerSwitch;
	int m_intImageCount;
	QPushButton *mapButVideo;
	QString m_StrFileName;
	bool m_blnclick;
private slots:
	void slotCapture01();
	void slotTimer();
	void slotVideo();
};
#endif




