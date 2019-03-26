#ifndef FLAMEIDE_COMMON_CONSTANTS_HPP
#define FLAMEIDE_COMMON_CONSTANTS_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{

#define FLAMEIDE_CONSTANT_MAX_STATIC_SIZE flame_ide::size_t(32)

struct Constants: public NonCreational
{
	static constexpr flame_ide::size_t MAX_STATIC_SIZE = FLAMEIDE_CONSTANT_MAX_STATIC_SIZE;
};

}

#endif // CONSTANTS_HPP
