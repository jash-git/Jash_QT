#include "dialogimpl.h"

//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	QString StrSrc,StrDec;
	bool blncopy,blndelete;
	StrSrc="/home/jash/Src/v1030812.wmv";
	StrDec="/home/jash/Dec/v1030812.wmv";
	blncopy=QFile::copy(StrSrc,StrDec);
	if(blncopy)
	{
		QMessageBox::information(0,"copy","OK");
	}
	else
	{
		QMessageBox::information(0,"copy","Not OK");
	}
	blndelete=QFile::remove(StrSrc);
	if(blndelete)
	{
		QMessageBox::information(0,"delete","OK");
	}
	else
	{
		QMessageBox::information(0,"delete","Not OK");
	}
}
//
