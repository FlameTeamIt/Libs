#ifndef FLAMEIDE_STREAMS_TESTS_NAMEDPIPESTREAMTEST_HPP
#define FLAMEIDE_STREAMS_TESTS_NAMEDPIPESTREAMTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace streams
{namespace tests
{

class NamedPipeStreamTest: public ::AbstractTest
{
public:
	NamedPipeStreamTest();
	virtual ~NamedPipeStreamTest();

private:
	virtual int vStart();
};

}}}

#endif // FLAMEIDE_STREAMS_TESTS_NAMEDPIPESTREAMTEST_HPP
