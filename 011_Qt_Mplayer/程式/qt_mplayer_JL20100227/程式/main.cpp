#include <QApplication>
#include <QProcess>
#include <QVBoxLayout>
#include <QLayoutItem>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>
#include <QRect>
#include <QLinearGradient>
#include <QSizePolicy>
#include <QPushButton>
#include <QTextEdit>
#include <QSlider>
#include <QCloseEvent>
#include <QTimer>

#ifdef Q_OS_WIN32
const QString mplayerPath("path/to/mplayer.exe");
#else
const QString mplayerPath("mplayer");
#endif
const QString movieFile("all.txt");

class PlayerWidget: public QWidget
{
	Q_OBJECT

public:
	PlayerWidget(QWidget *parent =0)
		:QWidget(parent), isPlaying(false)
	{
		controller = new QPushButton("Play");
		
		renderTarget = new QWidget(this);
		renderTarget->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
		renderTarget->setAttribute(Qt::WA_PaintOnScreen);
		//JL_2010-02-27//renderTarget->setMinimumSize(176, 144);
		renderTarget->setMinimumSize(640, 480);
		timeLine = new QSlider(Qt::Horizontal);

		log = new QTextEdit;
		log->setReadOnly(true);

		QVBoxLayout *layout = new QVBoxLayout;
		layout->addWidget(controller);
		layout->addWidget(renderTarget);
		layout->addWidget(timeLine);
		layout->addWidget(log);
		setLayout(layout);

		mplayerProcess = new QProcess(this);

		poller = new QTimer(this);

		connect(controller, SIGNAL(clicked()), this, SLOT(switchPlayState()));
		connect(mplayerProcess, SIGNAL(readyReadStandardOutput()),
			this, SLOT(catchOutput()));
		connect(mplayerProcess, SIGNAL(finished(int, QProcess::ExitStatus)),
			this, SLOT(mplayerEnded(int, QProcess::ExitStatus)));
		connect(poller, SIGNAL(timeout()), this, SLOT(pollCurrentTime()));
		connect(timeLine, SIGNAL(sliderMoved(int)), this, SLOT(timeLineChanged(int)));
	}

protected:
	virtual void closeEvent(QCloseEvent *e)
	{
		stopMPlayer();
		e->accept();
	}

private:
	bool startMPlayer()
	{
		if(isPlaying)
			return true;

		QStringList args;
				
		// On demande à utiliser mplayer comme backend
		args << "x 640";
		args << "y 480";
		args << "-slave";
		args << "-playlist";
		args << movieFile;
		// Et on veut ne pas avoir trop de chose à parser :)
		args << "-quiet";
#ifdef Q_WS_WIN
		// reinterpret_cast<qlonglong> obligatoire, winId() ne se laissant pas convertir gentiment ;)
		args << "-wid" << QString::number(reinterpret_cast<qlonglong>(renderTarget->winId()));
		args << "-vo" << "directx:noaccel";
#else
		// Sur linux, aucun driver n'a été nécessaire et pas de manip pour Wid :)
		args << "-wid" << QString::number(renderTarget->winId());

		log->append("Video output driver may not be necessary for your platform. \
					Check: http://www.mplayerhq.hu/DOCS/man/en/mplayer.1.html \
					at the VIDEO OUTPUT DRIVERS section.");
#endif
		
		//JLargs << movieFile;

		// On parse la stdout et stderr au même endroit, donc on demande à "fusionnner" les 2 flux
		mplayerProcess->setProcessChannelMode(QProcess::MergedChannels);
		mplayerProcess->start(mplayerPath, args);
		if(!mplayerProcess->waitForStarted(3000))
		{
			qDebug("allez, cherche le bug :o");
			return false;
		}

		// On récupère les infos de base
		mplayerProcess->write("get_video_resolution\n");
		mplayerProcess->write("get_time_length\n");

		poller->start(1000);

		isPlaying = true;

		return true;
	}

	bool stopMPlayer()
	{
		if(!isPlaying)
			return true;

		mplayerProcess->write("quit\n");
		if(!mplayerProcess->waitForFinished(3000))
		{
			qDebug("ZOMG, ça plante :(");
			return false;
		}

		return true;
	}

private slots:
	void catchOutput()
	{
		while(mplayerProcess->canReadLine())
		{
			QByteArray buffer(mplayerProcess->readLine());
			log->append(QString(buffer));
			
			// On vérifie si on a eu des réponses
			// réponse à get_video_resolution : ANS_VIDEO_RESOLUTION='<width> x <height>'
			if(buffer.startsWith("ANS_VIDEO_RESOLUTION"))
			{
				buffer.remove(0, 21); // vire ANS_VIDEO_RESOLUTION=
				buffer.replace(QByteArray("'"), QByteArray(""));
				buffer.replace(QByteArray(" "), QByteArray(""));
				buffer.replace(QByteArray("\n"), QByteArray(""));
				buffer.replace(QByteArray("\r"), QByteArray(""));
				int sepIndex = buffer.indexOf('x');
				int resX = buffer.left(sepIndex).toInt();
				int resY = buffer.mid(sepIndex+1).toInt();
				renderTarget->setMinimumSize(resX, resY);
			}
			// réponse à get_time_length : ANS_LENGTH=xx.yy
			else if(buffer.startsWith("ANS_LENGTH"))
			{
				buffer.remove(0, 11); // vire ANS_LENGTH=
				buffer.replace(QByteArray("'"), QByteArray(""));
				buffer.replace(QByteArray(" "), QByteArray(""));
				buffer.replace(QByteArray("\n"), QByteArray(""));
				buffer.replace(QByteArray("\r"), QByteArray(""));
				float maxTime = buffer.toFloat();
				timeLine->setMaximum(static_cast<int>(maxTime+1));
			}
			// réponse à get_time_pos : ANS_TIME_POSITION=xx.y
			else if(buffer.startsWith("ANS_TIME_POSITION"))
			{
				buffer.remove(0, 18); // vire ANS_TIME_POSITION=
				buffer.replace(QByteArray("'"), QByteArray(""));
				buffer.replace(QByteArray(" "), QByteArray(""));
				buffer.replace(QByteArray("\n"), QByteArray(""));
				buffer.replace(QByteArray("\r"), QByteArray(""));
				float currTime = buffer.toFloat();
				timeLine->setValue(static_cast<int>(currTime+1));
			}
		}
	}

	void pollCurrentTime()
	{
		mplayerProcess->write("get_time_pos\n");
	}

	// Dirige la timeline
	void timeLineChanged(int pos)
	{
		mplayerProcess->write(QString("seek " + QString::number(pos) + " 2\n").toUtf8());
	}

	// Play/stop
	void switchPlayState()
	{
		if(!isPlaying)
		{
			if(!startMPlayer())
				return;

			log->clear();
			controller->setText("Stop");
			isPlaying = true;
		}
		else
		{
			if(!stopMPlayer())
				return;

			poller->stop();
			log->clear();
			controller->setText("Play");
			isPlaying = false;
		}
	}

	void mplayerEnded(int exitCode, QProcess::ExitStatus exitStatus)
	{
		isPlaying = false;
		controller->setText("Play");
		poller->stop();
	}

private:
	QPushButton *controller;
	QWidget *renderTarget;
	QProcess *mplayerProcess;
	bool isPlaying;
	QSlider *timeLine;
	QTimer *poller;
	QTextEdit *log;
};

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	PlayerWidget *pw = new PlayerWidget;
	pw->show();

	return app.exec();
}

#include "main.moc"
