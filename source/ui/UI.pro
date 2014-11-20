#-------------------------------------------------
#
# Project created by QtCreator 2014-11-19T18:19:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    htmlgenerater.cpp

HEADERS  += mainwindow.h \
    htmlgenerater.h

FORMS    += mainwindow.ui

DEFINES += PROJECT_PATH=\"\\\"$$PWD\\\"\"
DEFINES += BUILD_PATH=\"\\\"$$OUT_PWD\\\"\"
