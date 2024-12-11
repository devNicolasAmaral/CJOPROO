/********************************************************************************
** Form generated from reading UI file 'tl_nova_venda.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TL_NOVA_VENDA_H
#define UI_TL_NOVA_VENDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_tl_nova_venda
{
public:

    void setupUi(QDialog *tl_nova_venda)
    {
        if (tl_nova_venda->objectName().isEmpty())
            tl_nova_venda->setObjectName("tl_nova_venda");
        tl_nova_venda->resize(400, 300);

        retranslateUi(tl_nova_venda);

        QMetaObject::connectSlotsByName(tl_nova_venda);
    } // setupUi

    void retranslateUi(QDialog *tl_nova_venda)
    {
        tl_nova_venda->setWindowTitle(QCoreApplication::translate("tl_nova_venda", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tl_nova_venda: public Ui_tl_nova_venda {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TL_NOVA_VENDA_H
