TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++14
INCLUDEPATH += src/

SOURCES += \
    src/Analysers/JSON/JSON_Array.cpp \
    src/Analysers/JSON/JSON_Data.cpp \
    src/Analysers/JSON/JSON_DataContainer.cpp \
    src/Analysers/JSON/JSON_Document.cpp \
    src/Analysers/JSON/JSON_Object.cpp \
    src/Analysers/JSON/JSON_Pair.cpp \
    src/Analysers/JSON/JSON_Single.cpp \
    src/Analysers/ArgsParser.cpp \
    src/Analysers/CodeParcer.cpp \
    src/Bus/MsgInterface.cpp \
    src/Filesystem/BasicFile.cpp \
    src/Filesystem/Project.cpp \
    src/Filesystem/Session.cpp \
    src/Others/Bits.cpp \
    src/Process/CommandLine.cpp \
    src/Tests/main.cpp \
    src/Tests/Test.cpp \
    src/Tests/Test_Analyzers.cpp \
    src/Tests/Test_Analyzers_JSONLib.cpp \
    src/Tests/Test_Bus.cpp \
    src/Tests/Test_Filesystem.cpp \
    src/Tests/Test_Others.cpp \
    src/Tests/Test_Templates.cpp \
    tests/Templates/ArrayBlocks.cpp

HEADERS += \
    src/About/About.hpp \
    src/Analysers/JSON/JSON.hpp \
    src/Analysers/JSON/JSON_Array.hpp \
    src/Analysers/JSON/JSON_Data.hpp \
    src/Analysers/JSON/JSON_DataContainer.hpp \
    src/Analysers/JSON/JSON_Document.hpp \
    src/Analysers/JSON/JSON_Object.hpp \
    src/Analysers/JSON/JSON_Pair.hpp \
    src/Analysers/JSON/JSON_Single.hpp \
    src/Analysers/ArgsParser.hpp \
    src/Analysers/CodeParcer.hpp \
    src/Bus/MsgInterface.hpp \
    src/Constants/C.hpp \
    src/Constants/CPP.hpp \
    src/Filesystem/BasicFile.hpp \
    src/Filesystem/Project.hpp \
    src/Filesystem/Session.hpp \
    src/Others/Bits.hpp \
    src/Others/PrimitiveTypes.hpp \
    src/Others/TextStyle.hpp \
    src/Process/CommandLine.hpp \
    src/Templates/NewConseptions/Arrays.hpp \
    src/Templates/Allocator.hpp \
    src/Templates/Array.hpp \
    src/Templates/Array_Functions.hpp \
    src/Templates/Array_Iterators.hpp \
    src/Templates/ArrayBlocks.hpp \
    src/Templates/ArrayBlocks_Iterators.hpp \
    src/Templates/BasicIterator.hpp \
    src/Templates/ForAll.hpp \
    src/Templates/List.hpp \
    src/Templates/List_Container.hpp \
    src/Templates/List_Functions.hpp \
    src/Templates/Pointers.hpp \
    src/Templates/Pointers_BasicPointer.hpp \
    src/Templates/Pointers_Functions.hpp \
    src/Templates/Pointers_SharedPointer.hpp \
    src/Templates/Pointers_UniquePointer.hpp \
    src/Templates/SimpleArray.hpp \
    src/Templates/SimpleArray_Iterators.hpp \
    src/Templates/String.hpp \
    src/Templates/String_Functions.hpp \
    src/Templates/String_TString.hpp \
    src/Templates/Templates.hpp \
    src/Tests/Test.hpp \
    tests/Templates/ArrayBlocks.hpp \
    tests/Test.hpp \
    src/Templates/Utils.hpp \
    src/Templates/ObjectViewer.hpp \
    src/Templates/IntializerList.hpp \
    src/Templates/Iterator.hpp \
    src/Templates/View.hpp \
    src/Templates/Vector.hpp \
    src/Templates/CircularVector.hpp \
    src/Templates/Trees.hpp \
    src/Templates/Tuple.hpp
