#include "ShapDockWidget.h"
ShapDockWidget::ShapDockWidget(const QString &title,QWidget *parent,Qt::WindowFlags flags) : QDockWidget(title,parent,flags)
{
	w=new QWidget(this);
	nameLabel = new QLabel("name");
	nameEdit = new QTextEdit();
	nameLayout = new QHBoxLayout(w);
	nameLayout->addWidget(nameLabel);
	nameLayout->addWidget(nameEdit);
	w->setLayout(nameLayout);
	setWidget(w);
}
ShapDockWidget::~ShapDockWidget()
{
	delete w;
	delete nameLabel;
	delete nameEdit;
	delete nameLayout;	
}

// place your code here
