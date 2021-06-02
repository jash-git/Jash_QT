#ifndef DIALOGIMPL_H
#define DIALOGIMPL_H
//
#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QProcess>
#include <QStringList>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include<fstream>
#include "ui_AnyMovietoH264.h"
using namespace std;
//
class DialogImpl : public QDialog, public Ui::AnyMovietoH264
{
Q_OBJECT
public:
	DialogImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	QProcess m_cmd;
	QString m_StrPath_Name;
	QString m_StrCUP,m_StrAudioFormat,m_StrVideoFormat,m_StrAudioSample,m_StrAudioBitrate,m_StrVideoFsp,m_StrVideoBitrate,m_StrSize;
private slots:
	void slotSelect();
	void slotDetail();
	void slotRun();
	void outputCommand();
	void processFinished(int exitCode,QProcess::ExitStatus exitStatus);
};
#endif




