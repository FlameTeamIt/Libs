TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXXFLAGS += -fno-exceptions

INCLUDEPATH += ../../
INCLUDEPATH += ../../../

HEADERS += \
	../Allocator.hpp \
	../Array.hpp \
	../ArrayBlocks.hpp \
	../List.hpp \
	../ObjectViewer.hpp \
	../Pointers.hpp \
	../String.hpp \
	../Templates.hpp \
	../Traits.hpp \
	../Utils.hpp \
	../InitializerList.hpp \
	../Vector.hpp \
	../View.hpp \
	../Iterator.hpp \
	TestClass.hpp \
	Allocator.hpp \
	Array.hpp \
	Vector.hpp \
	List.hpp \
	String.hpp \
	SharedPointer.hpp \
	UniquePoiter.hpp \
    Tuple.hpp

SOURCES += \
	main.cpp \
	TestClass.cpp \
	Allocator.cpp \
	Array.cpp \
	Vector.cpp \
	List.cpp \
	String.cpp \
	SharedPointer.cpp \
	UniquePoiter.cpp \
    Tuple.cpp

