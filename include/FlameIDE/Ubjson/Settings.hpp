#ifndef FLAMEIDE_UBJSON_SETTINGS_HPP
#define FLAMEIDE_UBJSON_SETTINGS_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Traits.hpp>

namespace flame_ide
{namespace ubjson
{

struct Settings : public NonCreational
{
	static constexpr size_t MAX_STATIC_SIZE = 32;
};

}}

#endif // FLAMEIDE_UBJSON_SETTINGS_HPP
