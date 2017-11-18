#include <Templates/Tests/Allocator.hpp>
#include <Templates/Tests/Array.hpp>
#include <Templates/Tests/Vector.hpp>
#include <Templates/Tests/List.hpp>
#include <Templates/Tests/SharedPointer.hpp>
#include <Templates/Tests/UniquePoiter.hpp>
#include <Templates/Tests/Tuple.hpp>

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

	Vector vector;
	vector.start();
}

void testList()
{
	using namespace flame_ide::test;

	List list;
	list.start();
}

void testPointers()
{
	using namespace flame_ide::test;

	SharedPointer sharedPointer;
	sharedPointer.start();

	UniquePointer uniquePointer;
	uniquePointer.start();
}

void testTuple()
{
	using namespace flame_ide::test;

	Tuple tuple;
	tuple.start();
}

int main(int /*argc*/, char */*argv*/[])
{
	testAllocator();
	testArray();
	testList();
	testPointers();
	testTuple();
	return 0;
}

