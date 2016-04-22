#include <iostream>
#include <Templates/ArrayBlocks.h>
#include "../Test.h"
#include "Templates_ArrayBlocks.h"

using namespace flame_ide::templates;

void
print_all(ArrayBlocks<long> &blocks)
{
	for(auto it = blocks.begin(); it != blocks.end(); ++it)
	{
		std::cout << '\t' << *it << '\n';
	}
}

arrblocks_constructs_empty::arrblocks_constructs_empty(
		ArrayBlocks<long> &blocks)
	: virtual_arrblocks_test<void>(blocks, "constructs_empty") {}
arrblocks_constructs_back_adding::arrblocks_constructs_back_adding(
		ArrayBlocks<long> &blocks)
	: virtual_arrblocks_test<void>(blocks, "constructs_back_adding") {}
arrblocks_constructs_front_adding::arrblocks_constructs_front_adding(
		ArrayBlocks<long> &blocks)
	: virtual_arrblocks_test<void>(blocks, "constructs_front_adding") {}


arrblocks_push_back::arrblocks_push_back(ArrayBlocks<long> &blocks)
	: virtual_arrblocks_test<void>(blocks, "push_back") {}
arrblocks_pop_back::arrblocks_pop_back(ArrayBlocks<long> &blocks)
	: virtual_arrblocks_test<void>(blocks, "pop_back") {}


arrblocks_push_front::arrblocks_push_front(ArrayBlocks<long> &blocks)
	: virtual_arrblocks_test<void>(blocks, "push_front") {}
arrblocks_pop_front::arrblocks_pop_front(ArrayBlocks<long> &blocks)
	: virtual_arrblocks_test<void>(blocks, "pop_front") {}


arrblocks_insert::arrblocks_insert(ArrayBlocks<long> &blocks)
	: virtual_arrblocks_test<void>(blocks, "insert") {}
arrblocks_insert_range::arrblocks_insert_range(ArrayBlocks<long> &blocks)
	: virtual_arrblocks_test<void>(blocks, "insert_range") {}


arrblocks_erase::arrblocks_erase(ArrayBlocks<long> &blocks)
	: virtual_arrblocks_test<void>(blocks, "erase") {}
arrblocks_erase_range::arrblocks_erase_range(ArrayBlocks<long> &blocks)
	: virtual_arrblocks_test<void>(blocks, "erase_range") {}




int
arrblocks_push_back::_start()
{
	int return_code;
	long arr[] = {0,1,2,3,4,5,6,7,8};
	
	for(long i = 0; i < 8; ++i)
	{
		_blocks.pushBack(arr[i]);
	}
	_blocks.pushBack(8);
	
	std::cout << "Result (push):\n";
	print_all(_blocks);
	if(is_equal(&arr[0], &arr[9], _blocks.begin(), _blocks.end()))
	{
		std::cout << "IS TRUE EQUAL\n";
		return_code = 0;
	}
	else
	{
		std::cout << "IS FALSE EQUAL\n";
		return_code = 1;
	}
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

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
//	ArrayBlocksTest test;
	
//	test.all();
	
	typedef ArrayBlocks<long> ArrayBlocks_long;
	
//	ArrayBlocks_long empty_block;
	ArrayBlocks<long> back_add_blocks(5);
//	ArrayBlocks_long front_add_blocks(true, 5);
	
	arrblocks_push_back test_push_back(back_add_blocks);
	test_push_back.start();
	
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


//--------------------------------------------------
//--------------------------------------------------
