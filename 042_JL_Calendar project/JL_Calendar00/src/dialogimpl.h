#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QTableWidgetItem>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QTableWidget *TableWidget;
	QStringList header;
private slots:
 void slotInsertData();
 void slotSelectData(int,int);
};
#endif




