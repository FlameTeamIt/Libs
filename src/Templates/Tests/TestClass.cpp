#include <FlameIDE/Templates/Allocator.hpp>

#include "TestClass.hpp"

using namespace flame_ide::templates::allocator;

TestClass::TestClass() :
		l(nullptr)
		, i(nullptr)
		, s(nullptr)
		, c(nullptr)
{}

TestClass::TestClass(const TestClass &object) :
		l(ObjectAllocator<long>().construct(object.getLong()))
		, i(ObjectAllocator<int>().construct(object.getInt()))
		, s(ObjectAllocator<short>().construct(object.getShort()))
		, c(ObjectAllocator<char>().construct(object.getChar()))
{}

TestClass::TestClass(TestClass &&object) noexcept :
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
	clean();
}

TestClass &TestClass::operator=(const TestClass &object)
{
	if (this != &object)
	{
		if (l)
			getLong() = object.getLong();
		else
			l = ObjectAllocator<long>().construct(object.getLong());

		if (i)
			getInt() = object.getInt();
		else
			i = ObjectAllocator<int>().construct(object.getInt());

		if (s)
			getShort() = object.getShort();
		else
			s = ObjectAllocator<short>().construct(object.getShort());

		if (c)
			getChar() = object.getChar();
		else
			c = ObjectAllocator<char>().construct(object.getChar());
	}
	return *this;
}

TestClass &TestClass::operator=(TestClass &&object) noexcept
{
	if (this != &object)
	{
		clean();

		l = object.l;
		i = object.i;
		s = object.s;
		c = object.c;

		object.l = nullptr;
		object.i = nullptr;
		object.s = nullptr;
		object.c = nullptr;
	}

	return *this;
}

bool TestClass::operator==(const TestClass &testClass) const
{
	return ((*this && testClass)
			? (this->getChar() == testClass.getChar()
					&& this->getShort() == testClass.getShort()
					&& this->getInt() == testClass.getInt()
					&& this->getLong() == testClass.getLong())
			: false);
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

void TestClass::clean()
{
	if (l)
	{
		ObjectAllocator<long>().destroy(l);
		l = nullptr;
	}
	if (i)
	{
		ObjectAllocator<int>().destroy(i);
		i = nullptr;
	}
	if (s)
	{
		ObjectAllocator<short>().destroy(s);
		s = nullptr;
	}
	if (c)
	{
		ObjectAllocator<char>().destroy(c);
		c = nullptr;
	}

}
