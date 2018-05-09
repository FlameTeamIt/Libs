#include <Templates/Tests/Allocator.hpp>
#include <Templates/Tests/Array.hpp>
#include <Templates/Tests/Bits.hpp>
#include <Templates/Tests/ByteOrder.hpp>
#include <Templates/Tests/List.hpp>
#include <Templates/Tests/SharedPointer.hpp>
#include <Templates/Tests/Serialization.hpp>
#include <Templates/Tests/String.hpp>
#include <Templates/Tests/Tuple.hpp>
#include <Templates/Tests/UniquePoiter.hpp>
#include <Templates/Tests/Vector.hpp>

#include <tests/Test.hpp>
#include <Templates/Tests/TestAggregator.hpp>

namespace flame_ide
{namespace templates
{

TestAggregator::TestAggregator() : ::TestAggregator("Templates")
{
	pushBackTest(new test::ObjectAllocator);
	pushBackTest(new test::ArrayAllocator);
	pushBackTest(new test::Array());
	pushBackTest(new test::Bits());
	pushBackTest(new test::ByteOrderTest());
	pushBackTest(new test::List());
	pushBackTest(new test::SharedPointer());
	pushBackTest(new test::Serialization());
	pushBackTest(new test::String());
	pushBackTest(new test::Tuple());
	pushBackTest(new test::UniquePointer());
	pushBackTest(new test::Vector());
}

}}