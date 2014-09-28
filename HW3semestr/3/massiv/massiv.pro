#-------------------------------------------------
#
# Project created by QtCreator 2013-09-21T08:35:42
#
#-------------------------------------------------

QT       += core testlib

QT       -= gui

TARGET = massiv
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    MassivAnalyzer.cpp \
    FileParser.cpp

HEADERS += \
    FileParser.h \
    MassivAnalyzer.h \
    tests/ProgramTest.h

INCLUDEPATH += tests/
