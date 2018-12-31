#include <FlameIDE/../../src/Templates/Tests/Allocator.hpp>
#include <FlameIDE/../../src/Templates/Tests/Array.hpp>
#include <FlameIDE/../../src/Templates/Tests/Bits.hpp>
#include <FlameIDE/../../src/Templates/Tests/ByteOrder.hpp>
#include <FlameIDE/../../src/Templates/Tests/CircularVector.hpp>
#include <FlameIDE/../../src/Templates/Tests/List.hpp>
#include <FlameIDE/../../src/Templates/Tests/SharedPointer.hpp>
#include <FlameIDE/../../src/Templates/Tests/Serialization.hpp>
#include <FlameIDE/../../src/Templates/Tests/String.hpp>
#include <FlameIDE/../../src/Templates/Tests/Tuple.hpp>
#include <FlameIDE/../../src/Templates/Tests/UniquePoiter.hpp>
#include <FlameIDE/../../src/Templates/Tests/Variant.hpp>
#include <FlameIDE/../../src/Templates/Tests/Vector.hpp>
#include <FlameIDE/../../src/Templates/Tests/WideInt.hpp>
#include <FlameIDE/../../src/Templates/Tests/HybridVector.hpp>
#include <FlameIDE/../../src/Templates/Tests/IntegerIterator.hpp>

#include <FlameIDE/../../src/Templates/Tests/TestAggregator.hpp>

#include <tests/Test.hpp>

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
