#-------------------------------------------------
#
# Project created by QtCreator 2016-04-01T04:57:01
#
#-------------------------------------------------
include(../global.pri)

QT       -= core

TARGET = FlameIDELib
TEMPLATE = lib
CONFIG = staticlib


DEFINES += STATIC_LIBRARY

SOURCES += \
    ../src/Analysers/JSON/JSON_Array.cpp \
    ../src/Analysers/JSON/JSON_Data.cpp \
    ../src/Analysers/JSON/JSON_DataContainer.cpp \
    ../src/Analysers/JSON/JSON_Document.cpp \
    ../src/Analysers/JSON/JSON_Object.cpp \
    ../src/Analysers/JSON/JSON_Pair.cpp \
    ../src/Analysers/JSON/JSON_Single.cpp \
    ../src/Analysers/ArgsParser.cpp \
    ../src/Analysers/CodeParcer.cpp \
    ../src/Bus/MsgInterface.cpp \
    ../src/Filesystem/BasicFile.cpp \
    ../src/Filesystem/Project.cpp \
    ../src/Filesystem/Session.cpp \
    ../src/Process/CommandLine.cpp \
    ../src/Templates/String.cpp \
    ../src/Others/Bits.cpp

HEADERS += \
    ../src/About/About.h \
    ../src/Analysers/JSON/JSON.h \
    ../src/Analysers/JSON/JSON_Array.h \
    ../src/Analysers/JSON/JSON_Data.h \
    ../src/Analysers/JSON/JSON_DataContainer.h \
    ../src/Analysers/JSON/JSON_Document.h \
    ../src/Analysers/JSON/JSON_Object.h \
    ../src/Analysers/JSON/JSON_Pair.h \
    ../src/Analysers/JSON/JSON_Single.h \
    ../src/Analysers/ArgsParser.h \
    ../src/Analysers/CodeParcer.h \
    ../src/Bus/MsgInterface.h \
    ../src/Constants/C.h \
    ../src/Constants/CPP.h \
    ../src/Filesystem/BasicFile.h \
    ../src/Filesystem/Project.h \
    ../src/Filesystem/Session.h \
    ../src/Others/Bits.h \
    ../src/Others/PrimitiveTypes.h \
    ../src/Others/TextStyle.h \
    ../src/Process/CommandLine.h \
    ../src/Templates/NewConseptions/Arrays.h \
    ../src/Templates/Allocator.h \
    ../src/Templates/Array.h \
    ../src/Templates/Array_Functions.h \
    ../src/Templates/Array_Iterators.h \
    ../src/Templates/ArrayBlocks.h \
    ../src/Templates/ArrayBlocks_Iterators.h \
    ../src/Templates/BasicIterator.h \
    ../src/Templates/ForAll.h \
    ../src/Templates/List.h \
    ../src/Templates/List_Container.h \
    ../src/Templates/List_Functions.h \
    ../src/Templates/Pointers.h \
    ../src/Templates/Pointers_BasicPointer.h \
    ../src/Templates/Pointers_Functions.h \
    ../src/Templates/Pointers_SharedPointer.h \
    ../src/Templates/Pointers_UniquePointer.h \
    ../src/Templates/SimpleArray.h \
    ../src/Templates/SimpleArray_Iterators.h \
    ../src/Templates/String.h \
    ../src/Templates/String_Functions.h \
    ../src/Templates/String_TString.h \
    ../src/Templates/Templates.h

INCLUDEPATH += ../src

QMAKE_CXXFLAGS += -std=c++14

