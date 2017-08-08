/*
 * file:       TestClass.cpp
 *
 * created:    17.07.2017
 * author:     kachsheev
 */
#include "TestClass.hpp"

TestClass::TestClass() :
		l(new long(0))
		, i(new int(0))
		, s(new short(0))
		, c(new char(0))
{}

TestClass::TestClass(const TestClass &object) :
		l(new long(*object.l))
		, i(new int(*object.i))
		, s(new short(*object.s))
		, c(new char(*object.c))
{}

TestClass::TestClass(TestClass &&object) :
		l(object.l)
		, i(object.i)
		, s(object.s)
		, c(object.c)
{
	object.l = nullptr;
	object.i = nullptr;
	object.s = nullptr;
	object.c = nullptr;
}

TestClass::~TestClass()
{
	delete l;
	delete i;
	delete s;
	delete c;
}

TestClass &TestClass::operator=(const TestClass &object)
{
	*l = *object.l;
	*i = *object.i;
	*s = *object.s;
	*c = *object.c;

	return *this;
}

TestClass &TestClass::operator=(TestClass &&object)
{
	delete l;
	delete i;
	delete s;
	delete c;

	l = object.l;
	i = object.i;
	s = object.s;
	c = object.c;

	object.l = nullptr;
	object.i = nullptr;
	object.s = nullptr;
	object.c = nullptr;

	return *this;
}

long &TestClass::getLong()
{
	return *l;
}

const long &TestClass::getLong() const
{
	return *l;
}

int &TestClass::getInt()
{
	return *i;
}

const int &TestClass::getInt() const
{
	return *i;
}

short &TestClass::getShort()
{
	return *s;
}

const short &TestClass::getShort() const
{
	return *s;
}

char &TestClass::getChar()
{
	return *c;
}

const char &TestClass::getChar() const
{
	return *c;
}

