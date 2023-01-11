#ifndef FLAMEIDE_COMMON_TESTS_UTILS_HPP
#define FLAMEIDE_COMMON_TESTS_UTILS_HPP

#include <FlameIDE/Common/Utils.hpp>

#include <tests/Test.hpp>

namespace flame_ide
{namespace common
{namespace tests
{

class Utils: public AbstractTest
{
public:
	Utils();
	virtual ~Utils();

private:
	virtual int vStart();

private:
	int length() noexcept;
};

}}}

#endif // FLAMEIDE_COMMON_TESTS_UTILS_HPP
