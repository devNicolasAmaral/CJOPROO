/********************************************************************************
** Form generated from reading UI file 'tl_login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TL_LOGIN_H
#define UI_TL_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tl_login
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txt_username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *txt_senha;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_entrar;
    QPushButton *btn_cancelar;

    void setupUi(QDialog *tl_login)
    {
        if (tl_login->objectName().isEmpty())
            tl_login->setObjectName("tl_login");
        tl_login->resize(400, 300);
        layoutWidget = new QWidget(tl_login);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 381, 271));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        txt_username = new QLineEdit(layoutWidget);
        txt_username->setObjectName("txt_username");

        horizontalLayout->addWidget(txt_username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        txt_senha = new QLineEdit(layoutWidget);
        txt_senha->setObjectName("txt_senha");
        txt_senha->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_2->addWidget(txt_senha);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btn_entrar = new QPushButton(layoutWidget);
        btn_entrar->setObjectName("btn_entrar");
        btn_entrar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_3->addWidget(btn_entrar);

        btn_cancelar = new QPushButton(layoutWidget);
        btn_cancelar->setObjectName("btn_cancelar");
        btn_cancelar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_3->addWidget(btn_cancelar);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(tl_login);

        QMetaObject::connectSlotsByName(tl_login);
    } // setupUi

    void retranslateUi(QDialog *tl_login)
    {
        tl_login->setWindowTitle(QCoreApplication::translate("tl_login", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("tl_login", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("tl_login", "Senha:", nullptr));
        btn_entrar->setText(QCoreApplication::translate("tl_login", "Entrar", nullptr));
        btn_cancelar->setText(QCoreApplication::translate("tl_login", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tl_login: public Ui_tl_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TL_LOGIN_H
