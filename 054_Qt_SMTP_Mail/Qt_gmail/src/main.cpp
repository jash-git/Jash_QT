#include <QtGui/QApplication>

#include "SmtpMime"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // This is a first demo application of the SmtpClient for Qt project


    // First we need to create an SmtpClient object
    // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    // We need to set the username (your email address) and password
    // for smtp authentification.

    smtp.setUser("lubita.co@gmail.com");
    smtp.setPassword("asd700502");

    // Now we create a MimeMessage object. This is the email.

    MimeMessage message;

    message.setSender(new EmailAddress("lubita.co@gmail.com", "jashliao"));
    message.addRecipient(new EmailAddress("jashliao@tw-airnet.com.tw", "jashliao"));
    message.setSubject("SmtpClient for Qt - Demo01");


    // Now add some text to the email.
    // First we create a MimeText object.

    MimeText text;

    text.setText("Hi,\nThis is a simple email message01.\n");

    // Now add it to the mail

    message.addPart(&text);


    // Now we can send the mail

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();

}