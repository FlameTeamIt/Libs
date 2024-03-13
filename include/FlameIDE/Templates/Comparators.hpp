#ifndef FLAMEIDE_TEMPLATES_COMPARATORS_HPP
#define FLAMEIDE_TEMPLATES_COMPARATORS_HPP

#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace templates
{

template<typename T, typename Traits = DefaultTraits<T>>
struct Equal;

template<typename T, typename Traits = DefaultTraits<T>>
struct More;

template<typename T, typename Traits = DefaultTraits<T>>
struct MoreEqual;

template<typename T, typename Traits = DefaultTraits<T>>
struct Less;

template<typename T, typename Traits = DefaultTraits<T>>
struct LessEqual;

}} // namespace flame_ide::templates

namespace flame_ide
{namespace templates
{

template<typename T, typename Traits>
struct Equal
{
	using ConstReference = typename Traits::ConstReference;

	bool operator()(ConstReference dataLeft, ConstReference dataRight) const noexcept
	{
		return dataLeft == dataRight;
	}
};

template<typename T, typename Traits>
struct More
{
	using ConstReference = typename Traits::ConstReference;

	bool operator()(ConstReference dataLeft, ConstReference dataRight) const noexcept
	{
		return dataLeft > dataRight;
	}
};

template<typename T, typename Traits>
struct MoreEqual
{
	using ConstReference = typename Traits::ConstReference;

	bool operator()(ConstReference dataLeft, ConstReference dataRight) const noexcept
	{
		using Equal = flame_ide::templates::Equal<T>;
		using More = flame_ide::templates::More<T>;

		return Equal{}(dataLeft, dataRight) || More{}(dataLeft, dataRight);
	}
};

template<typename T, typename Traits>
struct Less
{
	using ConstReference = typename Traits::ConstReference;

	bool operator()(ConstReference dataLeft, ConstReference dataRight) const noexcept
	{
		return dataLeft < dataRight;
	}
};

template<typename T, typename Traits>
struct LessEqual
{
	using ConstReference = typename Traits::ConstReference;

	bool operator()(ConstReference dataLeft, ConstReference dataRight) const noexcept
	{
		using Equal = flame_ide::templates::Equal<T>;
		using Less = flame_ide::templates::Less<T>;

		return Equal{}(dataLeft, dataRight) || Less{}(dataLeft, dataRight);
		return false;
	}
};

}} // namespace flame_ide::templates

namespace flame_ide
{namespace templates
{namespace defaults
{

template<typename T>
using Equal = flame_ide::templates::Equal<T>;

template<typename T>
using More = flame_ide::templates::More<T>;

template<typename T>
using MoreEqual = flame_ide::templates::MoreEqual<T>;

template<typename T>
using Less = flame_ide::templates::Less<T>;

template<typename T>
using LessEqual = flame_ide::templates::LessEqual<T>;

}}} // namespace flame_ide::templates::defaults

#endif // FLAMEIDE_TEMPLATES_COMPARATORS_HPP
