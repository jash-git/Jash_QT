#include "ljconfigparser.h"
#include "ljinterface.h"

bool LJConfigParser::startDocument() {
	printf("starting to parse the document\n");
	mode = NONE;
	errorStr.truncate(0);
	return true;
}

bool LJConfigParser::startElement( const QString&, 
				const QString&, 
				const QString& qName, const QXmlAttributes& attribs) {
	printf("qname %s\n", qName.ascii());
	if (mode == NONE) {
		if (qName == "ljconfig")
			mode = CONFIG;
	} else if (mode == CONFIG) {
		if (qName == "user") {
			mode = USER;
			LJUser *newUser = new LJUser;
			for (int i=0; i < attribs.length(); i++) {
				printf("attribute %d name %s value %s\n", i, attribs.qName(i).ascii(),
					attribs.value(i).ascii());
				if (attribs.qName(i) == "name")
					newUser->userName = attribs.value(i);
				else if (attribs.qName(i) == "password")
					newUser->password = attribs.value(i);
				else if (attribs.qName(i) == "hpassword")
					newUser->hpassword = attribs.value(i);
				else if (attribs.qName(i) == "autologin")
					newUser->auto_login = (attribs.value(i) == "yes");
				else if (attribs.qName(i) == "savepassword")
					newUser->savePassword = (attribs.value(i) == "yes");
			}
			users.insert(newUser->userName, newUser);
		} else if (qName == "host") {
			mode = HOST;
		}
	} else {
		errorStr = "unknown string %1";
		errorStr = errorStr.arg(qName);
		return false;
	}

	return true;
}

bool LJConfigParser::endElement( const QString &, 
				const QString &, 
				const QString & qName) {
	printf("finishing qname %s\n", qName.ascii());
	if (mode == CONFIG) {
		mode = NONE;
	} else if (mode == USER) {
		mode = CONFIG;
	} else if (mode == HOST) {
		mode = CONFIG;
	}
	return true;
}

bool LJConfigParser::error( const QXmlParseException& e ) {
	printf("got error %s\n", e.message().ascii());
	return true;
}

bool LJConfigParser::characters( const QString& chars) {
	printf("got chars %s\n", chars.ascii());
	if (mode == HOST) {
		host = chars;
	}
	return true;
}

bool LJConfigParser::fatalError( const QXmlParseException& e ) {
	printf("got error %s\n", e.message().ascii());
	return true;
}
