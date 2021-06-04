/***************************************************************************
 *   Copyright (C) 2007 by root   *
 *   root@localhost.localdomain   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <qapplication.h>
#include <qlabel.h>
#include <qpushbutton.h>
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	//QLabel *Labl=new QLabel("Hello Qt",0);
	QPushButton *button=new QPushButton("Quit",0);
	QObject::connect(button,SIGNAL(clicked()),&app,SLOT(quit()));
	app.setMainWidget(button);
	button->show();
	//Labl->show();
	return app.exec();
}
