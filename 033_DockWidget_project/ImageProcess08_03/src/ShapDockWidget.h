#ifndef __SHAPDOCKWIDGET_H__
#define __SHAPDOCKWIDGET_H__
#include "newfile.h"
#include <QTextEdit>
#include <QHBoxLayout>
#include <QLabel>
#include <QDockWidget>
#include <QString>
// place your code here
class ShapDockWidget : public QDockWidget
{
Q_OBJECT
public:
	ShapDockWidget(const QString &title,QWidget *parent=0,Qt::WindowFlags flags=0);
	~ShapDockWidget();
	newfile *w;
	QLabel *nameLabel;
	QTextEdit *nameEdit;
	QHBoxLayout *nameLayout;
};
#endif // __SHAPDOCKWIDGET_H__
