#include "tl_login.h"
#include "ui_tl_login.h"
#include <QMessageBox>
#include "tl_principal.h"

tl_login::tl_login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tl_login)
{
    ui->setupUi(this);
    logado = false;



}

tl_login::~tl_login()
{
    delete ui;
}

void tl_login::on_btn_entrar_clicked()
{

    if(!con.Abrir()){
        QMessageBox::warning(this, "Erro - Banco de dados", "Não foi possível se conectar ao banco de dados.");
    }else{
        QString username, senha;
        username = ui->txt_username->text().trimmed();
        senha = ui->txt_senha->text().trimmed();

        QSqlQuery query;
        query.prepare("SELECT * FROM db_colaboradores WHERE username_colab = '" + username + "' AND senha_colab =   '" + senha + "'");
        if(query.exec()){
            query.first();
            if(query.value(1).toString() != ""){
                Tl_principal::logado = true;
                Tl_principal::nome_colab = query.value(1).toString();
                Tl_principal::id_colab = query.value(0).toInt();
                Tl_principal::acesso_colab = query.value(5).toString();
                con.Fechar();
                close();
            }else{
                QMessageBox::warning(this, "Erro - Usuário/Senha", "Username ou senha não encontrados.");
            }
        }else{
            QMessageBox::warning(this, "Erro - Banco de dados", "Falha no Login");

        }
    }
    con.Fechar();
}


void tl_login::on_btn_cancelar_clicked()
{
    logado = false;
    close();
}
