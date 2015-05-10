#include "Test.h"
#include <vector>
#include <iostream>

int main()
{
	flame_ide::Test test;
	test.all();
	
	std::cout << "pos_type = "
			  << sizeof(std::istream::pos_type)*8
			  << '\n';
	
	return 0;
}
