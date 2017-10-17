#ifndef VIEW_HPP
#define VIEW_HPP

#include <Templates/Utils.hpp>

namespace flame_ide
{namespace templates
{

template<typename Container
	, typename InputIterator = typename Container::ConstIterator>
class View
{
public:
	using Me = View<Container, InputIterator>;
	using Iterator = InputIterator;

	View() = delete;
	View(const Me &) = default;
	View(Me &&) = default;
	View(Iterator itBegin, Iterator itEnd);
	~View() = default;

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Iterator begin();
	Iterator end();

private:
	Iterator first;
	Iterator last;
};

// View getters

template<typename Container>
View<Container, typename Container::ConstIterator>
getView(const Container &container);

template<typename Container>
View<Container, typename Container::ConstReverseIterator>
getReverseView(const Container &container);

// Range class

template<typename InputIterator>
class Range
{
public:
	using Me = Range<InputIterator>;
	using Iterator = InputIterator;

	Range() = delete;
	Range(const Me &) = default;
	Range(Me &&) = default;
	Range(Iterator itBegin, Iterator itEnd);
	~Range() = default;

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Iterator begin();
	Iterator end();

private:
	Iterator first;
	Iterator last;
};

// Range getters

template<typename Container>
Range<typename Container::Iterator>
getRange(Container &container);

template<typename Container>
Range<typename Container::ConstIterator>
getConstRange(const Container &container);

template<typename Container>
Range<typename Container::ReverseIterator>
getReverseRange(Container &container);

template<typename Container>
Range<typename Container::ConstReverseIterator>
getConstReverseRange(const Container &container);

}}

namespace flame_ide
{namespace templates
{

// View

template<typename Container, typename InputIterator>
View<Container, InputIterator>::
		View(View<Container, InputIterator>::Iterator itBegin
		, View<Container, InputIterator>::Iterator itEnd) :
		first(itBegin), last(itEnd)
{}

template<typename Container, typename InputIterator>
typename View<Container, InputIterator>::Iterator
View<Container, InputIterator>::begin()
{
	return first;
}

template<typename Container, typename InputIterator>
typename View<Container, InputIterator>::Iterator
View<Container, InputIterator>::end()
{
	return last;
}

// View getters

template<typename Container>
View<Container, typename Container::ConstIterator>
getView(const Container &container)
{
	return View<Container, typename Container::ConstIterator>(
			cbegin(container), cend(container)
	);
}

template<typename Container>
View<Container, typename Container::ConstReverseIterator>
getReverseView(const Container &container)
{
	return View<Container, typename Container::ConstReverseIterator>(
			crbegin(container), crend(container)
	);
}

// Range

template<typename InputIterator>
Range<InputIterator>::Range(
		Range<InputIterator>::Iterator itBegin, Range<InputIterator>::Iterator itEnd) :
		first(itBegin), last(itEnd)
{}

template<typename InputIterator>
typename Range<InputIterator>::Iterator
Range<InputIterator>::begin()
{
	return first;
}

template<typename InputIterator>
typename Range<InputIterator>::Iterator
Range<InputIterator>::end()
{
	return last;
}

// Range getters

template<typename Container>
Range<typename Container::Iterator>
getRange(Container &container)
{
	return Range<typename Container::Iterator>(
			begin(container), end(container)
	);
}

template<typename Container>
Range<typename Container::ConstIterator>
getConstRange(const Container &container)
{
	return Range<typename Container::ConstIterator>(
			cbegin(container), cend(container)
	);
}

template<typename Container>
Range<typename Container::ReverseIterator>
getReverseRange(Container &container)
{
	return Range<typename Container::ConstIterator>(
			rbegin(container), rend(container)
	);
}

template<typename Container>
Range<typename Container::ConstReverseIterator>
getConstReverseRange(const Container &container)
{
	return Range<typename Container::ConstIterator>(
			crbegin(container), crend(container)
	);
}

}}
#endif // VIEW_HPP
