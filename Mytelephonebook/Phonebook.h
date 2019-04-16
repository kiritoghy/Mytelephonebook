#pragma once

#include <QWidget>
#include "contactdb.h"
namespace Ui { class Phonebook; };

class Phonebook : public QWidget
{
    Q_OBJECT

public:
    Phonebook(QWidget *parent = Q_NULLPTR);
    ~Phonebook();

private:
    Ui::Phonebook *ui;
    QSqlTableModel* model;
signals:
  void sendlogoutsignals(bool);
private slots:
  void on_Btn_logout_clicked(bool);
};
