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
    Material.cpp \
    RayCaster.cpp \
    Matrix.cpp \
    Point.cpp \
    Ray.cpp \
    Vector.cpp \
    Color.cpp \
    Window.cpp

HEADERS  += mainwindow.h \
    Camera.h \
    Face.h \
    Material.h \
    RayCaster.h \
    Vector.h \
    Edge.h \
    Color.h \
    Ray.h \
    Point.h \
    Window.h \
    Matrix.h

FORMS    += mainwindow.ui
