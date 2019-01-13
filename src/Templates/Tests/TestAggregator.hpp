#ifndef FLAMEIDE_TEMPLATES_TESTS_TESTAGGREGATOR_HPP
#define FLAMEIDE_TEMPLATES_TESTS_TESTAGGREGATOR_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace templates
{namespace tests
{

class TestAggregator: public ::TestAggregator
{
public:
	TestAggregator();
	~TestAggregator() = default;
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTAGGREGATOR_HPP
