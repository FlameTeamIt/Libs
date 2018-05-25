TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS = -std=c++14 -pedantic -fno-rtti -fno-exceptions
INCLUDEPATH += src/
INCLUDEPATH += .

# headers
HEADERS += \
	./src/About/About.hpp \
	./src/Templates/ObjectViewer.hpp \
	./src/Templates/Variant.hpp \
	./src/Templates/View.hpp \
	./src/Templates/InitializerList.hpp \
	./src/Templates/Pointers.hpp \
	./src/Templates/Vector.hpp \
	./src/Templates/Utils.hpp \
	./src/Templates/WideInt.hpp \
	./src/Templates/Trees.hpp \
	./src/Templates/AlignObject.hpp \
	./src/Templates/Byte.hpp \
	./src/Templates/Serialization/Deserializer.hpp \
	./src/Templates/Serialization/Serializer.hpp \
	./src/Templates/Serialization/SpecializedValue.hpp \
	./src/Templates/ByteOrder.hpp \
	./src/Templates/Serialization.hpp \
	./src/Templates/FloatViewer.hpp \
	./src/Templates/Tuple.hpp \
	./src/Templates/List.hpp \
	./src/Templates/String.hpp \
	./src/Templates/Array.hpp \
	./src/Templates/Macroses.hpp \
	./src/Templates/Allocator.hpp \
	./src/Templates/Tests/Variant.hpp \
	./src/Templates/Tests/TestAggregator.hpp \
	./src/Templates/Tests/Vector.hpp \
	./src/Templates/Tests/UniquePoiter.hpp \
	./src/Templates/Tests/SharedPointer.hpp \
	./src/Templates/Tests/ByteOrder.hpp \
	./src/Templates/Tests/Serialization.hpp \
	./src/Templates/Tests/Tuple.hpp \
	./src/Templates/Tests/List.hpp \
	./src/Templates/Tests/String.hpp \
	./src/Templates/Tests/Array.hpp \
	./src/Templates/Tests/Allocator.hpp \
	./src/Templates/Tests/TestClass.hpp \
	./src/Templates/Tests/Bits.hpp \
	./src/Templates/Traits.hpp \
	./src/Templates/ArrayBits.hpp \
	./src/Templates/Iterator.hpp \
	./src/Templates/Templates.hpp \
	./src/Templates/Bits.hpp \
	./src/Templates/CircularVector.hpp \
	./src/Templates/BitSet.hpp \
	./src/Templates/WideFloat.hpp \
	./src/Templates/SimpleAlgorithms.hpp \
	./src/Templates/ArrayBlocks.hpp \
	./src/Constants/C.hpp \
	./src/Constants/CPP.hpp \
	./src/Bus/MsgInterface.hpp \
	./src/Process/CommandLine.hpp \
	./src/Filesystem/Session.hpp \
	./src/Filesystem/Project.hpp \
	./src/Filesystem/BasicFile.hpp \
	./src/Analysers/CodeParcer.hpp \
	./src/Analysers/Bson/Types.hpp \
	./src/Analysers/Bson/DefaultAccumulator.hpp \
	./src/Analysers/Bson/Input.hpp \
	./src/Analysers/Bson/Stream.hpp \
	./src/Analysers/ArgsParser.hpp \
	./src/Others/TextStyle.hpp \
	./src/Common/Byte.hpp \
	./src/Common/PrimitiveTypes.hpp \
	./tests/Test.hpp 

# sources
SOURCES += \
	./src/Templates/Tests/Allocator.cpp \
	./src/Templates/Tests/List.cpp \
	./src/Templates/Tests/TestAggregator.cpp \
	./src/Templates/Tests/Serialization.cpp \
	./src/Templates/Tests/UniquePoiter.cpp \
	./src/Templates/Tests/String.cpp \
	./src/Templates/Tests/Vector.cpp \
	./src/Templates/Tests/Variant.cpp \
	./src/Templates/Tests/ByteOrder.cpp \
	./src/Templates/Tests/Bits.cpp \
	./src/Templates/Tests/SharedPointer.cpp \
	./src/Templates/Tests/Array.cpp \
	./src/Templates/Tests/TestClass.cpp \
	./src/Templates/Tests/Tuple.cpp \
	./src/Bus/MsgInterface.cpp \
	./src/Process/CommandLine.cpp \
	./src/Filesystem/Session.cpp \
	./src/Filesystem/BasicFile.cpp \
	./src/Filesystem/Project.cpp \
	./src/Analysers/ArgsParser.cpp \
	./src/Analysers/CodeParcer.cpp \
	./src/Analysers/Bson/DefaultAccumulator.cpp \
	./src/Analysers/Bson/Input.cpp \
	./tests/main.cpp 

