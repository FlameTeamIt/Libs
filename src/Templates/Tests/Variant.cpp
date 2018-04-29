#include "Variant.hpp"

namespace flame_ide
{namespace test
{

Variant::Variant() : AbstractTest("Variant")
{}

Variant::~Variant()
{}

int Variant::vStart()
{
	using flame_ide::templates::Variant;

	Variant<int, long> variant;
//	Variant<int, int> variant1;
}

}}
