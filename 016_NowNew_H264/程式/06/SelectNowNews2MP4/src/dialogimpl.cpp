#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	LineEditFile=lineEditFile;
	ListWidgetFile=listWidgetFile;
	PushButAdd=pushButAdd;
	PushButExe=pushButExe;
	PushButSelect=pushButSelect; 
}
void DialogImpl::slotAdd()
{
	QString StrFilePath;
	StrFilePath=LineEditFile->text();
	ListWidgetFile->addItem (StrFilePath);
	LineEditFile->setText("");
}
void DialogImpl::slotExe()
{
	QString StrFilePath;	
	FILE *pf;
	int i = 0;
    int c = ListWidgetFile->count();
    pf=fopen("listfile.txt","w");
    for(i=0;i<c;i++)
    {
    	StrFilePath=ListWidgetFile->item(i)->text(); 
    	//QMessageBox msg;
    	//msg.setText(StrFilePath);
    	//msg.exec();
    	fprintf(pf,"%s\n",StrFilePath.toAscii().data());
   	}
   	fclose(pf);
   	m_StrCurrentPath=QDir::currentPath();
   	m_StrCurrentPath=m_StrCurrentPath+"/";
	ListWidgetFile->clear();
	m_cmd=new QProcess();
	QString StrExeName;
	StrExeName=m_StrCurrentPath+"ConverterWMV2Mp4";
	m_cmd->start(StrExeName);
	QApplication::quit();
}
void DialogImpl::slotSelect()
{
	QString StrFilePath;
	StrFilePath=QFileDialog::getOpenFileName(this,"select file","/home/","*.*");
	LineEditFile->setText(StrFilePath);
}
void DialogImpl::slotSelectAdd()
{
	QString StrFilePath;
 	QStringList files = QFileDialog::getOpenFileNames(this,"Select one or more files to open","/home","ALL (*.*)");	
	int i,j;
	j=files.size();
	for(i=0;i<j;i++)
	{
		StrFilePath=files.at(i);
		ListWidgetFile->addItem (StrFilePath);
	}
}
//
