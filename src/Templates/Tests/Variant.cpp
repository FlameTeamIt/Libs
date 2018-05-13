#include "Variant.hpp"
#include "TestClass.hpp"

namespace flame_ide
{namespace test
{

Variant::Variant() : AbstractTest("Variant")
{}

Variant::~Variant()
{}

int Variant::vStart()
{
	if (!testVariantStruct())
	{
		return -1;
	}
	if (!testVariant())
	{
		return -1;
	}
	return 0;
}

bool Variant::testVariantStruct()
{
	using flame_ide::templates::variant_utils::VariantStruct;

	VariantStruct<int, TestClass> variantStrct;
	variantStrct.set(TestClass(1000L, 100, 10, '1'));

	return true;
}

bool Variant::testVariant()
{
	using flame_ide::templates::Variant;

	Variant<int, long> variant;
//	Variant<int, int> variant1; // static-assert works

	return true;
}

}}
