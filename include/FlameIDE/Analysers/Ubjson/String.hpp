#ifndef ANALYSERS_UBJSON_STRING_HPP
#define ANALYSERS_UBJSON_STRING_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>

#include <FlameIDE/Templates/String.hpp>
#include <FlameIDE/Templates/Variant.hpp>
#include <FlameIDE/Templates/Array.hpp>

#include <FlameIDE/Analysers/Ubjson/Settings.hpp>
#include <FlameIDE/Analysers/Ubjson/Types.hpp>
#include <FlameIDE/Analysers/Ubjson/Traits.hpp>


namespace flame_ide
{namespace ubjson
{

class String
{
public:
	static constexpr size_t STATIC_STRING_SIZE = Settings::MAX_STATIC_SIZE;
	using StringVariant = templates::Variant<
		templates::String, templates::Array<char_t, STATIC_STRING_SIZE>
	>;

	String(const char_t *cstring);
private:
};

}}

#endif // ANALYSERS_UBJSON_STRING_HPP
