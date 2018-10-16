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

#define CHECK_RESULT(result) \
	if (ResultType::FAILED == result) return false

#define CHECK_RESULT_END(result) \
	if (ResultType::FAILED == result) return false; \
	else return true

#define IN_CASE_CHECK(condition) \
	if (!(result)) return ResultType::FAILED;

#define IN_CASE_CHECK_END(condition) \
	if (result) return ResultType::SUCCESS; \
	else return ResultType::FAILED;

class AbstractTest
{
public:
	enum ResultType
	{
		SUCCESS
		, FAILED
	};

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
		int resultCode = 0;

		printStart();
		printFinishMessage((resultCode = vStart()));
		printEnd();

		return resultCode;
	}

protected:
	virtual int vStart() = 0;

	enum MessageType
	{
		EMPTY
		, INFO
		, WARNING
		, ERROR
	};

	static void printMessage(MessageType messageType, const std::string &message)
	{
		printMessage(messageType, message.c_str());
	}

	static void printMessage(MessageType messageType, const char *message)
	{
		struct
		{
			const char *EMPTY = "";
			const char *INFO =
					"INFO"
					;

			const char *WARINIG =
					"WARINIG"
					;

			const char *ERROR =
					"ERROR"
					;
		} messageTypeTexts;

		const char *messageTypeText = [&messageTypeTexts](MessageType messageType) -> const char *
		{
			switch (messageType)
			{
				case MessageType::EMPTY:
				{
					return messageTypeTexts.EMPTY;
				}
				case MessageType::INFO:
				{
					return messageTypeTexts.INFO;
				}
				case MessageType::WARNING:
				{
					return messageTypeTexts.WARINIG;
				}
				case MessageType::ERROR:
				{
					return messageTypeTexts.ERROR;
				}
			}
		} (messageType);

		std::cout << messageTypeText << ": " << message << std::endl;
	}

	template<typename Function>
	ResultType doTestCase(const char *name, Function &&function)
	{
		ResultType status = ResultType::SUCCESS;
		std::cout << "--------> Case \"" << name << "\": " << std::endl;
		if (function() == ResultType::SUCCESS)
		{
			std::cout << "--------> "
			#if defined (__linux)
					TEXT_STYLE_BOLD TEXT_STYLE_GREEN
			#endif
					"Success"
			#if defined (__linux)
					TEXT_STYLE_NULL
			#endif
					<< std::endl << std::endl;
		}
		else
		{
			std::cout << "--------> "
			#if defined (__linux)
					TEXT_STYLE_BOLD TEXT_STYLE_RED
			#endif
					"Failed"
			#if defined (__linux)
					TEXT_STYLE_NULL
			#endif
					<< std::endl << std::endl;
			status = ResultType::FAILED;
		}
		return status;
	}

	template<typename Function>
	ResultType doTestCase(const std::string &name, Function &&function)
	{
		return doTestCase(name.c_str(), std::move(function));
	}

	template<typename Container1, typename Container2>
	bool compareContainers(Container1 &&container1, Container2 &&container2)
	{
		auto it1Begin = container1.begin();
		auto it1End = container1.end();
		auto it2Begin = container2.begin();
		auto it2End = container2.end();

		auto it1 = it1Begin;
		auto it2 = it2Begin;

		for (; it1 != it1End || it2 != it2End; ++it1, ++it2)
		{
			auto &v1 = *it1;
			auto &v2 = *it2;
			if (v1 != v2)
			{
				return ResultType::FAILED;
			}
		}
		return ResultType::SUCCESS;
	}

private:
	void printStart()
	{
#if defined(__linux)
		std::cout << "> " TEXT_STYLE_BOLD TEXT_STYLE_CYAN "Start" TEXT_STYLE_NULL " " << testName << std::endl << std::endl;
#else
		std::cout << "> Start " << testName << '\n';
#endif
	}

	void printEnd()
	{
#if defined(__linux)
		std::cout << "> " TEXT_STYLE_BOLD TEXT_STYLE_CYAN "End" TEXT_STYLE_NULL " " << testName << std::endl << std::endl;
#else
		std::cout << "> End " << testName << "\n\n";
#endif
	}

	void printTestSuccess()
	{
#if defined(__linux)
		std::cout << "----> " TEXT_STYLE_BOLD TEXT_STYLE_GREEN "SUCCESS TEST\n" TEXT_STYLE_NULL;
#else
		std::cout << "----> SUCCESS TEST\n";
#endif
	}

	void printTestFailed()
	{
#if defined(__linux)
		std::cout << "----> " TEXT_STYLE_BOLD TEXT_STYLE_RED "FAILED TEST\n" TEXT_STYLE_NULL;
#else
		std::cout << "----> FAILED TEST\n";
#endif
	}

	void printFinishMessage(int resultCode)
	{
		if (resultCode)
		{
			printTestFailed();
		}
		else
		{
			printTestSuccess();
		}
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

	void pushBackTest(AbstractTest *test, int is_enable = 1)
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
