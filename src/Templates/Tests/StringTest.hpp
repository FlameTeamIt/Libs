#ifndef FLAMEIDE_TEMPLATES_TESTS_STRINGTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_STRINGTEST_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/String.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

class StringTest: public AbstractTest
{
public:
	StringTest();
	virtual ~StringTest();

	virtual int vStart();

private:
	templates::String string;
	std::string stdstring;
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTS_STRINGTEST_HPP
