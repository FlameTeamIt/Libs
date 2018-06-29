#ifndef ANALYSERS_UBJSON_HUGENUMERIC_HPP
#define ANALYSERS_UBJSON_HUGENUMERIC_HPP

#include <Analysers/Ubjson/Types.hpp>
#include <Analysers/Ubjson/Traits.hpp>

namespace flame_ide
{namespace ubjson
{

class HugeNumeric
{
};

template<>
struct ValueTraits<EnumeratedType::HUGE_NUM>
{
	static constexpr Type VALUE_TYPE = Type::HUGE_NUM;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = HugeNumeric;
	ValueType value;
};

}}

#endif // ANALYSERS_UBJSON_HUGENUMERIC_HPP
