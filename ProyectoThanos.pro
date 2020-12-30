QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arbol.cpp \
    archivo.cpp \
    eliminarhumanos.cpp \
    listadeportes.cpp \
    listadoble.cpp \
    listapecvir.cpp \
    listasimple.cpp \
    main.cpp \
    mainwindow.cpp \
    persona.cpp \
    personatest.cpp \
    randomize.cpp

HEADERS += \
    arbol.h \
    archivo.h \
    eliminarhumanos.h \
    listadeportes.h \
    listadoble.h \
    listapecvir.h \
    listasimple.h \
    mainwindow.h \
    persona.h \
    personatest.h \
    randomize.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
