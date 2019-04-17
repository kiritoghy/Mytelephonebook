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
  QString confpwd = ui->LE_confpwd->text();
  if (username.length() == 0 || pwd.length() == 0 || confpwd.length() == 0)
  {
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui->label_hint3->setPalette(pa);
    ui->label_hint3->setText(QStringLiteral("账户或密码不能为空"));
  }
  else if (pwd != confpwd) {
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    ui->label_hint3->setPalette(pa);
    ui->label_hint3->setText(QStringLiteral("两次密码不一致！"));
  }
  else {
    QSqlQuery query;
    query.exec(QObject::tr("select * from user where uusername = '%1'").arg(username));
    if (query.size()) {
      QPalette pa;
      pa.setColor(QPalette::WindowText, Qt::red);
      ui->label_hint3->setPalette(pa);
      ui->label_hint3->setText(QStringLiteral("账户已存在！"));
    }
    else {
      query.exec(QObject::tr("insert into user (uusername,upwd) values('%1','%2')").arg(username).arg(pwd));
      emit sendsignupsignals(username, pwd);
      this->close();
    }
  }
}
