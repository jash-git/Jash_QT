#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	TableWidget=tableWidget;
	TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改內容
	TableWidget->setRowCount(10);
	TableWidget->setColumnCount(5);
	TableWidget->setColumnWidth(3,185);//設定寬度
	TableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//設置選擇模式，選擇單行
	TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //設置選擇行為，以行為單位
	header.append("Day");
	header.append("Hour");
	header.append("Minutes");
	header.append("Note");
	header.append("on/off");
	TableWidget->setHorizontalHeaderLabels(header);
	TableWidget->setItem(0, 0, new QTableWidgetItem("2011-05-01"));
	TableWidget->setItem(0, 1, new QTableWidgetItem("21"));
	TableWidget->setItem(0, 2, new QTableWidgetItem("00"));
	TableWidget->setItem(0, 3, new QTableWidgetItem("Qt coding 123456789"));
	TableWidget->setItem(0, 4, new QTableWidgetItem("true"));
	TableWidget->setItem(1, 0, new QTableWidgetItem("2011-05-02"));
	TableWidget->setItem(1, 1, new QTableWidgetItem("21"));
	TableWidget->setItem(1, 2, new QTableWidgetItem("30"));
	TableWidget->setItem(1, 3, new QTableWidgetItem("Qt coding"));
	TableWidget->setItem(1, 4, new QTableWidgetItem("off"));
	///////////////////////////////////////////////////////////////
	int i,j;
	QString StrData;
	for (i=2; i<10; ++i)
	{
		for(j=0;j<5;++j)
		{
			QTableWidgetItem *item=new QTableWidgetItem("");
			StrData=QString("Row is %1,Column is %2") .arg(i) .arg(j);
			item->setText(StrData);
			TableWidget->setItem(i, j, item);
		}
	}
}
void DialogImpl::slotInsertData()
{
	TableWidget->clear();
	//TableWidget->insertRow(10);//插入在第幾列之後，新增一列
	TableWidget->setRowCount(20);
	TableWidget->setColumnCount(4);
	TableWidget->setHorizontalHeaderLabels(header);	
}
void DialogImpl::slotSelectData( int row, int column)
{
	QString StrData;
	StrData=QString("Row is %1,Column is %2") .arg(row) .arg(column);
	QMessageBox box;
	box.setText(StrData);
	box.exec();
	QTableWidgetItem *TWI=TableWidget->item(row,column);//一定要有資料
	StrData=TWI->text();
	QMessageBox box1;
	box1.setText(StrData);
	box1.exec();
}
//
