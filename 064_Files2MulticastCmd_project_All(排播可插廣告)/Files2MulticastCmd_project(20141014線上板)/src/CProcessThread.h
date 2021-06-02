#ifndef __CPROCESSTHREAD_H__
#define __CPROCESSTHREAD_H__
#include <QThread>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QStringList>
#include <QProcess>
#include <QTextStream>
#include <QDir>
class CProcessThread:public QThread
{
Q_OBJECT
public:
	CProcessThread();
	QStringList m_arguments;
	void SetValue(QString StrMediaPath,QString StrStartPoint);
protected:
	void run();	
};
#endif // __CPROCESSTHREAD_H__

