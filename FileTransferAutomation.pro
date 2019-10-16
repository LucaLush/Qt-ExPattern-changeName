#-------------------------------------------------
#
# Project created by QtCreator 2019-09-27T22:05:21
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileTransferAutomation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dragwidget.cpp

HEADERS  += mainwindow.h \
    dragwidget.h

FORMS    += mainwindow.ui \
    dragwidget.ui
