#ifndef FLAMEIDE_STREAMS_TESTS_NAMEDPIPEREADERTEST_HPP
#define FLAMEIDE_STREAMS_TESTS_NAMEDPIPEREADERTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace streams
{namespace tests
{

class NamedPipeReaderTest: public ::AbstractTest
{
public:
	NamedPipeReaderTest();
	virtual ~NamedPipeReaderTest();

private:
	virtual int vStart();
};

}}}

#endif // FLAMEIDE_STREAMS_TESTS_NAMEDPIPEREADERTEST_HPP
