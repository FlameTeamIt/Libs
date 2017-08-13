/*
 * file:       TestClass.cpp
 *
 * created:    17.07.2017
 * author:     kachsheev
 */
#include <Templates/Allocator.hpp>

#include "TestClass.hpp"

using namespace flame_ide::templates::allocator;

TestClass::TestClass() :
		l(ObjectAllocator<long>().construct(0))
		, i(ObjectAllocator<int>().construct(0))
		, s(ObjectAllocator<short>().construct(0))
		, c(ObjectAllocator<char>().construct(0))
{}

TestClass::TestClass(const TestClass &object) : TestClass()
{
	getLong() = object.getLong();
	getInt() = object.getInt();
	getShort() = object.getShort();
	getChar() = object.getChar();
}

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

TestClass::TestClass(long initL, int initI
		, short initS, char initC) :
		l(ObjectAllocator<long>().construct(initL))
		, i(ObjectAllocator<int>().construct(initI))
		, s(ObjectAllocator<short>().construct(initS))
		, c(ObjectAllocator<char>().construct(initC))
{}

TestClass::~TestClass()
{
	ObjectAllocator<long>().destruct(l);
	ObjectAllocator<int>().destruct(i);
	ObjectAllocator<short>().destruct(s);
	ObjectAllocator<char>().destruct(c);
}

TestClass &TestClass::operator=(const TestClass &object)
{
	getLong() = object.getLong();
	getInt() = object.getInt();
	getShort() = object.getShort();
	getChar() = object.getChar();

	return *this;
}

TestClass &TestClass::operator=(TestClass &&object)
{
	ObjectAllocator<long>().destruct(l);
	ObjectAllocator<int>().destruct(i);
	ObjectAllocator<short>().destruct(s);
	ObjectAllocator<char>().destruct(c);

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

