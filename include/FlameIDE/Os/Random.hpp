#ifndef FLAMEIDE_OS_POSIX_RANDOM_HPP
#define FLAMEIDE_OS_POSIX_RANDOM_HPP

#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Common/Traits/Functional.hpp>

namespace flame_ide
{namespace os
{

flame_ide::primitive_types::ssize_t RandomRange(void *buf, flame_ide::primitive_types::size_t size);

/// @brief Get next random value from POSIX getrandom(2).
///        It fills all bytes of returned value.
/// @tparam T Integral type used for returned value (default is int).
template <typename T = flame_ide::primitive_types::int_t>
typename EnableType<IsIntegralValue<T>, T>::Type Random()
{
	T result{};
	return RandomRange(&result, sizeof(T)) == sizeof(T) ? result : 0;
}

}}

#endif // FLAMEIDE_OS_POSIX_RANDOM_HPP
