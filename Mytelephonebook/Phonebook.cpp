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
  QFileDialog* fileDialog = new QFileDialog(this);
  fileDialog->setWindowTitle(tr("Open"));//设置文件保存对话框的标题
  fileDialog->setAcceptMode(QFileDialog::AcceptOpen);//设置文件对话框为保存模式
  fileDialog->setFileMode(QFileDialog::AnyFile);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
  fileDialog->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
  fileDialog->setDirectory(".");
  fileDialog->setNameFilter(tr("csv (*.csv)"));
  if (fileDialog->exec() == QFileDialog::Accepted) {
    QString filename = fileDialog->selectedFiles()[0];
    QSqlQuery query;
    if (!query.exec(QObject::tr("load data infile '%1'\
    into table phonebook\
    fields terminated by ','  optionally enclosed by '\"' escaped by '\"'  \
    lines terminated by '\r\n'\
    (@sid,susername,sname, snumber,semail) set susername = '%2';").arg(filename).arg(this->username))) {
      QMessageBox::warning(this, QStringLiteral("导入错误！"), QString(query.lastError().text()), QMessageBox::Yes);
    }
    else {
      disp();
      QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("导入成功！"), QMessageBox::Yes, QMessageBox::Yes);
    }
  }
  disp();
}

void Phonebook::on_Btn_export_clicked(bool)
{
  QFileDialog* fileDialog = new QFileDialog(this);
  fileDialog->setWindowTitle(tr("Save As"));//设置文件保存对话框的标题
  fileDialog->setAcceptMode(QFileDialog::AcceptSave);//设置文件对话框为保存模式
  fileDialog->setFileMode(QFileDialog::AnyFile);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
  fileDialog->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
  fileDialog->setDirectory(".");
  fileDialog->setNameFilter(tr("csv (*.csv)"));
  if (fileDialog->exec() == QFileDialog::Accepted) {
    QString filename = fileDialog->selectedFiles()[0];
    QSqlQuery query;
    if (!query.exec(QObject::tr("select * from phonebook where susername = '%1'\
    into outfile '%2'\
    fields terminated by ',' optionally enclosed by '\"'\
    lines terminated by '\r\n'; ").arg(this->username).arg(filename))) {
      QMessageBox::warning(this, QStringLiteral("导出错误！"), QString(query.lastError().text()), QMessageBox::Yes);
    }
    else {
      QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("导出成功！"), QMessageBox::Yes, QMessageBox::Yes);
    }
  }
}

void Phonebook::on_Btn_merge_clicked(bool)
{
  QSqlQuery query;
  qDebug() << query.exec(QObject::tr("CREATE TABLE IF NOT EXISTS merge (\
    sid INT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,\
    susername varchar(40),\
    sname varchar(255) default NULL,\
    snumber varchar(255) default NULL,\
    semail varchar(255) default NULL) ENGINE = InnoDB DEFAULT CHARSET = utf8;"));
  QFileDialog* fileDialog = new QFileDialog(this);
  fileDialog->setWindowTitle(tr("Select"));//设置文件保存对话框的标题
  fileDialog->setAcceptMode(QFileDialog::AcceptOpen);//设置文件对话框为保存模式
  fileDialog->setFileMode(QFileDialog::ExistingFiles);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
  fileDialog->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
  fileDialog->setDirectory(".");
  fileDialog->setNameFilter(tr("csv (*.csv)"));
  if (fileDialog->exec() == QFileDialog::Accepted) {
    QStringList filenames = fileDialog->selectedFiles();
    for (int i = 0; i < filenames.size(); ++i) {
      qDebug() << filenames[i];
      if (!query.exec(QObject::tr("load data infile '%1'\
        into table merge\
        fields terminated by ','  optionally enclosed by '\"' escaped by '\"'  \
        lines terminated by '\r\n'\
        (@sid,susername,sname, snumber,semail) set susername = '%2';").arg(filenames[i]).arg(QString("merge")))) {
        QMessageBox::warning(this, QStringLiteral("合并错误！"), QString(query.lastError().text()), QMessageBox::Yes);
      }
    }
  }
  fileDialog->setWindowTitle(tr("Save As"));//设置文件保存对话框的标题
  fileDialog->setAcceptMode(QFileDialog::AcceptSave);//设置文件对话框为保存模式
  fileDialog->setFileMode(QFileDialog::AnyFile);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
  fileDialog->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
  fileDialog->setDirectory(".");
  fileDialog->setNameFilter(tr("csv (*.csv)"));
  if (fileDialog->exec() == QFileDialog::Accepted) {
    QString filename = fileDialog->selectedFiles()[0];
    QSqlQuery query;
    if (!query.exec(QObject::tr("select * from merge where susername = '%1'\
    into outfile '%2'\
    fields terminated by ',' optionally enclosed by '\"'\
    lines terminated by '\r\n'; ").arg(QString("merge")).arg(filename))) {
      QMessageBox::warning(this, QStringLiteral("合并错误！"), QString(query.lastError().text()), QMessageBox::Yes);
    }
    else {
      QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("合并成功！"), QMessageBox::Yes, QMessageBox::Yes);
    }
  }
  query.exec(QObject::tr("drop table merge"));
}
