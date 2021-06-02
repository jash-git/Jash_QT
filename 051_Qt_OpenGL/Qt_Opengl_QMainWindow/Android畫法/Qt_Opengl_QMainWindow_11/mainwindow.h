#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include "glwidget.h"
#include <QTimer>
#include <QKeyEvent>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *timer;
private:
    GLWidget *w;
private slots:
	void Timer_slot();
	void keyPressEvent( QKeyEvent *e );
};

#endif // MAINWINDOW_H
