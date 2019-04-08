TEMPLATE = app
CONFIG += console
CONFIG += object_parallel_to_source
win32 {
CONFIG += c++14
}
CONFIG -= app_bundle
CONFIG -= qt

!win32 {
QMAKE_CXXFLAGS = -std=c++14 -pedantic -fno-rtti -fno-exceptions
QMAKE_CXXFLAGS_DEBUG += -gdwarf-3
QMAKE_CXXFLAGS_RELEASE = -O3 -Wall -W
QMAKE_LFLAGS = -pthread
}
INCLUDEPATH += include/
INCLUDEPATH += .

# headers
## common headers
HEADERS += \
	./include/FlameIDE/About/About.hpp \
	./include/FlameIDE/Analysers/Ubjson/Array.hpp \
	./include/FlameIDE/Analysers/Ubjson/BaseValue.hpp \
	./include/FlameIDE/Analysers/Ubjson/HugeNumber.hpp \
	./include/FlameIDE/Analysers/Ubjson/Object.hpp \
	./include/FlameIDE/Analysers/Ubjson/Pair.hpp \
	./include/FlameIDE/Analysers/Ubjson/Settings.hpp \
	./include/FlameIDE/Analysers/Ubjson/SimpleTypeValues.hpp \
	./include/FlameIDE/Analysers/Ubjson/Stream.hpp \
	./include/FlameIDE/Analysers/Ubjson/String.hpp \
	./include/FlameIDE/Analysers/Ubjson/Traits.hpp \
	./include/FlameIDE/Analysers/Ubjson/Types.hpp \
	./include/FlameIDE/Analysers/Ubjson/Value.hpp \
	./include/FlameIDE/Analysers/Ubjson/ValueSpecializations.hpp \
	./include/FlameIDE/Bus/MsgInterface.hpp \
	./include/FlameIDE/Common/Byte.hpp \
	./include/FlameIDE/Common/Constants.hpp \
	./include/FlameIDE/Common/Macroses.hpp \
	./include/FlameIDE/Common/Macroses/ByteOrder.hpp \
	./include/FlameIDE/Common/Macroses/DetectOs.hpp \
	./include/FlameIDE/Common/OsTypes.hpp \
	./include/FlameIDE/Common/PrimitiveTypes.hpp \
	./include/FlameIDE/Common/Traits.hpp \
	./include/FlameIDE/Common/Traits/ContainerTraits.hpp \
	./include/FlameIDE/Common/Traits/CreationProhibitions.hpp \
	./include/FlameIDE/Common/Traits/Defaults.hpp \
	./include/FlameIDE/Common/Traits/Fuctional.hpp \
	./include/FlameIDE/Common/Traits/Numbers.hpp \
	./include/FlameIDE/Common/Utils.hpp \
	./include/FlameIDE/Constants/C.hpp \
	./include/FlameIDE/Constants/CPP.hpp \
	./include/FlameIDE/Others/TextStyle.hpp \
	./include/FlameIDE/Streams/Async/FileStreamReader.hpp \
	./include/FlameIDE/Streams/Async/FileStreamWriter.hpp \
	./include/FlameIDE/Streams/FileStreamReader.hpp \
	./include/FlameIDE/Streams/FileStreamWriter.hpp \
	./include/FlameIDE/Streams/NamedPipeReader.hpp \
	./include/FlameIDE/Streams/NamedPipeStream.hpp \
	./include/FlameIDE/Streams/NamedPipeWriter.hpp \
	./include/FlameIDE/Streams/PipeStream.hpp \
	./include/FlameIDE/Streams/RamStream.hpp \
	./include/FlameIDE/Streams/Reader.hpp \
	./include/FlameIDE/Streams/Socket.hpp \
	./include/FlameIDE/Streams/SocketClient.hpp \
	./include/FlameIDE/Streams/SocketServer.hpp \
	./include/FlameIDE/Streams/StreamUtils.hpp \
	./include/FlameIDE/Streams/Writer.hpp \
	./include/FlameIDE/Templates/AlignObject.hpp \
	./include/FlameIDE/Templates/Allocator.hpp \
	./include/FlameIDE/Templates/Allocator/ArrayAllocator.hpp \
	./include/FlameIDE/Templates/Allocator/Interface.hpp \
	./include/FlameIDE/Templates/Allocator/MallocAllocator.hpp \
	./include/FlameIDE/Templates/Allocator/ObjectAllocator.hpp \
	./include/FlameIDE/Templates/Array.hpp \
	./include/FlameIDE/Templates/ArrayBlocks.hpp \
	./include/FlameIDE/Templates/AsIntegralType.hpp \
	./include/FlameIDE/Templates/Bits.hpp \
	./include/FlameIDE/Templates/BitSet.hpp \
	./include/FlameIDE/Templates/ByteOrder.hpp \
	./include/FlameIDE/Templates/CircularArray.hpp \
	./include/FlameIDE/Templates/CircularVector.hpp \
	./include/FlameIDE/Templates/HybridVector.hpp \
	./include/FlameIDE/Templates/InitializerList.hpp \
	./include/FlameIDE/Templates/IntegerIterator.hpp \
	./include/FlameIDE/Templates/Iterator.hpp \
	./include/FlameIDE/Templates/Iterator/BaseIterator.hpp \
	./include/FlameIDE/Templates/Iterator/CircularIterator.hpp \
	./include/FlameIDE/Templates/Iterator/ConstCircularIterator.hpp \
	./include/FlameIDE/Templates/Iterator/ConstIterator.hpp \
	./include/FlameIDE/Templates/Iterator/ConstReverseIterator.hpp \
	./include/FlameIDE/Templates/Iterator/Iterator.hpp \
	./include/FlameIDE/Templates/Iterator/IteratorTraits.hpp \
	./include/FlameIDE/Templates/Iterator/Operators.hpp \
	./include/FlameIDE/Templates/Iterator/ReverseIterator.hpp \
	./include/FlameIDE/Templates/Iterator/UndefOperators.hpp \
	./include/FlameIDE/Templates/List.hpp \
	./include/FlameIDE/Templates/ObjectViewer.hpp \
	./include/FlameIDE/Templates/Optional.hpp \
	./include/FlameIDE/Templates/Pointers.hpp \
	./include/FlameIDE/Templates/RaiiCaller.hpp \
	./include/FlameIDE/Templates/Range.hpp \
	./include/FlameIDE/Templates/Serialization.hpp \
	./include/FlameIDE/Templates/Serialization/Deserializer.hpp \
	./include/FlameIDE/Templates/Serialization/Serializer.hpp \
	./include/FlameIDE/Templates/Serialization/SpecializedValue.hpp \
	./include/FlameIDE/Templates/Serialization/ValueInfo.hpp \
	./include/FlameIDE/Templates/SimpleAlgorithms.hpp \
	./include/FlameIDE/Templates/StaticAllocator.hpp \
	./include/FlameIDE/Templates/String.hpp \
	./include/FlameIDE/Templates/Templates.hpp \
	./include/FlameIDE/Templates/Trees.hpp \
	./include/FlameIDE/Templates/Tuple.hpp \
	./include/FlameIDE/Templates/Variant.hpp \
	./include/FlameIDE/Templates/Vector.hpp \
	./include/FlameIDE/Templates/WideFloat.hpp \
	./include/FlameIDE/Templates/WideInt.hpp \
	./include/FlameIDE/Threads/Mutex.hpp \
	./include/FlameIDE/Threads/Semaphore.hpp \
	./include/FlameIDE/Threads/Thread.hpp \
	./src/Common/Tests/TestAggregator.hpp \
	./src/Common/Tests/Utils.hpp \
	./src/Streams/Tests/NamedPipeReaderTest.hpp \
	./src/Streams/Tests/NamedPipeStreamTest.hpp \
	./src/Streams/Tests/NamedPipeWriterTest.hpp \
	./src/Streams/Tests/PipeStreamTest.hpp \
	./src/Streams/Tests/RamStreamTest.hpp \
	./src/Streams/Tests/TestAggregator.hpp \
	./src/Templates/Tests/AllocatorTest.hpp \
	./src/Templates/Tests/ArrayTest.hpp \
	./src/Templates/Tests/AsIntegralTypeTest.hpp \
	./src/Templates/Tests/BitsTest.hpp \
	./src/Templates/Tests/ByteOrderTest.hpp \
	./src/Templates/Tests/CircularArrayTest.hpp \
	./src/Templates/Tests/CircularIteratorTest.hpp \
	./src/Templates/Tests/CircularVectorTest.hpp \
	./src/Templates/Tests/HybridVectorTest.hpp \
	./src/Templates/Tests/IntegerIteratorTest.hpp \
	./src/Templates/Tests/ListTest.hpp \
	./src/Templates/Tests/SerializationTest.hpp \
	./src/Templates/Tests/SharedPointerTest.hpp \
	./src/Templates/Tests/StringTest.hpp \
	./src/Templates/Tests/TestAggregator.hpp \
	./src/Templates/Tests/TestClass.hpp \
	./src/Templates/Tests/TupleTest.hpp \
	./src/Templates/Tests/UniquePoiterTest.hpp \
	./src/Templates/Tests/VariantTest.hpp \
	./src/Templates/Tests/VectorTest.hpp \
	./src/Templates/Tests/WideIntTest.hpp \
	./src/Threads/Tests/MutexTest.hpp \
	./src/Threads/Tests/SemaphoreTest.hpp \
	./src/Threads/Tests/TestAggregator.hpp \
	./src/Threads/Tests/ThreadTest.hpp \
	./tests/Test.hpp

## Windows headers
win32 {
HEADERS += \
	./include/FlameIDE/Common/OsTypes/Windows.hpp \
	./src/Streams/Windows/InternalWinApiFunctions.hpp
}

## Posix headers
!win32 {
HEADERS += \
	./include/FlameIDE/Common/OsTypes/Posix.hpp \
	./src/Streams/Posix/InternalPosixFunctions.hpp
}

# sources
SOURCES += \
	./src/Analysers/Ubjson/Array.cpp \
	./src/Analysers/Ubjson/Object.cpp \
	./src/Analysers/Ubjson/Pair.cpp \
	./src/Analysers/Ubjson/String.cpp \
	./src/Bus/MsgInterface.cpp \
	./src/Common/Tests/TestAggregator.cpp \
	./src/Common/Tests/Utils.cpp \
	./src/Streams/RamStream.cpp \
	./src/Streams/StreamUtils.cpp \
	./src/Streams/Tests/NamedPipeReaderTest.cpp \
	./src/Streams/Tests/NamedPipeStreamTest.cpp \
	./src/Streams/Tests/NamedPipeWriterTest.cpp \
	./src/Streams/Tests/PipeStreamTest.cpp \
	./src/Streams/Tests/RamStreamTest.cpp \
	./src/Streams/Tests/TestAggregator.cpp \
	./src/Templates/Tests/AllocatorTest.cpp \
	./src/Templates/Tests/ArrayTest.cpp \
	./src/Templates/Tests/AsIntegralTypeTest.cpp \
	./src/Templates/Tests/BitsTest.cpp \
	./src/Templates/Tests/ByteOrderTest.cpp \
	./src/Templates/Tests/CircularArrayTest.cpp \
	./src/Templates/Tests/CircularIteratorTest.cpp \
	./src/Templates/Tests/CircularVectorTest.cpp \
	./src/Templates/Tests/HybridVectorTest.cpp \
	./src/Templates/Tests/IntegerIteratorTest.cpp \
	./src/Templates/Tests/ListTest.cpp \
	./src/Templates/Tests/SerializationTest.cpp \
	./src/Templates/Tests/SharedPointerTest.cpp \
	./src/Templates/Tests/StringTest.cpp \
	./src/Templates/Tests/TestAggregator.cpp \
	./src/Templates/Tests/TestClass.cpp \
	./src/Templates/Tests/TupleTest.cpp \
	./src/Templates/Tests/UniquePoiterTest.cpp \
	./src/Templates/Tests/VariantTest.cpp \
	./src/Templates/Tests/VectorTest.cpp \
	./src/Templates/Tests/WideIntTest.cpp \
	./src/Threads/MutexLocker.cpp \
	./src/Threads/SemaphorePoster.cpp \
	./src/Threads/SemaphoreWaiter.cpp \
	./src/Threads/Tests/MutexTest.cpp \
	./src/Threads/Tests/SemaphoreTest.cpp \
	./src/Threads/Tests/TestAggregator.cpp \
	./src/Threads/Tests/ThreadTest.cpp \
	./tests/main.cpp

## Windows sources
win32 {
SOURCES += \
	./src/Streams/Windows/Async/FileStreamReader.cpp \
	./src/Streams/Windows/Async/FileStreamWriter.cpp \
	./src/Streams/Windows/FileStreamReader.cpp \
	./src/Streams/Windows/FileStreamWriter.cpp \
	./src/Streams/Windows/InternalWinApiFunctions.cpp \
	./src/Streams/Windows/NamedPipeReader.cpp \
	./src/Streams/Windows/NamedPipeStream.cpp \
	./src/Streams/Windows/NamedPipeWriter.cpp \
	./src/Streams/Windows/PipeStream.cpp \
	./src/Streams/Windows/Socket.cpp \
	./src/Streams/Windows/SocketClient.cpp \
	./src/Streams/Windows/SocketServer.cpp \
	./src/Threads/Windows/Mutex.cpp \
	./src/Threads/Windows/Semaphore.cpp \
	./src/Threads/Windows/Thread.cpp
}

## Posix sources
!win32 {
SOURCES += \
	./src/Streams/Posix/Async/FileStreamReader.cpp \
	./src/Streams/Posix/Async/FileStreamWriter.cpp \
	./src/Streams/Posix/FileStreamReader.cpp \
	./src/Streams/Posix/FileStreamWriter.cpp \
	./src/Streams/Posix/InternalPosixFunctions.cpp \
	./src/Streams/Posix/NamedPipeReader.cpp \
	./src/Streams/Posix/NamedPipeStream.cpp \
	./src/Streams/Posix/NamedPipeWriter.cpp \
	./src/Streams/Posix/PipeStream.cpp \
	./src/Streams/Posix/Socket.cpp \
	./src/Streams/Posix/SocketClient.cpp \
	./src/Streams/Posix/SocketServer.cpp \
	./src/Threads/Posix/Mutex.cpp \
	./src/Threads/Posix/Semaphore.cpp \
	./src/Threads/Posix/Thread.cpp
}

