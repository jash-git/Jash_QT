#include "ShapDockWidget.h"
ShapDockWidget::ShapDockWidget(const QString &title,QWidget *parent,Qt::WindowFlags flags) : QDockWidget(title,parent,flags)
{
	w=new newfile(this);
	setWidget(w);
}
ShapDockWidget::~ShapDockWidget()
{
	delete w;
}

// place your code here
