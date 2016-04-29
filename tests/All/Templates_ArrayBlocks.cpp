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

arrblocks_constructs_empty::arrblocks_constructs_empty()
	: 
	  abstract_arrblocks_test<void>(__empty_blocks,
	                                "constructs_empty")
	  ,__empty_blocks() {}

arrblocks_constructs_back_adding::arrblocks_constructs_back_adding()
	:
	  abstract_arrblocks_test<void>(__back_adding_blocks,
	                                "constructs_back_adding")
	  ,__back_adding_blocks(5) {}

arrblocks_constructs_front_adding::arrblocks_constructs_front_adding()
	: 
	  
	  abstract_arrblocks_test<void>(__front_adding_blocks,
	                                "constructs_front_adding")
	  ,__front_adding_blocks(true, 5) {}

arrblocks_constructs_empty::~arrblocks_constructs_empty() {};
arrblocks_constructs_back_adding::~arrblocks_constructs_back_adding() {};
arrblocks_constructs_front_adding::~arrblocks_constructs_front_adding() {};



arrblocks_push_back::arrblocks_push_back(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "push_back") {}
arrblocks_pop_back::arrblocks_pop_back(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "pop_back") {}

arrblocks_push_back::~arrblocks_push_back() {}
arrblocks_pop_back::~arrblocks_pop_back() {}



arrblocks_push_front::arrblocks_push_front(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "push_front") {}
arrblocks_pop_front::arrblocks_pop_front(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "pop_front") {}

arrblocks_push_front::~arrblocks_push_front() {}
arrblocks_pop_front::~arrblocks_pop_front() {}



arrblocks_insert::arrblocks_insert(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "insert") {}
arrblocks_insert_range::arrblocks_insert_range(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "insert_range") {}

arrblocks_insert::~arrblocks_insert() {}
arrblocks_insert_range::~arrblocks_insert_range() {}



arrblocks_erase::arrblocks_erase(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "erase") {}
arrblocks_erase_range::arrblocks_erase_range(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "erase_range") {}

arrblocks_erase::~arrblocks_erase() {};
arrblocks_erase_range::~arrblocks_erase_range() {}


arrblocks_clearing::arrblocks_clearing(ArrayBlocks<long> &blocks)
	: abstract_arrblocks_test<void>(blocks, "clearing") {}

arrblocks_clearing::~arrblocks_clearing() {}

//--------------------------------------------------
//--------------------------------------------------

int
arrblocks_constructs_empty::_start()
{
	int return_code;
	
	if(this->_blocks.getSize() == DEF_DEFAULT_CAPACITY)
	{
		std::cout << "IS TRUE\n";
		return_code = 1;
	}
	else
	{
		std::cout << "IS FALSE\n";
		return_code = 0;
	}
	
	return return_code;
}

int
arrblocks_constructs_front_adding::_start()
{
	int return_code;
	
	if(_blocks.getSize() == 5
	   && _blocks.isFrontAdding())
	{
		std::cout << "IS TRUE\n";
		return_code = 1;
	}
	else
	{
		std::cout << "IS FALSE\n";
		return_code = 0;
	}
	
	return return_code;
}

int
arrblocks_constructs_back_adding::_start()
{
	int return_code;
	
	if(_blocks.getSize() == 5
	   && !_blocks.isFrontAdding())
	{
		std::cout << "IS TRUE\n";
		return_code = 1;
	}
	else
	{
		std::cout << "IS FALSE\n";
		return_code = 0;
	}
	
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

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

int
arrblocks_pop_back::_start()
{
	int return_code;
	
	long arr[] = {0,1,2,3,4,5,6,7,8};
	
	_blocks.popBack(2);
	_blocks.popBack();
	
	std::cout << "Result (pop):\n";
	print_all(_blocks);
	if(is_equal(&arr[0], &arr[6], _blocks.begin(), _blocks.end()))
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

int
arrblocks_push_front::_start()
{
	int return_code = 0;
	
	return return_code;
}

int
arrblocks_pop_front::_start()
{
	int return_code = 0;
	
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

int
arrblocks_insert::_start()
{
	int return_code = 0;
	
	return return_code;
}

int
arrblocks_insert_range::_start()
{
	int return_code = 0;
	
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

int
arrblocks_erase::_start()
{
	int return_code = 0;
	
	return return_code;
}

int
arrblocks_erase_range::_start()
{
	int return_code = 0;
	
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

int
arrblocks_clearing::_start()
{
	int return_code = 1;
	
	_blocks.clear();
	
	if(_blocks.getSize() == 0)
	{
		std::cout << "IS TRUE\n";
	}
	else
	{
		std::cout << "IS FALSE\n";
		return_code = 0;
	}
	
	return return_code;
}

//--------------------------------------------------
//--------------------------------------------------

int main()
{
	AbstractTestAggregator<void> test_aggregator_empty("Empty Array Blocks");
	AbstractTestAggregator<void> test_aggregator_front_add("Front-add Array Blocks");
	AbstractTestAggregator<void> test_aggregator_back_add( "Back-add Array Blocks");
	
	abstract_arrblocks_test<void> *tests_empty[10] =
	{
		new arrblocks_constructs_empty(),
		
		new arrblocks_push_back(tests_empty[0]->get_blocks()),
		new arrblocks_pop_back(tests_empty[0]->get_blocks()),
		
		new arrblocks_push_front(tests_empty[0]->get_blocks()),
		new arrblocks_pop_front(tests_empty[0]->get_blocks()),
		
		new arrblocks_insert(tests_empty[0]->get_blocks()),
		new arrblocks_erase(tests_empty[0]->get_blocks()),
		
		new arrblocks_insert_range(tests_empty[0]->get_blocks()),
		new arrblocks_erase_range(tests_empty[0]->get_blocks()),
		
		new arrblocks_clearing(tests_empty[0]->get_blocks()),
	};
	
	for(unsigned int i = 0; i < 10; ++i)
	{ test_aggregator_empty.push_back_test(tests_empty[i]); }
	test_aggregator_empty.start();
	
	
	abstract_arrblocks_test<void> *tests_front_add[10] =
	{
		new arrblocks_constructs_front_adding(),
		
		new arrblocks_push_back(tests_front_add[0]->get_blocks()),
		new arrblocks_pop_back(tests_front_add[0]->get_blocks()),
		
		new arrblocks_push_front(tests_front_add[0]->get_blocks()),
		new arrblocks_pop_front(tests_front_add[0]->get_blocks()),
		
		new arrblocks_insert(tests_front_add[0]->get_blocks()),
		new arrblocks_erase(tests_front_add[0]->get_blocks()),
		
		new arrblocks_insert_range(tests_front_add[0]->get_blocks()),
		new arrblocks_erase_range(tests_front_add[0]->get_blocks()),
		
		new arrblocks_clearing(tests_front_add[0]->get_blocks()),
	};
	
	for(unsigned int i = 0; i < 10; ++i)
	{ test_aggregator_front_add.push_back_test(tests_front_add[i]); }
	test_aggregator_front_add.start();
	
	
	abstract_arrblocks_test<void> *tests_back_add[10] =
	{
		new arrblocks_constructs_front_adding(),
		
		new arrblocks_push_back(tests_back_add[0]->get_blocks()),
		new arrblocks_pop_back(tests_back_add[0]->get_blocks()),
		
		new arrblocks_push_front(tests_back_add[0]->get_blocks()),
		new arrblocks_pop_front(tests_back_add[0]->get_blocks()),
		
		new arrblocks_insert(tests_back_add[0]->get_blocks()),
		new arrblocks_erase(tests_back_add[0]->get_blocks()),
		
		new arrblocks_insert_range(tests_back_add[0]->get_blocks()),
		new arrblocks_erase_range(tests_back_add[0]->get_blocks()),
		
		new arrblocks_clearing(tests_back_add[0]->get_blocks()),
	};
	
	for(unsigned int i = 0; i < 10; ++i)
	{ test_aggregator_back_add.push_back_test(tests_back_add[i]); }
	test_aggregator_back_add.start();
	
	return 0;
}

//--------------------------------------------------
