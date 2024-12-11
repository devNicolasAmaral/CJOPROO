#include "tl_principal.h"
#include "ui_tl_principal.h"
#include "tl_login.h"
#include "tl_gestao_estoque.h"

int Tl_principal::id_colab;
QString Tl_principal::nome_colab;
QString Tl_principal::acesso_colab;
QString Tl_principal::username_colab;
bool Tl_principal::logado;


Tl_principal::Tl_principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tl_principal)
{
    ui->setupUi(this);

    logado = false;

    cadFechado.addFile(":/Imagens/img/cadeado-fechado.png");
    cadAberto.addFile(":/Imagens/img/cadeado-aberto.png");

    ui->btn_bloquear->setText("");
    ui->btn_bloquear->setIcon(cadFechado);
    ui->statusbar->addWidget(ui->btn_bloquear);
        ui->statusbar->addWidget(ui->lb_nome);


}

Tl_principal::~Tl_principal()
{
    delete ui;
}

void Tl_principal::on_btn_bloquear_clicked()
{
    if(!logado){
        tl_login login;
        login.exec();

        if(logado){
            ui->btn_bloquear->setIcon(cadAberto);
            ui->lb_nome->setText(nome_colab);
        }
    }else{
        logado = false;
        ui->btn_bloquear->setIcon(cadFechado);
        ui->lb_nome->setText("Nenhum Colaborador Conectado.");

    }
}


void Tl_principal::on_pushButton_clicked()
{
    if(logado){
        if(acesso_colab == "A"){
            tl_gestao_estoque gestaoEstoque;
            gestaoEstoque.exec();
        }else{
            QMessageBox::warning(this, "Erro - Acesso", "Acesso não permitido.");
        }
    }else{
        QMessageBox::information(this, "Erro - Login", "Para acessar a gestão é necessário realizar o login!\n(Clique no cadeado)");
    }
}


void Tl_principal::on_actionEstoque_triggered()
{
    if(logado){
        if(acesso_colab == "A"){
            tl_gestao_estoque gestaoEstoque;
            gestaoEstoque.exec();
        }else{
            QMessageBox::warning(this, "Erro - Acesso", "Acesso não permitido.");
        }
    }else{
        QMessageBox::information(this, "Erro - Login", "Para acessar a gestão é necessário realizar o login!\n(Clique no cadeado)");
    }
}



void Tl_principal::on_actionSair_triggered()
{
    QApplication::quit();
}


void Tl_principal::on_actionSobre_2_triggered()
{
    QMessageBox::information(this, "Informações sobre o sistena", "Sistema criado por Nicolas Anaral.\nEsse sistema foi desenvolvido como projeto da matéria de Programação Orienteda a Objetos.\nUsuários e senhas de acesso\n\nnick_amaral\n123\n\nbrn_lopes\n123");
}

