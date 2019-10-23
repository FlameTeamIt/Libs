#ifndef FLAMEIDE_TEMPLATES_TESTS_TESTCLASS_HPP
#define FLAMEIDE_TEMPLATES_TESTS_TESTCLASS_HPP

#include <iostream>

class TestClass
{
public:
	TestClass();
	TestClass(const TestClass &testClass);
	TestClass(TestClass &&testClass) noexcept;
	TestClass(long initL, int initI
			, short initS, char initC);
	~TestClass();
	TestClass &operator=(const TestClass &testClass);
	TestClass &operator=(TestClass &&testClass) noexcept;

	bool operator==(const TestClass &testClass) const;

	bool operator!=(const TestClass &testClass) const
	{
		return !operator==(testClass);
	}

	operator bool() const
	{
		return l && i && s && c;
	}

	long &getLong();
	const long &getLong() const;

	int &getInt();
	const int &getInt() const;

	short &getShort();
	const short &getShort() const;

	char &getChar();
	const char &getChar() const;

private:
	void clean();

	long *l;
	int *i;
	short *s;
	char *c;
};
std::iostream &operator<<(std::iostream &cout, const TestClass &obj);

#endif // FLAMEIDE_TEMPLATES_TESTS_TESTCLASS_HPP
