#ifndef FLAMEIDE_TEMPLATES_SIMPLEALGORITHMS_HPP
#define FLAMEIDE_TEMPLATES_SIMPLEALGORITHMS_HPP

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace templates
{

///
/// @brief Copying range.
///
template<typename IteratorInput, typename IteratorOutput>
Types::size_t copy(IteratorInput start, IteratorInput end
		, IteratorOutput out);

template<typename InputContainer, typename IteratorOutput>
Types::size_t copy(const InputContainer &input, IteratorOutput out);

template<typename InputIterator, typename IteratorOutput>
Types::size_t copy(const Range<InputIterator> &range, IteratorOutput out);

///
/// @brief Getting size of range.
///
template<typename Iterator, typename SizeTraits = flame_ide::SizeTraits>
typename SizeTraits::SizeType countIterations(Iterator start, Iterator end);

///
/// @brief Iterate from start to end.
///
template<typename IteratorInput, typename FuncObject>
void foreach(IteratorInput start, IteratorInput end, FuncObject &&func);

///
/// @brief Iterate by all container elements without changing.
///
template<typename InputContainer, typename FuncObject>
void foreach(const InputContainer &container, FuncObject &&func);

///
/// @brief Iterate by range elements without changing.
///
template<typename InputIterator, typename FuncObject>
void foreach(const Range<InputIterator> &range, FuncObject &&func);

///
/// @brief Iterate by all container elements with changing.
///
template<typename InputContainer, typename FuncObject>
void foreachChangable(InputContainer &container, FuncObject &&func);

///
/// @brief Iterate by range elements with changing.
///
template<typename InputIterator, typename FuncObject>
void foreachChangable(Range<InputIterator> &range, FuncObject &&func);

}}

namespace flame_ide
{namespace templates
{

template<typename IteratorInput, typename IteratorOutput>
Types::size_t copy(IteratorInput start, IteratorInput end
		, IteratorOutput out)
{
	static_assert(
			isSameTypes<
				typename RemoveAll<decltype(*start)>::Type
				, typename RemoveAll<decltype(*out)>::Type
			>()
			, "Types is not equal."
	);

	static_assert(!isConst<decltype(*out)>(), "Out iterator cannot be const.");

	Types::size_t counter = 0;
	for (auto iterator = start; iterator != end; ++iterator, ++out, ++counter)
		*out = *iterator;

	return counter;
}

template<typename InputContainer, typename IteratorOutput>
Types::size_t copy(const InputContainer &input, IteratorOutput out)
{
	return copy(input.begin(), input.end(), out);
}

template<typename InputIterator, typename IteratorOutput>
Types::size_t copy(const Range<InputIterator> &range, IteratorOutput out)
{
	return copy(range.begin(), range.end(), out);
}

template<typename Iterator, typename Traits>
typename Traits::SizeType countIterations(Iterator start, Iterator end)
{
	typename Traits::SizeType count = 0;
	for(auto iterator = start; iterator != end; ++iterator, ++count)
	{}
	return count;
}

template<typename IteratorInput, typename FuncObject>
void foreach(IteratorInput start, IteratorInput end, FuncObject &&func)
{
	for (auto it = start; it != end; ++it)
	{
		func(*it);
	}
}

template<typename InputContainer, typename FuncObject>
void foreach(const InputContainer& container, FuncObject func)
{
	foreach(container.begin(), container.end(), func);
}

template<typename InputIterator, typename FuncObject>
void foreach(const Range<InputIterator> &range, FuncObject &&func)
{
	foreach(range.begin(), range.end(), func);
}

template<typename InputContainer, typename FuncObject>
void foreachChangable(InputContainer& container, FuncObject &&func)
{
	foreach(container.begin(), container.end(), func);
}

template<typename InputIterator, typename FuncObject>
void foreachChangable(Range<InputIterator> &range, FuncObject &&func)
{
	foreach(range.begin(), range.end(), func);
}

}}

#endif // SIMPLEALGORITHMS_HPP
