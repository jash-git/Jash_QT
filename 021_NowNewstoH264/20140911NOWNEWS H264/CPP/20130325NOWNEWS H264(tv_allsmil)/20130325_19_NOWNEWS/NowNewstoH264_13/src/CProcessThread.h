#ifndef __CPROCESSTHREAD_H__
#define __CPROCESSTHREAD_H__
#include <QThread>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QStringList>
#include <QProcess>
#include <QTextStream>
struct ConfigData
{
	QString StrEndPath;
	QString StrStartPath;
	QString StrScriptPath;
	QString StrNetEndPath;
	QString StrNetStartPath;
};
// place your code here
class CProcessThread:public QThread
{
Q_OBJECT
public:
	QString m_StrUID;
	QString m_StrFileName;
	QString m_StrSP;
	QString m_StrDP;
	struct ConfigData m_ConfigDataBuf;
	long *m_lngmp4FileSize;
	CProcessThread();
	CProcessThread(QString StrUID,QString StrFileName,QString StrSP,QString StrDP,struct ConfigData Config,long *m_lngmp4Size);
	void setvalue(QString StrUID,QString StrFileName,QString StrSP,QString StrDP,struct ConfigData Config,long *m_lngmp4Size);
	void CreateSmilFile(QString StrSmilName,QString FileName);
protected:
	void run();	
};
#endif // __CPROCESSTHREAD_H__
