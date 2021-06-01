#include "dialogimpl.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
using namespace std;
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	doc=new QDomDocument("Config");
	QFile file("Config.xml");
	QFile filelog("log.txt");
	filelog.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream TextStreamOut(&filelog);
	if(!file.open(QIODevice::ReadOnly))
	{
		file.close();
		return;	
	}
	if(doc->setContent(&file))
	{
		file.close();
	}
	QDomElement docElem=doc->documentElement();
	QDomNode docNode=docElem.firstChild();
	QDomElement docElement;
	QString StrData;
	while(!docNode.isNull())
	{
		docElement=docNode.toElement();
		if(!docElement.isNull())
		{
			StrData=docElement.tagName();
			TextStreamOut << StrData << "\t";
			StrData=docElement.text();
			TextStreamOut << StrData << endl;
		}
		docNode=docNode.nextSibling();
	}
	filelog.close();
}
DialogImpl::~DialogImpl()
{
	delete doc;
}
//
