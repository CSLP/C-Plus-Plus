#-------------------------------------------------
#
# Project created by QtCreator 2019-05-11T09:26:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mymainwindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myaction.cpp

HEADERS  += mainwindow.h \
    myaction.h

FORMS    += mainwindow.ui

RESOURCES += \
    myimages.qrc
