#-------------------------------------------------
#
# Project created by QtCreator 2015-11-26T19:19:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RayCaster
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Camera.cpp \
    Cor.cpp \
    Janela.cpp \
    Material.cpp \
    Matriz.cpp \
    Vetor.cpp

HEADERS  += mainwindow.h \
    Aresta.h \
    Camera.h \
    Cor.h \
    Face.h \
    Janela.h \
    Material.h \
    Matriz.h \
    Vetor.h

FORMS    += mainwindow.ui
