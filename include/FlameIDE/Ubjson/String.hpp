#ifndef FLAMEIDE_UBJSON_STRING_HPP
#define FLAMEIDE_UBJSON_STRING_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>

#include <FlameIDE/Templates/String.hpp>
#include <FlameIDE/Templates/Variant.hpp>
#include <FlameIDE/Templates/Array.hpp>

#include <FlameIDE/Ubjson/Settings.hpp>
#include <FlameIDE/Ubjson/Types.hpp>
#include <FlameIDE/Ubjson/Traits.hpp>


namespace flame_ide
{namespace ubjson
{

class String
{
public:
	static constexpr size_t STATIC_STRING_SIZE = Settings::MAX_STATIC_STRING_SIZE;
	using StringVariant = templates::Variant<
		templates::String, templates::Array<char_t, STATIC_STRING_SIZE>
	>;

	String(const char_t *cstring);
private:
};

}}

#endif // FLAMEIDE_UBJSON_STRING_HPP
