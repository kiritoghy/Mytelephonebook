#pragma once
#ifndef CONTACTDB_H
#define CONTACTDB_H
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QObject> 
#include <QMessageBox>
bool ConnectDB();
void ImportDB();
void ExportDB();
#endif // !CONTACTDB_H

