#include "mainwindowimpl.h"
#include <stdio.h>
#include <unistd.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlistbox.h>
#include <qcheckbox.h>
#include <qmultilineedit.h>
#include <qmessagebox.h>

void MainWindowImpl::closeEvent(QCloseEvent* e) {
	e->accept();
	printf("writing config information\n");
	interface.writeConfig();
}

MainWindowImpl::MainWindowImpl(QWidget* parent, 
				const char* name , WFlags fl  )
    		: Main_Window( parent, name, fl ), timeToDie(false) {
}

// this contortion is so that we're not calling processEvent while the
// event loop is in LoginDialog::exec, which seems to hang the system
void MainWindowImpl::customEvent(QCustomEvent*) {
	loginUser(); 
}

void MainWindowImpl::showEvent(QShowEvent* ) {
	// already processing a login?

	if (!(interface.getState() & LJInterface::VALID)) {
		qApp->postEvent(this, new QCustomEvent(65536));
	}
}

MainWindowImpl::~MainWindowImpl() {
}

void MainWindowImpl::post_comment() {
	if (!((interface.getState() & LJInterface::VALID) || loginUser())) {
		return;
	}

	setCursor(waitCursor);

	LJEvent newEvent;
	newEvent.subject = subject->text();
	newEvent.text = message->text();
	if (Mood->currentItem() > 0)
		newEvent.mood = Mood->currentText();
	newEvent.music = Music->text();
	newEvent.auto_format = AutoFormat->isOn();
	newEvent.comments_allowed = AllowComments->isOn();
	if (Picture->currentItem() > 0)
		newEvent.picture = Picture->currentText();
	LJVisibility& security = newEvent.security;
	security.setFriendGroups(&(interface.getCurrentUser()->friendGroups));

	QListBox* lb = Visibility->listBox();

	//for (int i=0; i < lb->numRows(); i++) {
		//printf("item %d text %s selected %d\n", i, lb->text(i).latin1(), lb->isSelected(i));
	//}
				
	if (lb->isSelected(lb->findItem("Public"))) {
		security.setPublic();
	} else if (lb->isSelected(lb->findItem("Private"))) {
		security.setPrivate();
	} else if (lb->isSelected(lb->findItem("All Friends"))) {
		security.addAllFriendGroups();
	} else {
		security.removeAllFriendGroups();
		int i;
		for (i=3; i < lb->numRows(); i++) {
			if (lb->isSelected(i))
				security.addFriendGroup(lb->text(i));
		}
	}

	if (JournalSelect->currentItem() > 0)
		newEvent.journal = JournalSelect->currentText();

	QString status;
	if (!interface.postEvent(newEvent, status)) {
		if (!status.length()) {
			status = "Server Error";
		}
		QMessageBox::warning(this, "Post Failed", status);
	}

	setCursor(arrowCursor);
	
	// set the comboboxen to default values
	subject->clear();
	message->clear();

	Mood->setCurrentItem(0);

	Picture->setCurrentItem(0);

	lb->setCurrentItem(0);
	lb->setSelected(0,true);

	JournalSelect->setCurrentItem(0);

	AutoFormat->setChecked(true);
	AllowComments->setChecked(true);
}

void MainWindowImpl::login_accept() {
	//printf("user logging in\n");
	setCursor(waitCursor);
	QString login_message;
	QString username = ld->userName->currentText(), 
			password = ld->Password->text();

	// if the password has not been changed, prefer hpassword
	// if the password has been changed, clear the hpassword so
	// interface.login will rehash it.
	// Both cases require that the user was selected from the combobox
	LJUser* current = interface.getCurrentUser();
	if (current) {
		if (ld->Password->edited()) {
			if (current->hpassword.length())
				current->hpassword.truncate(0);
		} else {
			password.truncate(0);
		}
	}

	interface.login(username, password);

	current = interface.getCurrentUser();
	current->savePassword = ld->SavePassword->isChecked();
	current->auto_login = ld->AutoLogin->isChecked();

	setCursor(arrowCursor);

	if ((~interface.getState()) & LJInterface::VALID)
		return ;

	// populate the comboboxen
	unsigned int counter;

	Mood->clear();
	Mood->insertItem("<none>", -1);
	for (counter = 0; counter < current->moods.size(); counter++) {
		if (current->moods[counter])
			Mood->insertItem(current->moods[counter]->moodName, -1);
	}
	Mood->setCurrentItem(0);

	Picture->clear();
	Picture->insertItem("<default>", -1);
	for (counter=0; counter < current->picture_keywords.size(); counter++) {
		if (current->picture_keywords[counter])
			Picture->insertItem(*(current->picture_keywords[counter]), -1);
	}
	Picture->setCurrentItem(0);

	QListBox* lb = Visibility->listBox();
	if (!lb) {
		lb = new QListBox(Visibility);
		Visibility->setListBox(lb);
	}
	lb->clear();
	lb->setSelectionMode(QListBox::Multi);
	lb->insertItem("Public", -1);
	lb->insertItem("Private", -1);
	lb->insertItem("All Friends", -1);
	for (counter=0; counter < current->friendGroups.size(); counter++) {
		if (current->friendGroups[counter])
			lb->insertItem(current->friendGroups[counter]->groupName, -1);
	}
	lb->setCurrentItem(0);
	lb->setSelected(0,true);

	JournalSelect->clear();
	JournalSelect->insertItem("<default>", -1);
	for (counter = 0; counter < current->shared_accesses.size(); counter++) {
		JournalSelect->insertItem(*(current->shared_accesses[counter]), -1);
	}
	JournalSelect->setCurrentItem(0);

	AutoFormat->setChecked(true);
	AllowComments->setChecked(true);
}

void MainWindowImpl::login_cancel() {
	//printf("user cancelled logging in\n");
	close();
}

void MainWindowImpl::user_changed(const QString& new_username) {
	LJUser* new_user = interface.setCurrentUser(new_username);
	if (new_user) {
		ld->SavePassword->setChecked(new_user->savePassword);
		ld->AutoLogin->setChecked(new_user->auto_login);

		if (new_user->savePassword) {
			if (new_user->hpassword.length())
				ld->Password->setText("<saved>");
			else
				ld->Password->setText(new_user->password);

			ld->Password->setEdited(false);
		}
	}
}

bool MainWindowImpl::loginUser() {
	//printf("in loginUser\n");
	if (!ld) {
		ld = new LoginDialog(this, "login", true);
		//connect(ld->buttonOk, SIGNAL(clicked()), this, SLOT(login_accept()));
		//connect(ld->buttonCancel, SIGNAL(clicked()), this, SLOT(login_cancel()));
		connect(ld->userName, SIGNAL(textChanged(const QString&)), 
						this, SLOT(user_changed(const QString&)));
		const QDict<LJUser>& user_list = interface.getUserList();
		QDictIterator<LJUser> it(user_list);
		while (it.current()) {
			//printf("adding user %s\n", it.currentKey().ascii());
			ld->userName->insertItem(it.currentKey(), -1);
			++it;
		}
		ld->userName->setCurrentItem(0);	// automatically calls userchanged

		ld->userName->setFocus();
		if (ld->exec()) {
			login_accept();
		} else {
			login_cancel();
		}
		delete ld;
		ld = 0;
	}

	return true;
}

