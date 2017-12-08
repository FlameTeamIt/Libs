#include <Templates/Tests/Allocator.hpp>
#include <Templates/Tests/Array.hpp>
#include <Templates/Tests/Vector.hpp>
#include <Templates/Tests/List.hpp>
#include <Templates/Tests/SharedPointer.hpp>
#include <Templates/Tests/UniquePoiter.hpp>
#include <Templates/Tests/Tuple.hpp>
#include <Templates/Tests/String.hpp>

int main(int /*argc*/, char */*argv*/[])
{
	using namespace flame_ide::test;

	ArrayAllocator arrayAlloc;
	arrayAlloc.start();

	ObjectAllocator objectAlloc;
	objectAlloc.start();

	Array array;
	array.start();

	Vector vector;
	vector.start();

	List list;
	list.start();

	SharedPointer sharedPointer;
	sharedPointer.start();

	UniquePointer uniquePointer;
	uniquePointer.start();

	Tuple tuple;
	tuple.start();

	String string;
	string.start();

	return 0;
}

