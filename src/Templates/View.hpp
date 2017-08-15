#ifndef VIEW_HPP
#define VIEW_HPP

namespace flame_ide
{namespace templates
{

template<typename Container
	, typename InputIterator = typename Container::Iterator>
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

}}
#endif // VIEW_HPP
