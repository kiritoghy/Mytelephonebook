#pragma once
#ifndef CONTACTDB_H
#define CONTACTDB_H
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QObject> 
#include <QMessageBox>
#include <QFileDialog>
bool ConnectDB();
#endif // !CONTACTDB_H

