#ifndef VIEW_HPP
#define VIEW_HPP

namespace flame_ide
{namespace templates
{

template<typename Container
	, typename Iterator = typename Container::Iterator>
class View
{
public:
	using Me = View<Container, Iterator>;

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

}}

namespace flame_ide
{namespace templates
{

template<typename Container, typename Iterator>
View<Container, Iterator>::View(Iterator itBegin, Iterator itEnd) :
		first(itBegin), last(itEnd)
{}

template<typename Container, typename Iterator>
Iterator View<Container, Iterator>::begin()
{
	return first;
}

template<typename Container, typename Iterator>
Iterator View<Container, Iterator>::end()
{
	return last;
}

}}
#endif // VIEW_HPP
