/*
 * file:       TestClass.hpp
 *
 * created:    17.07.2017
 * author:     kachsheev
 */
#ifndef TEST_TESTCLASS_HPP
#define TEST_TESTCLASS_HPP

class TestClass
{
public:
	TestClass();
	TestClass(const TestClass &object);
	TestClass(TestClass &&object);
	~TestClass();
	TestClass &operator=(const TestClass &object);
	TestClass &operator=(TestClass &&object);

	long &getLong();
	const long &getLong() const;

	int &getInt();
	const int &getInt() const;

	short &getShort();
	const short &getShort() const;

	char &getChar();
	const char &getChar() const;

private:
	long *l;
	int *i;
	short *s;
	char *c;
};

#endif // TEST_TESTCLASS_HPP
