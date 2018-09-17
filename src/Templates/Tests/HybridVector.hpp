#ifndef TEST_HYBRIDVECTOR_HPP
#define TEST_HYBRIDVECTOR_HPP

#include <tests/Test.hpp>
#include <Templates/HybridVector.hpp>
#include "TestClass.hpp"

namespace flame_ide
{namespace test
{

class HybridVector: public AbstractTest
{
public:
	using Me = HybridVector;

	HybridVector();
	virtual ~HybridVector();

private:
	virtual int vStart();

	bool iterators();

	using Array = flame_ide::templates::Array<Types::int_t, 4>;
	using Vector = flame_ide::templates::Vector<Types::int_t>;
	using HybVector = flame_ide::templates::HybridVector<Types::int_t, 4>;
	using HybVectorIterator = HybVector::Iterator;
	using HybConstVectorIterator = HybVector::ConstIterator;
};

}}

#endif // HYBRIDVECTOR_HPP
