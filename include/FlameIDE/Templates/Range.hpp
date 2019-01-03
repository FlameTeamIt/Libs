#ifndef FLAMEIDE_TEMPLATES_RANGE_HPP
#define FLAMEIDE_TEMPLATES_RANGE_HPP

#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace templates
{

template<typename InputIterator>
class Range
{
public:
	using Me = Range<InputIterator>;
	using Iterator = InputIterator;

	Range() = delete;
	Range(const Me &) = default;
	Range(Me &&) noexcept = default;
	Range(Iterator itBegin, Iterator itEnd) noexcept;
	~Range() = default;

	Me &operator=(const Me &) noexcept = default;
	Me &operator=(Me &&) noexcept = default;

	Iterator begin() noexcept;
	Iterator end() noexcept;

	Iterator begin() const noexcept;
	Iterator end() const noexcept;

private:
	mutable Iterator first;
	mutable Iterator last;
};

template<typename Container>
Range<typename Container::Iterator>
makeRange(Container &container) noexcept;

template<typename InputIterator>
Range<InputIterator>
makeRange(InputIterator itBegin, InputIterator itEnd) noexcept;

template<typename Container>
Range<typename Container::ConstIterator>
makeConstRange(const Container &container) noexcept;

template<typename Container>
Range<typename Container::ReverseIterator>
makeReverseRange(Container &container) noexcept;

template<typename Container>
Range<typename Container::ConstReverseIterator>
makeConstReverseRange(const Container &container) noexcept;

}}

namespace flame_ide
{namespace templates
{

// Range

template<typename InputIterator>
Range<InputIterator>::Range(InputIterator itBegin, InputIterator itEnd) noexcept
		: first(itBegin), last(itEnd)
{}

template<typename InputIterator>
typename Range<InputIterator>::Iterator
Range<InputIterator>::begin() noexcept
{
	return first;
}

template<typename InputIterator>
typename Range<InputIterator>::Iterator
Range<InputIterator>::end() noexcept
{
	return last;
}

template<typename InputIterator>
typename Range<InputIterator>::Iterator
Range<InputIterator>::begin() const noexcept
{
	return first;
}

template<typename InputIterator>
typename Range<InputIterator>::Iterator
Range<InputIterator>::end() const noexcept
{
	return last;
}

// Range makers

template<typename Container>
Range<typename Container::Iterator>
makeRange(Container &container) noexcept
{
	return Range<typename Container::Iterator>(
			begin(container), end(container)
	);
}

template<typename InputIterator>
Range<InputIterator>
makeRange(InputIterator itBegin, InputIterator itEnd) noexcept
{
	return Range<InputIterator> (
			itBegin, itEnd
	);
}

template<typename Container>
Range<typename Container::ConstIterator>
makeConstRange(const Container &container) noexcept
{
	return Range<typename Container::ConstIterator>(
			cbegin(container), cend(container)
	);
}

template<typename Container>
Range<typename Container::ReverseIterator>
makeReverseRange(Container &container) noexcept
{
	return Range<typename Container::ConstIterator>(
			rbegin(container), rend(container)
	);
}

template<typename Container>
Range<typename Container::ConstReverseIterator>
makeConstReverseRange(const Container &container) noexcept
{
	return Range<typename Container::ConstIterator>(
			crbegin(container), crend(container)
	);
}

template<typename T>
Range<Types::uichar_t*> makeByteRange(T &value) noexcept
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
Range<const Types::uichar_t*> makeConstByteRange(const T &value) noexcept
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
#endif // FLAMEIDE_TEMPLATES_RANGE_HPP
