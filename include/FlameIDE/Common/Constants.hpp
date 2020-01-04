#ifndef FLAMEIDE_COMMON_CONSTANTS_HPP
#define FLAMEIDE_COMMON_CONSTANTS_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{

#ifndef FLAMEIDE_CONSTANT_MAX_STATIC_SIZE
#	define FLAMEIDE_CONSTANT_MAX_STATIC_SIZE flame_ide::size_t(32)
#endif

struct Constants: public NonCreational
{
	static constexpr flame_ide::size_t MAX_STATIC_SIZE = FLAMEIDE_CONSTANT_MAX_STATIC_SIZE;
};

#undef FLAMEIDE_CONSTANT_MAX_STATIC_SIZE

}

#endif // FLAMEIDE_COMMON_CONSTANTS_HPP
