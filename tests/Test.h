#ifndef TEST_BASETEST_H
#define TEST_BASETEST_H

#include <string>
#include <vector>
#include <iostream>

template<typename T>
struct BaseTest
{
//------------------------------------------------------------
// Data
	
	int count_all_tests;
	int count_successed_tests;
	int count_failed_tests;
	
	std::vector<std::string> v_names_of_tests;
	std::vector<int> v_tests_return_codes;
	
	int current_test_number;
	int current_test_return_code;
	
//------------------------------------------------------------
	BaseTest();
	
	BaseTest(const BaseTest&) = delete;
	BaseTest(BaseTest&&) = delete;
	
	virtual ~BaseTest();
//------------------------------------------------------------
// Functions
	
	virtual int all() = 0;
	void print_start();
	void print_end();
	void print_test_start(int _number);
	void print_test_end(int _number);
	void print_test_list();
	
//------------------------------------------------------------
	void set_count_all_tests(int _count_all_tests);
	void set_count_successed_tests(int _count_success_tests);
	void set_count_failed_tests(int _count_fail_tests);
	
	int get_count_all_tests();
	int get_count_successed_tests();
	int get_count_failed_tests();
	
	void inc_count_success_tests();
	void inc_count_failed_tests();
//------------------------------------------------------------
	void set_name_test(int _number, std::string &&_name);
	void set_test_return_code(int _number, int _return_code);
	
	std::string get_name_test(int _number);
	int get_test_return_code(int _number);
//------------------------------------------------------------
	void set_current_test_number(int _number);
	void set_current_test_return_code(int _return_code);
	
	int get_current_test_number();
	int get_current_test_return_code();
//------------------------------------------------------------
	void test_start(int _number);
	void test_end(int _number, int _return_code);
//------------------------------------------------------------
};

//------------------------------------------------------------

template<typename T>
BaseTest<T>::BaseTest() {}

template<typename T>
BaseTest<T>::~BaseTest() {}

//------------------------------------------------------------

template<typename T>
void
BaseTest<T>::print_start() {std::cout << "-> Start test\n";}

template<typename T>
void
BaseTest<T>::print_end() {std::cout << "\n\n-> End test\n";}

template<typename T>
void
BaseTest<T>::print_test_start(int _number)
{ std::cout << "\n\n--> Start " << v_names_of_tests[_number] << "\n"; }

template<typename T>
void
BaseTest<T>::print_test_end(int _number)
{ std::cout << "--> End " << v_names_of_tests[_number] << "\n"; }

template<typename T>
void
BaseTest<T>::print_test_list()
{
	std::cout << "--> Print list of tests\n";
	for(int test_number = 0; test_number < this->get_count_all_tests(); ++test_number)
	{
		std::cout << test_number << " <-> " << this->get_name_test(test_number) << '\n';
	}
	std::cout << '\n';
}

//------------------------------------------------------------

template<typename T>
void
BaseTest<T>::set_count_all_tests(int _count_all_tests)
{
	this->count_all_tests = _count_all_tests;
	this->v_names_of_tests.resize(_count_all_tests);
	this->v_tests_return_codes.resize(_count_all_tests);
}

template<typename T>
void
BaseTest<T>::set_count_successed_tests(int _count_success_tests)
{
	this->count_successed_tests = _count_success_tests;
}

template<typename T>
void
BaseTest<T>::set_count_failed_tests(int _count_all_tests)
{
	this->count_failed_tests = _count_all_tests;
}



template<typename T>
int
BaseTest<T>::get_count_all_tests()
{
	return this->count_all_tests;
}

template<typename T>
int
BaseTest<T>::get_count_successed_tests()
{
	return this->count_successed_tests;
}

template<typename T>
int
BaseTest<T>::get_count_failed_tests()
{
	return this->count_failed_tests;
}



template<typename T>
void
BaseTest<T>::inc_count_success_tests()
{
	++this->count_successed_tests;
}

template<typename T>
void
BaseTest<T>::inc_count_failed_tests()
{
	++this->count_failed_tests;
}

//------------------------------------------------------------

template<typename T>
void
BaseTest<T>::set_name_test(int _number, std::string &&_name)
{
	v_names_of_tests[_number] = _name;
}

template<typename T>
void
BaseTest<T>::set_test_return_code(int _number, int _return_code)
{
	v_tests_return_codes[_number] = _return_code;
}



template<typename T>
std::string
BaseTest<T>::get_name_test(int _number)
{
	return *(v_names_of_tests.begin() + _number);
}

template<typename T>
int
BaseTest<T>::get_test_return_code(int _number)
{
	return *(v_tests_return_codes.begin() + _number);
}

//------------------------------------------------------------

template<typename T>
void
BaseTest<T>::set_current_test_number(int _number)
{
	this->current_test_number = _number;
}

template<typename T>
void
BaseTest<T>::set_current_test_return_code(int _return_code)
{
	this->current_test_return_code = _return_code;
}



template<typename T>
int
BaseTest<T>::get_current_test_number()
{
	return this->current_test_number;
}

template<typename T>
int
BaseTest<T>::get_current_test_return_code()
{
	return this->current_test_return_code;
}

//------------------------------------------------------------

template<typename T>
void
BaseTest<T>::test_start(int _number)
{
	print_test_start(_number);
	set_current_test_number(_number);
}

template<typename T>
void
BaseTest<T>::test_end(int _number, int _return_code)
{
	set_current_test_return_code(_return_code);
	set_test_return_code(_number, _return_code);
	if(_return_code)
	{
		inc_count_failed_tests();
		std::cout << "---> FAILED <---\n";
	}
	else
	{
		inc_count_success_tests();
		std::cout << "---> SUCCESS <---\n";
	}
	print_test_end(_number);
}

#endif // TEST_BASETEST_H
