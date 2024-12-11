/********************************************************************************
** Form generated from reading UI file 'tl_gestao_estoque.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TL_GESTAO_ESTOQUE_H
#define UI_TL_GESTAO_ESTOQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tl_gestao_estoque
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_novo_produto;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *txt_codigo_produto;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *txt_descricao_produto;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *txt_qntd_estoque;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *txt_fornecedor;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLineEdit *txt_valor_compra;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLineEdit *txt_valor_venda;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_novo_produto;
    QPushButton *btn_gravar_novo_produto;
    QWidget *tab_gestao_produtos;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_7;
    QLineEdit *txt_ge_codigo_produto;
    QLabel *label_8;
    QLineEdit *txt_ge_produto;
    QLabel *label_9;
    QLineEdit *txt_ge_qntd;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_10;
    QLineEdit *txt_ge_valor_compra;
    QLabel *label_11;
    QLineEdit *txt_ge_valor_venda;
    QLabel *label_12;
    QLineEdit *txt_ge_fornecedor;
    QTableWidget *tw_ge_produtos;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_10;
    QRadioButton *rb_ge_codigo;
    QRadioButton *rb_ge_produto;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *txt_ge_filtrar;
    QPushButton *btn_ge_filtrar;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btn_ge_gravar;
    QPushButton *btn_ge_excluir;

    void setupUi(QDialog *tl_gestao_estoque)
    {
        if (tl_gestao_estoque->objectName().isEmpty())
            tl_gestao_estoque->setObjectName("tl_gestao_estoque");
        tl_gestao_estoque->resize(575, 410);
        tabWidget = new QTabWidget(tl_gestao_estoque);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 10, 561, 391));
        tabWidget->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        tab_novo_produto = new QWidget();
        tab_novo_produto->setObjectName("tab_novo_produto");
        layoutWidget = new QWidget(tab_novo_produto);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 20, 321, 221));
        verticalLayout_9 = new QVBoxLayout(layoutWidget);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        txt_codigo_produto = new QLineEdit(layoutWidget);
        txt_codigo_produto->setObjectName("txt_codigo_produto");

        verticalLayout->addWidget(txt_codigo_produto);


        verticalLayout_7->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        txt_descricao_produto = new QLineEdit(layoutWidget);
        txt_descricao_produto->setObjectName("txt_descricao_produto");

        verticalLayout_2->addWidget(txt_descricao_produto);


        verticalLayout_7->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        txt_qntd_estoque = new QLineEdit(layoutWidget);
        txt_qntd_estoque->setObjectName("txt_qntd_estoque");

        verticalLayout_3->addWidget(txt_qntd_estoque);


        verticalLayout_7->addLayout(verticalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4);

        txt_fornecedor = new QLineEdit(layoutWidget);
        txt_fornecedor->setObjectName("txt_fornecedor");

        verticalLayout_4->addWidget(txt_fornecedor);


        verticalLayout_8->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout_5->addWidget(label_5);

        txt_valor_compra = new QLineEdit(layoutWidget);
        txt_valor_compra->setObjectName("txt_valor_compra");

        verticalLayout_5->addWidget(txt_valor_compra);


        verticalLayout_8->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        verticalLayout_6->addWidget(label_6);

        txt_valor_venda = new QLineEdit(layoutWidget);
        txt_valor_venda->setObjectName("txt_valor_venda");

        verticalLayout_6->addWidget(txt_valor_venda);


        verticalLayout_8->addLayout(verticalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout_8);


        verticalLayout_9->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btn_novo_produto = new QPushButton(layoutWidget);
        btn_novo_produto->setObjectName("btn_novo_produto");
        btn_novo_produto->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(btn_novo_produto);

        btn_gravar_novo_produto = new QPushButton(layoutWidget);
        btn_gravar_novo_produto->setObjectName("btn_gravar_novo_produto");
        btn_gravar_novo_produto->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(btn_gravar_novo_produto);


        verticalLayout_9->addLayout(horizontalLayout);

        tabWidget->addTab(tab_novo_produto, QString());
        tab_gestao_produtos = new QWidget();
        tab_gestao_produtos->setObjectName("tab_gestao_produtos");
        layoutWidget1 = new QWidget(tab_gestao_produtos);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 80, 551, 231));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName("label_7");

        verticalLayout_11->addWidget(label_7);

        txt_ge_codigo_produto = new QLineEdit(layoutWidget1);
        txt_ge_codigo_produto->setObjectName("txt_ge_codigo_produto");

        verticalLayout_11->addWidget(txt_ge_codigo_produto);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName("label_8");

        verticalLayout_11->addWidget(label_8);

        txt_ge_produto = new QLineEdit(layoutWidget1);
        txt_ge_produto->setObjectName("txt_ge_produto");

        verticalLayout_11->addWidget(txt_ge_produto);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName("label_9");

        verticalLayout_11->addWidget(label_9);

        txt_ge_qntd = new QLineEdit(layoutWidget1);
        txt_ge_qntd->setObjectName("txt_ge_qntd");

        verticalLayout_11->addWidget(txt_ge_qntd);


        horizontalLayout_3->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName("label_10");

        verticalLayout_12->addWidget(label_10);

        txt_ge_valor_compra = new QLineEdit(layoutWidget1);
        txt_ge_valor_compra->setObjectName("txt_ge_valor_compra");

        verticalLayout_12->addWidget(txt_ge_valor_compra);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName("label_11");

        verticalLayout_12->addWidget(label_11);

        txt_ge_valor_venda = new QLineEdit(layoutWidget1);
        txt_ge_valor_venda->setObjectName("txt_ge_valor_venda");

        verticalLayout_12->addWidget(txt_ge_valor_venda);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName("label_12");

        verticalLayout_12->addWidget(label_12);

        txt_ge_fornecedor = new QLineEdit(layoutWidget1);
        txt_ge_fornecedor->setObjectName("txt_ge_fornecedor");

        verticalLayout_12->addWidget(txt_ge_fornecedor);


        horizontalLayout_3->addLayout(verticalLayout_12);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        tw_ge_produtos = new QTableWidget(layoutWidget1);
        tw_ge_produtos->setObjectName("tw_ge_produtos");

        horizontalLayout_4->addWidget(tw_ge_produtos);

        layoutWidget2 = new QWidget(tab_gestao_produtos);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(0, 0, 551, 97));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget2);
        groupBox->setObjectName("groupBox");
        verticalLayout_14 = new QVBoxLayout(groupBox);
        verticalLayout_14->setObjectName("verticalLayout_14");
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        rb_ge_codigo = new QRadioButton(groupBox);
        rb_ge_codigo->setObjectName("rb_ge_codigo");
        rb_ge_codigo->setCursor(QCursor(Qt::CursorShape::SizeAllCursor));
        rb_ge_codigo->setChecked(true);

        verticalLayout_10->addWidget(rb_ge_codigo);

        rb_ge_produto = new QRadioButton(groupBox);
        rb_ge_produto->setObjectName("rb_ge_produto");
        rb_ge_produto->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout_10->addWidget(rb_ge_produto);


        verticalLayout_14->addLayout(verticalLayout_10);


        horizontalLayout_6->addWidget(groupBox);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName("label_13");

        verticalLayout_13->addWidget(label_13);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        txt_ge_filtrar = new QLineEdit(layoutWidget2);
        txt_ge_filtrar->setObjectName("txt_ge_filtrar");

        horizontalLayout_5->addWidget(txt_ge_filtrar);

        btn_ge_filtrar = new QPushButton(layoutWidget2);
        btn_ge_filtrar->setObjectName("btn_ge_filtrar");
        btn_ge_filtrar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_5->addWidget(btn_ge_filtrar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_13->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_13->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_13);

        layoutWidget3 = new QWidget(tab_gestao_produtos);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(380, 320, 171, 26));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        btn_ge_gravar = new QPushButton(layoutWidget3);
        btn_ge_gravar->setObjectName("btn_ge_gravar");
        btn_ge_gravar->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_7->addWidget(btn_ge_gravar);

        btn_ge_excluir = new QPushButton(layoutWidget3);
        btn_ge_excluir->setObjectName("btn_ge_excluir");
        btn_ge_excluir->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_7->addWidget(btn_ge_excluir);

        tabWidget->addTab(tab_gestao_produtos, QString());

        retranslateUi(tl_gestao_estoque);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(tl_gestao_estoque);
    } // setupUi

    void retranslateUi(QDialog *tl_gestao_estoque)
    {
        tl_gestao_estoque->setWindowTitle(QCoreApplication::translate("tl_gestao_estoque", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("tl_gestao_estoque", "C\303\263digo do Produto", nullptr));
        label_2->setText(QCoreApplication::translate("tl_gestao_estoque", "Descri\303\247\303\243o do Produto", nullptr));
        label_3->setText(QCoreApplication::translate("tl_gestao_estoque", "Quantidade em Estoque", nullptr));
        label_4->setText(QCoreApplication::translate("tl_gestao_estoque", "Fornecedor", nullptr));
        label_5->setText(QCoreApplication::translate("tl_gestao_estoque", "Valor de Compra", nullptr));
        label_6->setText(QCoreApplication::translate("tl_gestao_estoque", "Valor de Venda", nullptr));
        btn_novo_produto->setText(QCoreApplication::translate("tl_gestao_estoque", "Limpar", nullptr));
        btn_gravar_novo_produto->setText(QCoreApplication::translate("tl_gestao_estoque", "Gravar Novo Produto", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_novo_produto), QCoreApplication::translate("tl_gestao_estoque", "Novo Produto", nullptr));
        label_7->setText(QCoreApplication::translate("tl_gestao_estoque", "C\303\263digo do Produto", nullptr));
        label_8->setText(QCoreApplication::translate("tl_gestao_estoque", "Produto", nullptr));
        label_9->setText(QCoreApplication::translate("tl_gestao_estoque", "Quantidade em Estoque", nullptr));
        label_10->setText(QCoreApplication::translate("tl_gestao_estoque", "Valor de Compra", nullptr));
        label_11->setText(QCoreApplication::translate("tl_gestao_estoque", "Valor de Venda", nullptr));
        label_12->setText(QCoreApplication::translate("tl_gestao_estoque", "Fornecedor", nullptr));
        groupBox->setTitle(QCoreApplication::translate("tl_gestao_estoque", "Filtrar Por:", nullptr));
        rb_ge_codigo->setText(QCoreApplication::translate("tl_gestao_estoque", "C\303\263digo do Produto", nullptr));
        rb_ge_produto->setText(QCoreApplication::translate("tl_gestao_estoque", "Descri\303\247\303\243o do Produto", nullptr));
        label_13->setText(QCoreApplication::translate("tl_gestao_estoque", "Filtrar", nullptr));
        btn_ge_filtrar->setText(QCoreApplication::translate("tl_gestao_estoque", "FIltrar", nullptr));
        btn_ge_gravar->setText(QCoreApplication::translate("tl_gestao_estoque", "Gravar", nullptr));
        btn_ge_excluir->setText(QCoreApplication::translate("tl_gestao_estoque", "Excluir", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_gestao_produtos), QCoreApplication::translate("tl_gestao_estoque", "Gest\303\243o dos Produtos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tl_gestao_estoque: public Ui_tl_gestao_estoque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TL_GESTAO_ESTOQUE_H
