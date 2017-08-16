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
	TestClass.hpp \
	../Allocator.hpp \
	../Array.hpp \
	../ArrayBlocks.hpp \
	../List.hpp \
	../ObjectViewer.hpp \
	../Pointers.hpp \
	../SimpleArray.hpp \
	../String.hpp \
	../Templates.hpp \
	../Traits.hpp \
	../Utils.hpp \
	../InitializerList.hpp
	../Vector.hpp

SOURCES += \
	Allocator.cpp \
	Array.cpp \
	main.cpp \
	TestClass.cpp

