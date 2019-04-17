#include "contactdb.h"
#include <qDebug>
QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");     //驱动 
bool ConnectDB() {
  db.setHostName("localhost");          //数据库地址，一般都是本地，就填localhost就可以 
  db.setUserName("root");               //用户名，一般是本地用户，就填root就可以
  db.setPassword("0000");             //密码，填写你自己的Mysql登陆密码，为了保密我这里用*代替我的密码
  db.setPort(3306);                   //端口默认的是3306，可以不用写 
  if (!db.open()){
    QMessageBox::warning(NULL, QStringLiteral("提示"), "数据库连接失败，请重启", QMessageBox::Yes);
    return false;
  }
  QSqlQuery query;
  query.exec(QObject::tr("Create Database If Not Exists PhoneBookManager Character Set UTF8"));
  db.setDatabaseName("PhoneBookManager");
  qDebug() << db.open();
  qDebug() << query.exec(QObject::tr("CREATE TABLE IF NOT EXISTS PhoneBook (\
    sid INT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,\
    susername varchar(40),\
    sname varchar(255) default NULL,\
    snumber varchar(255) default NULL,\
    semail varchar(255) default NULL) ENGINE = InnoDB DEFAULT CHARSET = utf8;"));
  qDebug() << query.exec(QObject::tr("CREATE TABLE IF NOT EXISTS user (\
    uid INT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,\
    uaccess int default 0,\
    uusername varchar(40) NOT NULL,\
    upwd varchar(40) NOT NULL);"));
  qDebug() << query.exec(QObject::tr("INSERT INTO user (uaccess, uusername, upwd)\
    SELECT 1, 'admin', 'admin'\
    from DUAL\
    where not exists(select uusername from user where uusername = 'admin');"));
}
void ImportDB() {

}
void ExportDB() {

}