#include "dialogimpl.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QMessageBox>
using namespace std;
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	doc=new QDomDocument("Config");
	QFile file("Config.xml");
	QFile filelog("log.txt");
	QString StrPath;
	StrPath=QDir::currentPath();
	filelog.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream TextStreamOut(&filelog);
	TextStreamOut << "currentPath:"<< "\t" << StrPath <<"/" <<endl;
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
void DialogImpl::slotReadNodeList()
{
	doc1=new QDomDocument("XML_Nodes");
	QFile file("XML_Nodes.xml");
	QFile filelog("XML_Nodes.txt");
	QString StrPath;
	StrPath=QDir::currentPath();
	filelog.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream TextStreamOut(&filelog);
	TextStreamOut << "currentPath:"<< "\t" << StrPath <<"/" <<endl;
	if(!file.open(QIODevice::ReadOnly))
	{
		file.close();
		return;	
	}
	if(doc1->setContent(&file))
	{
		file.close();
	}
	QString StrBuf;
	StrBuf="BOOK";
	int i,j;
	int k,l;
	i=0;
	k=0;
	QDomElement docElem=doc1->documentElement();
	QDomNodeList docNodeList1=docElem.elementsByTagName(StrBuf);
	QMessageBox::information(0,"",QString("%1").arg(docNodeList1.count()));
	j=docNodeList1.count();
	QDomNode docNode1;
	QDomNode docNode2;
	QDomNodeList docNodeList2;
	QDomElement docElement;
	QString StrData;
	for(i=0;i<j;i++)
	{
		docNode1=docNodeList1.at(i);
		docNodeList2=docNode1.childNodes();
		k=0;
		l=docNodeList2.count();
		for(k=0;k<l;k++)
		{
			docNode2=docNodeList2.at(k);
			docElement=docNode2.toElement();
			if(!docElement.isNull())
			{
				StrData=docElement.tagName();
				TextStreamOut << StrData << "\t";
				StrData=docElement.text();
				TextStreamOut << StrData << endl;
			}
		}
	}
	filelog.close();
	QMessageBox::information(0,"Read NodeList","OK");
}
DialogImpl::~DialogImpl()
{
	delete doc;
	delete doc1;
}
//
