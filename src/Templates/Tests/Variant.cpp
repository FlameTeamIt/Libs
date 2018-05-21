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
	VariantStruct<int, TestClass> variantStrct1;

	TestClass tc1;
	TestClass tc2;
	TestClass tc3;

	auto index = variantStrct.set(TestClass(1000L, 100, 10, '1'));
	if (index < 0)
	{
		return false;
	}

	if (variantStrct.get<TestClass>())
	{
		tc1 = *variantStrct.get<TestClass>();
	}

	if (!variantStrct1.assign(index, variantStrct))
	{
		return false;
	}

	if(!variantStrct.reset(index) || !variantStrct1.reset(index))
	{
		return false;
	}

	return true;
}

bool Variant::testVariant()
{
	using flame_ide::templates::Variant;

	Variant<int, long, TestClass> variant;
//	Variant<int, int> variant1; // static-assert works

	auto index = variant.set(TestClass(1000L, 100, 10, '1'));
	if (index < 0 || index != 2)
	{
		log << "index = " << index << std::endl;
		return false;
	}

	if (variant.get<long>())
	{
		log << "variant.get<long>() != nullptr" << std::endl;
		return false;
	}

	variant.reset();
	if (variant.getCurrentIndex() >= 0)
	{
		log << "variant.getCurrentIndex() >= 0" << std::endl;
	}

	variant = decltype(variant)(int(10));

	if (variant.get<TestClass>())
	{
		log << "variant.get<TestClass>() != nullptr" << std::endl;
		log << "variant.getCurrentIndex() = " << variant.getCurrentIndex() << std::endl;
		return false;
	}

	return true;
}

}}
