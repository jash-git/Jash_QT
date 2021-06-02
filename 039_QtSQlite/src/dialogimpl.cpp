#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	UseSQLite();
}
void DialogImpl::UseSQLite()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("database.dat");
	if (!db.open())
	{
		QMessageBox::warning(0, QObject::tr("Database Error"),db.lastError().text());
	}
	else
	{
		QSqlQuery rs(db);
		rs.exec("CREATE TABLE person (firstname varchar(20), lastname varchar(20))");
		QByteArray strSql("insert into person(firstname,lastname) values('Jash', 'Liao')");
		QTextCodec *codec = QTextCodec::codecForName("UTF-8");
		QString string = codec->toUnicode(strSql);
		rs.exec(string);
		
		QSqlQueryModel *model = new QSqlQueryModel;
		model->setQuery("SELECT * FROM person");
		model->setHeaderData(0, Qt::Horizontal, "firstname");
		model->setHeaderData(1, Qt::Horizontal, "lastname");
		QString name;
		for (int i = 0; i < model->rowCount(); ++i)
		{
    		QSqlRecord record = model->record(i);
    		QString srtfirstname = record.value(0).toString();
    		QString srtlastname = record.value(1).toString();
 			name=srtfirstname;
			name=name+".";
			name=name+srtlastname;
		}
		QMessageBox::warning(0, QObject::tr("Database Data"),name);	
		db.close();
	}
}
//
