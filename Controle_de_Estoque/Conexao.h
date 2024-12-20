#ifndef CONEXAO_H
#define CONEXAO_H
#include <QtSql>

class Conexao{
public:
    QSqlDatabase bancoDeDados;
    QString local, banco;
    Conexao(){
        local = qApp->applicationDirPath();
        banco = local + "/db/Controle_de_Estoque.db";
        bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");
    }

    void Fechar(){
        bancoDeDados.close();
    }

    bool Abrir(){

        bancoDeDados.setDatabaseName(banco);

        if(!bancoDeDados.open()){
            return false;
        }else{
            return true;
        }
    }
    bool Aberto(){
        if(!bancoDeDados.isOpen()){
            return true;
        }else{
            return false;
        }
    }
};

#endif // CONEXAO_H
