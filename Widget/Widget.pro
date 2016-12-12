#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T11:32:29
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Widget
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    appservice.cpp \
    comps.cpp \
    compservice.cpp \
    database.cpp \
    links.cpp \
    linkservice.cpp \
    person.cpp \
    tictactoe.cpp \
    unicorn.cpp \
    displaylist.cpp

HEADERS  += mainwindow.h \
    appservice.h \
    comps.h \
    compservice.h \
    database.h \
    linkservice.h \
    unicorn.h \
    tictactoe.h \
    person.h \
    links.h \
    displaylist.h

FORMS    += mainwindow.ui \
    displaylist.ui
