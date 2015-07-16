#include "Test.h"
#include <vector>
#include <iostream>

int main(unsigned int argc, char** argv)
{
	
	std::cout << argv[0] << '\n';
	
	flame_ide::Test test;
	test.all();
	
	std::cout << "pos_type = "
			  << sizeof(std::istream::pos_type)*8
			  << '\n';
	
	return 0;
}
