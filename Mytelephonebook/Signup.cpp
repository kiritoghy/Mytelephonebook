#include "Signup.h"
#include "ui_Signup.h"

Signup::Signup(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::Signup();
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}
void Signup::on_Btn_register_clicked(bool) {
  QString username = ui->LE_signusername->text();
  QString pwd = ui->LE_signpwd->text();
  emit sendsignupsignals(username, pwd);
  this->close();
}
