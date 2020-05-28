#-------------------------------------------------
#
# Project created by QtCreator 2020-04-16T13:42:38
#
#-------------------------------------------------

QT       += core gui sql
QT += network
QT +=charts
QT +=printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    personnel.cpp \
    conge.cpp \
    departement.cpp \
    connexion.cpp \
    s.cpp \
    prog.cpp \
    bonf.cpp \
    boni.cpp \
    equipement.cpp \
    f.cpp \
    dialog.cpp \
    login.cpp \
    statistique5.cpp \
    statistique4.cpp \
    maintenance.cpp \
    menus.cpp \
    nomen.cpp \
    produit.cpp \
    statistique.cpp \
    statistique3.cpp \
    vendre.cpp \
    statistique1.cpp \
    fourn.cpp \
    statistique2.cpp

HEADERS += \
    personnel.h \
    conge.h \
    departement.h \
    connexion.h \
    s.h \
    prog.h \
    bonf.h \
    boni.h \
    equipement.h \
    f.h \
    dialog.h \
    login.h \
    statistique5.h \
    statistique4.h \
    maintenance.h \
    menus.h \
    nomen.h \
    produit.h \
    statistique.h \
    statistique1.h \
    statistique3.h \
    vendre.h \
    fourn.h \
    statistique2.h

FORMS += \
    s.ui \
    statistique.ui \
    prog.ui \
    f.ui \
    dialog.ui \
    statistique4.ui \
    menus.ui \
    statistique1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
