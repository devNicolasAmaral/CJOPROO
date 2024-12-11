#include "tl_gestao_estoque.h"
#include "ui_tl_gestao_estoque.h"
#include <QtSql>
#include <QDebug>

tl_gestao_estoque::tl_gestao_estoque(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tl_gestao_estoque)
{
    ui->setupUi(this);
    if(!con.Abrir()){
        QMessageBox::warning(this, "Erro - Banco de dados", "Não foi possível abrir o banco de dados.");
    }else{
        QSqlQuery query;
        query.prepare("SELECT * FROM db_produtos");
        if(!query.exec()){
            QMessageBox::warning(this, "Erro - Banco de dados", "Não foi possível listar os produtos gravados.");
        }
    }
    ui->tw_ge_produtos->setColumnCount(2);
    ui->tabWidget->setCurrentIndex(0);
}

tl_gestao_estoque::~tl_gestao_estoque()
{
    delete ui;
    con.Fechar();
}

void tl_gestao_estoque::on_btn_novo_produto_clicked()
{
    ui->txt_codigo_produto->clear();
    ui->txt_descricao_produto->clear();
    ui->txt_fornecedor->clear();
    ui->txt_qntd_estoque->clear();
    ui->txt_valor_compra->clear();
    ui->txt_valor_venda->clear();
    ui->txt_codigo_produto->setFocus();

}

void tl_gestao_estoque::on_btn_gravar_novo_produto_clicked()
{
    QString aux;
    QString codigo = ui->txt_codigo_produto->text();
    QString produto = ui->txt_descricao_produto->text();
    QString fornecedor = ui->txt_fornecedor->text();
    QString quantidade = ui->txt_qntd_estoque->text();

    aux = ui->txt_valor_compra->text();
    std::replace(aux.begin(), aux.end(), ',', '.');
    QString valCompra = aux;

    aux = ui->txt_valor_venda->text();
    std::replace(aux.begin(), aux.end(), ',', '.');
    QString valVenda = aux;

    QSqlQuery query;
    query.prepare("INSERT INTO db_produtos (id_produto, produto, id_fornecedor, qntd_estoque, valor_compra, valor_venda)"
                  "values("+ QString::number(codigo.toInt()) + ", '"+ produto +"', "+ QString::number(fornecedor.toInt()) +", "+ QString::number(quantidade.toInt()) +", "+ QString::number(valCompra.toFloat()) +", "+ QString::number(valVenda.toFloat()) +")");
    if(!query.exec()){
        QMessageBox::warning(this, "Erro - Banco de dados", "Não foi possível inserir o produto.");

    }else{
        QMessageBox::information(this, "Sucesso - Inserção de Produto", "O produto foi gravado com sucesso no banco de dados!");
        ui->txt_codigo_produto->clear();
        ui->txt_descricao_produto->clear();
        ui->txt_fornecedor->clear();
        ui->txt_qntd_estoque->clear();
        ui->txt_valor_compra->clear();
        ui->txt_valor_venda->clear();
        ui->txt_codigo_produto->setFocus();
    }
}


void tl_gestao_estoque::on_tabWidget_currentChanged(int index)
{
    if(index == 1){
        removerLinhas(ui->tw_ge_produtos);
        int countLinhas = 0;
        QSqlQuery query;
        query.prepare("SELECT id_produto, produto FROM db_produtos ORDER BY produto");
        if(!query.exec()){
            QMessageBox::warning(this, "Erro - Banco de dados", "Não foi possível listar os produtos.");
        }else{
            while(query.next()){
                ui->tw_ge_produtos->insertRow(countLinhas);
                ui->tw_ge_produtos->setItem(countLinhas, 0, new QTableWidgetItem(query.value(0).toString()));
                ui->tw_ge_produtos->setItem(countLinhas, 1, new QTableWidgetItem(query.value(1).toString()));
                ui->tw_ge_produtos->setRowHeight(countLinhas, 20);
                countLinhas++;
            }
            ui->tw_ge_produtos->setColumnWidth(0, 150);
            ui->tw_ge_produtos->setColumnWidth(1, 230);
            QStringList cabecalhos = {"Código", "Produto"};
            ui->tw_ge_produtos->setHorizontalHeaderLabels(cabecalhos);
            ui->tw_ge_produtos->setStyleSheet("QTableView {selection-background-color: red}");
            ui->tw_ge_produtos->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tw_ge_produtos->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tw_ge_produtos->verticalHeader()->setVisible(false);
        }
    }
}

void tl_gestao_estoque::removerLinhas(QTableWidget *tw){
    while(tw->rowCount() > 0){
        tw->removeRow(0);
    }
}


void tl_gestao_estoque::on_tw_ge_produtos_itemSelectionChanged()
{
    int id = ui->tw_ge_produtos->item(ui->tw_ge_produtos->currentRow(), 0)->text().toInt();
    QSqlQuery query;
    query.prepare("SELECT * FROM db_produtos WHERE id_produto = " + QString::number(id));
    if(query.exec()){
        query.first();
        ui->txt_ge_codigo_produto->setText(query.value(0).toString());
        ui->txt_ge_produto->setText(query.value(1).toString());
        ui->txt_ge_qntd->setText(query.value(3).toString());
        ui->txt_ge_valor_compra->setText(query.value(4).toString());
        ui->txt_ge_valor_venda->setText(query.value(5).toString());
        ui->txt_ge_fornecedor->setText(query.value(2).toString());
    }
}


void tl_gestao_estoque::on_btn_ge_gravar_clicked()
{
    {
        int id = ui->tw_ge_produtos->item(ui->tw_ge_produtos->currentRow(), 0)->text().toInt();
        QString aux;
        QString prod = ui->txt_ge_produto->text();
        QString forn = ui->txt_ge_fornecedor->text();
        QString qntd = ui->txt_ge_qntd->text();

        aux = ui->txt_valor_compra->text();
        aux.replace(',', '.');
        QString valCompra = aux;

        aux = ui->txt_valor_venda->text();
        aux.replace(',', '.');
        QString valVenda = aux;

        QSqlQuery query;
        query.prepare("UPDATE db_produtos SET id_produto =" + QString::number(id) + ", produto = '" + prod + "', id_fornecedor = " + QString::number(forn.toInt()) + ", qntd_estoque = " + QString::number(qntd.toInt()) + ", valor_compra = " + QString::number(valCompra.toInt()) + ", valor_venda = " + QString::number(valVenda.toInt()) + " WHERE id_produto = " + QString::number(id));

        if(query.exec()){
            int linha = ui->tw_ge_produtos->currentRow();
            ui->tw_ge_produtos->item(linha, 0)->setText(ui->txt_ge_codigo_produto->text());
            ui->tw_ge_produtos->item(linha, 1)->setText(prod);
            QMessageBox::information(this, "Sucesso - Atualização", "Produto atualizado com sucesso.");
        }else{
            QMessageBox::warning(this, "Erro - Atualização", "Não foi possível atualizar o produto.");
        }
    }
}

void tl_gestao_estoque::on_btn_ge_excluir_clicked()
{
    if(ui->txt_ge_codigo_produto->text() == ""){
        QMessageBox::warning(this, "Erro - Seleção", "Nenhum registro ativo.");
    }else{
        QMessageBox::StandardButton opc = QMessageBox::question(this, "Confirmar Exclusão", "O produto será excluído permanentemente. Deseja continuar?", QMessageBox::Yes|QMessageBox::No);
        if(opc == QMessageBox::Yes){
            int linha = ui->tw_ge_produtos->currentRow();
            int id = ui->tw_ge_produtos->item(linha, 0)->text().toInt();
            QSqlQuery query;
            query.prepare("DELETE FROM db_produtos WHERE id_produto =" + QString::number(id));
            if(query.exec()){
                ui->tw_ge_produtos->removeRow(linha);
                QMessageBox::information(this, "Item Excluído", "Produto excluído com sucesso!");
            }else{
                QMessageBox::warning(this, "Erro - Banco de Dados", "Não foi possível excluir esse produto.");

            }
        }
    }
}


void tl_gestao_estoque::on_btn_ge_filtrar_clicked()
{
    QString busca;
    removerLinhas(ui->tw_ge_produtos);
    if(ui->txt_ge_filtrar->text() == ""){
        if(ui->rb_ge_codigo->isChecked()){
            busca = "SELECT id_produto, produto FROM db_produtos ORDER BY id_produto ";
        }else{
            busca = "SELECT id_produto, produto FROM db_produtos ORDER BY produto";
        }
    }else{
        if(ui->rb_ge_codigo->isChecked()){
            busca = "SELECT id_produto, produto FROM db_produtos WHERE id_produto = " + ui->txt_ge_filtrar->text() + " ORDER BY id_produto";
        }else{
            busca = "SELECT id_produto, produto FROM db_produtos WHERE produto LIKE  '%" + ui->txt_ge_filtrar->text() + "%' ORDER BY produto";
        }
    }
    int countLinhas = 0;
    QSqlQuery query;
    query.prepare(busca);
    if(query.exec()){
        while(query.next()){
            ui->tw_ge_produtos->insertRow(countLinhas);
            ui->tw_ge_produtos->setItem(countLinhas, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tw_ge_produtos->setItem(countLinhas, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tw_ge_produtos->setRowHeight(countLinhas, 20);
            countLinhas++;
        }
    }else{
        QMessageBox::warning(this, "Erro - Banco de Dados", "Não foi possível filtrar nenhum produto.");
    }
    ui->txt_ge_filtrar->clear();
    ui->txt_ge_filtrar->setFocus();
}

