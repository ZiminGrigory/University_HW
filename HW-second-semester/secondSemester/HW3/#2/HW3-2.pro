TEMPLATE = app
CONFIG += console qtestlib
CONFIG += qt

SOURCES += main.cpp \
    printInFile.cpp \
    printInConsole.cpp \
    toOneDimensional.cpp

HEADERS += \
    print.h \
    printInFile.h \
    printInConsole.h \
    toOneDimensional.h \
    testToOneDimension.h

