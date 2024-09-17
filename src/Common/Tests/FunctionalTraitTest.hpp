#ifndef FLAMEIDE_COMMON_TESTS_FUNCTIONALTRAITTEST_HPP
#define FLAMEIDE_COMMON_TESTS_FUNCTIONALTRAITTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace common
{namespace tests
{

class FunctionalTraitTest: public ::AbstractTest
{
public:
	FunctionalTraitTest() noexcept;
	~FunctionalTraitTest() noexcept override;

private:
	int vStart() override;

private:
	int typeMapper();
};

}}} // namespace flame_ide::common::tests

#endif // FLAMEIDE_COMMON_TESTS_FUNCTIONALTRAITTEST_HPP
