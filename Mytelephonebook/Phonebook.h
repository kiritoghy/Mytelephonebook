#pragma once

#include <QWidget>
#include "Addcontact.h"
#include "contactdb.h"
namespace Ui { class Phonebook; };

class Phonebook : public QWidget
{
    Q_OBJECT

public:
    Phonebook(QWidget *parent = Q_NULLPTR);
    ~Phonebook();
    void setUserName(QString);
    void fresh();
private:
    Ui::Phonebook *ui;
    QSqlTableModel* model = NULL;
    QString username;
signals:
  void sendlogoutsignals(bool);
private slots:
  void on_Btn_logout_clicked(bool);
  void on_Btn_new_clicked(bool);
  void on_Btn_save_clicked(bool);
  void on_Btn_undo_clicked(bool);
  void on_Btn_delete_clicked(bool);
  void on_Btn_all_clicked(bool);
  void on_Btn_Qname_clicked(bool);
  void on_Btn_Qphone_clicked(bool);
  void on_Btn_import_clicked(bool);
  void on_Btn_export_clicked(bool);
  void on_Btn_merge_clicked(bool);
  void disp();
};
