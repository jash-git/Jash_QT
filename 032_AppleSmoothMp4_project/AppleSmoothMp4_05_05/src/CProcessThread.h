#ifndef __CPROCESSTHREAD_H__
#define __CPROCESSTHREAD_H__
#include <QThread>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QStringList>
#include <QProcess>
#include <QDir>
#include <QtGlobal>
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
	QString m_StrDesFileName;
	QString m_StrSouFileName;
	QString m_StrDesFolder;
	QString m_StrSouFolder;
	struct ConfigData m_ConfigDataBuf;
	qint64 *m_lngmp4FileSize;
	CProcessThread();
	CProcessThread(QString StrSouFolder,QString StrDesFolder,QString StrDesFileName,QString StrSouFileName,struct ConfigData Config,qint64 *m_lngmp4Size);
	void setvalue(QString StrSouFolder,QString StrDesFolder,QString StrDesFileName,QString StrSouFileName,struct ConfigData Config,qint64 *m_lngmp4Size);
protected:
	void run();	
};
#endif // __CPROCESSTHREAD_H__
