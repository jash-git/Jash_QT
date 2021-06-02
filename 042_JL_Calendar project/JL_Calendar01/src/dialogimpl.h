#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QComboBox>
#include <QDateTime>
#include <QLineEdit>
#include "ui_dialog.h"
//
class DialogImpl : public QDialog, public Ui::Dialog
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QTableWidget *TableWidget;
	QLineEdit *LineEditNote;
	QComboBox *ComboYear,*ComboMonth,*ComboDay,*ComboHour,*ComboMinute,*ComboSwitch;
	QStringList StrListYear,StrListMonth,StrListDay,StrListHour,StrListMinute,StrListSwitch;
	QStringList header;
	void InitGUI();
private slots:
 void slotInsertData();
 void slotSelectData(int,int);
};
#endif