#ifndef FLAMEIDE_COMMON_TESTAGGREGATOR_HPP
#define FLAMEIDE_COMMON_TESTAGGREGATOR_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace common
{namespace tests
{

class TestAggregator: public ::TestAggregator
{
public:
	TestAggregator();
	~TestAggregator() = default;
};

}}}

#endif // FLAMEIDE_COMMON_TESTAGGREGATOR_HPP
