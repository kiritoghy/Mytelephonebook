/********************************************************************************
** Form generated from reading UI file 'Phonebook.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONEBOOK_H
#define UI_PHONEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Phonebook
{
public:
    QTableView *tableView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *LE_Qphone;
    QPushButton *Btn_Qname;
    QPushButton *Btn_Qphone;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Btn_new;
    QPushButton *Btn_delete;
    QPushButton *Btn_logout;
    QPushButton *Btn_import;
    QPushButton *Btn_export;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *LE_Qname;

    void setupUi(QWidget *Phonebook)
    {
        if (Phonebook->objectName().isEmpty())
            Phonebook->setObjectName(QString::fromUtf8("Phonebook"));
        Phonebook->resize(636, 480);
        tableView = new QTableView(Phonebook);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(9, 40, 401, 431));
        layoutWidget = new QWidget(Phonebook);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 230, 181, 40));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        LE_Qphone = new QLineEdit(layoutWidget);
        LE_Qphone->setObjectName(QString::fromUtf8("LE_Qphone"));

        verticalLayout_2->addWidget(LE_Qphone);

        Btn_Qname = new QPushButton(Phonebook);
        Btn_Qname->setObjectName(QString::fromUtf8("Btn_Qname"));
        Btn_Qname->setGeometry(QRect(480, 130, 75, 23));
        Btn_Qphone = new QPushButton(Phonebook);
        Btn_Qphone->setObjectName(QString::fromUtf8("Btn_Qphone"));
        Btn_Qphone->setGeometry(QRect(480, 290, 75, 23));
        widget = new QWidget(Phonebook);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Btn_new = new QPushButton(widget);
        Btn_new->setObjectName(QString::fromUtf8("Btn_new"));

        horizontalLayout->addWidget(Btn_new);

        Btn_delete = new QPushButton(widget);
        Btn_delete->setObjectName(QString::fromUtf8("Btn_delete"));

        horizontalLayout->addWidget(Btn_delete);

        Btn_logout = new QPushButton(widget);
        Btn_logout->setObjectName(QString::fromUtf8("Btn_logout"));

        horizontalLayout->addWidget(Btn_logout);

        Btn_import = new QPushButton(widget);
        Btn_import->setObjectName(QString::fromUtf8("Btn_import"));

        horizontalLayout->addWidget(Btn_import);

        Btn_export = new QPushButton(widget);
        Btn_export->setObjectName(QString::fromUtf8("Btn_export"));

        horizontalLayout->addWidget(Btn_export);

        widget1 = new QWidget(Phonebook);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(430, 80, 181, 40));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        LE_Qname = new QLineEdit(widget1);
        LE_Qname->setObjectName(QString::fromUtf8("LE_Qname"));

        verticalLayout->addWidget(LE_Qname);


        retranslateUi(Phonebook);

        QMetaObject::connectSlotsByName(Phonebook);
    } // setupUi

    void retranslateUi(QWidget *Phonebook)
    {
        Phonebook->setWindowTitle(QApplication::translate("Phonebook", "Phonebook", nullptr));
        label_2->setText(QApplication::translate("Phonebook", "            \347\224\265\350\257\235", nullptr));
        Btn_Qname->setText(QApplication::translate("Phonebook", "\346\237\245\350\257\242", nullptr));
        Btn_Qphone->setText(QApplication::translate("Phonebook", "\346\237\245\350\257\242", nullptr));
        Btn_new->setText(QApplication::translate("Phonebook", "\346\226\260\345\273\272", nullptr));
        Btn_delete->setText(QApplication::translate("Phonebook", "\345\210\240\351\231\244", nullptr));
        Btn_logout->setText(QApplication::translate("Phonebook", "\346\263\250\351\224\200", nullptr));
        Btn_import->setText(QApplication::translate("Phonebook", "\345\257\274\345\205\245", nullptr));
        Btn_export->setText(QApplication::translate("Phonebook", "\345\257\274\345\207\272", nullptr));
        label->setText(QApplication::translate("Phonebook", "            \345\247\223\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Phonebook: public Ui_Phonebook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONEBOOK_H
