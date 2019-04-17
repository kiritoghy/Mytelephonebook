/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QLocale>
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

class Ui_LoginClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *LE_username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *LE_pwd;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Btn_login;
    QPushButton *Btn_signup;
    QLabel *label_hint1;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_hint2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *LoginClass)
    {
        if (LoginClass->objectName().isEmpty())
            LoginClass->setObjectName(QString::fromUtf8("LoginClass"));
        LoginClass->resize(600, 400);
        gridLayout = new QGridLayout(LoginClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 140, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(LoginClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        LE_username = new QLineEdit(LoginClass);
        LE_username->setObjectName(QString::fromUtf8("LE_username"));

        horizontalLayout->addWidget(LE_username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(LoginClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        LE_pwd = new QLineEdit(LoginClass);
        LE_pwd->setObjectName(QString::fromUtf8("LE_pwd"));
        LE_pwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(LE_pwd);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Btn_login = new QPushButton(LoginClass);
        Btn_login->setObjectName(QString::fromUtf8("Btn_login"));

        horizontalLayout_3->addWidget(Btn_login);

        Btn_signup = new QPushButton(LoginClass);
        Btn_signup->setObjectName(QString::fromUtf8("Btn_signup"));

        horizontalLayout_3->addWidget(Btn_signup);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 3, 1);

        label_hint1 = new QLabel(LoginClass);
        label_hint1->setObjectName(QString::fromUtf8("label_hint1"));
        label_hint1->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));

        gridLayout->addWidget(label_hint1, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(187, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(187, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        label_hint2 = new QLabel(LoginClass);
        label_hint2->setObjectName(QString::fromUtf8("label_hint2"));

        gridLayout->addWidget(label_hint2, 3, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 139, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);


        retranslateUi(LoginClass);

        QMetaObject::connectSlotsByName(LoginClass);
    } // setupUi

    void retranslateUi(QWidget *LoginClass)
    {
        LoginClass->setWindowTitle(QApplication::translate("LoginClass", "Login", nullptr));
        label->setText(QApplication::translate("LoginClass", "\350\264\246\346\210\267:", nullptr));
        label_2->setText(QApplication::translate("LoginClass", "\345\257\206\347\240\201:", nullptr));
        Btn_login->setText(QApplication::translate("LoginClass", "\347\231\273\345\275\225", nullptr));
#ifndef QT_NO_SHORTCUT
        Btn_login->setShortcut(QApplication::translate("LoginClass", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        Btn_signup->setText(QApplication::translate("LoginClass", "\346\263\250\345\206\214", nullptr));
        label_hint1->setText(QString());
        label_hint2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginClass: public Ui_LoginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
