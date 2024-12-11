/********************************************************************************
** Form generated from reading UI file 'tl_principal.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TL_PRINCIPAL_H
#define UI_TL_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tl_principal
{
public:
    QAction *actionEstoque;
    QAction *actionSair;
    QAction *actionSobre_2;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_bloquear;
    QLabel *lb_nome;
    QMenuBar *menubar;
    QMenu *menuGest_o;
    QMenu *menuSistema;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Tl_principal)
    {
        if (Tl_principal->objectName().isEmpty())
            Tl_principal->setObjectName("Tl_principal");
        Tl_principal->resize(457, 372);
        actionEstoque = new QAction(Tl_principal);
        actionEstoque->setObjectName("actionEstoque");
        actionSair = new QAction(Tl_principal);
        actionSair->setObjectName("actionSair");
        actionSobre_2 = new QAction(Tl_principal);
        actionSobre_2->setObjectName("actionSobre_2");
        centralwidget = new QWidget(Tl_principal);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 150, 181, 41));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background: #248;\n"
"color: #fff;\n"
"font-size: 12pt;\n"
"border: none;\n"
"border-radius: 6px;"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 20, 291, 41));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: black;"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 300, 265, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_bloquear = new QPushButton(widget);
        btn_bloquear->setObjectName("btn_bloquear");
        btn_bloquear->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn_bloquear->setFlat(true);

        horizontalLayout->addWidget(btn_bloquear);

        lb_nome = new QLabel(widget);
        lb_nome->setObjectName("lb_nome");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_nome->sizePolicy().hasHeightForWidth());
        lb_nome->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lb_nome);

        Tl_principal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Tl_principal);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 457, 21));
        menuGest_o = new QMenu(menubar);
        menuGest_o->setObjectName("menuGest_o");
        menuSistema = new QMenu(menubar);
        menuSistema->setObjectName("menuSistema");
        Tl_principal->setMenuBar(menubar);
        statusbar = new QStatusBar(Tl_principal);
        statusbar->setObjectName("statusbar");
        Tl_principal->setStatusBar(statusbar);

        menubar->addAction(menuGest_o->menuAction());
        menubar->addAction(menuSistema->menuAction());
        menuGest_o->addSeparator();
        menuGest_o->addSeparator();
        menuGest_o->addAction(actionEstoque);
        menuSistema->addAction(actionSair);
        menuSistema->addAction(actionSobre_2);

        retranslateUi(Tl_principal);

        QMetaObject::connectSlotsByName(Tl_principal);
    } // setupUi

    void retranslateUi(QMainWindow *Tl_principal)
    {
        Tl_principal->setWindowTitle(QCoreApplication::translate("Tl_principal", "Tl_principal", nullptr));
        actionEstoque->setText(QCoreApplication::translate("Tl_principal", "Estoque", nullptr));
        actionSair->setText(QCoreApplication::translate("Tl_principal", "Sair", nullptr));
        actionSobre_2->setText(QCoreApplication::translate("Tl_principal", "Sobre", nullptr));
        pushButton->setText(QCoreApplication::translate("Tl_principal", "Gerenciar Estoque", nullptr));
        label->setText(QCoreApplication::translate("Tl_principal", "Sistema de Gest\303\243o de Produtos", nullptr));
        btn_bloquear->setText(QCoreApplication::translate("Tl_principal", "Cadeado", nullptr));
        lb_nome->setText(QCoreApplication::translate("Tl_principal", "Nenhum Colaborador Conectado", nullptr));
        menuGest_o->setTitle(QCoreApplication::translate("Tl_principal", "Gest\303\243o", nullptr));
        menuSistema->setTitle(QCoreApplication::translate("Tl_principal", "Sistema", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tl_principal: public Ui_Tl_principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TL_PRINCIPAL_H
