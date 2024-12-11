#ifndef TL_GESTAO_ESTOQUE_H
#define TL_GESTAO_ESTOQUE_H

#include <QDialog>
#include "Conexao.h"
#include <QMessageBox>
#include <QTableWidget>

namespace Ui {
class tl_gestao_estoque;
}

class tl_gestao_estoque : public QDialog
{
    Q_OBJECT

public:
    explicit tl_gestao_estoque(QWidget *parent = nullptr);
    ~tl_gestao_estoque();
    Conexao con;
    void removerLinhas(QTableWidget *tw);



private slots:
    void on_btn_novo_produto_clicked();

    void on_btn_gravar_novo_produto_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_tw_ge_produtos_itemSelectionChanged();

    void on_btn_ge_gravar_clicked();

    void on_btn_ge_excluir_clicked();

    void on_btn_ge_filtrar_clicked();

private:
    Ui::tl_gestao_estoque *ui;
};

#endif // TL_GESTAO_ESTOQUE_H
