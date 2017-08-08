#include <Templates/Tests/Allocator.hpp>

int main(int /*argc*/, char */*argv*/[])
{
	using namespace flame_ide::test;
	using namespace flame_ide::templates;

	ArrayAllocator arrayAlloc;
	ObjectAllocator objectAlloc;

	arrayAlloc.start();
	objectAlloc.start();

	int *p = (int *) malloc(sizeof(int));
	int i = 10;
	const int &ri = i;
	placementNew<int>(p, ri);

	return 0;
}

