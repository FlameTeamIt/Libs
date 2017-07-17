#ifndef TEST_BASETEST_H
#define TEST_BASETEST_H

#include <string>
#include <vector>
#include <iostream>

#ifdef __linux
#include <Others/TextStyle.h>
#endif
//------------------------------------------------------------
//------------------------------------------------------------


template<typename T>
class AbstractTest
{
	std::string __name;
	
	void __print_start()
	{
#if defined(__linux)
		std::cout << "> " TEXT_STYLE_BOLD TEXT_STYLE_CYAN "Start" TEXT_STYLE_NULL " " << __name << '\n';
#else
		std::cout << "> Start " << __name << '\n';
#endif
	}

	void __print_end()
	{
#if defined(__linux)
		std::cout << "> " TEXT_STYLE_BOLD TEXT_STYLE_CYAN "End" TEXT_STYLE_NULL " " << __name << "\n\n";
#else
		std::cout << "> End " << __name << "\n\n";
#endif
	}
	
	void __print_message_true()
	{
#if defined(__linux)
		std::cout << "----> " TEXT_STYLE_BOLD TEXT_STYLE_GREEN "SUCCESS TEST\n" TEXT_STYLE_NULL;
#else
		std::cout << "----> SUCCESS TEST\n";
#endif
	}

	void __print_message_false()
	{
#if defined(__linux)
		std::cout << "----> " TEXT_STYLE_BOLD TEXT_STYLE_RED "FAILED TEST\n" TEXT_STYLE_NULL;
#else
		std::cout << "----> FAILED TEST\n";
#endif		
	}
	
protected:
	virtual int _start() = 0;
	
public:
	AbstractTest() : __name("Null test") {}
	AbstractTest(const AbstractTest &) = delete;
	AbstractTest(AbstractTest &&) = delete;
	
	AbstractTest(std::string const &  name) :  __name(name)       {}
	AbstractTest(std::string       && name) :  __name(name)       {}
	AbstractTest(char const * name_c_str)   :  __name(name_c_str) {}
	
	virtual ~AbstractTest() {}
	
	int start()
	{
		int return_code;
		
		__print_start();
		
		return_code = _start();
		if(return_code)
		{
			__print_message_false();
		}
		else
		{
			__print_message_true();
		}
		
		__print_end();
		
		return return_code;
	}
};
		

template<typename T>
class TestAggregator
{
	std::string __name;
	std::vector<AbstractTest<T> *> __v_vtests;
	
protected:
	std::vector<int> _v_return_codes;
	std::vector<int> _v_enable_tests;
	
	virtual void _start()
	{
		AbstractTest<T> *test;
		for(auto it = __v_vtests.begin(); it != __v_vtests.end(); ++it)
		{
			test = *it;
			_v_return_codes.push_back(test->start());
		}
	}
	
	void _print_start()
	{
#if defined(__linux)
		std::cout << TEXT_STYLE_BOLD TEXT_STYLE_YELLOW "-------------------- " TEXT_STYLE_NULL
				  << __name
				  << TEXT_STYLE_BOLD TEXT_STYLE_YELLOW " --------------------" TEXT_STYLE_NULL "\n";
#else
		std::cout << "-------------------- " << __name << " --------------------" "\n";
#endif
	}
					 
	void _print_end()
	{
#if defined(__linux)
		std::cout << TEXT_STYLE_BOLD TEXT_STYLE_YELLOW "-------------------- " TEXT_STYLE_NULL
					 "END"
					 TEXT_STYLE_BOLD TEXT_STYLE_YELLOW " --------------------" TEXT_STYLE_NULL "\n\n";
#else
		std::cout << "-------------------- "    "END"     " --------------------" "\n\n";
#endif
	}
	
	virtual void _print_statistic() const {}
	
	std::string  _get_name() const { return __name; }
	std::string& _get_name()	   { return __name; }
	
	void _set_name(const std::string  & new_name) { __name = new_name; }
	void _set_name(      std::string && new_name) { __name = new_name; }
	
public:
	TestAggregator() : __name("NONAME") { }
	TestAggregator(const TestAggregator<T> &) = delete;
	TestAggregator(TestAggregator<T> &&)      = delete;
	
	TestAggregator(char const * name_c_str)   :  __name(name_c_str) {}
	TestAggregator(std::string const &  name) :  __name(name)       {}
	TestAggregator(std::string       && name) :  __name(name)       {}
	
	~TestAggregator()
	{
		for(auto it : __v_vtests)
		{ delete it; }
	}
	
	void start()
	{
		_print_start();
		_start();
		_print_end();
	}
	
	void push_back_test(AbstractTest<T> *test, int is_enable=1)
	{
		__v_vtests.push_back(test);
		_v_enable_tests.push_back(is_enable);
	}
	
	void print_statistic()
	{
		_print_statistic();
	}
};

#endif // TEST_BASETEST_H
