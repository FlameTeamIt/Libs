#ifndef TEST_BASETEST_H
#define TEST_BASETEST_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include <FlameIDE/Others/TextStyle.hpp>

#define log \
	std::cout << __PRETTY_FUNCTION__ << ":" << __LINE__ << ": "

#define CHECK_RESULT_SUCCESS(result) \
	if (ResultType::FAILED == result) \
	{ \
		log << #result << std::endl; \
		return true; \
	}

#define CHECK_RESULT_SUCCESS_END(result) \
	if (ResultType::FAILED == result) \
	{ \
		log << #result << std::endl; \
		return true; \
	} \
	else \
	{ \
		return false; \
	}

#define IN_CASE_CHECK(condition) \
	if (!(condition)) \
	{ \
		log << #condition << std::endl; \
		return ResultType::FAILED; \
	}

#define IN_CASE_CHECK_END(condition) \
	if (condition) \
	{ \
		return ResultType::SUCCESS; \
	} \
	else \
	{ \
		log << #condition << std::endl; \
		return ResultType::FAILED; \
	}

#define IN_TEST_CHECK(condition) \
	if (!(condition)) \
	{\
		log << #condition << std::endl; \
		return 1; \
	}

#define IN_TEST_CHECK_END(condition) \
	if (!(condition)) \
	{ \
		log << #condition << std::endl; \
		return 1; \
	} \
	else \
	{ \
		return 0; \
	}

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

	const std::string &getName() const
	{
		return testName;
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
			const char *INFO = "INFO";
			const char *WARINIG = "WARINIG";
			const char *ERROR = "ERROR";
		} messageTypeTexts;

		const char *messageTypeText = [&messageTypeTexts](MessageType messageType)
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
	static ResultType doTestCase(const char *name, Function &&function)
	{
		ResultType status = ResultType::SUCCESS;
		std::cout << "----> "
				<< TEXT_STYLE_BOLD TEXT_STYLE_VIOLET
				<< "Case"
				<< TEXT_STYLE_NULL
				<< " \""
				<< name
				<< "\": "
				<< std::endl;
		if ((status = static_cast<ResultType>(function())) == ResultType::SUCCESS)
		{
			std::cout << "----> "
					<< TEXT_STYLE_BOLD TEXT_STYLE_GREEN
					<< "Success"
					<< TEXT_STYLE_NULL
					<< std::endl << std::endl;
		}
		else
		{
			std::cout << "----> "
					TEXT_STYLE_BOLD TEXT_STYLE_RED
					"Failed"
					TEXT_STYLE_NULL
					<< std::endl << std::endl;
		}
		return status;
	}

	template<typename Function>
	static ResultType doTestCase(const std::string &name, Function &&function)
	{
		return doTestCase(name.c_str(), std::move(function));
	}

	template<typename Container1, typename Container2>
	static ResultType compareContainers(Container1 &&container1, Container2 &&container2)
	{
		auto it1Begin = container1.begin();
		auto it1End = container1.end();
		auto it2Begin = container2.begin();
		auto it2End = container2.end();

		auto it1 = it1Begin;
		auto it2 = it2Begin;

		for (; it1 != it1End && it2 != it2End; ++it1, ++it2)
		{
			auto &v1 = *it1;
			auto &v2 = *it2;
			if (v1 != v2)
			{
				return ResultType::FAILED;
			}
		}
		if ((it1 != it1End && it2 == it2End)
				|| (it1 == it1End && it2 != it2End))
		{
			return ResultType::FAILED;
		}
		return ResultType::SUCCESS;
	}

	static void printTestSuccess()
	{
		std::cout << TEXT_STYLE_BOLD
				<< TEXT_STYLE_GREEN
				<< "SUCCESS TEST"
				<< TEXT_STYLE_NULL
				<< std::endl;
	}

	static void printTestFailed()
	{
		std::cout << TEXT_STYLE_BOLD
				<< TEXT_STYLE_RED
				<< "FAILED TEST"
				<< TEXT_STYLE_NULL
				<< std::endl;
	}

	static void printFinishMessage(int resultCode)
	{
		std::cout << "----> ";
		if (resultCode)
		{
			printTestFailed();
		}
		else
		{
			printTestSuccess();
		}
	}

private:
	void printStart()
	{
		std::cout << "> "
				<< TEXT_STYLE_BOLD TEXT_STYLE_CYAN
				<< "Start"
				<< TEXT_STYLE_NULL
				<< " "
				<< testName << std::endl;
	}

	void printEnd()
	{
		std::cout << "> "
				TEXT_STYLE_BOLD TEXT_STYLE_CYAN
				"End"
				TEXT_STYLE_NULL
				" "
				<< testName << std::endl;
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

	virtual ~TestAggregator() = default;

	void start()
	{
		printStart();
		vStart();
		printStatistic();
		printEnd();
	}

	void pushBackTest(const std::shared_ptr<AbstractTest> &test)
	{
		vectorTests.push_back(test);
	}

	void pushBackTest(std::shared_ptr<AbstractTest> &&test)
	{
		vectorTests.push_back(std::move(test));
	}

	void printStatistic()
	{
		printGlobalMessage(aggregatorName + " STATISTIC");
		vPrintStatistic();
	}

protected:
	virtual void vStart()
	{
		auto it = vectorTests.begin();
		for (; it != vectorTests.end(); ++it)
		{
			vectorReturnCodes.push_back((*it)->start());
			if (it != --vectorTests.end())
				std::cout << std::endl;
		}
	}

	void printGlobalMessage(const std::string &message)
	{
		printGlobalMessage(message.c_str());
	}

	void printGlobalMessage(const char *message)
	{
		std::cout << TEXT_STYLE_BOLD
				<< TEXT_STYLE_YELLOW
				<< "-------------------- "
				<< TEXT_STYLE_NULL
				<< message
				<< TEXT_STYLE_BOLD
				<< TEXT_STYLE_YELLOW
				<< " --------------------"
				<< TEXT_STYLE_NULL
				<< std::endl;

	}

	void printStart()
	{
		printGlobalMessage(aggregatorName + " START");
	}

	void printEnd()
	{
		printGlobalMessage(aggregatorName + " END");
	}

	virtual void vPrintStatistic() const
	{
		auto test = vectorTests.begin();
		auto code = vectorReturnCodes.begin();
		size_t countFailed = 0;
		size_t countSuccess = 0;

		for (; test != vectorTests.end() && code != vectorReturnCodes.end(); ++test, ++code)
		{
			std::cout << "Test \"" << (*test)->getName() << "\" : ";
			printStatus(*code);
			if (*code)
			{
				++countFailed;
			}
			else
			{
				++countSuccess;
			}
			std::cout << std::endl;
		}
		std::cout << TEXT_STYLE_BOLD
				<< TEXT_STYLE_VIOLET
				<< "Count tests"
				<< TEXT_STYLE_NULL
				<< ": "
				<< vectorTests.size() << std::endl;
		if (countSuccess)
		{
			std::cout << TEXT_STYLE_BOLD
					<< TEXT_STYLE_VIOLET
					<< "Count "
					<< TEXT_STYLE_NULL;
			printTestSuccess();
			std::cout << TEXT_STYLE_BOLD
					<< TEXT_STYLE_VIOLET
					<< " tests"
					<< TEXT_STYLE_NULL
					<< ": "
					<< countSuccess
					<< std::endl;
		}
		if (countFailed)
		{
			std::cout << TEXT_STYLE_BOLD
					<< TEXT_STYLE_VIOLET
					<< "Count "
					<< TEXT_STYLE_NULL;
			printTestFailed();
			std::cout << " tests: " << countFailed;
			std::cout << TEXT_STYLE_BOLD
					<< TEXT_STYLE_VIOLET
					<< " tests"
					<< TEXT_STYLE_NULL
					<< ": "
					<< countSuccess
					<< std::endl;
		}
	}

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

	static void printStatus(int resultCode)
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

	static void printTestSuccess()
	{
		std::cout << TEXT_STYLE_BOLD
				<< TEXT_STYLE_GREEN
				<< "SUCCESS"
				<< TEXT_STYLE_NULL;
	}

	static void printTestFailed()
	{
		std::cout << TEXT_STYLE_BOLD
				<< TEXT_STYLE_RED
				<< "FAILED"
				<< TEXT_STYLE_NULL;
	}

	std::string aggregatorName;
	std::vector<int> vectorReturnCodes;
	std::vector<std::shared_ptr<AbstractTest>> vectorTests;
};

#endif // TEST_BASETEST_H
