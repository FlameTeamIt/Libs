include(global.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Templates_ArrayBlocks.cpp

INCLUDEPATH += ../../src

QMAKE_CXXFLAGS += -std=c++14
