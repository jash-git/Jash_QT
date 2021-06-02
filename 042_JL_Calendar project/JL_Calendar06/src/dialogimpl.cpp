#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	m_modifyid=-1;
	timer=new QTimer(this);
	InitGUI();
	connect(timer,SIGNAL(timeout()),this,SLOT(slotTimer()));
	timer->start(30000);
}
void DialogImpl::InitGUI()
{
	int intYear,intMonth,intDay;//存放目前日期
	int intHour,intMinute;//存放目前時間
	QString StrBuf;//字串暫存器
	QDate date = QDate::currentDate();//取得目前日期
	QTime time = QTime::currentTime();//取得目前時間
	//***
	//將相關時間息放到變數中
	intHour=time.hour();
	intMinute=time.minute();
	date.getDate(&intYear,&intMonth,&intDay);
	//***
	//新增年的清單內容
	StrBuf.setNum(intYear-1);
	StrListYear.append(StrBuf);
	StrBuf.setNum(intYear-0);
	StrListYear.append(StrBuf);
	StrBuf.setNum(intYear+1);
	StrListYear.append(StrBuf);
	//***
	//新增月的清單內容
	StrListMonth.append("01");
	StrListMonth.append("02");
	StrListMonth.append("03");
	StrListMonth.append("04");
	StrListMonth.append("05");
	StrListMonth.append("06");
	StrListMonth.append("07");
	StrListMonth.append("08");
	StrListMonth.append("09");
	StrListMonth.append("10");
	StrListMonth.append("11");
	StrListMonth.append("12");
	//***
	//新增日的清單內容
	StrListDay.append("01");
	StrListDay.append("02");
	StrListDay.append("03");
	StrListDay.append("04");
	StrListDay.append("05");
	StrListDay.append("06");
	StrListDay.append("07");
	StrListDay.append("08");
	StrListDay.append("09");
	StrListDay.append("10");
	StrListDay.append("11");
	StrListDay.append("12");
	StrListDay.append("13");
	StrListDay.append("14");
	StrListDay.append("15");
	StrListDay.append("16");
	StrListDay.append("17");
	StrListDay.append("18");
	StrListDay.append("19");
	StrListDay.append("21");
	StrListDay.append("22");
	StrListDay.append("23");
	StrListDay.append("24");
	StrListDay.append("25");
	StrListDay.append("26");
	StrListDay.append("27");
	StrListDay.append("28");
	StrListDay.append("29");
	StrListDay.append("30");
	StrListDay.append("31");
	//***
	//新增小時的清單內容
	StrListHour.append("01");
	StrListHour.append("02");
	StrListHour.append("03");
	StrListHour.append("04");
	StrListHour.append("05");
	StrListHour.append("06");
	StrListHour.append("07");
	StrListHour.append("08");
	StrListHour.append("09");
	StrListHour.append("10");
	StrListHour.append("11");
	StrListHour.append("12");
	StrListHour.append("13");
	StrListHour.append("14");
	StrListHour.append("15");
	StrListHour.append("16");
	StrListHour.append("17");
	StrListHour.append("18");
	StrListHour.append("19");
	StrListHour.append("20");
	StrListHour.append("21");
	StrListHour.append("22");
	StrListHour.append("23");
	StrListHour.append("24");
	//***	
	//新增分鐘的清單內容
	StrListMinute.append("00");
	StrListMinute.append("30");
	//***
	//新增開關的清單內容
	StrListSwitch.append("on");
	StrListSwitch.append("off");
	//***
	//將介面元件指定給自訂元件變數
	ComboYear=comboYear;
	ComboMonth=comboMonth;
	ComboDay=comboDay;
	ComboHour=comboHour;
	ComboMinute=comboMinute;
	ComboSwitch=comboSwitch;
	LineEditNote=lineEditNote;
	TableWidget=tableWidget;
	//***
	//將ListString資料放到comboBox內
	ComboYear->addItems(StrListYear);
	ComboYear->setCurrentIndex(1);
	ComboMonth->addItems(StrListMonth);
	ComboMonth->setCurrentIndex(intMonth-1);
	ComboDay->addItems(StrListDay);
	ComboDay->setCurrentIndex(intDay-1);
	ComboHour->addItems(StrListHour);
	ComboHour->setCurrentIndex(intHour-1);
	ComboMinute->addItems(StrListMinute);
	if(intMinute<30)
		ComboMinute->setCurrentIndex(0);
	else
		ComboMinute->setCurrentIndex(1);
	ComboSwitch->addItems(StrListSwitch);
	//***
	//設定顯示表格的相關參數
	TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改內容
	//TableWidget->setRowCount(10);
	TableWidget->setRowCount(0);
	TableWidget->setColumnCount(6);
	TableWidget->setColumnWidth(0,50);//設定寬度-id
	TableWidget->setColumnWidth(1,115);//設定寬度-Date
	TableWidget->setColumnWidth(2,70);//設定寬度-Hour
	TableWidget->setColumnWidth(3,80);//設定寬度-Minutes
	TableWidget->setColumnWidth(4,300);//設定寬度-Note
	TableWidget->setColumnWidth(5,80);//設定寬度-Switch
	TableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//設置選擇模式，選擇單行
	TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //設置選擇行為，以行為單位
	header.append("id");
	header.append("Date");
	header.append("Hour");
	header.append("Minutes");
	header.append("Note");
	header.append("Switch");
	TableWidget->setHorizontalHeaderLabels(header);
	//***
	//讀取資料庫
	SQLiteOpenReadAll();
	/*
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
	//*/	
}
void DialogImpl::SQLiteOpenReadAll()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	QFile FilecheckDB("JL.db");
	bool blncheckDB=false;
	blncheckDB=FilecheckDB.exists();//判斷檔案是否存在
	db.setDatabaseName("JL.db");//設定開啟的DB
	if (!db.open())
	{
		QMessageBox::warning(0, QObject::tr("Database Error"),db.lastError().text());
	}
	else
	{
		if(!blncheckDB)//如果DB不存在，則重新建立
		{
			QSqlQuery rs(db);
			rs.exec("CREATE TABLE Calendar (id INTEGER PRIMARY KEY,Date varchar(20), Hour varchar(10), Minutes varchar(10), Note varchar(500), Switch varchar(10))");
			QString StrBuf;
			StrBuf=QString("insert into Calendar(id,Date,Hour,Minutes,Note,Switch) values(null,'%1', '%2', '%3', '%4', '%5')") .arg("YYYY-MM-DD") .arg("hh") .arg("mm") .arg("sample-測試") .arg("on");
			QByteArray strSql=StrBuf.toAscii();
			QTextCodec *codec = QTextCodec::codecForName("UTF-8");
			QString string = codec->toUnicode(strSql);
			rs.exec(string);			
		}
		//***
		//取得DB資料
		QSqlQueryModel *model = new QSqlQueryModel;
		model->setQuery("SELECT * FROM Calendar");
		//***
		//將DB資料顯示出來
		TableWidget->clear();
		TableWidget->setRowCount(model->rowCount());
		TableWidget->setColumnCount(6);
		TableWidget->setHorizontalHeaderLabels(header);
		QString Strid,StrDate,StrHour,StrMinutes,StrNote,StrSwitch;
		for (int i = 0; i < model->rowCount(); ++i)
		{
    		QSqlRecord record = model->record(i);
    		Strid = record.value(0).toString();
    		StrDate = record.value(1).toString();
			StrHour = record.value(2).toString();
			StrMinutes = record.value(3).toString();
			StrNote = record.value(4).toString();
			StrSwitch = record.value(5).toString();
			QTableWidgetItem *itemid=new QTableWidgetItem("");
			QTableWidgetItem *itemDate=new QTableWidgetItem("");
			QTableWidgetItem *itemHour=new QTableWidgetItem("");
			QTableWidgetItem *itemMinutes=new QTableWidgetItem("");
			QTableWidgetItem *itemNote=new QTableWidgetItem("");
			QTableWidgetItem *itemSwitch=new QTableWidgetItem("");
			itemid->setText(Strid);
			itemDate->setText(StrDate);
			itemHour->setText(StrHour);
			itemMinutes->setText(StrMinutes);
			itemNote->setText(StrNote);
			itemSwitch->setText(StrSwitch);
			TableWidget->setItem(i, 0, itemid);
			TableWidget->setItem(i, 1, itemDate);
			TableWidget->setItem(i, 2, itemHour);
			TableWidget->setItem(i, 3, itemMinutes);
			TableWidget->setItem(i, 4, itemNote);
			TableWidget->setItem(i, 5, itemSwitch);
		}
		//***
		db.close();
	}
}
void DialogImpl::slotInsertData()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("JL.db");//設定開啟的DB
	if (!db.open())
	{
		QMessageBox::warning(0, QObject::tr("Database Error"),db.lastError().text());
	}
	else
	{
		QSqlQuery rs(db);
		QString StrBuf;
		QString StrDate,StrHour,StrMinutes,StrNote,StrSwitch;
		StrDate=QString("%1-%2-%3") .arg(ComboYear->currentText()).arg(ComboMonth->currentText()).arg(ComboDay->currentText());
		StrHour=ComboHour->currentText();
		StrMinutes=ComboMinute->currentText();
		StrSwitch=ComboSwitch->currentText();
		StrNote=LineEditNote->text();
		StrBuf=QString("insert into Calendar(id,Date,Hour,Minutes,Note,Switch) values(null,'%1', '%2', '%3', '%4', '%5')") .arg(StrDate) .arg(StrHour) .arg(StrMinutes) .arg(StrNote) .arg(StrSwitch);
		QByteArray strSql=StrBuf.toAscii();
		QTextCodec *codec = QTextCodec::codecForName("UTF-8");
		QString string = codec->toUnicode(strSql);
		rs.exec(string);
	}
	db.close();
	SQLiteOpenReadAll();
}
void DialogImpl::slotSelectData( int row, int column)
{
	QDate date = QDate::currentDate();//取得目前日期
	QTime time = QTime::currentTime();//取得目前時間
	QString StrData;

	int intYear,intMonth,intDay,intHour,intMinutes;
	if(row <= 0)
	{
		StrData="The Data is sample.";
		QMessageBox box1;
		box1.setText(StrData);
		box1.exec();
	}
	else
	{
		//***
		m_modifyid=-1;
		QTableWidgetItem *itemid=TableWidget->item(row,0);
		StrData=itemid->text();
		m_modifyid=StrData.toInt();
		//***
		QTableWidgetItem *itemDate=TableWidget->item(row,1);//一定要有資料-Date
		StrData=itemDate->text();
		sscanf(StrData.toAscii(),"%d-%d-%d",&intYear,&intMonth,&intDay);
		if(intYear==date.year())
		{
			ComboYear->setCurrentIndex(1);
		}
		else
		{
			if(intYear<date.year())
			{
				ComboYear->setCurrentIndex(0);
			}
			else
			{
				ComboYear->setCurrentIndex(2);
			}
		}
		ComboMonth->setCurrentIndex(intMonth-1);
		ComboDay->setCurrentIndex(intDay-1);
		//***
		QTableWidgetItem *itemHour=TableWidget->item(row,2);//一定要有資料-Hour
		StrData=itemHour->text();
		intHour=StrData.toInt();
		ComboHour->setCurrentIndex(intHour-1);
		//***
		QTableWidgetItem *itemMinutes=TableWidget->item(row,3);//一定要有資料-Minutes
		StrData=itemMinutes->text();
		sscanf(StrData.toAscii(),"%d",&intMinutes);
		if(intMinutes<30)
			ComboMinute->setCurrentIndex(0);
		else
			ComboMinute->setCurrentIndex(1);
		//***
		QTableWidgetItem *itemNote=TableWidget->item(row,4);//一定要有資料-Note
		StrData=itemNote->text();
		LineEditNote->setText(StrData);
		//***
		QTableWidgetItem *itemSwitch=TableWidget->item(row,5);//一定要有資料-Switch
		StrData=itemSwitch->text();
		if(StrData=="on")
			ComboSwitch->setCurrentIndex(0);
		else
			ComboSwitch->setCurrentIndex(1);
	}
	/*
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
	*/
}
void DialogImpl::slotModifyData()
{
	int id;
	id=m_modifyid;
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("JL.db");//設定開啟的DB
	if (!db.open())
	{
		QMessageBox::warning(0, QObject::tr("Database Error"),db.lastError().text());
	}
	else
	{
		QSqlQuery rs(db);
		QString StrBuf;
		QString StrDate,StrHour,StrMinutes,StrNote,StrSwitch;
		StrDate=QString("%1-%2-%3") .arg(ComboYear->currentText()).arg(ComboMonth->currentText()).arg(ComboDay->currentText());
		StrHour=ComboHour->currentText();
		StrMinutes=ComboMinute->currentText();
		StrSwitch=ComboSwitch->currentText();
		StrNote=LineEditNote->text();
		StrBuf=QString("update Calendar set Date='%1',Hour='%2',Minutes='%3',Note='%4',Switch='%5' where id='%6'") .arg(StrDate) .arg(StrHour) .arg(StrMinutes) .arg(StrNote) .arg(StrSwitch).arg(id);
		QByteArray strSql=StrBuf.toAscii();
		QTextCodec *codec = QTextCodec::codecForName("UTF-8");
		QString string = codec->toUnicode(strSql);
		rs.exec(string);
	}
	db.close();
	SQLiteOpenReadAll();
	m_modifyid=-1;
}
void DialogImpl::slotExportDB()
{
	QString StrBuf;
	QFile file("ExportDB.xml");
	if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
	{
		QMessageBox::warning(0, QObject::tr("Export DB Error"),"Export DB Error");
		return ;
	}
	QDomDocument doc;
	QDomProcessingInstruction instruction;//add file tag
	instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
	doc.appendChild(instruction);
	QDomElement root = doc.createElement(tr("JL_Calendar"));
	QDomElement Note = doc.createElement(tr("Note"));
	QDomElement id = doc.createElement(tr("ID"));
	QDomElement Date = doc.createElement(tr("Date"));
	QDomElement Hour = doc.createElement(tr("Hour"));
	QDomElement Minutes = doc.createElement(tr("Minutes"));
	QDomElement Event = doc.createElement(tr("Event"));
	QDomElement Switch = doc.createElement(tr("Switch"));
	QDomText text;
	doc.appendChild(root); // add root
	//***
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	QFile FilecheckDB("JL.db");
	bool blncheckDB=false;
	blncheckDB=FilecheckDB.exists();//判斷檔案是否存在
	db.setDatabaseName("JL.db");//設定開啟的DB
	if (!db.open())
	{
		QMessageBox::warning(0, QObject::tr("Database Error"),db.lastError().text());
	}
	else
	{
		if(!blncheckDB)//如果DB不存在，則重新建立
		{
			QSqlQuery rs(db);
			rs.exec("CREATE TABLE Calendar (id INTEGER PRIMARY KEY,Date varchar(20), Hour varchar(10), Minutes varchar(10), Note varchar(500), Switch varchar(10))");
			QString StrBuf;
			StrBuf=QString("insert into Calendar(id,Date,Hour,Minutes,Note,Switch) values(null,'%1', '%2', '%3', '%4', '%5')") .arg("YYYY-MM-DD") .arg("hh") .arg("mm") .arg("sample-測試") .arg("on");
			QByteArray strSql=StrBuf.toAscii();
			QTextCodec *codec = QTextCodec::codecForName("UTF-8");
			QString string = codec->toUnicode(strSql);
			rs.exec(string);			
		}
		//***
		//娶得DB資料
		QSqlQueryModel *model = new QSqlQueryModel;
		model->setQuery("SELECT * FROM Calendar");
		//***
		//將DB資料顯示出來
		QString Strid,StrDate,StrHour,StrMinutes,StrNote,StrSwitch;
		for (int i = 0; i < model->rowCount(); ++i)
		{
			QSqlRecord record = model->record(i);
			Note = doc.createElement(tr("Note"));
			id = doc.createElement(tr("ID"));
			Date = doc.createElement(tr("Date"));
			Hour = doc.createElement(tr("Hour"));
			Minutes = doc.createElement(tr("Minutes"));
			Event = doc.createElement(tr("Event"));
			Switch = doc.createElement(tr("Switch"));
    		//***
    		Strid = record.value(0).toString();
    		text = doc.createTextNode(Strid);
			id.appendChild(text);
			//***
			StrDate = record.value(1).toString();
			text = doc.createTextNode(StrDate);
			Date.appendChild(text);
			//***
			StrHour = record.value(2).toString();
			text = doc.createTextNode(StrHour);
			Hour.appendChild(text);
			//***
			StrMinutes = record.value(3).toString();
			text = doc.createTextNode(StrMinutes);
			Minutes.appendChild(text);
			//***
			StrNote = record.value(4).toString();
			text = doc.createTextNode(StrNote);
			Event.appendChild(text);
			//***
			StrSwitch = record.value(5).toString();
			text = doc.createTextNode(StrSwitch);
			Switch.appendChild(text);
			//***
			Note.appendChild(id);
			Note.appendChild(Date);
			Note.appendChild(Hour);
			Note.appendChild(Minutes);
			Note.appendChild(Event);
			Note.appendChild(Switch);
			root.appendChild(Note);
		}
		//***
		db.close();
	}
	//***
	QTextStream out(&file);
	out.setCodec("UTF-8");
	doc.save(out,4,QDomNode::EncodingFromTextStream); //儲存文件，4縮排符號
	file.close();
	/*
	QString StrBuf;
	QFile file("ExportDB.xml");
	if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
	{
		QMessageBox::warning(0, QObject::tr("Export DB Error"),"Export DB Error");
		return ;
	}
	QDomDocument doc;
	QDomProcessingInstruction instruction;//add file tag
	instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
	doc.appendChild(instruction);
	QDomElement root = doc.createElement(tr("Books"));
	doc.appendChild(root); // add root
	//***
	//add book元素及其子元素
	QDomElement book = doc.createElement(tr("Book"));
	//QDomAttr id = doc.createAttribute(tr("ID"));
	QDomElement id = doc.createElement(tr("ID"));
	QDomElement title = doc.createElement(tr("Name"));
	QDomElement author = doc.createElement(tr("Author"));
	QDomText text;
	text = doc.createTextNode(tr("1"));
	//id.setValue(tr("1"));
	id.appendChild(text);
	//book.setAttributeNode(id);
	StrBuf="中文";
	text = doc.createTextNode(StrBuf);
	title.appendChild(text);
	StrBuf="shiming";
	text = doc.createTextNode(StrBuf);
	author.appendChild(text);
	book.appendChild(id);
	book.appendChild(title);
	book.appendChild(author);
	root.appendChild(book);
	//***
	book = doc.createElement(tr("Book"));
	//id = doc.createAttribute(tr("ID"));
	id = doc.createElement(tr("ID"));
	title = doc.createElement(tr("Name"));
	author = doc.createElement(tr("Author"));
	text = doc.createTextNode(tr("2"));
	//id.setValue(tr("2"));
	id.appendChild(text);
	//book.setAttributeNode(id);
	text = doc.createTextNode(tr("Linux"));
	title.appendChild(text);
	text = doc.createTextNode(tr("yafei"));
	author.appendChild(text);
	book.appendChild(id);
	book.appendChild(title);
	book.appendChild(author);
	root.appendChild(book);
	QTextStream out(&file);
	out.setCodec("UTF-8");
	doc.save(out,4,QDomNode::EncodingFromTextStream); //儲存文件，4縮排符號

	file.close();
	*/
}
void DialogImpl::slotTimer()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	QFile FilecheckDB("JL.db");
	bool blncheckDB=false;
	blncheckDB=FilecheckDB.exists();//判斷檔案是否存在
	db.setDatabaseName("JL.db");//設定開啟的DB
	if (!db.open())
	{
		QMessageBox::warning(0, QObject::tr("Database Error"),db.lastError().text());
	}
	else
	{
		//***
		//取得DB資料
		FILE *pf;
		pf=fopen("timer.txt","a");
		QSqlQueryModel *model = new QSqlQueryModel;
		model->setQuery("SELECT * FROM Calendar Where Switch='on'");
		//***
		//將SQL之後的資料顯示出來
		QString Strid,StrDate,StrHour,StrMinutes,StrNote,StrSwitch;
		QByteArray Arrid,ArrDate,ArrHour,ArrMinutes,ArrNote,ArrSwitch;//strSql=StrBuf.toAscii();
		for (int i = 0; i < model->rowCount(); ++i)
		{
    		QSqlRecord record = model->record(i);
    		Strid = record.value(0).toString();
    		Arrid=Strid.toAscii();
    		StrDate = record.value(1).toString();
    		ArrDate=StrDate.toAscii();
			StrHour = record.value(2).toString();
			ArrHour=StrHour.toAscii();
			StrMinutes = record.value(3).toString();
			ArrMinutes=StrMinutes.toAscii();
			StrNote = record.value(4).toString();
			ArrNote=StrNote.toAscii();
			StrSwitch = record.value(5).toString();
			ArrSwitch=StrSwitch.toAscii();
			fprintf(pf,"%s,%s,%s,%s,%s,%s\n",Arrid.data(),ArrDate.data(),ArrHour.data(),ArrMinutes.data(),ArrNote.data(),ArrSwitch.data());
		}
		fclose(pf);
		//***
		db.close();
	}
}
//
