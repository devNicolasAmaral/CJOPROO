/********************************************************************************
** Form generated from reading UI file 'tl_gestao_colaboradores.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TL_GESTAO_COLABORADORES_H
#define UI_TL_GESTAO_COLABORADORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_tl_gestao_colaboradores
{
public:

    void setupUi(QDialog *tl_gestao_colaboradores)
    {
        if (tl_gestao_colaboradores->objectName().isEmpty())
            tl_gestao_colaboradores->setObjectName("tl_gestao_colaboradores");
        tl_gestao_colaboradores->resize(400, 300);

        retranslateUi(tl_gestao_colaboradores);

        QMetaObject::connectSlotsByName(tl_gestao_colaboradores);
    } // setupUi

    void retranslateUi(QDialog *tl_gestao_colaboradores)
    {
        tl_gestao_colaboradores->setWindowTitle(QCoreApplication::translate("tl_gestao_colaboradores", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tl_gestao_colaboradores: public Ui_tl_gestao_colaboradores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TL_GESTAO_COLABORADORES_H
