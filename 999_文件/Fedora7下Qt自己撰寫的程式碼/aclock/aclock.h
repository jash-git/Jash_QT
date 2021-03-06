/****************************************************************************
** $Id:  qt/aclock.h   3.0.2   edited Oct 12 12:18 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#ifndef ACLOCK_H
#define ACLOCK_H

#include <qwidget.h>
#include <qdatetime.h>


class AnalogClock : public QWidget		// analog clock widget
{
    Q_OBJECT
public:
    AnalogClock( QWidget *parent=0, const char *name=0 );
    void setAutoMask(bool b);

public slots:    
    void setTime( const QTime & t );
    
protected:
    void updateMask();
    void paintEvent( QPaintEvent *);
    void mousePressEvent( QMouseEvent *);
    void mouseMoveEvent( QMouseEvent *);
    
private slots:
    void drawClock( QPainter* );
    void	timeout();

private:
    QPoint clickPos;
    QTime	time;
};


#endif // ACLOCK_H
