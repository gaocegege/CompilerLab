#-------------------------------------------------
#
# Project created by QtCreator 2014-11-19T18:19:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
TEMPLATE = app
CONFIG += c++11

INCLUDEPATH += /opt/local/include/
QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++ -Wall -Wextra -pedantic -O1

SOURCES += main.cpp\
        mainwindow.cpp \
    htmlgenerater.cpp

HEADERS  += mainwindow.h \
    htmlgenerater.h \
    ../mylang.hpp \
    ../mylang_syntax.hpp \
    ../parser/lib/ccc.hpp \
    ../parser/myparser_ast.hpp \
    ../parser/myparser_common.hpp \
    ../parser/myparser_pass.hpp \
    ../parser/myparser_pass_filter.hpp \
    ../parser/myparser_pass_repr.hpp \
    ../parser/myparser_rule.hpp \
    ../parser/myparser_str.hpp

FORMS    += mainwindow.ui

DEFINES += PROJECT_PATH=\"\\\"$$PWD\\\"\"
DEFINES += BUILD_PATH=\"\\\"$$OUT_PWD\\\"\"
