TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++14 -fno-exceptions

INCLUDEPATH += ../../
INCLUDEPATH += ../../../

HEADERS += \
    Allocator.hpp \
    Array.hpp \
    TestClass.hpp \
    ../Allocator.hpp \
    ../Array.hpp \
    ../Array_Functions.hpp \
    ../Array_Iterators.hpp \
    ../ArrayBlocks.hpp \
    ../ArrayBlocks_Iterators.hpp \
    ../BasicIterator.hpp \
    ../List.hpp \
    ../List_Container.hpp \
    ../List_Functions.hpp \
    ../ObjectViewer.hpp \
    ../Pointers.hpp \
    ../Pointers_BasicPointer.hpp \
    ../Pointers_Functions.hpp \
    ../Pointers_SharedPointer.hpp \
    ../Pointers_UniquePointer.hpp \
    ../SimpleArray.hpp \
    ../SimpleArray_Iterators.hpp \
    ../String.hpp \
    ../String_Functions.hpp \
    ../String_TString.hpp \
    ../Templates.hpp \
    ../Traits.hpp \
    ../Utils.hpp \
    ../InitializerList.hpp

SOURCES += \
    Allocator.cpp \
    Array.cpp \
    main.cpp \
    TestClass.cpp \
    ../String.cpp

