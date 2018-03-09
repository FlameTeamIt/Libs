#ifndef TEMPLATES_ALIGNOBJECT_HPP
#define TEMPLATES_ALIGNOBJECT_HPP

#include <Templates/Traits.hpp>

namespace flame_ide
{namespace templates
{

template<typename T>
struct AlignObject
{
	static constexpr Types::size_t ARRAY_SIZE = (sizeof(T) % sizeof(Types::size_t))
			? sizeof(T) / sizeof(Types::size_t) + 1
			: sizeof(T) / sizeof(Types::size_t);

	AlignObject() noexcept;

	size_t array[ARRAY_SIZE];
};

}}

namespace flame_ide
{namespace templates
{

template<typename T>
AlignObject<T>::AlignObject() noexcept
{
	for (Types::size_t i = 0; i < ARRAY_SIZE; ++i)
		array[i] = 0u;
}

}}

#endif // TEMPLATES_ALIGNOBJECT_HPP
