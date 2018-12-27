#ifndef TEST_WIDEINT_HPP
#define TEST_WIDEINT_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Templates/WideInt.hpp>

namespace flame_ide
{namespace test
{

class WideInt: public AbstractTest
{
public:
	WideInt();
	virtual ~WideInt() = default;

private:
	virtual int vStart();
};

}}

#endif // TEST_WIDEINT_HPP
