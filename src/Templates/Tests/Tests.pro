TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXXFLAGS += -fno-exceptions

INCLUDEPATH += ../../
INCLUDEPATH += ../../../

HEADERS += \
    Allocator.hpp \
    Array.hpp \
    List.hpp \
    SharedPointer.hpp \
    String.hpp \
    TestClass.hpp \
    Tuple.hpp \
    UniquePoiter.hpp \
    Vector.hpp \
    ../Allocator.hpp \
    ../Array.hpp \
    ../ArrayBlocks.hpp \
    ../CircularVector.hpp \
    ../InitializerList.hpp \
    ../Iterator.hpp \
    ../List.hpp \
    ../ObjectViewer.hpp \
    ../Pointers.hpp \
    ../SimpleAlgorithms.hpp \
    ../String.hpp \
    ../Templates.hpp \
    ../Traits.hpp \
    ../Tuple.hpp \
    ../Utils.hpp \
    ../Vector.hpp \
    ../View.hpp \
    ../WideInt.hpp \
    ../Bits.hpp

SOURCES += \
    Allocator.cpp \
    Array.cpp \
    List.cpp \
    main.cpp \
    SharedPointer.cpp \
    String.cpp \
    TestClass.cpp \
    Tuple.cpp \
    UniquePoiter.cpp \
    Vector.cpp

