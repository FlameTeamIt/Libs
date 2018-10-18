#ifndef TEST_LIST_HPP
#define TEST_LIST_HPP

#include <tests/Test.hpp>
#include <Templates/List.hpp>

#include "TestClass.hpp"

#include <list>

namespace flame_ide
{namespace test
{

class List: public AbstractTest
{
public:
	List();
	virtual ~List();

private:
	virtual int vStart();

	templates::List<TestClass> list;
	std::list<TestClass> stdlist;
};

}}

#endif // TEST_LIST_HPP
