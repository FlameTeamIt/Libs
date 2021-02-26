#ifndef FLAMEIDE_COMMON_TRAITS_CONTAINERTRAITS_HPP
#define FLAMEIDE_COMMON_TRAITS_CONTAINERTRAITS_HPP

#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Common/Byte.hpp>

namespace flame_ide
{

///
/// @brief Default size, diff and traits.
///
struct SizeTraits: public NonCreational
{
	using SizeType = Types::size_t;
	using SsizeType = Types::ssize_t;
	using DiffType = Types::diff_t;
	using ByteType = byte_t;
};

///
/// @brief Default traits for containers such as Array, Vector, etc.
/// @tparam Raw type.
///
template<typename T>
struct ContainerTraits: public DefaultTraits<T>, public SizeTraits
{};


///
/// @brief Default traits for containers such as Array, Vector, etc.
/// @tparam Is volatile type.
///
template<bool IS_VOLATILE>
struct SerializationTraits
{
	using InputDataBlock = void *;
	using ConstInputDataBlock =  const void *;

	using InternalDataBlock = Types::uichar_t *;
	using ConstInternalDataBlock =  const Types::uichar_t *;
};

template<>
struct SerializationTraits<true>
{
	using InputDataBlock = volatile void *;
	using ConstInputDataBlock =  const volatile void *;

	using InternalDataBlock = volatile Types::uichar_t *;
	using ConstInternalDataBlock =  const volatile Types::uichar_t *;
};

}

#endif // CONTAINERTRAITS_HPP
