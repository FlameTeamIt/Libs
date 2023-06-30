#ifndef FLAMEIDE_UBJSON_SETTINGS_HPP
#define FLAMEIDE_UBJSON_SETTINGS_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Traits.hpp>

#ifndef FLAMEIDE_UBJSON_MAX_STATIC_STRING_SIZE
#define FLAMEIDE_UBJSON_MAX_STATIC_STRING_SIZE flame_ide::Types::size_t{32}
#endif // FLAMEIDE_UBJSON_MAX_STATIC_STRING_SIZE

#ifndef FLAMEIDE_UBJSON_MAX_HUGE_NUMBER_SIZE
#define FLAMEIDE_UBJSON_MAX_HUGE_NUMBER_SIZE flame_ide::Types::size_t{32}
#endif // FLAMEIDE_UBJSON_MAX_HUGE_NUMBER_SIZE

namespace flame_ide
{namespace ubjson
{

struct Settings: public NonCreational
{
	static constexpr Types::size_t MAX_STATIC_STRING_SIZE = FLAMEIDE_UBJSON_MAX_STATIC_STRING_SIZE;
	static constexpr Types::size_t MAX_HUGE_NUMBER_SIZE = FLAMEIDE_UBJSON_MAX_HUGE_NUMBER_SIZE;
};

}} // namespace flame_ide::ubjson

#endif // FLAMEIDE_UBJSON_SETTINGS_HPP
