#ifndef FLAMEIDE_COMMON_TESTS_EXPECTEDTEST_HPP
#define FLAMEIDE_COMMON_TESTS_EXPECTEDTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace common
{namespace tests
{

class ExpectedTest: public ::AbstractTest
{
public:
	ExpectedTest() noexcept;
	~ExpectedTest() noexcept override;

private:
	int vStart() override;

	int noValue() noexcept;

	int errorPrimitiveCopy() noexcept;
	int resultPrimitiveCopy() noexcept;

	int errorPrimitiveMove() noexcept;
	int resultPrimitiveMove() noexcept;

	int errorNonPrimitiveCopy() noexcept;
	int resultNonPrimitiveCopy() noexcept;

	int errorNonPrimitiveMove() noexcept;
	int resultNonPrimitiveMove() noexcept;
};

}}} // namespace flame_ide::common::tests

#endif // FLAMEIDE_COMMON_TESTS_EXPECTEDTEST_HPP
