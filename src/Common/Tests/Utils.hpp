#ifndef COMMON_TESTS_UTILS_HPP
#define COMMON_TESTS_UTILS_HPP

#include <Common/Utils.hpp>

#include <tests/Test.hpp>

namespace flame_ide
{namespace tests
{

class Utils: public AbstractTest
{
public:
	Utils();
	virtual ~Utils();

private:
	virtual int vStart();
};

}}

#endif // COMMON_TESTS_UTILS_HPP
