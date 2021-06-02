#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>//GUI
#include <QPixmap>//圖片存檔
#include <QDesktopWidget>//桌面擷取
#include <QTimer>//計時器
#include <QString>//字串
#include <QWidget>//GUI
#include <QDir>//目前所在位置//建立或刪除資料夾
#include <QFileInfoList>
#include <QStringList>
#include <QList>
#include <QFile>
#include <QByteArray>
#include <QProcess>
#include <QTime>
#include <QDate>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ui_MainUI.h"
//
class DialogImpl : public QWidget, public Ui::MainForm
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QPixmap Pixmap_saveimage;
	QTimer *timer01;
	int m_intTimerSwitch;
	int m_intImageCount;
	QPushButton *mapButVideo;
	QString m_StrFileName;
	bool m_blnclick;
	QProcess *m_cmd;
	QString m_StrCurrentPath;
	bool DeleteDirectory(QString StrPath);
	bool CopyDirectory(const QString source, const QString destination, const bool override);
	void CreateRunBash();
private slots:
	void slotCapture01();
	void slotTimer();
	void slotVideo();
};
#endif




