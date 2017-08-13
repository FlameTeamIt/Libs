#include <Templates/Tests/Allocator.hpp>
#include <Templates/Tests/Array.hpp>

void testAllocator()
{
	using namespace flame_ide::test;

	ArrayAllocator arrayAlloc;
	arrayAlloc.start();

	ObjectAllocator objectAlloc;
	objectAlloc.start();
}

void testArray()
{
	using namespace flame_ide::test;

	Array array;
	array.start();
}

int main(int /*argc*/, char */*argv*/[])
{
	testAllocator();
	testArray();
	return 0;
}

