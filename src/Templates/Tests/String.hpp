#ifndef TEST_STRING_HPP
#define TEST_STRING_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/String.hpp>

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
	templates::String string;
	std::string stdstring;
};

}}

#endif // TEST_STRING_HPP
