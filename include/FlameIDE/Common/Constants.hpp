#ifndef FLAMEIDE_COMMON_CONSTANTS_HPP
#define FLAMEIDE_COMMON_CONSTANTS_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{

#ifndef FLAMEIDE_CONSTANT_MAX_STATIC_SIZE
#	define FLAMEIDE_CONSTANT_MAX_STATIC_SIZE flame_ide::size_t(32)
#endif

#ifndef FLAMEIDE_CONSTANT_MAX_BUFFER_SIZE
#	define FLAMEIDE_CONSTANT_MAX_BUFFER_SIZE flame_ide::size_t(4)
#endif

#ifndef FLAMEIDE_CONSTANT_MAX_STATIC_STRING_SIZE
#	define FLAMEIDE_CONSTANT_MAX_STATIC_STRING_SIZE flame_ide::size_t(2)
#endif

struct Constants: public NonCreational
{
	static constexpr flame_ide::size_t KILOBYTE = 1024;
	static constexpr flame_ide::size_t MAX_STATIC_SIZE = 
			FLAMEIDE_CONSTANT_MAX_STATIC_SIZE;
	static constexpr flame_ide::size_t MAX_BUFFER_SIZE = 
			FLAMEIDE_CONSTANT_MAX_BUFFER_SIZE * KILOBYTE;
	static constexpr flame_ide::size_t MAX_STATIC_STRING_SIZE = 
			FLAMEIDE_CONSTANT_MAX_STATIC_STRING_SIZE * KILOBYTE;
};

#undef FLAMEIDE_CONSTANT_MAX_STATIC_SIZE

}

#endif // FLAMEIDE_COMMON_CONSTANTS_HPP
