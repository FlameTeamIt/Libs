#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <Templates/Traits.hpp>

namespace flame_ide
{namespace templates
{

template<typename Iterator, typename Traits = DefaultTraits<typename Iterator::Type>>
class ReverseIterator
{
public:
	using Me = ReverseIterator<Iterator, Traits>;
	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;

	ReverseIterator() = default;
	ReverseIterator(const Me &iterator) = default;
	ReverseIterator(Me &&iterator) = default;

	ReverseIterator(Iterator it);

	~ReverseIterator() = default;

	inline Me &operator=(const Me &revIt) = default;
	inline Me &operator=(Me &&revIt) = default;

	inline bool operator==(const Me &revIt) const;
	inline bool operator!=(const Me &revIt) const;

	inline Me &operator++();
	inline Me operator++(int);

	inline const Me &operator++() const;
	inline const Me operator++(int) const;

	inline Me &operator--();
	inline Me operator--(int);

	inline const Me &operator--() const;
	inline const Me operator--(int) const;

	inline Reference operator*();
	inline ConstReference operator*() const;

	inline Pointer operator->();
	inline PointerToConst operator->() const;

private:
	Iterator wrappedIterator;
};

template<typename Iterator, typename Traits = DefaultTraits<typename Iterator::Type>>
class RaReverseIterator
{
public:
	using Me = RaReverseIterator<Iterator, Traits>;
	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;

	RaReverseIterator() = default;
	RaReverseIterator(const RaReverseIterator<Iterator, Traits> &) = default;
	RaReverseIterator(RaReverseIterator<Iterator, Traits> &&) = default;
	~RaReverseIterator() = default;

	RaReverseIterator(Iterator it);

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	inline bool operator==(const Me &revIt) const;
	inline bool operator!=(const Me &revIt) const;

	inline Me &operator++();
	inline Me operator++(int);
	inline const Me &operator++() const;
	inline const Me operator++(int) const;

	inline Me &operator--();
	inline Me operator--(int);
	inline const Me &operator--() const;
	inline const Me operator--(int) const;

	inline Me &operator+=(SizeTraits::SsizeType size);
	inline const Me &operator+=(SizeTraits::SsizeType size) const;

	inline Me &operator-=(SizeTraits::SsizeType size);
	inline const Me &operator-=(SizeTraits::SsizeType size) const;

	inline Reference operator*();
	inline ConstReference operator*() const;

	inline Pointer operator->();
	inline PointerToConst operator->() const;

private:
	Iterator wrappedIterator;
};

template<typename Iterator, typename Traits>
RaReverseIterator<Iterator, Traits> operator+(
		RaReverseIterator<Iterator, Traits> it, SizeTraits::SsizeType size);

template<typename Iterator, typename Traits>
RaReverseIterator<Iterator, Traits> operator+(
		SizeTraits::SsizeType size, RaReverseIterator<Iterator, Traits> it);

template<typename Iterator, typename Traits>
RaReverseIterator<Iterator, Traits> operator-(
		RaReverseIterator<Iterator, Traits> it, SizeTraits::SsizeType size);

}}

namespace flame_ide
{namespace templates
{

// ReverseIterator

template<typename Iterator, typename Traits>
ReverseIterator<Iterator, Traits>::ReverseIterator(Iterator it)
		: wrappedIterator(it)
{}

template<typename Iterator, typename Traits> inline
bool ReverseIterator<Iterator, Traits>::operator==(
		const ReverseIterator<Iterator, Traits> &revIt) const
{
	return wrappedIterator = revIt.wrappedIterator;
}

template<typename Iterator, typename Traits> inline
bool ReverseIterator<Iterator, Traits>::operator!=(
		const ReverseIterator<Iterator, Traits> &revIt) const
{
	return !(*this == revIt);
}

template<typename Iterator, typename Traits> inline
ReverseIterator<Iterator, Traits> &
ReverseIterator<Iterator, Traits>::operator++()
{
	--wrappedIterator;
	return *this;
}

template<typename Iterator, typename Traits> inline
ReverseIterator<Iterator, Traits>
ReverseIterator<Iterator, Traits>::operator++(int)
{
	ReverseIterator returnIt = *this;
	--wrappedIterator;
	return returnIt;

}

template<typename Iterator, typename Traits> inline
const ReverseIterator<Iterator, Traits> &
ReverseIterator<Iterator, Traits>::operator++() const
{
	--wrappedIterator;
	return *this;
}

template<typename Iterator, typename Traits> inline
const ReverseIterator<Iterator, Traits>
ReverseIterator<Iterator, Traits>::operator++(int) const
{
	ReverseIterator returnIt = *this;
	--wrappedIterator;
	return returnIt;
}

template<typename Iterator, typename Traits> inline
ReverseIterator<Iterator, Traits> &
ReverseIterator<Iterator, Traits>::operator--()
{
	++wrappedIterator;
	return *this;
}

template<typename Iterator, typename Traits> inline
ReverseIterator<Iterator, Traits>
ReverseIterator<Iterator, Traits>::operator--(int)
{
	ReverseIterator returnIt = *this;
	++wrappedIterator;
	return returnIt;
}

template<typename Iterator, typename Traits> inline
const ReverseIterator<Iterator, Traits> &
ReverseIterator<Iterator, Traits>::operator--() const
{
	++wrappedIterator;
	return *this;
}

template<typename Iterator, typename Traits> inline
const ReverseIterator<Iterator, Traits>
ReverseIterator<Iterator, Traits>::operator--(int) const
{
	ReverseIterator returnIt = *this;
	++wrappedIterator;
	return returnIt;
}

template<typename Iterator, typename Traits> inline
typename ReverseIterator<Iterator, Traits>::Reference
ReverseIterator<Iterator, Traits>::operator*()
{
	return *wrappedIterator;
}

template<typename Iterator, typename Traits> inline
typename ReverseIterator<Iterator, Traits>::ConstReference
ReverseIterator<Iterator, Traits>::operator*() const
{
	return *wrappedIterator;
}

template<typename Iterator, typename Traits> inline
typename ReverseIterator<Iterator, Traits>::Pointer
ReverseIterator<Iterator, Traits>::operator->()
{
	return wrappedIterator.operator->();
}

template<typename Iterator, typename Traits> inline
typename ReverseIterator<Iterator, Traits>::PointerToConst
ReverseIterator<Iterator, Traits>::operator->() const
{
	return wrappedIterator.operator->();
}

// RaReverseIterator

template<typename Iterator, typename Traits>
RaReverseIterator<Iterator, Traits>::RaReverseIterator(Iterator it)
		: wrappedIterator(it)
{}

template<typename Iterator, typename Traits> inline
bool RaReverseIterator<Iterator, Traits>::operator==(
		const RaReverseIterator<Iterator, Traits> &revIt) const
{
	return wrappedIterator = revIt.wrappedIterator;
}

template<typename Iterator, typename Traits> inline
bool RaReverseIterator<Iterator, Traits>::operator!=(
		const RaReverseIterator<Iterator, Traits> &revIt) const
{
	return !(*this == revIt);
}

template<typename Iterator, typename Traits> inline
RaReverseIterator<Iterator, Traits> &
RaReverseIterator<Iterator, Traits>::operator++()
{
	--wrappedIterator;
	return *this;
}

template<typename Iterator, typename Traits> inline
RaReverseIterator<Iterator, Traits>
RaReverseIterator<Iterator, Traits>::operator++(int)
{
	RaReverseIterator returnIt = *this;
	--wrappedIterator;
	return returnIt;

}

template<typename Iterator, typename Traits> inline
const RaReverseIterator<Iterator, Traits> &
RaReverseIterator<Iterator, Traits>::operator++() const
{
	--wrappedIterator;
	return *this;
}

template<typename Iterator, typename Traits> inline
const RaReverseIterator<Iterator, Traits>
RaReverseIterator<Iterator, Traits>::operator++(int) const
{
	RaReverseIterator returnIt = *this;
	--wrappedIterator;
	return returnIt;
}

template<typename Iterator, typename Traits> inline
RaReverseIterator<Iterator, Traits> &
RaReverseIterator<Iterator, Traits>::operator--()
{
	++wrappedIterator;
	return *this;
}

template<typename Iterator, typename Traits> inline
RaReverseIterator<Iterator, Traits>
RaReverseIterator<Iterator, Traits>::operator--(int)
{
	RaReverseIterator returnIt = *this;
	++wrappedIterator;
	return returnIt;
}

template<typename Iterator, typename Traits> inline
const RaReverseIterator<Iterator, Traits> &
RaReverseIterator<Iterator, Traits>::operator--() const
{
	++wrappedIterator;
	return *this;
}

template<typename Iterator, typename Traits> inline
const RaReverseIterator<Iterator, Traits>
RaReverseIterator<Iterator, Traits>::operator--(int) const
{
	RaReverseIterator returnIt = *this;
	++wrappedIterator;
	return returnIt;
}

template<typename Iterator, typename Traits> inline
RaReverseIterator<Iterator, Traits> &
RaReverseIterator<Iterator, Traits>::operator+=(SizeTraits::SsizeType size)
{
	wrappedIterator -= size;
	return *this;
}

template<typename Iterator, typename Traits> inline
const RaReverseIterator<Iterator, Traits> &
RaReverseIterator<Iterator, Traits>::operator+=(SizeTraits::SsizeType size) const
{
	wrappedIterator -= size;
	return *this;
}

template<typename Iterator, typename Traits> inline
RaReverseIterator<Iterator, Traits> &
RaReverseIterator<Iterator, Traits>::operator-=(SizeTraits::SsizeType size)
{
	wrappedIterator += size;
	return *this;
}

template<typename Iterator, typename Traits> inline
const RaReverseIterator<Iterator, Traits> &
RaReverseIterator<Iterator, Traits>::operator-=(SizeTraits::SsizeType size) const
{
	wrappedIterator += size;
	return *this;
}

template<typename Iterator, typename Traits> inline
typename RaReverseIterator<Iterator, Traits>::Reference
RaReverseIterator<Iterator, Traits>::operator*()
{
	return *wrappedIterator;
}

template<typename Iterator, typename Traits> inline
typename RaReverseIterator<Iterator, Traits>::ConstReference
RaReverseIterator<Iterator, Traits>::operator*() const
{
	return *wrappedIterator;
}

template<typename Iterator, typename Traits> inline
typename RaReverseIterator<Iterator, Traits>::Pointer
RaReverseIterator<Iterator, Traits>::operator->()
{
	return wrappedIterator.operator->();
}

template<typename Iterator, typename Traits> inline
typename RaReverseIterator<Iterator, Traits>::PointerToConst
RaReverseIterator<Iterator, Traits>::operator->() const
{
	return wrappedIterator.operator->();
}

template<typename Iterator, typename Traits>
RaReverseIterator<Iterator, Traits> operator+(
		RaReverseIterator<Iterator, Traits> it, SizeTraits::SsizeType size)
{
	it -= size;
	return it;
}

template<typename Iterator, typename Traits>
RaReverseIterator<Iterator, Traits> operator+(
		SizeTraits::SsizeType size, RaReverseIterator<Iterator, Traits> it)
{
	it -= size;
	return it;
}

template<typename Iterator, typename Traits>
RaReverseIterator<Iterator, Traits> operator-(
		RaReverseIterator<Iterator, Traits> it, SizeTraits::SsizeType size)
{
	it += size;
	return it;
}

}}
#endif // ITERATOR_HPP
