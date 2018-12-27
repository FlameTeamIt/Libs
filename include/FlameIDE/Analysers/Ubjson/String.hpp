#ifndef ANALYSERS_UBJSON_STRING_HPP
#define ANALYSERS_UBJSON_STRING_HPP

#include <Common/PrimitiveTypes.hpp>

#include <Templates/String.hpp>
#include <Templates/Variant.hpp>
#include <Templates/Array.hpp>

#include <Analysers/Ubjson/Settings.hpp>
#include <Analysers/Ubjson/Types.hpp>
#include <Analysers/Ubjson/Traits.hpp>


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
