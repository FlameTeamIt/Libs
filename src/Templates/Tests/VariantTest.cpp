#include "VariantTest.hpp"
#include "TestClass.hpp"

namespace flame_ide
{namespace test
{

VariantTest::VariantTest() : AbstractTest("Variant")
{}

VariantTest::~VariantTest()
{}

int VariantTest::vStart()
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

bool VariantTest::testVariantStruct()
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

bool VariantTest::testVariant()
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
		return false;
	}

	variant = decltype(variant)(int(10));

	if (variant.get<TestClass>())
	{
		log << "variant.get<TestClass>() != nullptr"
				<< std::endl;
		log << "variant.getCurrentIndex() = "
				<< variant.getCurrentIndex()
				<< std::endl;
		return false;
	}

	Variant<Types::int_t, Types::long_t> variantArray[6] = {
		Variant<Types::int_t, Types::long_t>(Types::int_t(10))
		, Variant<Types::int_t, Types::long_t>(Types::int_t(10))
		, Variant<Types::int_t, Types::long_t>(Types::int_t(25))
		, Variant<Types::int_t, Types::long_t>(Types::long_t(100))
		, Variant<Types::int_t, Types::long_t>(Types::long_t(100))
		, Variant<Types::int_t, Types::long_t>(Types::long_t(125))
	};
	{
		size_t offset = 0;
		if (variantArray[offset + 0] != variantArray[offset + 1])
		{
			log << "Variant<Types::int_t, Types::long_t>(Types::int_t(10))"
					" != Variant<Types::int_t, Types::long_t>(Types::int_t(10))"
					<< std::endl;
			return false;
		}
		if (variantArray[offset + 0] == variantArray[offset + 2])
		{
			log << "Variant<Types::int_t, Types::long_t>(Types::int_t(10))"
					" == Variant<Types::int_t, Types::long_t>(Types::int_t(25))"
					<< std::endl;
			return false;
		}

		if (variantArray[offset + 0] == variantArray[offset + 3])
		{
			log << "Variant<Types::int_t, Types::long_t>(Types::int_t(10))"
					" == Variant<Types::int_t, Types::long_t>(Types::long_t(100))"
					<< std::endl;
			return false;
		}

		offset = 3;
		if (variantArray[offset + 0] != variantArray[offset + 1])
		{
			log << "Variant<Types::int_t, Types::long_t>(Types::long_t(100))"
					" != Variant<Types::int_t, Types::long_t>(Types::long_t(100))"
					<< std::endl;
			return false;
		}
		if (variantArray[offset + 0] == variantArray[offset + 2])
		{
			log << "Variant<Types::int_t, Types::long_t>(Types::long_t(100))"
					" != Variant<Types::int_t, Types::long_t>(Types::long_t(125))"
					<< std::endl;
			return false;
		}
	}

	return true;
}

}}
