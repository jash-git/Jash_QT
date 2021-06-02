#include <qsocket.h>
#include <qfile.h>
#include <qstring.h>
#include <qxml.h>
#include <qtextstream.h>
#include <qmessagebox.h>

#include <stdlib.h>

#include "ljhttp.h"
#include "ljinterface.h"
#include "ljconfigparser.h"

#include "md5.h"

#ifndef USE_QPE
void pound_heap(char* where);
#else
#define pound_heap
#endif

LJInterface::LJInterface() : _state(0) {
	// see if there's a .rc file
	QString rcFileName = "%1/.liveqtrc";
	QString home = getenv("HOME");
	QFile rcFile;

	rcFile.setName(rcFileName.arg(home));
	//printf("attempting to open %s\n", rcFileName.arg(home).ascii());
	if (!rcFile.exists()) {
		printf("rcfile doesn't exist.\n");
		return;
	}

	// parse it and read in what we can
	QXmlInputSource source(rcFile);
	QXmlSimpleReader reader;
	LJConfigParser configParser;
	reader.setContentHandler(&configParser);
	reader.setErrorHandler(&configParser);

	if (reader.parse(source)) {
		//printf("user size %d\n", configParser.users.count());
		if (configParser.users.count()) {
			users = configParser.users;
			//_state |= VALID;
		} 
		if (configParser.host.length()) {
			host = configParser.host;
		} else {
			host = DEFAULT_HOST;
		}

		// check for auto-login
		QDictIterator<LJUser> it(users);
		while (it.current()) {
			if (it.current()->auto_login) {
				current = it.current();
				printf("auto-login user %s\n", current->userName.ascii());
				QString message;
				login(current->userName, current->password);
				break;
			}
		}
	} else {
		printf("parse failed: %s\n",configParser.errorString().ascii());
	}
}

bool LJInterface::writeConfig() {
	QString fname("%1/.liveqtrc");
	QFile configF(fname.arg(getenv("HOME")));

	if (!configF.open(IO_WriteOnly | IO_Truncate)) {
		printf("couldn't open %s for writing\n", fname.arg(getenv("HOME")).ascii());
		return false;
	}

	QTextStream t(&configF);
	t << "<!-- Edits will be lost -->" << endl;
	t << "<ljconfig>" << endl;
	t << "<host proxy=\"no\">" << host << "</host>" << endl;
	QDictIterator<LJUser> it(users);
	while (it.current()) {
		LJUser* luser = it.current();
		t << "<user name=\"" << luser->userName << "\"";
		if (luser->auto_login)
			t << " autologin=\"yes\"";
		if (luser->savePassword)
			t << " savepassword=\"yes\"";
		if (luser->savePassword) {
			t << " hpassword=\"" << luser->hpassword << "\"";
		}
		t << "/>" << endl;
		++it;
	}
	t << "</ljconfig>" << endl;
	configF.close();
	return true;
}

LJInterface::~LJInterface() {
	//printf("destructing ljinterface\n");
}

//int LJInterface::checkfriends() {
//}

//int LJInterface::editevent(const LJEvent&) {
//}

//int LJInterface::editfriendgroups(const QVector<LJFriendGroup>& ) {
//}

//int LJInterface::editfriends(const QVector<LJFriend>&) {
//}

//QVector<LJFriend>& LJInterface::friendof() {
//}

//int LJInterface::getdaycounts(QString usejournal = "") {
//}

//QVector<LJEvent>& LJInterface::getoneevent(int itemid, QString usejournal="", 
		//int subjectOnly=0, int truncate=0, int noProps=0, 
		//_lineEndings lineEndings=LE_UNIX) {
//}

//QVector<LJEvent>& LJInterface::getdayevents(QDate day, QString usejournal="", int subjectOnly=0, 
						//int truncate=0, int noProps=0, _lineEndings lineEndings=LE_UNIX) {
//}

//QVector<LJEvent>& LJInterface::getlastnevents(int n, 
						//QString usejournal="", int subjectOnly=0, 
						//int truncate=0, int noProps=0, _lineEndings lineEndings=LE_UNIX) {
//}

//QVector<LJEvent>& LJInterface::getlastnevents(int n, QDate beforeDate, 
						//QString usejournal="", int subjectOnly=0, 
						//int truncate=0, int noProps=0, _lineEndings lineEndings=LE_UNIX) {
//}

//QVector<LJEvent>& LJInterface::getsyncevents(QDate syncDate, 
						//QString usejournal="", int subjectOnly=0, 
						//int truncate=0, int noProps=0, _lineEndings lineEndings=LE_UNIX) {
//}

//QVector<LJFriendGroup>& LJInterface::getfriendgroups() {
//}

//QVector<LJFriend>& LJInterface::getfriends() {
//}

LJUser* LJInterface::setCurrentUser(const QString& userName) {
	current = users.find(userName);
	return current;
}

bool LJInterface::login(QString& username, QString& password) {
	current = users[username];

	if (!current) {
		current = new LJUser();
		users.insert(username, current);
		current->userName = username;
	}
	
	QString hpassword = current->hpassword;
	if (!current->hpassword.length()) {
		md5_state_t md5_state;
		md5_init(&md5_state);
		md5_append(&md5_state, (const md5_byte_t *)password.latin1(), password.length());
		unsigned char digest[16];
		md5_finish(&md5_state, digest);
		QTextOStream qos(&hpassword);
		qos.flags(QTextStream::hex);
		qos.fill('0');
		qos.width(2);
		for (int i=0; i < 16; i++) {
			qos << digest[i];
		}
		current->hpassword = hpassword;
	} 

	//printf("RMD: user %s password %s\n", username.ascii(), hpassword.ascii());

	QMap<QString, QString> params;
	params.insert("mode","login");
	params.insert("user",username);
	params.insert("hpassword",hpassword);
#if defined(_WS_X11_)
	params.insert("clientversion",QString("X11-Linux-LiveQt/0.1"));
#elif defined(_WS_QWS_)
	params.insert("clientversion",QString("arm-Linux-LiveQt/0.1"));
#elif defined(_WS_WIN_)
	params.insert("clientversion",QString("Win-LiveQt/0.1"));
#endif
	int moodCount = 0;
	if (current) {
		moodCount = current->moods.size();
	}
	params.insert("getmoods",QString::number(moodCount));
	params.insert("getpickws","1");
	
	LJHttp interface(host);
	QDict<QString> response;

	if (!interface.sendRequest(params, response) || response.count() == 0) {
		// login failed or couldn't connect to net
		// use stored params, if any
		_state = 0;
		return false;
	}

	QString status = *response["success"];
	if (status != "OK") {
		_state = 0;
		return false;
	}

	QString *value;

	if ((value = response["message"]) != 0) {
		QMessageBox::information(0, "Login Message",*value);
	}

	QString fgrpcount_str = *response["frgrp_maxnum"];
	unsigned int fgrpcount = fgrpcount_str.toInt();
	if (current->friendGroups.size() < 	fgrpcount) {
		current->friendGroups.resize(fgrpcount);
	}

	//printf("resized friendgroups to %d\n", fgrpcount);

	QString index;
	for (unsigned int fgrp = 0; fgrp < fgrpcount; fgrp++) {
		//printf("friendgroup %d\n", fgrp);
		index = "frgrp_%1_name";
		if ((value = response[index.arg(fgrp+1)]) != 0) {
			current->friendGroups.insert(fgrp,  new LJFriendGroup());
			current->friendGroups[fgrp]->groupName = *value;
			index = "frgrp_%1_sortorder";
			index = index.arg(fgrp+1);
			value = response[index];
			current->friendGroups[fgrp]->sortOrder = value->toInt();
		}
	}
	
	QString *journalcount = response["access_count"];
	if (journalcount) {
		unsigned int journals = journalcount->toInt();
		if (current->shared_accesses.size() < journals) {
			current->shared_accesses.resize(journals);
		}
		for (unsigned int journal = 0; journal < journals; journal++) {
			QString index = "access_%1";
			QString *value = response[index.arg(journal+1)];
			current->shared_accesses.insert(journal, new QString(*value));
		}
	}
	
	QString *moodcount = response["mood_count"];
	if (moodcount) {
		unsigned int moods = moodcount->toInt();
		if (current->moods.size() < moods) {
			current->moods.resize(moods);
		}
		for (unsigned int mood = 0; mood  < moods; mood++) {
			current->moods.insert(mood, new LJMood());
			QString index = "mood_%1_id";
			QString *value = response[index.arg(mood+1)];
			current->moods[mood]->moodID = value->toInt();
			
			index = "mood_%1_name";
			value = response[index.arg(mood+1)];
			current->moods[mood]->moodName = *value;
		}
	}	

	QString *pickw_count = response["pickw_count"];
	if (pickw_count) {
		unsigned int pix = pickw_count->toInt();
		if (current->picture_keywords.size() < pix) {
			current->picture_keywords.resize(pix);
		}
		for (unsigned int pic = 0; pic < pix; pic++) {
			QString index = "pickw_%1";
			QString* value = response[index.arg(pic+1)];
			current->picture_keywords.insert(pic,  new QString(*value));
		}
	}
	
	if (response["fastserver"] && response["fastserver"]->toInt() == 1) {
		current->fast_server = true;
	}

	_state |= VALID;
	return true;
}

bool LJInterface::postEvent(const LJEvent& event, QString& postStatus) {
	if (!current)
		return false;

	QMap<QString, QString> params;
	params.insert("user", current->userName);
	params.insert("hpassword",current->hpassword);
	params.insert("mode","postevent");
	params.insert("event", event.text);
	if (event.subject.length())
		params.insert("subject", event.subject);
	QDict<QString> security;
	event.security.getSecurity(security);
	QDictIterator<QString> it(security);
	while(it.current()) {
		params.insert(it.currentKey(), *it.current());
		++it;
	}
	if (event.journal.length())
		params.insert("usejournal", event.journal);
	QDateTime now = QDateTime::currentDateTime();
	params.insert("year", QString::number(now.date().year()));
	params.insert("mon", QString::number(now.date().month()));
	params.insert("day", QString::number(now.date().day()));
	params.insert("hour", QString::number(now.time().hour()));
	params.insert("min", QString::number(now.time().minute()));

	params.insert("prop_current_mood",event.mood);
	params.insert("prop_current_music",event.music);
	if (!event.auto_format)
		params.insert("prop_opt_preformatted","1");
	if (!event.comments_allowed)
		params.insert("prop_opt_nocomments","1");
	if (event.picture.length())
		params.insert("prop_picture_keyword",event.picture);

	LJHttp interface(host);
	QDict<QString> response;

	if (!interface.sendRequest(params, response) || response.count() == 0) {
		return false;
	}

	if (response["success"]->compare("OK")) {
		if (response["errmsg"])
			postStatus = *response["errmsg"];
		return false;
	}

	return true;
}

//int LJInterface::syncitems() {
//}

//int LJInterface::syncitems(QDate lastDate) {
//}

//bool LJInterface::serializeXML(QFile&) {
	//return false;
//}

//bool LJInterface::deSerializeXML(QFile&) {
	//return false;
//}

//int LJInterface::sendQueue() {
//}

void LJVisibility::getSecurity(QDict<QString>& ret) const {
	ret.clear();
	ret.setAutoDelete(true);
	if (security == PUBLIC) {
		ret.insert("security",new QString("public"));
		return;
	} else if (security == PRIVATE) {
		ret.insert("security",new QString("private"));
		return;
	} else {
		ret.insert("security",new QString("usemask"));
		QString* _mask = new QString();
		_mask->setNum(mask);
		ret.insert("allowmask", _mask);
		return;
	}
}

void LJVisibility::addFriendGroup(QString friendName) {
	if (friendGroups == 0)
		return;
	unsigned int idx;
	unsigned long bit = 1;
	for (idx=0; idx < friendGroups->size(); idx++, bit <<= 1) {
		if (friendGroups->at(idx)->groupName == friendName) {
			mask |= bit;
			return;
		}
	}
}

void LJVisibility::removeFriendGroup(QString friendName) {
	if (friendGroups == 0)
		return;
	unsigned int idx;
	unsigned long bit = 1;
	for (idx=0; idx < friendGroups->size(); idx++, bit <<= 1) {
		if (friendGroups->at(idx)->groupName == friendName) {
			mask &= ~bit;
			return;
		}
	}
}

bool LJEvent::serializeXML(QTextStream&) {
	return false;
}

bool LJEvent::deSerializeXML(QTextStream&) {
	return false;
}

#ifndef USE_QPE
#define ARRAY_SIZE 1000
void pound_heap(char* where) {
	printf("start pound_heap %s\n",where);
	QString *j[ARRAY_SIZE];

	int i;
	for (i=0; i < ARRAY_SIZE; i++) {
		j[i] = new QString("hello world %1");
		j[i]->operator=(j[i]->arg(i));
	}

	for (i=0; i < ARRAY_SIZE; i++) {
		delete j[i];
	}
	printf("end pound_heap\n");
}
#endif
