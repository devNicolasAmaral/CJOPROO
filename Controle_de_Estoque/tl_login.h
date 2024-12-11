#ifndef TL_LOGIN_H
#define TL_LOGIN_H

#include <QDialog>
#include "Conexao.h"

namespace Ui {
class tl_login;
}

class tl_login : public QDialog
{
    Q_OBJECT

public:
    explicit tl_login(QWidget *parent = nullptr);
    ~tl_login();
    bool logado;
    Conexao con;
    QString nome, acesso;
    int id;

private slots:
    void on_btn_entrar_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::tl_login *ui;
};

#endif // TL_LOGIN_H
