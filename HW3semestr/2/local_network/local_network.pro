#-------------------------------------------------
#
# Project created by QtCreator 2013-09-13T23:45:37
#
#-------------------------------------------------

QT       += core gui testlib

QT += widgets

TARGET = local_network
TEMPLATE = app


SOURCES += main.cpp\
    Switch.cpp \
    OperatingSystem.cpp \
    Mac_OS.cpp \
    Linux.cpp \
    Windows.cpp \
    DialogForm.cpp \
    Server.cpp \
    PC.cpp \
    Package.cpp \
    Virus.cpp \
    Starter.cpp \
	Random.cpp \
    PseudoRandom.cpp

HEADERS  += \
    Switch.h \
    OperatingSystem.h \
    Mac_OS.h \
    Linux.h \
    Windows.h \
    DialogForm.h \
    Server.h \
    PC.h \
    mConst.h \
    Package.h \
    Virus.h \
    Starter.h \
    tests/OSTest.h \
    tests/PCTest.h \
    tests/StarterTest.h \
    tests/SwitchTest.h \
    Random.h \
    PseudoRandom.h \
    tests/InfectedProcessTest.h

FORMS    += \
    DialogForm.ui

INCLUDEPATH += tests/
