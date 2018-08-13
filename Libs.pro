TEMPLATE = app
CONFIG += console
CONFIG += object_parallel_to_source
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS = -std=c++14 -pedantic -fno-rtti -fno-exceptions
QMAKE_CXXFLAGS_DEBUG += -gdwarf-3
INCLUDEPATH += src/
INCLUDEPATH += .

# headers
HEADERS += \
	./src/About/About.hpp \
	./src/Analysers/Ubjson/Array.hpp \
	./src/Analysers/Ubjson/HugeNumeric.hpp \
	./src/Analysers/Ubjson/Object.hpp \
	./src/Analysers/Ubjson/Pair.hpp \
	./src/Analysers/Ubjson/Settings.hpp \
	./src/Analysers/Ubjson/Stream.hpp \
	./src/Analysers/Ubjson/String.hpp \
	./src/Analysers/Ubjson/Traits.hpp \
	./src/Analysers/Ubjson/Types.hpp \
	./src/Analysers/Ubjson/Value.hpp \
	./src/Bus/MsgInterface.hpp \
	./src/Common/Byte.hpp \
	./src/Common/Macroses.hpp \
	./src/Common/PrimitiveTypes.hpp \
	./src/Common/Traits.hpp \
	./src/Common/Utils.hpp \
	./src/Constants/C.hpp \
	./src/Constants/CPP.hpp \
	./src/Filesystem/BasicFile.hpp \
	./src/Filesystem/Project.hpp \
	./src/Filesystem/Session.hpp \
	./src/Others/TextStyle.hpp \
	./src/Process/CommandLine.hpp \
	./src/Streams/StreamBase.hpp \
	./src/Templates/AlignObject.hpp \
	./src/Templates/Allocator.hpp \
	./src/Templates/Allocator/ArrayAllocator.hpp \
	./src/Templates/Allocator/Interface.hpp \
	./src/Templates/Allocator/MallocAllocator.hpp \
	./src/Templates/Allocator/ObjectAllocator.hpp \
	./src/Templates/Array.hpp \
	./src/Templates/ArrayBits.hpp \
	./src/Templates/ArrayBlocks.hpp \
	./src/Templates/BitSet.hpp \
	./src/Templates/Bits.hpp \
	./src/Templates/Byte.hpp \
	./src/Templates/ByteOrder.hpp \
	./src/Templates/CircularVector.hpp \
	./src/Templates/InitializerList.hpp \
	./src/Templates/Iterator.hpp \
	./src/Templates/List.hpp \
	./src/Templates/ObjectViewer.hpp \
	./src/Templates/Optional.hpp \
	./src/Templates/Pointers.hpp \
	./src/Templates/Serialization.hpp \
	./src/Templates/Serialization/Deserializer.hpp \
	./src/Templates/Serialization/Serializer.hpp \
	./src/Templates/Serialization/SpecializedValue.hpp \
	./src/Templates/Serialization/ValueInfo.hpp \
	./src/Templates/SimpleAlgorithms.hpp \
	./src/Templates/String.hpp \
	./src/Templates/Templates.hpp \
	./src/Templates/Tests/Allocator.hpp \
	./src/Templates/Tests/Array.hpp \
	./src/Templates/Tests/Bits.hpp \
	./src/Templates/Tests/ByteOrder.hpp \
	./src/Templates/Tests/CircularVector.hpp \
	./src/Templates/Tests/List.hpp \
	./src/Templates/Tests/Serialization.hpp \
	./src/Templates/Tests/SharedPointer.hpp \
	./src/Templates/Tests/String.hpp \
	./src/Templates/Tests/TestAggregator.hpp \
	./src/Templates/Tests/TestClass.hpp \
	./src/Templates/Tests/Tuple.hpp \
	./src/Templates/Tests/UniquePoiter.hpp \
	./src/Templates/Tests/Variant.hpp \
	./src/Templates/Tests/Vector.hpp \
	./src/Templates/Tests/WideInt.hpp \
	./src/Templates/Trees.hpp \
	./src/Templates/Tuple.hpp \
	./src/Templates/Variant.hpp \
	./src/Templates/Vector.hpp \
	./src/Templates/View.hpp \
	./src/Templates/WideFloat.hpp \
	./src/Templates/WideInt.hpp \
	./tests/Test.hpp

# sources
SOURCES += \
	./src/Analysers/Ubjson/Array.cpp \
	./src/Analysers/Ubjson/Object.cpp \
	./src/Analysers/Ubjson/Pair.cpp \
	./src/Analysers/Ubjson/String.cpp \
	./src/Bus/MsgInterface.cpp \
	./src/Filesystem/BasicFile.cpp \
	./src/Filesystem/Project.cpp \
	./src/Filesystem/Session.cpp \
	./src/Process/CommandLine.cpp \
	./src/Streams/StreamBase.cpp \
	./src/Templates/Tests/Allocator.cpp \
	./src/Templates/Tests/Array.cpp \
	./src/Templates/Tests/Bits.cpp \
	./src/Templates/Tests/ByteOrder.cpp \
	./src/Templates/Tests/CircularVector.cpp \
	./src/Templates/Tests/List.cpp \
	./src/Templates/Tests/Serialization.cpp \
	./src/Templates/Tests/SharedPointer.cpp \
	./src/Templates/Tests/String.cpp \
	./src/Templates/Tests/TestAggregator.cpp \
	./src/Templates/Tests/TestClass.cpp \
	./src/Templates/Tests/Tuple.cpp \
	./src/Templates/Tests/UniquePoiter.cpp \
	./src/Templates/Tests/Variant.cpp \
	./src/Templates/Tests/Vector.cpp \
	./src/Templates/Tests/WideInt.cpp \
	./tests/main.cpp

