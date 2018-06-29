#ifndef TEMPLATES_VIEW_HPP
#define TEMPLATES_VIEW_HPP

#include <Templates/Utils.hpp>
#include <Templates/Iterator.hpp>

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

	Iterator begin() const;
	Iterator end() const;

private:
	Iterator first;
	Iterator last;
};

// View getters

template<typename Container>
View<Container, typename Container::ConstIterator>
makeView(const Container &container);

template<typename Container>
View<Container, typename Container::ConstReverseIterator>
makeReverseView(const Container &container);

// Range class

template<typename InputIterator>
class Range
{
public:
	using Me = Range<InputIterator>;
	using Iterator = InputIterator;
	using ConstIterator = templates::ConstIterator<Iterator>;

	Range() = delete;
	Range(const Me &) = default;
	Range(Me &&) = default;
	Range(Iterator itBegin, Iterator itEnd);
	~Range() = default;

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Iterator begin();
	Iterator end();

	ConstIterator begin() const;
	ConstIterator end() const;

private:
	Iterator first;
	Iterator last;
};

// Range getters

template<typename Container>
Range<typename Container::Iterator>
makeRange(Container &container);

template<typename InputIterator>
Range<InputIterator>
makeRange(InputIterator itBegin, InputIterator itEnd);

template<typename Container>
Range<typename Container::ConstIterator>
makeConstRange(const Container &container);

template<typename Container>
Range<typename Container::ReverseIterator>
makeReverseRange(Container &container);

template<typename Container>
Range<typename Container::ConstReverseIterator>
makeConstReverseRange(const Container &container);

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
View<Container, InputIterator>::begin() const
{
	return first;
}

template<typename Container, typename InputIterator>
typename View<Container, InputIterator>::Iterator
View<Container, InputIterator>::end() const
{
	return last;
}


// View makers

template<typename Container>
View<Container, typename Container::ConstIterator>
makeView(const Container &container)
{
	return View<Container, typename Container::ConstIterator>(
			cbegin(container), cend(container)
	);
}

template<typename Container>
View<Container, typename Container::ConstReverseIterator>
makeReverseView(const Container &container)
{
	return View<Container, typename Container::ConstReverseIterator>(
			crbegin(container), crend(container)
	);
}


// Range

template<typename InputIterator>
Range<InputIterator>::Range(Range<InputIterator>::Iterator itBegin
		, Range<InputIterator>::Iterator itEnd)
		: first(itBegin), last(itEnd)
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

template<typename InputIterator>
typename Range<InputIterator>::ConstIterator
Range<InputIterator>::begin() const
{
	return first;
}

template<typename InputIterator>
typename Range<InputIterator>::ConstIterator
Range<InputIterator>::end() const
{
	return last;
}


// Range makers

template<typename Container>
Range<typename Container::Iterator>
makeRange(Container &container)
{
	return Range<typename Container::Iterator>(
			begin(container), end(container)
	);
}

template<typename InputIterator>
Range<InputIterator>
makeRange(InputIterator itBegin, InputIterator itEnd)
{
	return Range<InputIterator> (
			itBegin, itEnd
	);
}

template<typename Container>
Range<typename Container::ConstIterator>
makeConstRange(const Container &container)
{
	return Range<typename Container::ConstIterator>(
			cbegin(container), cend(container)
	);
}

template<typename Container>
Range<typename Container::ReverseIterator>
makeReverseRange(Container &container)
{
	return Range<typename Container::ConstIterator>(
			rbegin(container), rend(container)
	);
}

template<typename Container>
Range<typename Container::ConstReverseIterator>
makeConstReverseRange(const Container &container)
{
	return Range<typename Container::ConstIterator>(
			crbegin(container), crend(container)
	);
}

template<typename T>
Range<Types::uichar_t*> makeByteRange(T &value)
{
	auto begin = [](T &value)
	{
		void *pointer = &value;
		return static_cast<Types::uichar_t *>(pointer);
	} (value);
	auto end = begin + sizeof(value);
	return makeRange(begin, end);
}

template<typename T>
Range<const Types::uichar_t*> makeConstByteRange(const T &value)
{
	auto begin = [](const T &value)
	{
		const void *pointer = &value;
		return static_cast<const Types::uichar_t *>(pointer);
	} (value);
	auto end = begin + sizeof(value);
	return makeRange(begin, end);
}

}}
#endif // TEMPLATES_VIEW_HPP
