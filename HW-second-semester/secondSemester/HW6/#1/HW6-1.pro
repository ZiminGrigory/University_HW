TEMPLATE = app
CONFIG += console qtestlib
CONFIG += qt


SOURCES += main.cpp \
    parsetree.cpp \
    node.cpp \
    operator.cpp \
    operand.cpp

HEADERS += \
    testTask.h \
    parsetree.h \
    node.h \
    operator.h \
    operand.h
