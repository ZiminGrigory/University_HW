TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    AdrBook.cpp \
    holydays.cpp \
    tests.cpp

HEADERS += \
    AdrBook.h \
    mTime.h \
    holydays.h
