#ifndef TEST_STRING_HPP
#define TEST_STRING_HPP

#include <tests/Test.hpp>
#include <Templates/String.hpp>

namespace flame_ide
{namespace test
{

class String: public AbstractTest
{
public:
	String();
	virtual ~String();

	virtual int vStart();

private:
};

}}

#endif // TEST_STRING_HPP
