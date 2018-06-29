#ifndef ANALYSERS_UBJSON_OBJECT_HPP
#define ANALYSERS_UBJSON_OBJECT_HPP

#include <Templates/Vector.hpp>

#include <Analysers/Ubjson/Types.hpp>
#include <Analysers/Ubjson/Pair.hpp>

namespace flame_ide
{namespace ubjson
{

class Object
{
};

template<>
struct ValueTraits<EnumeratedType::OBJECT>
{
	static constexpr Type VALUE_TYPE = Type::OBJECT_OPEN;
	static constexpr Type VALUE_TYPE_CLOSE = Type::OBJECT_CLOSE;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = Object;
};

}}

#endif // ANALYSERS_UBJSON_OBJECT_HPP
