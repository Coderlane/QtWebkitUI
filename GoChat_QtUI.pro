#-------------------------------------------------
#
# Project created by QtCreator 2013-03-24T12:23:31
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += webkitwidgets
lessThan(QT_MAJOR_VERSION, 5): QT += webkit

TARGET = GoChat_QtUI
TEMPLATE = app


SOURCES += main.cpp\
        browserwindow.cpp \
    server.cpp

HEADERS  += browserwindow.h \
    server.h

FORMS    += browserwindow.ui
