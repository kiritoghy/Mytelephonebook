#pragma once

#include <QWidget>
#include "contactdb.h"
namespace Ui { class Addcontact; };

class Addcontact : public QWidget
{
    Q_OBJECT

public:
    Addcontact(QWidget *parent = Q_NULLPTR);
    ~Addcontact();
    void setUserName(QString);
private:
    Ui::Addcontact *ui;
    QString username;
signals:
  void addnewconfsignals();
private slots:
  void on_Btn_addconf_clicked(bool);
};
