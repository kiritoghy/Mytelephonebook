#include "Login.h"
#include "Signup.h"
#include "Phonebook.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    init();
}
void Login::init() {
}
void Login::on_Btn_login_clicked(bool) {

  Phonebook* PB = new Phonebook();
  connect(PB, SIGNAL(sendlogoutsignals(bool)), this, SLOT(reshow()));
  ui.LE_username->setText(QString(""));
  ui.LE_pwd->setText(QString(""));
  this->hide();
  PB->show();
}
void Login::on_Btn_signup_clicked(bool) {
  Signup* signup = new Signup();
  connect(signup, SIGNAL(sendsignupsignals(QString, QString)), this, SLOT(reshow(QString,QString)));
  ui.LE_username->setText(QString(""));
  ui.LE_pwd->setText(QString(""));
  this->hide();
  signup->show();
}
void Login::reshow() {
  this->show();
}
void Login::reshow(QString username, QString pwd) {
  ui.LE_username->setText(username);
  ui.LE_pwd->setText(pwd);
  this->show();
}