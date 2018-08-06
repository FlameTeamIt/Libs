#ifndef TEMPLATES_ALIGNOBJECT_HPP
#define TEMPLATES_ALIGNOBJECT_HPP

#include <Templates/Traits.hpp>

namespace flame_ide
{namespace templates
{

template<typename T>
struct AlignObject
{
	using ArrayValueType = typename ChooseType
	<
		sizeof(T) <= sizeof(Types::size_t)
		, typename ChooseType<
			sizeof(T) <= sizeof(Types::size_t) / 2
			, typename ChooseType<
				sizeof(T) <= sizeof(Types::size_t) / 4
				, typename ChooseType<
					sizeof(T) <= sizeof(Types::size_t) / 8
					, Types::uichar_t
					, void
				>::Type
				, typename ChooseType<
					sizeof(Types::size_t) / 4 == sizeof(Types::ushort_t)
					, Types::ushort_t
					, Types::uichar_t
				>::Type
			>::Type
			, typename ChooseType<
				sizeof(Types::size_t) / 2 == sizeof(Types::uint_t)
				, Types::uint_t
				, Types::ushort_t
			>::Type
		>::Type
		, Types::size_t
	>::Type;
	static constexpr Types::size_t SIZE = (sizeof(T) % sizeof(ArrayValueType) != 0)
			? (
					sizeof(T) / sizeof(ArrayValueType)
			) + 1
			: sizeof(T) / sizeof(ArrayValueType);
	static constexpr auto INIT_VALUE = ArrayValueType();

	AlignObject() noexcept;
	ArrayValueType array[SIZE];
};

}}

namespace flame_ide
{namespace templates
{

template<typename T>
AlignObject<T>::AlignObject() noexcept
{
	for (Types::size_t i = 0; i < SIZE; ++i)
	{
		array[i] = INIT_VALUE;
	}
}

}}

#endif // TEMPLATES_ALIGNOBJECT_HPP
