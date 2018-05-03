#ifndef TEMPLATES_SIMPLEALGORITHMS_HPP
#define TEMPLATES_SIMPLEALGORITHMS_HPP

#include <Templates/Utils.hpp>

namespace flame_ide
{namespace templates
{

/**
 * @brief Copying range.
 */
template<typename IteratorInput, typename IteratorOutput>
Types::size_t copy(IteratorInput start, IteratorInput end
		, IteratorOutput out);
template<typename ContainerInput, typename IteratorOutput>
Types::size_t copy(const ContainerInput &input, IteratorOutput out);


/**
 * @brief Getting size of range.
 */
template<typename Iterator, typename SizeTraits = flame_ide::templates::SizeTraits>
typename SizeTraits::SizeType countIterations(Iterator start, Iterator end);


/**
 * @brief Iterate from start to end.
 */
template<typename IteratorInput, typename FuncObject>
void foreach(IteratorInput start, IteratorInput end, FuncObject func);

/**
 * @brief Iterate by all container elements without changing.
 */
template<typename ContainerInput, typename FuncObject>
void foreach(const ContainerInput& container, FuncObject func);

/**
 * @brief Iterate by all container elements with changing.
 */
template<typename ContainerInput, typename FuncObject>
void foreachChangable(ContainerInput& container, FuncObject func);

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

template<typename ContainerInput, typename IteratorOutput>
Types::size_t copy(const ContainerInput &input, IteratorOutput out)
{
	return copy(input.begin(), input.end(), out);
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
void foreach(IteratorInput start, IteratorInput end, FuncObject func)
{
	for (auto it = start; it != end; ++it)
	{
		func(*it);
	}
}

template<typename ContainerInput, typename FuncObject>
void foreach(const ContainerInput& container, FuncObject func)
{
	foreach(container.begin(), container.end(), func);
}

template<typename ContainerInput, typename FuncObject>
void foreachChangable(ContainerInput& container, FuncObject func)
{
	foreach(container.begin(), container.end(), func);
}

}}

#endif // SIMPLEALGORITHMS_HPP
