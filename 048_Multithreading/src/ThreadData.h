#ifndef __THREADDATA_H__
#define __THREADDATA_H__

// place your code here
#include <QList>
#include <QString>
#include <QMutex>
class ThreadData
{
	public:
		ThreadData();
		void addData(QString StrBuf);
		bool GetData(QString *StrBuf);
		int m_size;
		int m_index;
private:
		QMutex mutex;
		QList<QString> m_ListData;
};
#endif // __THREADDATA_H__
