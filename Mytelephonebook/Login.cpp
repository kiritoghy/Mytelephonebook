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
  QSqlQuery query;
  QString username = ui.LE_username->text();
  QString pwd = ui.LE_pwd->text();
  qDebug() << query.exec(QObject::tr("select * from user where uusername = '%1'").arg(username));
  if (query.size() == 0) {
    //QMessageBox::warning(NULL, QStringLiteral("提示"), QString::fromUtf8("这是汉字"), QMessageBox::Yes);
    ui.label_hint2->setText("");
    ui.label_hint1->setText("");
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui.label_hint1->setPalette(pa);
    ui.label_hint1->setText(QStringLiteral("账户不存在，请注册！"));
  }
  else if(query.next() && query.value(3).toString() == pwd){
    ui.label_hint2->setText("");
    ui.label_hint1->setText("");
    Phonebook* PB = new Phonebook();
    PB->setUserName(username);
    PB->fresh();
    connect(PB, SIGNAL(sendlogoutsignals(bool)), this, SLOT(reshow()));
    ui.LE_username->setText(QString(""));
    ui.LE_pwd->setText(QString(""));
    this->hide();
    PB->show();
  }
  else {
    ui.label_hint2->setText("");
    ui.label_hint1->setText("");
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui.label_hint2->setPalette(pa);
    ui.label_hint2->setText(QStringLiteral("账户或密码错误，请检查!"));
  }
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