#ifndef TEMPLATES_TESTAGGREGATOR_HPP
#define TEMPLATES_TESTAGGREGATOR_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace templates
{

class TestAggregator : public ::TestAggregator
{
public:
	TestAggregator();
	~TestAggregator() = default;
};

}}

#endif // TEMPLATES_TESTAGGREGATOR_HPP
