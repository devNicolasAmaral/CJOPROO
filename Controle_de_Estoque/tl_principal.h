#ifndef TL_PRINCIPAL_H
#define TL_PRINCIPAL_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Tl_principal;
}
QT_END_NAMESPACE

class Tl_principal : public QMainWindow
{
    Q_OBJECT

public:
    Tl_principal(QWidget *parent = nullptr);
    ~Tl_principal();

    QIcon cadFechado;
    QIcon cadAberto;
    static bool logado;
    static QString nome_colab, acesso_colab, username_colab;
    static int id_colab;



private slots:
    void on_btn_bloquear_clicked();

    void on_pushButton_clicked();

    void on_actionEstoque_triggered();

    void on_actionSair_triggered();

    void on_actionSobre_2_triggered();

private:
    Ui::Tl_principal *ui;
};
#endif // TL_PRINCIPAL_H
