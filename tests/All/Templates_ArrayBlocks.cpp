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

test_arrblocks_constructs_empty::test_arrblocks_constructs_empty()
	: 
	  abstract_arrblocks_test<void>(__empty_blocks,
	                                "constructs_empty")
	  ,__empty_blocks() {}

test_arrblocks_constructs_back_adding::test_arrblocks_constructs_back_adding()
	:
	  abstract_arrblocks_test<void>(__back_adding_blocks,
	                                "constructs_back_adding")
	  ,__back_adding_blocks(5) {}

test_arrblocks_constructs_front_adding::test_arrblocks_constructs_front_adding()
	: 
	  
	  abstract_arrblocks_test<void>(__front_adding_blocks,
	                                "constructs_front_adding")
	  ,__front_adding_blocks(true, 5) {}

test_arrblocks_constructs_empty::~test_arrblocks_constructs_empty() {};
test_arrblocks_constructs_back_adding::~test_arrblocks_constructs_back_adding() {};
test_arrblocks_constructs_front_adding::~test_arrblocks_constructs_front_adding() {};



test_arrblocks_push_back::test_arrblocks_push_back(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "push_back") {}
test_arrblocks_pop_back::test_arrblocks_pop_back(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "pop_back") {}

test_arrblocks_push_back::~test_arrblocks_push_back() {}
test_arrblocks_pop_back::~test_arrblocks_pop_back() {}



test_arrblocks_push_front::test_arrblocks_push_front(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "push_front") {}
test_arrblocks_pop_front::test_arrblocks_pop_front(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "pop_front") {}

test_arrblocks_push_front::~test_arrblocks_push_front() {}
test_arrblocks_pop_front::~test_arrblocks_pop_front() {}



test_arrblocks_insert::test_arrblocks_insert(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "insert") {}
arrblocks_insert_range::arrblocks_insert_range(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "insert_range") {}

test_arrblocks_insert::~test_arrblocks_insert() {}
arrblocks_insert_range::~arrblocks_insert_range() {}



test_arrblocks_erase::test_arrblocks_erase(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "erase") {}
test_arrblocks_erase_range::test_arrblocks_erase_range(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "erase_range") {}

test_arrblocks_erase::~test_arrblocks_erase() {};
test_arrblocks_erase_range::~test_arrblocks_erase_range() {}


test_arrblocks_clearing::test_arrblocks_clearing(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "clearing") {}

test_arrblocks_clearing::~test_arrblocks_clearing() {}

//--------------------------------------------------
//--------------------------------------------------

int
test_arrblocks_constructs_empty::_start()
{
	int return_code;
	
	if(this->_blocks.getCapacity() == DEF_DEFAULT_CAPACITY)
	{
		return_code = 0;
	}
	else
	{
		return_code = 1;
	}
	
	return return_code;
}

int
test_arrblocks_constructs_front_adding::_start()
{
	int return_code;
	
	if(_blocks.getCapacity() == 5
	   && _blocks.isFrontAdding())
	{
		return_code = 0;
	}
	else
	{
		return_code = 1;
	}
	
	return return_code;
}

int
test_arrblocks_constructs_back_adding::_start()
{
	int return_code;
	
	if(_blocks.getCapacity() == 5
	   && !_blocks.isFrontAdding())
	{
		return_code = 0;
	}
	else
	{
		return_code = 1;
	}
	
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

int
test_arrblocks_push_back::_start()
{
	int return_code;
	long arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	
	for(long i = 0; i < 8; ++i)
	{
		_blocks.pushBack(arr[i]);
	}
	_blocks.pushBack(8);
	
	std::cout << "Result (pushBack):\n";
	print_all(_blocks);
	if(is_equal(&arr[0], &arr[9], _blocks.begin(), _blocks.end()))
	{
		return_code = 0;
	}
	else
	{
		return_code = 1;
	}
	return return_code;
}

int
test_arrblocks_pop_back::_start()
{
	int return_code;
	
	long arr[] = {0, 1, 2, 3, 4, 5};
	
	_blocks.popBack(2);
	_blocks.popBack();
	
	std::cout << "Result (popBack):\n";
	print_all(_blocks);
	if(is_equal(&arr[0], &arr[6], _blocks.begin(), _blocks.end()))
	{
		return_code = 0;
	}
	else
	{
		return_code = 1;
	}
	
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

int
test_arrblocks_push_front::_start()
{
	int return_code;
	
	long arr[] = {8, 7, 6, 5, 4, 3, 2, 1,
	              0, 1, 2, 3, 4, 5};
	
	for(long i = 0; i < 7; ++i)
	{
		_blocks.pushFront(arr[7 - i]);
	}
	_blocks.pushFront(8);
	
	std::cout << "Result (pushFront):\n";
	print_all(_blocks);
	if(is_equal(&arr[0], &arr[14], _blocks.begin(), _blocks.end()))
	{
		return_code = 0;
	}
	else
	{
		return_code = 1;
	}
	return return_code;
}

int
test_arrblocks_pop_front::_start()
{
	int return_code;
	
	long arr[] = {/*8, 7, 6, */
	              5, 4, 3, 2, 1,
	              0, 1, 2, 3, 4, 5};
	
	_blocks.popFront();
	_blocks.popFront(2);
	
	std::cout << "Result (popFront):\n";
	print_all(_blocks);
	if(is_equal(&arr[0], &arr[11], _blocks.begin(), _blocks.end()))
	{
		return_code = 0;
	}
	else
	{
		return_code = 1;
	}
	
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

int
test_arrblocks_insert::_start()
{
	int return_code = 1;
	
//	long arr[] = {5, 4, 3, 2, 1,
//	              0, 1, 2, 3, 4, 5};
	long arr[] = {5, -105, 4, -104, 3, -103, 2, -102, 1, -101,
	              0, -100, 1, -101, 2, -102, 3, -101, 4, -104, 5 -105};
	
	for(auto it = _blocks.begin(); it != _blocks.end(); ++it)
	{
		if(*it >= 0)
		{
			_blocks.insert(it, -100 - *it);
		}
	}
	std::cout << "Result (insert):\n";
	print_all(_blocks);
	if(is_equal(&arr[0], &arr[22], _blocks.begin(), _blocks.end()))
	{
		return_code = 0;
	}
	else
	{
		return_code = 1;
	}
	
	
	return return_code;
}

int
arrblocks_insert_range::_start()
{
	int return_code = 1;
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

int
test_arrblocks_erase::_start()
{
	int return_code = 1;
	long arr[] = {5, 4, 3, 2, 1,
	              0, 1, 2, 3, 4, 5};
		
	for(auto it = _blocks.begin(); it != _blocks.end(); ++it)
	{
		if(*it < 0)
		{
			_blocks.erase(it);
			it = _blocks.begin();
		}
	}
	std::cout << "Result (erase):\n";
	print_all(_blocks);
	if(is_equal(&arr[0], &arr[11], _blocks.begin(), _blocks.end()))
	{
		return_code = 0;
	}
	else
	{
		return_code = 1;
	}
	return return_code;
}

int
test_arrblocks_erase_range::_start()
{
	int return_code = 1;
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

int
test_arrblocks_clearing::_start()
{
	int return_code;
	
	_blocks.clear();
	auto blocks_size = _blocks.getSize();
	
	if(blocks_size == 0)
	{
		return_code = 0;
	}
	else
	{
		return_code = 1;
	}
	
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

int main()
{
	TestAggregator<void> test_aggregator_empty("Empty Array Blocks");
	TestAggregator<void> test_aggregator_front_add("Front-add Array Blocks");
	TestAggregator<void> test_aggregator_back_add( "Back-add Array Blocks");
	
	auto init_and_start_tests =
	+[](TestAggregator<void> &test_aggregator, int type)
	{
		abstract_arrblocks_test<void> *tests[10];
		switch (type)
		{
		case 1:
			tests[0] = new test_arrblocks_constructs_empty();
			break;
		case 2:
			tests[0] = new test_arrblocks_constructs_front_adding();
			break;
		case 3:
			tests[0] = new test_arrblocks_constructs_back_adding();
			break;
		default:
			return;
		}
		
		tests[1] = new test_arrblocks_push_back(tests[0]->get_blocks());
		tests[2] = new test_arrblocks_pop_back(tests[0]->get_blocks());
		
		tests[3] = new test_arrblocks_push_front(tests[0]->get_blocks());
		tests[4] = new test_arrblocks_pop_front(tests[0]->get_blocks());
		
		tests[5] = new test_arrblocks_insert(tests[0]->get_blocks());
		tests[6] = new test_arrblocks_erase(tests[0]->get_blocks());
		
		tests[7] = new arrblocks_insert_range(tests[0]->get_blocks());
		tests[8] = new test_arrblocks_erase_range(tests[0]->get_blocks());
		
		tests[9] = new test_arrblocks_clearing(tests[0]->get_blocks());
		
		for(unsigned int i = 0; i < 10; ++i)
		{ test_aggregator.push_back_test(tests[i]); }
		test_aggregator.start();
	};
	
	init_and_start_tests(test_aggregator_empty,     1);
//	init_and_start_tests(test_aggregator_front_add, 2);
//	init_and_start_tests(test_aggregator_back_add,  3);
	
	return 0;
}

//--------------------------------------------------
