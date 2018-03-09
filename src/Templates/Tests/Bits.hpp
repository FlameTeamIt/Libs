#ifndef BITS_HPP
#define BITS_HPP

#include <tests/Test.hpp>

#include <Templates/Bits.hpp>

namespace flame_ide
{namespace test
{

class Bits: public AbstractTest
{
public:
	Bits();
	virtual ~Bits();

private:
	virtual int vStart();

	bool minimalType();
	bool arrayBits();
};

}}

#endif // BITS_HPP
