TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS = -std=c++14 -pedantic
INCLUDEPATH += src/
INCLUDEPATH += .

# headers
HEADERS += \
	./tests/Test.hpp \
	./src/Others/TextStyle.hpp \
	./src/Others/PrimitiveTypes.hpp \
	./src/Analysers/ArgsParser.hpp \
	./src/Analysers/CodeParcer.hpp \
	./src/Constants/CPP.hpp \
	./src/Constants/C.hpp \
	./src/Bus/MsgInterface.hpp \
	./src/About/About.hpp \
	./src/Process/CommandLine.hpp \
	./src/Filesystem/Project.hpp \
	./src/Filesystem/BasicFile.hpp \
	./src/Filesystem/Session.hpp \
	./src/Templates/Serialization/Serializer.hpp \
	./src/Templates/Serialization/SpetializedValue.hpp \
	./src/Templates/Serialization/Deserializer.hpp \
	./src/Templates/CircularVector.hpp \
	./src/Templates/AlignObject.hpp \
	./src/Templates/Vector.hpp \
	./src/Templates/ArrayBits.hpp \
	./src/Templates/Tests/SharedPointer.hpp \
	./src/Templates/Tests/Vector.hpp \
	./src/Templates/Tests/List.hpp \
	./src/Templates/Tests/Bits.hpp \
	./src/Templates/Tests/TestClass.hpp \
	./src/Templates/Tests/Variant.hpp \
	./src/Templates/Tests/Tuple.hpp \
	./src/Templates/Tests/Allocator.hpp \
	./src/Templates/Tests/UniquePoiter.hpp \
	./src/Templates/Tests/TestAggregator.hpp \
	./src/Templates/Tests/String.hpp \
	./src/Templates/Tests/ByteOrder.hpp \
	./src/Templates/Tests/Array.hpp \
	./src/Templates/Tests/Serialization.hpp \
	./src/Templates/List.hpp \
	./src/Templates/WideInt.hpp \
	./src/Templates/Templates.hpp \
	./src/Templates/Iterator.hpp \
	./src/Templates/BitSet.hpp \
	./src/Templates/Bits.hpp \
	./src/Templates/View.hpp \
	./src/Templates/FloatViewer.hpp \
	./src/Templates/Pointers.hpp \
	./src/Templates/Variant.hpp \
	./src/Templates/ArrayBlocks.hpp \
	./src/Templates/Tuple.hpp \
	./src/Templates/Trees.hpp \
	./src/Templates/Allocator.hpp \
	./src/Templates/Byte.hpp \
	./src/Templates/SimpleAlgorithms.hpp \
	./src/Templates/String.hpp \
	./src/Templates/ObjectViewer.hpp \
	./src/Templates/InitializerList.hpp \
	./src/Templates/Macroses.hpp \
	./src/Templates/ByteOrder.hpp \
	./src/Templates/Array.hpp \
	./src/Templates/Utils.hpp \
	./src/Templates/WideFloat.hpp \
	./src/Templates/Traits.hpp \
	./src/Templates/Serialization.hpp 

# sources
SOURCES += \
	./tests/main.cpp \
	./src/Analysers/ArgsParser.cpp \
	./src/Analysers/CodeParcer.cpp \
	./src/Bus/MsgInterface.cpp \
	./src/Process/CommandLine.cpp \
	./src/Filesystem/BasicFile.cpp \
	./src/Filesystem/Project.cpp \
	./src/Filesystem/Session.cpp \
	./src/Templates/Tests/Array.cpp \
	./src/Templates/Tests/Bits.cpp \
	./src/Templates/Tests/Serialization.cpp \
	./src/Templates/Tests/List.cpp \
	./src/Templates/Tests/Allocator.cpp \
	./src/Templates/Tests/SharedPointer.cpp \
	./src/Templates/Tests/Vector.cpp \
	./src/Templates/Tests/TestClass.cpp \
	./src/Templates/Tests/TestAggregator.cpp \
	./src/Templates/Tests/String.cpp \
	./src/Templates/Tests/UniquePoiter.cpp \
	./src/Templates/Tests/Tuple.cpp \
	./src/Templates/Tests/ByteOrder.cpp \
	./src/Templates/Tests/Variant.cpp 

