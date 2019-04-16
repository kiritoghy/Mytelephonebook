#pragma once
#include "contactdb.h"
#include <QtWidgets/QWidget>
#include "Phonebook.h"
#include "ui_Login.h"

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = Q_NULLPTR);

private:
    Ui::LoginClass ui;
    QSqlTableModel* model;
private:
  void init();
private slots:
  void on_Btn_login_clicked(bool);
  void on_Btn_signup_clicked(bool);
  void reshow();
  void reshow(QString, QString);
};
