/********************************************************************************
** Form generated from reading UI file 'tl_gestao_vendas.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TL_GESTAO_VENDAS_H
#define UI_TL_GESTAO_VENDAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_tl_gestao_vendas
{
public:

    void setupUi(QDialog *tl_gestao_vendas)
    {
        if (tl_gestao_vendas->objectName().isEmpty())
            tl_gestao_vendas->setObjectName("tl_gestao_vendas");
        tl_gestao_vendas->resize(400, 300);

        retranslateUi(tl_gestao_vendas);

        QMetaObject::connectSlotsByName(tl_gestao_vendas);
    } // setupUi

    void retranslateUi(QDialog *tl_gestao_vendas)
    {
        tl_gestao_vendas->setWindowTitle(QCoreApplication::translate("tl_gestao_vendas", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tl_gestao_vendas: public Ui_tl_gestao_vendas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TL_GESTAO_VENDAS_H
