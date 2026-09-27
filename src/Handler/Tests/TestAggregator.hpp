#ifndef FLAMEIDE_SRC_HANDLER_TESTS_TESTAGGREGATOR_HPP
#define FLAMEIDE_SRC_HANDLER_TESTS_TESTAGGREGATOR_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace tests
{

class TestAggregator: public ::TestAggregator
{
public:
	TestAggregator();
	virtual ~TestAggregator() = default;
};

}}} // namespace flame_ide::handler::tests

#endif // FLAMEIDE_SRC_HANDLER_TESTS_TESTAGGREGATOR_HPP
