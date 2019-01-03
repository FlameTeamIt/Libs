#ifndef FLAMEIDE_TEMPLATES_ITERATOR_ITERATORTRAITS_HPP
#define FLAMEIDE_TEMPLATES_ITERATOR_ITERATORTRAITS_HPP

#include <FlameIDE/Common/Traits/Fuctional.hpp>
#include <FlameIDE/Common/Traits/CustomTraits.hpp>

namespace flame_ide
{namespace templates
{

enum class IteratorCategory
{
	OUTPUT
	, INPUT
	, FORWARD
	, BIDIRECTIONAL
	, RANDOM_ACCESS
};

enum class IteratorAccess
{
	NON_CONSTANT
	, CONSTANT
};

namespace iterator_utils
{

template<typename IteratorType>
struct GetType
{
	using Type = typename IteratorType::Type;
};

template<typename IteratorType>
struct GetType<IteratorType *>
{
	using Type = IteratorType;
};

template<typename IteratorType>
struct GetIteratorInfo
{
	static constexpr IteratorCategory CATEGORY = IteratorType::CATEGORY;
	static constexpr IteratorAccess ACCESS = IteratorType::ACCESS;
};

template<typename IteratorType>
struct GetIteratorInfo<IteratorType *>
{
	static constexpr IteratorCategory CATEGORY = IteratorCategory::RANDOM_ACCESS;
	static constexpr IteratorAccess ACCESS = flame_ide::IsConst<IteratorType>::VALUE
			? IteratorAccess::CONSTANT : IteratorAccess::NON_CONSTANT;
};

template<typename IteratorType>
struct IteratorTraits: public ContainerTraits<typename GetType<IteratorType>::Type>
{};

} // namespace iterator_utils

}}

#endif // FLAMEIDE_TEMPLATES_ITERATOR_ITERATORTRAITS_HPP
