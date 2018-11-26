#ifndef COMMON_TESTAGGREGATOR_HPP
#define COMMON_TESTAGGREGATOR_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace tests
{

class TestAggregator: public ::TestAggregator
{
public:
	TestAggregator();
	~TestAggregator() = default;
};

}}

#endif // COMMON_TESTAGGREGATOR_HPP
