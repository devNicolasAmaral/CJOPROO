QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    tl_gestao_estoque.cpp \
    tl_login.cpp \
    tl_principal.cpp

HEADERS += \
    Conexao.h \
    tl_gestao_estoque.h \
    tl_login.h \
    tl_principal.h

FORMS += \
    tl_gestao_estoque.ui \
    tl_login.ui \
    tl_principal.ui

TRANSLATIONS += \
    Controle_de_Estoque_pt_BR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Arquivo_de_Recursos.qrc
