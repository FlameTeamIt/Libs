#ifndef ANALYSERS_UBJSON_ARRAY_HPP
#define ANALYSERS_UBJSON_ARRAY_HPP

#include <Analysers/Ubjson/Types.hpp>
#include <Analysers/Ubjson/Traits.hpp>

#include <Templates/Array.hpp>

namespace flame_ide
{namespace ubjson
{

class Array
{
};

template<>
struct ValueTraits<EnumeratedType::ARRAY>
{
	static constexpr Type VALUE_TYPE = Type::ARRAY_OPEN;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ARRAY_CLOSE;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = Array;
};

}}

#endif // ANALYSERS_UBJSON_ARRAY_HPP
