#include <Templates/Tests/Allocator.hpp>
#include <Templates/Tests/Array.hpp>
#include <Templates/Tests/Bits.hpp>
#include <Templates/Tests/ByteOrder.hpp>
#include <Templates/Tests/CircularVector.hpp>
#include <Templates/Tests/List.hpp>
#include <Templates/Tests/SharedPointer.hpp>
#include <Templates/Tests/Serialization.hpp>
#include <Templates/Tests/String.hpp>
#include <Templates/Tests/Tuple.hpp>
#include <Templates/Tests/UniquePoiter.hpp>
#include <Templates/Tests/Variant.hpp>
#include <Templates/Tests/Vector.hpp>
#include <Templates/Tests/WideInt.hpp>
#include <Templates/Tests/HybridVector.hpp>
#include <Templates/Tests/IntegerIterator.hpp>

#include <tests/Test.hpp>
#include <Templates/Tests/TestAggregator.hpp>

namespace flame_ide
{namespace templates
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Templates")
{
	pushBackTest(std::make_shared<test::ObjectAllocator>());
	pushBackTest(std::make_shared<test::ArrayAllocator>());
	pushBackTest(std::make_shared<test::Array>());
	pushBackTest(std::make_shared<test::Bits>());
	pushBackTest(std::make_shared<test::ByteOrderTest>());
	pushBackTest(std::make_shared<test::CircularVector>());
	pushBackTest(std::make_shared<test::List>());
	pushBackTest(std::make_shared<test::SharedPointer>());
	pushBackTest(std::make_shared<test::Serialization>());
	pushBackTest(std::make_shared<test::String>());
	pushBackTest(std::make_shared<test::Tuple>());
	pushBackTest(std::make_shared<test::UniquePointer>());
	pushBackTest(std::make_shared<test::Vector>());
	pushBackTest(std::make_shared<test::Variant>());
	pushBackTest(std::make_shared<test::WideInt>());
	pushBackTest(std::make_shared<test::HybridVector>());
	pushBackTest(std::make_shared<test::IntegerIterator>());
}

}}}
