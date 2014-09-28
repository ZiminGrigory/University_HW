#-------------------------------------------------
#
# Project created by QtCreator 2013-09-20T20:03:02
#
#-------------------------------------------------

QT       += core testlib

QT       -= gui

TARGET = robots
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    FileParser.cpp \
    MatrixAnalyzer.cpp \
    AnswerAnalyzer.cpp

HEADERS += \
    FileParser.h \
    MatrixAnalyzer.h \
    AnswerAnalyzer.h \
    tests/ProgramTest.h

INCLUDEPATH += tests/
