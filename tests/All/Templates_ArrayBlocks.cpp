#include <iostream>
#include <Templates/ArrayBlocks.h>
#include "../Test.h"

using namespace flame_ide::templates;

struct ArrayBlocksTest : public BaseTest<void>
{
	typedef ArrayBlocks<long> ArrayBlocks_long;
	
	ArrayBlocks_long empty_block;
	ArrayBlocks_long back_add_block;
	ArrayBlocks_long front_add_block;
	
	ArrayBlocksTest();
	ArrayBlocksTest(const ArrayBlocksTest &) = delete;
	ArrayBlocksTest(ArrayBlocksTest &&) = delete;
	
	~ArrayBlocksTest();
	
//--------------------------------------------------
	int all();
//--------------------------------------------------
	int constructs(ArrayBlocks_long &blocks);
//--------------------------------------------------
	int push_pop_back(ArrayBlocks_long &blocks);
	int push_pop_front(ArrayBlocks_long &blocks);
	
	int push_back(ArrayBlocks_long &blocks);
	int pop_back(ArrayBlocks_long &blocks);
	
	int push_front(ArrayBlocks_long &blocks);
	int pop_front(ArrayBlocks_long &blocks);
	
	int insert_erase(ArrayBlocks_long &blocks);
//--------------------------------------------------
	int indexing(ArrayBlocks_long &blocks);
//--------------------------------------------------
	int print_all(ArrayBlocks_long &blocks);
//--------------------------------------------------
};

int main()
{
	
	
//	std::cout << "\n"
//	             "--> Back adding blocks"
//	             "\n\n";
	
//	all(back_add_block);
	
//	std::cout << "\n"
//	             "--> Front adding blocks"
//	             "\n\n";
	
//	all(front_add_block);
	
	ArrayBlocksTest test;
	
	test.all();
	
	return 0;
}

//--------------------------------------------------

ArrayBlocksTest::ArrayBlocksTest()
	:
	  back_add_block(5)
	,front_add_block(true, 5)
{
	int test_number = 0;
	
	set_count_all_tests(10);
	
	/*  0 */ set_name_test(test_number++, std::string("cunstructs"));
	
	/*  1 */ set_name_test(test_number++, std::string("push_back"));
	/*  2 */ set_name_test(test_number++, std::string("pop_back"));
	
	/*  3 */ set_name_test(test_number++, std::string("push_front"));
	/*  4 */ set_name_test(test_number++, std::string("pop_front"));
	
	/*  5 */ set_name_test(test_number++, std::string("insert_erase"));
	/*  6 */ set_name_test(test_number++, std::string("indexing"));
	
	print_test_list();
}

ArrayBlocksTest::~ArrayBlocksTest() {}

//--------------------------------------------------
//--------------------------------------------------

int
ArrayBlocksTest::all()
{
	std::cout <<
	    "---------- ArrayBlocks test ----------"
	    "\n";
	
	this->print_start();
	
	this->push_back(back_add_block);
	this->pop_back(back_add_block);
	
	this->print_end();
	
	return 1;
}

//--------------------------------------------------

int
ArrayBlocksTest::constructs(ArrayBlocks_long &blocks)
{
	int test_number = 0;
	print_test_start(test_number);
	print_test_end(test_number);
	return 1;
}

//--------------------------------------------------
//--------------------------------------------------

int
ArrayBlocksTest::push_pop_back(ArrayBlocks_long &blocks)
{
	int test_number = 1;
	int return_code;
	
	print_test_start(test_number);
	set_current_test_number(test_number);
	
	long arr[] = {0,1,2,3,4,5,6,7,8};
	
	for(long i = 0; i < 8; ++i)
	{
		blocks.pushBack(arr[i]);
	}
	blocks.pushBack(8);
	
	std::cout << "Result (push):\n";
	print_all(blocks);
	if(is_equal(&arr[0], &arr[9], blocks.begin(), blocks.end()))
	{
		std::cout << "IS TRUE EQUAL\n";
		return_code = 1;
	}
	else
	{
		std::cout << "IS FALSE EQUAL\n";
		return_code = 0;
	}
	std::cout << '\n';
	
	front_add_block.popBack(2);
	front_add_block.popBack();
	
	std::cout << "Result (pop):\n";
	print_all(blocks);
	if(is_equal(&arr[0], &arr[5], blocks.begin(), blocks.end()))
	{
		std::cout << "IS TRUE EQUAL\n";
		return_code = 1;
	}
	else
	{
		std::cout << "IS FALSE EQUAL\n";
		return_code = 0;
	}
	
	
	if(return_code)
	{
		inc_count_failed_tests();
	}
	else
	{
		inc_count_success_tests();
	}
	
	set_current_test_return_code(return_code);
	set_test_return_code(test_number, return_code);
	print_test_end(test_number);
	
	return return_code;
}

//--------------------------------------------------

int
ArrayBlocksTest::push_back(ArrayBlocks_long &blocks)
{
	int test_number = 1;
	int return_code;
	
	test_start(test_number);
	
	long arr[] = {0,1,2,3,4,5,6,7,8};
	
	for(long i = 0; i < 8; ++i)
	{
		blocks.pushBack(arr[i]);
	}
	blocks.pushBack(8);
	
	std::cout << "Result (push):\n";
	print_all(blocks);
	if(is_equal(&arr[0], &arr[9], blocks.begin(), blocks.end()))
	{
		std::cout << "IS TRUE EQUAL\n";
		return_code = 0;
	}
	else
	{
		std::cout << "IS FALSE EQUAL\n";
		return_code = 1;
	}
	
	test_end(test_number, return_code);
	
	return return_code;
}

int
ArrayBlocksTest::pop_back(ArrayBlocks_long &blocks)
{
	int test_number = 2;
	int return_code;
	
	test_start(test_number);
	
	long arr[] = {0,1,2,3,4,5,6,7,8};
	
	front_add_block.popBack(2);
	front_add_block.popBack();
	
	std::cout << "Result (pop):\n";
	print_all(blocks);
	if(is_equal(&arr[0], &arr[5], blocks.begin(), blocks.end()))
	{
		std::cout << "IS TRUE EQUAL\n";
		return_code = 0;
	}
	else
	{
		std::cout << "IS FALSE EQUAL\n";
		return_code = 1;
	}
	
	test_end(test_number, return_code);
	
	return return_code;
}

//--------------------------------------------------


//--------------------------------------------------

int
ArrayBlocksTest::push_pop_front(ArrayBlocks_long &blocks)
{
	int test_number = 0;
	int return_code;
	
	test_start(test_number);
	test_end(test_number, return_code);
	return return_code;
}

int
ArrayBlocksTest::push_front(ArrayBlocks_long &blocks)
{
	int test_number = 0;
	int return_code;
	
	test_start(test_number);
	test_end(test_number, return_code);
	return return_code;
}

int
ArrayBlocksTest::pop_front(ArrayBlocks_long &blocks)
{
	int test_number = 0;
	int return_code;
	
	test_start(test_number);
	test_end(test_number, return_code);
	return return_code;
}

//--------------------------------------------------

int
ArrayBlocksTest::insert_erase(ArrayBlocks_long &blocks)
{
	int test_number = 0;
	int return_code;
	
	test_start(test_number);
	test_end(test_number, return_code);
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

int
ArrayBlocksTest::indexing(ArrayBlocks_long &blocks)
{
	int test_number = 0;
	int return_code;
	
	test_start(test_number);
	test_end(test_number, return_code);
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

int
ArrayBlocksTest::print_all(ArrayBlocks_long &blocks)
{
//	int test_number = 9;
	int return_code = 1;
	
//	test_start(test_number);
	for(auto it = blocks.begin(); it != blocks.end(); ++it)
	{
		std::cout << '\t' << *it << '\n';
	}
//	test_end(test_number, return_code);
	return return_code;
}

