#include "dialogimpl.h"
//
DialogImpl::DialogImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	cmd=new QProcess();
	setupUi(this);

}
DialogImpl::~DialogImpl()
{
	delete cmd;	
}
void DialogImpl::slotsource()
{
	QString Strfolder;
	Strfolder = QFileDialog::getExistingDirectory(this, tr("Select folder"),"/home",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	lab_source->setText(Strfolder);
}
void DialogImpl::slottarget()
{
	QString Strfolder;
	Strfolder = QFileDialog::getExistingDirectory(this, tr("Select folder"),"/home",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	lab_target->setText(Strfolder);
}
void DialogImpl::slotRun()
{
	QString Strtargetpath;
	QStringList arguments;
	
	arguments <<"-zcvf";
	
	Strtargetpath=lab_target->text();
	Strtargetpath+="/test.tar";
	arguments <<Strtargetpath;
	
	arguments <<lab_source->text();
	cmd->setStandardOutputFile("./output.txt");
	cmd->start("tar",arguments);
	//*

	pushRun->setEnabled(false);
	while(!cmd->waitForFinished())
	{
		continue;//m_StrShowBuf+=cmd->readAll();	
	}
	pushRun->setEnabled(true);
	//*/
}

//
