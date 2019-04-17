/********************************************************************************
** Form generated from reading UI file 'Addcontact.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCONTACT_H
#define UI_ADDCONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Addcontact
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *LE_acname;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *LE_acphone;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *LE_acemail;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Btn_addconf;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *Addcontact)
    {
        if (Addcontact->objectName().isEmpty())
            Addcontact->setObjectName(QString::fromUtf8("Addcontact"));
        Addcontact->resize(405, 300);
        gridLayout = new QGridLayout(Addcontact);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 49, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Addcontact);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        LE_acname = new QLineEdit(Addcontact);
        LE_acname->setObjectName(QString::fromUtf8("LE_acname"));

        horizontalLayout->addWidget(LE_acname);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Addcontact);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        LE_acphone = new QLineEdit(Addcontact);
        LE_acphone->setObjectName(QString::fromUtf8("LE_acphone"));

        horizontalLayout_2->addWidget(LE_acphone);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Addcontact);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        LE_acemail = new QLineEdit(Addcontact);
        LE_acemail->setObjectName(QString::fromUtf8("LE_acemail"));

        horizontalLayout_3->addWidget(LE_acemail);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 1, 1, 1);

        Btn_addconf = new QPushButton(Addcontact);
        Btn_addconf->setObjectName(QString::fromUtf8("Btn_addconf"));

        gridLayout->addWidget(Btn_addconf, 3, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 49, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 2, 1, 1);


        retranslateUi(Addcontact);

        QMetaObject::connectSlotsByName(Addcontact);
    } // setupUi

    void retranslateUi(QWidget *Addcontact)
    {
        Addcontact->setWindowTitle(QApplication::translate("Addcontact", "Addcontact", nullptr));
        label->setText(QApplication::translate("Addcontact", "\345\247\223\345\220\215:", nullptr));
        label_2->setText(QApplication::translate("Addcontact", "\347\224\265\350\257\235:", nullptr));
        label_3->setText(QApplication::translate("Addcontact", "E-mail:", nullptr));
        Btn_addconf->setText(QApplication::translate("Addcontact", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Addcontact: public Ui_Addcontact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONTACT_H
