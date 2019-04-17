#pragma once
#include "contactdb.h"
#include <QWidget>
namespace Ui { class Signup; };

class Signup : public QWidget
{
    Q_OBJECT

public:
    Signup(QWidget *parent = Q_NULLPTR);
    ~Signup();
signals:
  void sendsignupsignals(QString,QString);
private:
    Ui::Signup *ui;
private slots:
  void on_Btn_register_clicked(bool);
};
