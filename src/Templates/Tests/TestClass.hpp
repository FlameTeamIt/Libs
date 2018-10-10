#ifndef TEST_TESTCLASS_HPP
#define TEST_TESTCLASS_HPP

class TestClass
{
public:
	TestClass();
	TestClass(const TestClass &object);
	TestClass(TestClass &&object) noexcept;
	TestClass(long initL, int initI
			, short initS, char initC);
	~TestClass();
	TestClass &operator=(const TestClass &object);
	TestClass &operator=(TestClass &&object) noexcept;

	bool operator==(const TestClass &testClass) const
	{
		return this->getChar() == testClass.getChar()
				&& this->getShort() == testClass.getShort()
				&& this->getInt() == testClass.getInt()
				&& this->getLong() == testClass.getLong();
	}

	bool operator!=(const TestClass &testClass)
	{
		return !operator==(testClass);
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

#endif // TEST_TESTCLASS_HPP
