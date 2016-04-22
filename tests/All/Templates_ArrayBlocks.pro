include(global.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Templates_ArrayBlocks.cpp

INCLUDEPATH += ../../src

QMAKE_CXXFLAGS += -std=c++14

HEADERS += \
    ../Test.h \
    Templates_ArrayBlocks.h

