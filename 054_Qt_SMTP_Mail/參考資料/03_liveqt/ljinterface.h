/**********************************************************************************************
 * Implements the LiveJournal interface tasks.  
 *
 * If there is no 'net connection available, store the events in a queue, if possible,
 * and use ljqd to send them later.
 *
 **********************************************************************************************/
#ifndef _LJINTERFACE_H_
#define _LJINTERFACE_H_

#include <qvector.h>
#include <qtextstream.h>
#include <qcolor.h>
#include <qurl.h>
#include <qdict.h>
#include <stdio.h>

#if USE_QPE
#include <qpeapplication.h>
#else
#include <qapplication.h>
#endif

// TODO: this is temporary.  Eventually we'll read this from the config file
#define DEFAULT_HOST "http://www.livejournal.com/interface/flat"

/*
 * Encapsulates journal post visibility. 
 */
class LJFriendGroup;
class LJVisibility {
	public:
		LJVisibility() { setPublic(); friendGroups = 0; }
		// return those properties which need to be set to match this item's
		// security settings
		void getSecurity(QDict<QString>&) const;
		long getAllowMask() { return mask; }
		void setPublic() { security = PUBLIC; mask = 0l; }
		void setPrivate() { security = PRIVATE; mask = 0l; }
		void setFriendGroups(QVector<LJFriendGroup>* groups) { friendGroups = groups; }
		void addFriendGroup(QString friendName);
		void removeFriendGroup(QString friendName);
		void addAllFriendGroups() { security = USEMASK; mask=1l; }
		void removeAllFriendGroups() { setPrivate(); }
	private:
		enum { PUBLIC, PRIVATE, USEMASK } security;
		long mask;
		QVector<LJFriendGroup>* friendGroups;
};

/*
 * A LiveJournal Event.  Right now just a regular posting, but eventually there will be
 * things like to-do lists and comments
 */
class LJEvent {
	public:
		QDateTime postDate;
		QString subject;
		QString text;
		LJVisibility security;
		QString mood;
		QString music;
		QString picture;
		bool auto_format;
		bool comments_allowed;
		QDict<QString> properties;
		QString journal;

		virtual bool serializeXML(QTextStream&);
		virtual bool deSerializeXML(QTextStream&);
		virtual ~LJEvent() {}
		/*
		 * Save this event to an XML file
		 */
};

/*
 * A LiveJournal Friend.
 */
class LJFriend {
	public:
		QString userName;
		QString fullName;
		QColor fg;
		QColor bg;
		long groupMask;
		QString userType;
};

/*
 * A LiveJournal FriendGroup.  
 */

class LJFriendGroup {
	public:
		LJFriendGroup() : sortOrder(0), isPublic(false) { }
		QString groupName;
		int sortOrder;
		bool isPublic;
};

class LJMood {
	public:
		QString moodName;
		int moodID;
};

// encapsulates the information about a user
class LJUser {
	public:
		LJUser() : fast_server(false), auto_login(false), savePassword(false)
			{}
		QString userName;
		QString password;
		QString hpassword;
		bool fast_server;
		bool auto_login;		
		bool savePassword;
		QVector<LJMood> moods;
		QVector<QString> picture_keywords;
		QVector<LJFriendGroup> friendGroups;
		QVector<QString> shared_accesses;
		QVector<LJFriend> friends;
};

class LJInterface {

	public:
		LJInterface();
		/* reads parameters like login, moods, pix, music.  Sets state (see commentary below) */

		~LJInterface();
		// calls writeConfig
		
		bool writeConfig();
		// writes the config data back, if possible (returns true on success)

		// TODO: I'll start out with all this object's functions commented out, and
		// as I implement them I'll uncomment the declarations.
		// This will eliminate a lot of warnings.
		//
		enum state { VALID=1, LOGIN=2 };
		int getState() { return _state; }
		/* Returns the state of the object.  
		 * Valid indicates there is enough information to post, but
		 * we're not necessarily connected to the 'net.  Login indicates
		 * a net connection and should include valid, but no guarantees
		 */

		//int checkfriends();
		/* Mode that clients can use to poll the server to see if their friends list has 
		 * been updated. This request is extremely quick, and is the preferred way for 
		 * users to see when their friends list is updated, rather than pounding on reload
		 * in their browser, which is stressful on the serves. */

		////int editevent(const LJEvent&);
		/* Edit or delete a user's past journal entry */

		//int editfriendgroups(const QVector<LJFriendGroup>& );
		/* Edit the user's defined groups of friends. */

		//int editfriends(const QVector<LJFriend>&);
		/* Add, edit, or delete friends from the user's friends list. */

		//QVector<LJFriend>& friendof();
		/* Returns a list of which other LiveJournal users list this user as their friend. */
		/* for all functions which return an array, if there's an error the array will be zero
		 * length.  If there's a catastrophic error throw an exception.
		 */

		//int getdaycounts(QString usejournal = "");
		/* This mode retrieves the number of journal entries per day. Useful for populating
		 * calendar widgets in GUI clients. */

		enum _lineEndings { LE_UNIX, LE_PC, LE_MAC };
		//QVector<LJEvent>& getoneevent(int itemid, QString usejournal="", int subjectOnly=0, 
						//int truncate=0, int noProps=0, _lineEndings lineEndings=LE_UNIX);
		//QVector<LJEvent>& getdayevents(QDate day, QString usejournal="", int subjectOnly=0, 
						//int truncate=0, int noProps=0, _lineEndings lineEndings=LE_UNIX);
		//QVector<LJEvent>& getlastnevents(int n, 
						//QString usejournal="", int subjectOnly=0, 
						//int truncate=0, int noProps=0, _lineEndings lineEndings=LE_UNIX);
		//QVector<LJEvent>& getlastnevents(int n, QDate beforeDate, 
						//QString usejournal="", int subjectOnly=0, 
						//int truncate=0, int noProps=0, _lineEndings lineEndings=LE_UNIX);
		//QVector<LJEvent>& getsyncevents(QDate syncDate, 
						//QString usejournal="", int subjectOnly=0, 
						//int truncate=0, int noProps=0, _lineEndings lineEndings=LE_UNIX);
		/* Download parts of the user's journal. */
		/* for all functions which return an array, if there's an error the array will be zero
		 * length.  If there's a catastrophic error throw an exception.
		 */
		/* I decided to split this into five functions for clarity.  If you disagree, I'll gladly
		 * refund what you paid for this source code :-)
		 */

		//QVector<LJFriendGroup>& getfriendgroups();
		/* Retrieves a list of the user's defined groups of friends. */
		/* for all functions which return an array, if there's an error the array will be zero
		 * length.  If there's a catastrophic error throw an exception.
		 */

		//QVector<LJFriend>& getfriends();
		/* Returns a list of which other LiveJournal users this user lists as their friend. */
		/* for all functions which return an array, if there's an error the array will be zero
		 * length.  If there's a catastrophic error throw an exception.
		 */

		bool login(QString& username, QString& password);
		/* Log in to the server, while announcing your client version. The server 
		 * returns with whether the password is good or not, the user's name, an optional
		 * message to be displayed to the user, and the list of the user's friend groups.
		 * (friend groups can also be retrieved using the getfriendgroups mode) */
		/* Stores various parameters related to the connection in the Interface object. */

		bool postEvent(const LJEvent&, QString&);
		/* The most important mode, this is how a user actually submits a new log entry 
		 * to the server. */

		//int syncitems();
		//int syncitems(QDate lastDate);
		/* Returns a list (or part of a list) of all the items (journal entries, to-do
		 * items, comments) that have been created or updated on LiveJournal since you 
		 * last downloaded them. Note that the items themselves are not returned --- 
		 * only the item type and the item number. After you get this you have to go 
		 * fetch the items using another protocol mode. For journal entries (type "L"), 
		 * use the getevents mode with a selecttype of "syncitems". */

		LJUser* getCurrentUser() { return current; }
		LJUser* setCurrentUser(const QString& userName);
		const QDict<LJUser>& getUserList() { return users; }
	private:
		int serializeXML(QFile&);
		int deSerializeXML(QFile&);
		QVector<LJEvent> event_queue;
		int sendQueue();
		QString host;
		/*
		 * Save/load the event queue to an xml file, and send the event queue
		 */

		QUrl url;
		QTime nextrequest;	// server-imposed time when we can send our next request
		int _state;
		
		QDict<LJUser> users;
		LJUser *current;		// the current logged-in user

	protected:
};

#endif 
