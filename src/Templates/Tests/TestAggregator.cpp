#include <FlameIDE/../../src/Templates/Tests/AllocatorTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/ArrayTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/BitsTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/ByteOrderTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/CircularVectorTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/ListTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/SharedPointerTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/SerializationTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/StringTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/TupleTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/UniquePoiterTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/VariantTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/VectorTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/WideIntTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/HybridVectorTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/IntegerIteratorTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/CircularIteratorTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/CircularArrayTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/AsIntegralTypeTest.hpp>
#include <FlameIDE/../../src/Templates/Tests/ExpectedTest.hpp>

#include <FlameIDE/../../src/Templates/Tests/TestAggregator.hpp>

#include <tests/Test.hpp>

namespace flame_ide
{namespace templates
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Templates")
{
	pushBackTest(std::make_shared<test::ObjectAllocatorTest>());
	pushBackTest(std::make_shared<test::ArrayAllocator>());
	pushBackTest(std::make_shared<test::ArrayTest>());
	pushBackTest(std::make_shared<test::BitsTest>());
	pushBackTest(std::make_shared<test::ByteOrderTest>());
	pushBackTest(std::make_shared<test::CircularVectorTest>());
	pushBackTest(std::make_shared<test::ListTest>());
	pushBackTest(std::make_shared<test::SharedPointerTest>());
	pushBackTest(std::make_shared<test::SerializationTest>());
	pushBackTest(std::make_shared<test::StringTest>());
	pushBackTest(std::make_shared<test::TupleTest>());
	pushBackTest(std::make_shared<test::UniquePointerTest>());
	pushBackTest(std::make_shared<test::VectorTest>());
	pushBackTest(std::make_shared<test::VariantTest>());
	pushBackTest(std::make_shared<test::WideIntTest>());
	pushBackTest(std::make_shared<test::HybridVectorTest>());
	pushBackTest(std::make_shared<test::IntegerIteratorTest>());
	pushBackTest(std::make_shared<test::CircularIteratorTest>());
	pushBackTest(std::make_shared<test::CircularArrayTest>());
	pushBackTest(std::make_shared<test::AsIntegralTypeTest>());
	pushBackTest(std::make_shared<test::ExpectedTest>());
}

}}}
