#pragma once

#include <QWidget>
#include "contactdb.h"
#include "Phonebook.h"
namespace Ui { class Usermanage; };

class Usermanage : public QWidget
{
    Q_OBJECT

public:
    Usermanage(QWidget *parent = Q_NULLPTR);
    ~Usermanage();
    void disp();
private:
    Ui::Usermanage *ui;
    QSqlTableModel* model = NULL;
signals:
  void sendulogoutsignals(bool);
private slots:
  void on_Btn_ulogout_clicked(bool);
  void on_Btn_usave_clicked(bool);
  void on_Btn_uundo_clicked(bool);
  void on_Btn_udelete_clicked(bool);
  void on_Btn_Quname_clicked(bool);
  void on_Btn_uall_clicked(bool);
};
