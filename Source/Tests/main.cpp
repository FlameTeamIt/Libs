#include <iostream>
#include <About/About.h>
#include <Tests/Test.h>

int main(int argc, char** argv)
{
	
	std::cout << argc << ' ' << argv[0] << '\n';
	
	flame_ide::Test test;
	test.all();
	
	flame_ide::About about;
	
	std::cout << about.date << ' '
			  << about.time << '\n'
			  << "Build Number = " << about.buid_number << '\n';
	
	return 0;
}
