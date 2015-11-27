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
    Vetor.cpp \
    RayCaster.cpp \
    Raio.cpp \
    ponto.cpp \
    Matrix.cpp

HEADERS  += mainwindow.h \
    Camera.h \
    Face.h \
    Janela.h \
    Material.h \
    Matriz.h \
    RayCaster.h \
    Raio.h \
    ponto.h \
    Vector.h \
    Edge.h \
    Color.h

FORMS    += mainwindow.ui
