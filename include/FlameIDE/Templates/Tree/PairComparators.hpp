#ifndef FLAMEIDE_TEMPLATES_TREE_PAIRCOMPARATORS_HPP
#define FLAMEIDE_TEMPLATES_TREE_PAIRCOMPARATORS_HPP

#include <FlameIDE/Common/Traits/Defaults.hpp>
#include <FlameIDE/Templates/Pair.hpp>

namespace flame_ide
{namespace templates
{namespace tree
{namespace comparator
{

template<typename T>
inline constexpr bool isPair(T &&) { return false; }

template<typename T, typename U>
inline constexpr bool isPair(templates::Pair<T, U> &&) { return true; }

template<typename Pair, typename Traits = DefaultTraits<Pair>>
struct PairMore
{
	static_assert(
			isPair(flame_ide::declareValue<Pair>())
			, "Type is not Pair"
	);

	using ConstReference = typename Traits::ConstReference;
	bool operator()(ConstReference dataLeft, ConstReference dataRight) const noexcept
	{
		return dataLeft.first() > dataRight.first();
	}
};

template<typename Pair, typename Traits = DefaultTraits<Pair>>
struct PairLess
{
	static_assert(
			isPair(flame_ide::declareValue<Pair>())
			, "Type is not Pair"
	);

	using ConstReference = typename Traits::ConstReference;
	bool operator()(ConstReference dataLeft, ConstReference dataRight) const noexcept
	{
		return dataLeft.first() < dataRight.first();
	}
};

using Less = PairLess<Pair<int, int>>;
using NotLess = PairLess<int>;

}}}} // namespace flame_ide::templates::tree::comparator

#endif // FLAMEIDE_TEMPLATES_TREE_PAIRCOMPARATORS_HPP
