#include <iostream>
#include <Templates/ArrayBlocks.h>

using namespace flame_ide::templates;

//--------------------------------------------------
template<typename T>
int all(ArrayBlocks<T> &blocks);
//--------------------------------------------------
template<typename T>
int constructs(ArrayBlocks<T> &blocks);
//--------------------------------------------------
template<typename T>
int push_pop_back(ArrayBlocks<T> &blocks);
template<typename T>
int push_pop_front(ArrayBlocks<T> &blocks);
template<typename T>
int insert_erase(ArrayBlocks<T> &blocks);
//--------------------------------------------------
template<typename T>
int indexing(ArrayBlocks<T> &blocks);
//--------------------------------------------------
template<typename T>
int print_all(ArrayBlocks<T> &blocks);
//--------------------------------------------------


int main()
{
	std::cout <<
	    "---------- ArrayBlocks test ----------"
	    "\n"
	
	ArrayBlocks<long> empty_block;
	ArrayBlocks<long> back_add_block(6);
	ArrayBlocks<long> front_add_block(true, 6);
	
	std::cout << "\n"
	             "--> Back adding blocks"
	             "\n\n";
	
	all(back_add_block);
	
	std::cout << "\n"
	             "--> Front adding blocks"
	             "\n\n";
	
	all(front_add_block);
	
	return 0;
}


//--------------------------------------------------
template<typename T>
int all(ArrayBlocks<T> &blocks)
{
	int sum_return_codes = 0, current_return_code;
	
	
	std::cout << " push_pop_back return code ->"
	          <<   push_pop_back(blocks);
	std::cout << "push_pop_front return code ->"
	          <<  push_pop_front(blocks);
	std::cout << "  insert_erase return code ->"
	          <<  insert_erase(blocks);
	
	std::cout << "      indexing return code ->"
	          <<        indexing(blocks);
	
	std::cout << print_all(blocks);
	return 1;
}

//--------------------------------------------------
//--------------------------------------------------
template<typename T>
int constructs(ArrayBlocks<T> &blocks)
{
	return 1;
}
//--------------------------------------------------
//--------------------------------------------------
template<typename T>
int push_pop_back(ArrayBlocks<T> &blocks)
{
	return 1;
}
//--------------------------------------------------
template<typename T>
int push_pop_front(ArrayBlocks<T> &blocks)
{
	return 1;
}
//--------------------------------------------------
template<typename T>
int insert_erase(ArrayBlocks<T> &blocks)
{
	return 1;
}
//--------------------------------------------------
//--------------------------------------------------
template<typename T>
int indexing(ArrayBlocks<T> &blocks)
{
	return 1;
}
//--------------------------------------------------
//--------------------------------------------------
template<typename T>
int print_all(ArrayBlocks<T> &blocks)
{
	return 1;
}

