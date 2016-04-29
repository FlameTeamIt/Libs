#ifndef TEST_BASETEST_H
#define TEST_BASETEST_H

#include <string>
#include <vector>
#include <iostream>

//------------------------------------------------------------
//------------------------------------------------------------


template<typename T>
class AbstractTest
{
	std::string _name;
	
	void _print_start()
	{
		std::cout << "--> Start " << _name << '\n';
	}

	void _print_end()
	{
		std::cout << "--> End " << _name << "\n\n";
	}

protected:
	virtual int _start() = 0;
	
public:
	AbstractTest() : _name("Null test") {}
	AbstractTest(const AbstractTest &) = delete;
	AbstractTest(AbstractTest &&) = delete;
	
	AbstractTest(std::string const &  name) :  _name(name)       {}
	AbstractTest(std::string       && name) :  _name(name)       {}
	AbstractTest(char const * name_c_str)   :  _name(name_c_str) {}
	
	virtual ~AbstractTest() {}
	
	int start()
	{
		int return_code;
		
		_print_start();
		return_code = _start();
		_print_end();
		
		return return_code;
	}
};
		

template<typename T>
class AbstractTestAggregator
{
	std::string _name;
	std::vector<AbstractTest<T> *> _v_vtests;
	
protected:
	std::vector<int> _v_return_codes;
	std::vector<int> _v_enable_tests;
	
	virtual void _start()
	{
		AbstractTest<T> *test;
		for(auto it = _v_vtests.begin(); it != _v_vtests.end(); ++it)
		{
			test = *it;
			_v_return_codes.push_back(test->start());
		}
	}
	
	void _print_start()
	{
		std::cout << "---------- " << _name << " ----------\n";
	}
					 
	void _print_end()
	{
		std::cout << "---------- " "END" " ----------" "\n\n";
	}
	
	virtual void _print_statistic() const {}
	
	std::string  _get_name() const { return _name; }
	std::string& _get_name()	   { return _name; }
	
	void _set_name(const std::string  & new_name) { _name = new_name; }
	void _set_name(      std::string && new_name) { _name = new_name; }
	
public:
	AbstractTestAggregator() : _name("NONAME") {}
	AbstractTestAggregator(const AbstractTestAggregator<T> &) = delete;
	AbstractTestAggregator(AbstractTestAggregator<T> &&)      = delete;
	
	AbstractTestAggregator(char const * name_c_str)   :  _name(name_c_str) {}
	AbstractTestAggregator(std::string const &  name) :  _name(name)       {}
	AbstractTestAggregator(std::string       && name) :  _name(name)       {}
	
	~AbstractTestAggregator()
	{
		for(auto it = _v_vtests.begin();
		    it != _v_vtests.end();
		    ++it)
		{ delete *it; }
	}
	
	void start()
	{
		_print_start();
		_start();
		_print_end();
	}
	
	void push_back_test(AbstractTest<T> *test, int is_enable=1)
	{
		_v_vtests.push_back(test);
		_v_enable_tests.push_back(is_enable);
	}
	
	void print_statistic()
	{
		_print_statistic();
	}
};

#endif // TEST_BASETEST_H
