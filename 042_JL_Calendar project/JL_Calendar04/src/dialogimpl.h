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
#include <QtSql>
#include <QByteArray>
#include <QTextCodec>
#include <QFile>
#include <stdio.h>
#include "ui_dialog.h"
//
/*
//常用參數類型：char *字串， QByteArray字元陣列， QString字串
//需要轉換：char * ---轉--- QByteArray ---需要調用QByteArray類的構造函數
char*     --------------QByteArray(const char*)-----------> QByteArray
char* str;
QByteArray byte(str);
char*     --------------QString(const char*)-------------->QString
char* str;
QString string(str);
QByteArray   -------------data()-------------------->char*
QByteArray byte;
char* str = byte.data();
QByteArray ------------QString()------------------->QString
QByteArray byte;
QString string(byte);
QString --------------toAscii()--------------------> QByteArray
QString string;
QByteArray byte = string.toAscii();
QString -------------qPrintable()------------------>char*
QString string;
char* str = qPrintable(string);


 */
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
	int m_modifyid;
	void InitGUI();
	void SQLiteOpenReadAll();
private slots:
 void slotInsertData();
 void slotModifyData();
 void slotSelectData(int,int);
};
#endif