#ifndef FLAMEIDE_STREAMS_TESTS_RAMSTREAMTEST_HPP
#define FLAMEIDE_STREAMS_TESTS_RAMSTREAMTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace streams
{namespace tests
{

class RamStreamTest : public ::AbstractTest
{
public:
	RamStreamTest();
	virtual ~RamStreamTest();

private:
	virtual int vStart();
};

}}}

#endif // FLAMEIDE_STREAMS_TESTS_RAMSTREAMTEST_HPP
