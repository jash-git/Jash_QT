#include <qxml.h>
#include <qdict.h>

class LJUser;

class LJConfigParser : public QXmlDefaultHandler {
	public:
		bool startDocument( );
		bool startElement( const QString&, const QString&, const QString&, const QXmlAttributes&);
		bool endElement( const QString&, const QString&, const QString&);
		bool characters( const QString& );
		bool error( const QXmlParseException& e );
		bool fatalError( const QXmlParseException& e );

		QString errorString() { return errorStr; }

		QDict<LJUser> users;
		QString host;
		QString errorStr;

		enum { NONE, CONFIG, USER, HOST } mode;
};
