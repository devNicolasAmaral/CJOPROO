#include "tl_principal.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QPalette>
#include <QStyleFactory>
#include <QMenu>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Controle_de_Estoque_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette palette = QApplication::palette();
    palette.setColor(QPalette::Window, QColor(255, 255, 255));       // Fundo branco
    palette.setColor(QPalette::WindowText, QColor(0, 0, 0));         // Texto preto
    palette.setColor(QPalette::Button, QColor(240, 240, 240));       // Botões claros
    palette.setColor(QPalette::ButtonText, QColor(0, 0, 0));         // Texto de botão preto
    palette.setColor(QPalette::Base, QColor(255, 255, 255));         // Fundo do menu branco
    palette.setColor(QPalette::Text, QColor(0, 0, 0));               // Texto do menu preto
    palette.setColor(QPalette::Highlight, QColor(200, 200, 200));    // Cor de seleção no menu
    palette.setColor(QPalette::HighlightedText, QColor(0, 0, 0));    // Texto destacado no menu
    a.setPalette(palette);

    // Adicionando estilo adicional ao menu para bordas claras
    a.setStyleSheet(
        "QMenu {"
        "    background-color: white;"
        "    border: 1px solid lightgray;"
        "}"
        "QMenu::item {"
        "    padding: 5px 20px;"
        "    background-color: transparent;"
        "    color: black;"
        "}"
        "QMenu::item:selected {"
        "    background-color: lightgray;"
        "    color: black;"
        "}"
        );

    Tl_principal w;
    w.show();
    return a.exec();
}
