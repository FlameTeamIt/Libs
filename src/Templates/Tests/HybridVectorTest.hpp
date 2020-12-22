#ifndef FLAMEIDE_TEMPLATES_TESTS_HYBRIDVECTORTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_HYBRIDVECTORTEST_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/HybridVector.hpp>
#include "TestClass.hpp"

#include <array>
#include <vector>

namespace flame_ide
{namespace templates
{namespace test
{

class HybridVectorTest: public AbstractTest
{
public:
	using Me = HybridVectorTest;

	static constexpr Types::size_t ARRAY_SIZE = 10;

	HybridVectorTest();
	virtual ~HybridVectorTest();

private:
	virtual int vStart();

	bool iterators();
	bool container();
	bool containerAsArray();
	bool containerAsVector();

	bool fullTestAsArray();
	bool fullTestAsVector();

	bool hybridTest();

	using Array = flame_ide::templates::Array<Types::int_t, ARRAY_SIZE>;
	using array_t = std::array<Types::int_t, ARRAY_SIZE>;

	using Vector = flame_ide::templates::Vector<Types::int_t>;
	using vector_t = std::vector<Types::int_t>;

	using HybVector = flame_ide::templates::HybridVector<Types::int_t, ARRAY_SIZE>;
	using HybVectorIterator = HybVector::Iterator;
	using HybConstVectorIterator = HybVector::ConstIterator;
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTS_HYBRIDVECTORTEST_HPP
