/********************************************************************************
** Form generated from reading UI file 'Usermanage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGE_H
#define UI_USERMANAGE_H

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

class Ui_Usermanage
{
public:
    QPushButton *Btn_Quname;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *LE_Quname;
    QPushButton *Btn_uall;
    QTableView *TV_um;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *Btn_usave;
    QPushButton *Btn_uundo;
    QPushButton *Btn_udelete;
    QPushButton *Btn_ulogout;

    void setupUi(QWidget *Usermanage)
    {
        if (Usermanage->objectName().isEmpty())
            Usermanage->setObjectName(QString::fromUtf8("Usermanage"));
        Usermanage->resize(634, 451);
        Btn_Quname = new QPushButton(Usermanage);
        Btn_Quname->setObjectName(QString::fromUtf8("Btn_Quname"));
        Btn_Quname->setGeometry(QRect(460, 170, 75, 23));
        layoutWidget = new QWidget(Usermanage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(420, 120, 151, 40));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        LE_Quname = new QLineEdit(layoutWidget);
        LE_Quname->setObjectName(QString::fromUtf8("LE_Quname"));

        verticalLayout->addWidget(LE_Quname);

        Btn_uall = new QPushButton(Usermanage);
        Btn_uall->setObjectName(QString::fromUtf8("Btn_uall"));
        Btn_uall->setGeometry(QRect(460, 210, 75, 23));
        TV_um = new QTableView(Usermanage);
        TV_um->setObjectName(QString::fromUtf8("TV_um"));
        TV_um->setGeometry(QRect(10, 30, 331, 411));
        layoutWidget1 = new QWidget(Usermanage);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 331, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Btn_usave = new QPushButton(layoutWidget1);
        Btn_usave->setObjectName(QString::fromUtf8("Btn_usave"));

        horizontalLayout->addWidget(Btn_usave);

        Btn_uundo = new QPushButton(layoutWidget1);
        Btn_uundo->setObjectName(QString::fromUtf8("Btn_uundo"));

        horizontalLayout->addWidget(Btn_uundo);

        Btn_udelete = new QPushButton(layoutWidget1);
        Btn_udelete->setObjectName(QString::fromUtf8("Btn_udelete"));

        horizontalLayout->addWidget(Btn_udelete);

        Btn_ulogout = new QPushButton(layoutWidget1);
        Btn_ulogout->setObjectName(QString::fromUtf8("Btn_ulogout"));

        horizontalLayout->addWidget(Btn_ulogout);


        retranslateUi(Usermanage);

        QMetaObject::connectSlotsByName(Usermanage);
    } // setupUi

    void retranslateUi(QWidget *Usermanage)
    {
        Usermanage->setWindowTitle(QApplication::translate("Usermanage", "Usermanage", nullptr));
        Btn_Quname->setText(QApplication::translate("Usermanage", "\346\237\245\350\257\242", nullptr));
        label->setText(QApplication::translate("Usermanage", "          \350\264\246\345\217\267", nullptr));
        Btn_uall->setText(QApplication::translate("Usermanage", "\346\237\245\347\234\213\345\205\250\351\203\250", nullptr));
        Btn_usave->setText(QApplication::translate("Usermanage", "\344\277\235\345\255\230", nullptr));
        Btn_uundo->setText(QApplication::translate("Usermanage", "\346\222\244\351\224\200", nullptr));
        Btn_udelete->setText(QApplication::translate("Usermanage", "\345\210\240\351\231\244", nullptr));
        Btn_ulogout->setText(QApplication::translate("Usermanage", "\346\263\250\351\224\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Usermanage: public Ui_Usermanage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGE_H
