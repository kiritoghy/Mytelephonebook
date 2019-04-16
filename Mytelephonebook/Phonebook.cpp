#include "Phonebook.h"
#include "ui_Phonebook.h"

Phonebook::Phonebook(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::Phonebook();
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select(); //选取整个表的所有行  
    ui->tableView->setModel(model);
}

Phonebook::~Phonebook()
{
    delete ui;
}
void Phonebook::on_Btn_logout_clicked(bool) {
  emit sendlogoutsignals(true);
  this->close();
}