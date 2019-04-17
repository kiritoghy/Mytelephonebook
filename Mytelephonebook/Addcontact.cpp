#include "Addcontact.h"
#include "ui_Addcontact.h"

Addcontact::Addcontact(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::Addcontact();
    ui->setupUi(this);
}

Addcontact::~Addcontact()
{
    delete ui;
}

void Addcontact::setUserName(QString username)
{
  this->username = username;
}
void Addcontact::on_Btn_addconf_clicked(bool) {
  QString name = ui->LE_acname->text();
  QString phone = ui->LE_acphone->text();
  QString email = ui->LE_acemail->text();
  if (name.length() == 0 && phone.length() == 0 && email.length() == 0) {
    this->close();
  }
  else {
    QSqlQuery query;
    qDebug() << query.exec(QObject::tr("insert into phonebook (susername,sname,snumber,semail)\
                         values('%1','%2','%3','%4')").arg(this->username).arg(name).arg(phone).arg(email));
    emit addnewconfsignals();
    this->close();
  }
}
