#include "Phonebook.h"
#include "ui_Phonebook.h"

Phonebook::Phonebook(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::Phonebook();
    ui->setupUi(this);
    disp();
}

Phonebook::~Phonebook()
{
  qDebug() << "destory";
    delete ui;
}
void Phonebook::on_Btn_logout_clicked(bool) {
  emit sendlogoutsignals(true);
  this->close();
}
void Phonebook::disp() {
  model = new QSqlTableModel(this);
  model->setTable("phonebook");
  model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  model->setFilter(QObject::tr("susername = '%1'").arg(this->username));
  model->select(); //选取整个表的所有行  
  //model->removeColumn(0);
  model->setHeaderData(2, Qt::Orientation::Horizontal, QStringLiteral("姓名"));
  model->setHeaderData(3, Qt::Orientation::Horizontal, QStringLiteral("电话"));
  model->setHeaderData(4, Qt::Orientation::Horizontal, QStringLiteral("E-mail"));
  ui->tableView->setModel(model);
  ui->tableView->hideColumn(0);
  ui->tableView->hideColumn(1);
}

void Phonebook::setUserName(QString name)
{
  this->username = name;
}

void Phonebook::fresh()
{
  disp();
}

void Phonebook::on_Btn_new_clicked(bool)
{
  Addcontact* AC = new Addcontact();
  AC->setUserName(this->username);
  connect(AC, SIGNAL(addnewconfsignals()), this, SLOT(disp()));
  AC->show();
}
void Phonebook::on_Btn_save_clicked(bool)
{
  if (model == NULL)return;
  qDebug() << "submit:" << model->submitAll();
}
void Phonebook::on_Btn_undo_clicked(bool) {
  if (model == NULL)return;
  model->revertAll();
}
void Phonebook::on_Btn_delete_clicked(bool) {
  int curRow = ui->tableView->currentIndex().row();
  model->removeRow(curRow);
  int ok = QMessageBox::warning(this, QStringLiteral("删除联系人!"), QStringLiteral("你确定删除当前联系人吗?\n删除后将不能撤销"),
    QMessageBox::Yes, QMessageBox::No);
  if (ok == QMessageBox::No)
  {
    model->revertAll(); //如果不删除，则撤销  
  }
  else model->submitAll(); //否则提交，在数据库中删除该行  
}

void Phonebook::on_Btn_all_clicked(bool)
{
  disp();
}

void Phonebook::on_Btn_Qname_clicked(bool)
{
  QString name = ui->LE_Qname->text();
  if (model == NULL)return;
  model->setFilter(QObject::tr("susername = '%1' and sname = '%2'").arg(this->username).arg(name)); //根据姓名进行筛选  
  model->select();
  model->setHeaderData(2, Qt::Orientation::Horizontal, QStringLiteral("姓名"));
  model->setHeaderData(3, Qt::Orientation::Horizontal, QStringLiteral("电话"));
  model->setHeaderData(4, Qt::Orientation::Horizontal, QStringLiteral("E-mail"));
  ui->tableView->setModel(model);
  ui->tableView->hideColumn(0);
  ui->tableView->hideColumn(1);
}

void Phonebook::on_Btn_Qphone_clicked(bool)
{
  QString phone = ui->LE_Qphone->text();
  if (model == NULL)return;
  model->setFilter(QObject::tr("susername = '%1' and snumber = '%2'").arg(this->username).arg(phone)); //根据姓名进行筛选  
  model->select();
  model->setHeaderData(2, Qt::Orientation::Horizontal, QStringLiteral("姓名"));
  model->setHeaderData(3, Qt::Orientation::Horizontal, QStringLiteral("电话"));
  model->setHeaderData(4, Qt::Orientation::Horizontal, QStringLiteral("E-mail"));
  ui->tableView->setModel(model);
  ui->tableView->hideColumn(0);
  ui->tableView->hideColumn(1);
}

void Phonebook::on_Btn_import_clicked(bool)
{
  ImportDB();
}

void Phonebook::on_Btn_export_clicked(bool)
{
  ExportDB();
}
