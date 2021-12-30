#ifndef FLAMEIDE_COMMON_CONSTANTS_HPP
#define FLAMEIDE_COMMON_CONSTANTS_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>

namespace flame_ide
{

#ifdef FLAMEIDE_CONSTANT_KILOBYTE
#	undef FLAMEIDE_CONSTANT_KILOBYTE
#endif
#define FLAMEIDE_CONSTANT_KILOBYTE \
		(flame_ide::Types::size_t(1024))

#ifdef FLAMEIDE_CONSTANT_MEGABYTE
#	undef FLAMEIDE_CONSTANT_MEGABYTE
#endif
#define FLAMEIDE_CONSTANT_MEGABYTE \
		(FLAMEIDE_CONSTANT_KILOBYTE * flame_ide::Types::size_t(1024))

#ifdef FLAMEIDE_CONSTANT_GIGABYTE
#	undef FLAMEIDE_CONSTANT_GIGABYTE
#endif
#define FLAMEIDE_CONSTANT_GIGABYTE \
		(FLAMEIDE_CONSTANT_MEGABYTE * flame_ide::Types::size_t(1024))

#ifndef FLAMEIDE_CONSTANT_STATIC_SIZE
#	define \
			FLAMEIDE_CONSTANT_STATIC_SIZE flame_ide::Types::size_t(32)
#endif

#ifndef FLAMEIDE_CONSTANT_BUFFER_SIZE
#	define FLAMEIDE_CONSTANT_BUFFER_SIZE \
			flame_ide::Types::size_t(4) * KILOBYTE
#endif

#ifndef FLAMEIDE_CONSTANT_STATIC_STRING_SIZE
#	define FLAMEIDE_CONSTANT_STATIC_STRING_SIZE \
			flame_ide::Types::size_t(2) * KILOBYTE
#endif

#ifndef FLAMEIDE_CONSTANT_PIPE_BUFFER_SIZE
#	define FLAMEIDE_CONSTANT_PIPE_BUFFER_SIZE \
			flame_ide::Types::size_t(32) * KILOBYTE
#endif

#ifndef FLAMEIDE_CONSTANT_THREAD_STACK_SIZE
#	define FLAMEIDE_CONSTANT_THREAD_STACK_SIZE \
			flame_ide::Types::size_t(8) * MEGABYTE
#endif

#ifndef FLAMEIDE_CONSTANT_LISTEN_CLIENTS_COUNT
#	define FLAMEIDE_CONSTANT_LISTEN_CLIENTS_COUNT \
			flame_ide::Types::size_t(128)
#endif

struct Constants: public NonCreational
{
	static constexpr flame_ide::Types::size_t KILOBYTE = FLAMEIDE_CONSTANT_KILOBYTE;
	static constexpr flame_ide::Types::size_t MEGABYTE = FLAMEIDE_CONSTANT_MEGABYTE;
	static constexpr flame_ide::Types::size_t GIGABYTE = FLAMEIDE_CONSTANT_GIGABYTE;

	static constexpr flame_ide::Types::size_t STATIC_SIZE =
			FLAMEIDE_CONSTANT_STATIC_SIZE;

	static constexpr flame_ide::Types::size_t BUFFER_SIZE =
			FLAMEIDE_CONSTANT_BUFFER_SIZE;

	static constexpr flame_ide::Types::size_t STATIC_STRING_SIZE =
			FLAMEIDE_CONSTANT_STATIC_STRING_SIZE;

	static constexpr flame_ide::Types::size_t PIPE_BUFFER_SIZE =
			FLAMEIDE_CONSTANT_PIPE_BUFFER_SIZE;

	static constexpr flame_ide::Types::size_t THREAD_STACK_SIZE =
			FLAMEIDE_CONSTANT_THREAD_STACK_SIZE;

	static constexpr flame_ide::Types::size_t LISTEN_CLIENTS_COUNT =
			FLAMEIDE_CONSTANT_LISTEN_CLIENTS_COUNT;
};

#undef FLAMEIDE_CONSTANT_STATIC_SIZE
#undef FLAMEIDE_CONSTANT_BUFFER_SIZE
#undef FLAMEIDE_CONSTANT_STATIC_STRING_SIZE
#undef FLAMEIDE_CONSTANT_PIPE_BUFFER_SIZE
#undef FLAMEIDE_CONSTANT_THREAD_STACK_SIZE
#undef FLAMEIDE_CONSTANT_LISTEN_CLIENTS_COUNT

#undef FLAMEIDE_CONSTANT_GIGABYTE
#undef FLAMEIDE_CONSTANT_MEGABYTE
#undef FLAMEIDE_CONSTANT_KILOBYTE

}

#endif // FLAMEIDE_COMMON_CONSTANTS_HPP
