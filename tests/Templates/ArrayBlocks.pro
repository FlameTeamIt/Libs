include(../../global.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ArrayBlocks.cpp

INCLUDEPATH += ../../src

QMAKE_CXXFLAGS += -std=c++14

HEADERS += \
    ../Test.h \
    ArrayBlocks.h \
    ../../src/Templates/ArrayBlocks_Iterators.h \
    ../../src/Templates/ArrayBlocks.h

