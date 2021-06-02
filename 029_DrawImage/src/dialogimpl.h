#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include "ui_Widget01.h"
#include "ui_dialog.h"
#include <QLabel>
#include <QPainter>
#include <QString>
#include <QColor>
#include <QPixmap>
//
//class DialogImpl : public QWidget, public Ui::Form
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	~DialogImpl();
	int intW,intH;
	QLabel *DrawLabel;
	QPixmap *pixmap;
private slots:
	void slotButton();
};
#endif




