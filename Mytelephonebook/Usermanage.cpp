#include "Usermanage.h"
#include "ui_Usermanage.h"

Usermanage::Usermanage(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::Usermanage();
    ui->setupUi(this);
    disp();
}

Usermanage::~Usermanage()
{
    delete ui;
}
void Usermanage::disp()
{
  model = new QSqlTableModel(this);
  model->setTable("user");
  model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  model->select(); //ѡȡ�������������  
  model->setHeaderData(1, Qt::Orientation::Horizontal, QStringLiteral("Ȩ��"));
  model->setHeaderData(2, Qt::Orientation::Horizontal, QStringLiteral("�û���"));
  model->setHeaderData(3, Qt::Orientation::Horizontal, QStringLiteral("����"));
  ui->TV_um->setModel(model);
  ui->TV_um->hideColumn(0);
}
void Usermanage::on_Btn_usave_clicked(bool)
{
  if (model == NULL)return;
  qDebug() << "submit:" << model->submitAll();
}
void Usermanage::on_Btn_uundo_clicked(bool)
{
  if (model == NULL)return;
  model->revertAll();
}
void Usermanage::on_Btn_udelete_clicked(bool)
{
  int curRow = ui->TV_um->currentIndex().row();
  model->removeRow(curRow);
  int ok = QMessageBox::warning(this, QStringLiteral("ɾ���û�!"), QStringLiteral("��ȷ��ɾ���û���?\nɾ���󽫲��ܳ���"),
    QMessageBox::Yes, QMessageBox::No);
  if (ok == QMessageBox::No)
  {
    model->revertAll(); //�����ɾ��������  
  }
  else model->submitAll(); //�����ύ�������ݿ���ɾ������  
}
void Usermanage::on_Btn_Quname_clicked(bool)
{
  QString name = ui->LE_Quname->text();
  if (model == NULL)return;
  model->setFilter(QObject::tr("uusername = '%1'").arg(name)); //������������ɸѡ  
  model->select(); //ѡȡ�������������  
  model->setHeaderData(1, Qt::Orientation::Horizontal, QStringLiteral("Ȩ��"));
  model->setHeaderData(2, Qt::Orientation::Horizontal, QStringLiteral("�û���"));
  model->setHeaderData(3, Qt::Orientation::Horizontal, QStringLiteral("����"));
  ui->TV_um->setModel(model);
  ui->TV_um->hideColumn(0);
}
void Usermanage::on_Btn_uall_clicked(bool)
{
  disp();
}
void Usermanage::on_Btn_ulogout_clicked(bool) {
  emit sendulogoutsignals(true);
  this->close();
}
