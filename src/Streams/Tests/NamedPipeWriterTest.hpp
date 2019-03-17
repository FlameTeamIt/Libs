#ifndef FLAMEIDE_STREAMS_TESTS_NAMEDPIPEWRITERTEST_HPP
#define FLAMEIDE_STREAMS_TESTS_NAMEDPIPEWRITERTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace streams
{namespace tests
{

class NamedPipeWriterTest: public ::AbstractTest
{
public:
	NamedPipeWriterTest();
	virtual ~NamedPipeWriterTest();

private:
	virtual int vStart();
};

}}}

#endif // FLAMEIDE_STREAMS_TESTS_NAMEDPIPEWRITERTEST_HPP
