#ifndef FLAMEIDE_STREAMS_TESTS_PIPESTREAMTEST_HPP
#define FLAMEIDE_STREAMS_TESTS_PIPESTREAMTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace streams
{namespace tests
{

class PipeStreamTest: public ::AbstractTest
{
public:
	PipeStreamTest();
	virtual ~PipeStreamTest();

private:
	virtual int vStart();
};

}}}

#endif // FLAMEIDE_STREAMS_TESTS_PIPESTREAMTEST_HPP
