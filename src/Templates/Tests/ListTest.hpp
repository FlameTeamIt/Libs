#ifndef FLAMEIDE_TEMPLATES_TESTS_LISTTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_LISTTEST_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/List.hpp>

#include "TestClass.hpp"

#include <list>

namespace flame_ide
{namespace test
{

class ListTest: public AbstractTest
{
public:
	ListTest();
	virtual ~ListTest();

private:
	virtual int vStart();

	templates::List<TestClass> list;
	std::list<TestClass> stdlist;
};

}}

#endif // FLAMEIDE_TEMPLATES_TESTS_LISTTEST_HPP
