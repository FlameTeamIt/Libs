#include <iostream>
#include <Templates/ArrayBlocks.h>
#include "../Test.h"

using namespace flame_ide::templates;

struct ArrayBlocksTest : public BaseTests<void>
{
	typedef ArrayBlocks<long> ArrayBlocks_long;
	
	ArrayBlocks_long empty_block;
	ArrayBlocks_long back_add_blocks;
	ArrayBlocks_long front_add_blocks;
	
	ArrayBlocksTest();
	ArrayBlocksTest(const ArrayBlocksTest &) = delete;
	ArrayBlocksTest(ArrayBlocksTest &&) = delete;
	
	~ArrayBlocksTest();
	
//--------------------------------------------------
	int all();
//--------------------------------------------------
	int constructs(ArrayBlocks_long &blocks);

	int push_back(ArrayBlocks_long &blocks);
	int pop_back(ArrayBlocks_long &blocks);
	
	int push_front(ArrayBlocks_long &blocks);
	int pop_front(ArrayBlocks_long &blocks);
	
	int insert(ArrayBlocks_long &blocks);
	int erase(ArrayBlocks_long &blocks);
	int clearing(ArrayBlocks_long &blocks);

	int indexing(ArrayBlocks_long &blocks);
//--------------------------------------------------
	int print_all(ArrayBlocks_long &blocks);
//--------------------------------------------------
};

int main()
{
	ArrayBlocksTest test;
	
	test.all();
	
	return 0;
}

//--------------------------------------------------

ArrayBlocksTest::ArrayBlocksTest()
	:
	  back_add_blocks(5)
	,front_add_blocks(true, 5)
{
	int test_number = 0;
	
	set_count_all_tests(7);
	
	/*  0 */ set_name_test(test_number++, std::string("cunstructs"));
	
	/*  1 */ set_name_test(test_number++, std::string("push_back"));
	/*  2 */ set_name_test(test_number++, std::string("pop_back"));
	
	/*  3 */ set_name_test(test_number++, std::string("push_front"));
	/*  4 */ set_name_test(test_number++, std::string("pop_front"));
	
	/*  5 */ set_name_test(test_number++, std::string("insert"));
	/*  6 */ set_name_test(test_number++, std::string("erase"));
	/*  7 */ set_name_test(test_number++, std::string("clearing"));
	
	/*  8 */ set_name_test(test_number++, std::string("indexing"));
	
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
	
	this->push_back(back_add_blocks);
	this->pop_back(back_add_blocks);
	
	this->push_front(back_add_blocks);
	this->pop_front(back_add_blocks);
	
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
	
	blocks.popBack(2);
	blocks.popBack();
	
	std::cout << "Result (pop):\n";
	print_all(blocks);
	if(is_equal(&arr[0], &arr[6], blocks.begin(), blocks.end()))
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
ArrayBlocksTest::push_front(ArrayBlocks_long &blocks)
{
	int test_number = 3;
	int return_code;
	
	test_start(test_number);
	
	long arr[] = {0,1,2,3,4,5,6,7,8};
	
	for(long i = 0; i < 8; ++i)
	{
		blocks.pushFront(arr[8-i]);
	}
	blocks.pushFront(0);
	
	std::cout << "Result (pop):\n";
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
ArrayBlocksTest::pop_front(ArrayBlocks_long &blocks)
{
	int test_number = 4;
	int return_code;
	
	test_start(test_number);
	
	long arr[] = {0,1,2,3,4,5,6,7,8};
	
	blocks.popFront(2);
	blocks.popFront();
	
	std::cout << "Result (pop):\n";
	print_all(blocks);
	if(is_equal(&arr[3], &arr[9], blocks.begin(), blocks.end()))
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

int
ArrayBlocksTest::insert(ArrayBlocks_long &blocks)
{
	int test_number = 5;
	int return_code;
	
	test_start(test_number);
	test_end(test_number, return_code);
	return return_code;
}

int
ArrayBlocksTest::erase(ArrayBlocks_long &blocks)
{
	int test_number = 6;
	int return_code;
	
	test_start(test_number);
	test_end(test_number, return_code);
	return return_code;
}

int
ArrayBlocksTest::clearing(ArrayBlocks_long &blocks)
{
	int test_number = 7;
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
	int test_number = 8;
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
	for(auto it = blocks.begin(); it != blocks.end(); ++it)
	{
		std::cout << '\t' << *it << '\n';
	}
	return 0;
}

