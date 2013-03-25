#-------------------------------------------------
#
# Project created by QtCreator 2013-03-24T12:23:31
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += webkitwidgets
lessThan(QT_MAJOR_VERSION, 5): QT += webkit

TEMPLATE = app

# Different folders for debug/release
CONFIG(debug, debug|release) { 
    TARGET = ../bin/Goliath-debug
    OBJECTS_DIR = ../build/debug/objects
    MOC_DIR = ../build/debug/moc
    UI_DIR = ../build/debug/ui
}
CONFIG(release, debug|release) { 
    TARGET = ../bin/Goliath
    OBJECTS_DIR = ../build/release/objects
    MOC_DIR = ../build/release/moc
    UI_DIR = ../build/release/ui
}

SOURCES += main.cpp\
        browserwindow.cpp \
    server.cpp

HEADERS  += browserwindow.h \
    server.h

FORMS    += browserwindow.ui

