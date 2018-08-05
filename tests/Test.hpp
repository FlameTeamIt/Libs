#ifndef TEST_BASETEST_H
#define TEST_BASETEST_H

#include <string>
#include <vector>
#include <iostream>

#ifdef __linux
#include <Others/TextStyle.hpp>
#endif

#define log \
	std::cout << __PRETTY_FUNCTION__ << ":" << __LINE__ << ": "

class AbstractTest
{
public:
	AbstractTest() : testName("NONAME") {}
	AbstractTest(const AbstractTest &) = delete;
	AbstractTest(AbstractTest &&) = delete;

	AbstractTest(std::string const &name) : testName(name)
	{}
	AbstractTest(std::string &&name) : testName(name)
	{}
	AbstractTest(char const * nameCstr) : testName(nameCstr)
	{}

	virtual ~AbstractTest()
	{}

	int start()
	{
		int return_code;

		printStart();

		return_code = vStart();
		if (return_code)
			printMessageFalse();
		else
			printMessageTrue();

		printEnd();

		return return_code;
	}

protected:
	virtual int vStart() = 0;

private:
	void printStart()
	{
#if defined(__linux)
		std::cout << "> " TEXT_STYLE_BOLD TEXT_STYLE_CYAN "Start" TEXT_STYLE_NULL " " << testName << '\n';
#else
		std::cout << "> Start " << testName << '\n';
#endif
	}

	void printEnd()
	{
#if defined(__linux)
		std::cout << "> " TEXT_STYLE_BOLD TEXT_STYLE_CYAN "End" TEXT_STYLE_NULL " " << testName << "\n\n";
#else
		std::cout << "> End " << testName << "\n\n";
#endif
	}

	void printMessageTrue()
	{
#if defined(__linux)
		std::cout << "----> " TEXT_STYLE_BOLD TEXT_STYLE_GREEN "SUCCESS TEST\n" TEXT_STYLE_NULL;
#else
		std::cout << "----> SUCCESS TEST\n";
#endif
	}

	void printMessageFalse()
	{
#if defined(__linux)
		std::cout << "----> " TEXT_STYLE_BOLD TEXT_STYLE_RED "FAILED TEST\n" TEXT_STYLE_NULL;
#else
		std::cout << "----> FAILED TEST\n";
#endif
	}

	std::string testName;
};

class TestAggregator
{
public:
	TestAggregator() : aggregatorName("NONAME")
	{}
	TestAggregator(const TestAggregator &) = delete;
	TestAggregator(TestAggregator &&) = delete;

	TestAggregator(char const *nameCstr) : aggregatorName(nameCstr)
	{}
	TestAggregator(std::string const &name) : aggregatorName(name)
	{}
	TestAggregator(std::string &&name) : aggregatorName(name)
	{}

	virtual ~TestAggregator()
	{
		for (auto it : vectorTests)
			delete it;
	}

	void start()
	{
		printStart();
		vStart();
		printEnd();
	}

	void pushBackTest(AbstractTest *test, int is_enable=1)
	{
		vectorTests.push_back(test);
		vectorEnableTests.push_back(is_enable);
	}

	void printStatistic()
	{
		vPrintStatistic();
	}

protected:
	virtual void vStart()
	{
		for (auto it : vectorTests)
			vectorReturnCodes.push_back(it->start());
	}

	void printStart()
	{
#if defined(__linux)
		std::cout << TEXT_STYLE_BOLD TEXT_STYLE_YELLOW
				"-------------------- "
				TEXT_STYLE_NULL
				<< aggregatorName
				<< TEXT_STYLE_BOLD TEXT_STYLE_YELLOW
				" --------------------"
				TEXT_STYLE_NULL
				"\n";
#else
		std::cout << "-------------------- " << aggregatorName << " --------------------" "\n";
#endif
	}

	void printEnd()
	{
#if defined(__linux)
		std::cout << TEXT_STYLE_BOLD TEXT_STYLE_YELLOW
				"-------------------- "
				TEXT_STYLE_NULL
				"END"
				TEXT_STYLE_BOLD TEXT_STYLE_YELLOW
				" --------------------"
				TEXT_STYLE_NULL "\n\n";
#else
		std::cout << "-------------------- "
				"END"
				" --------------------"
				"\n\n";
#endif
	}

	virtual void vPrintStatistic() const
	{}

	std::string getName() const
	{
		return aggregatorName;
	}
	std::string& getName()
	{
		return aggregatorName;
	}

	void setName(const std::string &new_name)
	{
		aggregatorName = new_name;
	}
	void setName(std::string &&new_name)
	{
		aggregatorName = new_name;
	}

	std::vector<int> vectorReturnCodes;
	std::vector<int> vectorEnableTests;

private:
	std::string aggregatorName;
	std::vector<AbstractTest *> vectorTests;
};

#endif // TEST_BASETEST_H
