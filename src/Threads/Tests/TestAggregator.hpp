#ifndef FLAMEIDE_THREADS_TESTS_TESTAGGREGATOR_HPP
#define FLAMEIDE_THREADS_TESTS_TESTAGGREGATOR_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace threads
{namespace tests
{

class TestAggregator : public ::TestAggregator
{
public:
	TestAggregator();
	virtual ~TestAggregator();
};

}}}

#endif // FLAMEIDE_THREADS_TESTS_TESTAGGREGATOR_HPP
