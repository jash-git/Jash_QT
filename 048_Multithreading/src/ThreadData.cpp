#include "ThreadData.h"
ThreadData::ThreadData()
{
	m_size=0;	
	m_index=0;
	m_ListData.clear();
}
void ThreadData::addData(QString StrBuf)
{
	m_ListData.append(StrBuf);
	m_index=0;
	m_size=m_ListData.size();
}
bool ThreadData::GetData(QString *StrBuf)
{
	bool blnget=false;
	mutex.lock();	
	if((m_index+1)<=m_size)
	{
		*StrBuf=m_ListData.at(m_index);
		m_index++;
		blnget=true;
	}
	else
	{
		blnget=false;
	}
	mutex.unlock();
	return blnget;
}
// place your code here
