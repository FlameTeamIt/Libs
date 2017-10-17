#ifndef TEMPLATES_STRING_HPP
#define TEMPLATES_STRING_HPP

#include <Others/PrimitiveTypes.hpp>
#include <Templates/Allocator.hpp>
#include <Templates/Iterator.hpp>
#include <Templates/View.hpp>

#define TEMPLATE_TYPE \
	template< \
		typename T, typename Traits, typename Allocator\
	>

#define STRING_TYPE \
	BasicString<T, Traits, Allocator>

// Define classes

namespace flame_ide
{namespace templates
{

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ArrayAllocator<T>>
class BasicString;

using String = BasicString<char>;
using U8String = BasicString<Types::uchar_t>;
using U16String = BasicString<Types::ushort_t>;
using U32String = BasicString<Types::uint_t>;

}}

// Define types

namespace flame_ide
{namespace templates
{

TEMPLATE_TYPE
class BasicString: public Traits
{
public:
	using Me = STRING_TYPE;

	using typename Traits::Type;

	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	using typename Traits::Pointer;
	using typename Traits::PointerToConst;

	using typename Traits::SizeType;
	using typename Traits::SsizeType;

	using Iterator = flame_ide::templates::Iterator<
			Pointer, IteratorCategory::RANDOM_ACCESS, Traits
	>;
	using ConstIterator = flame_ide::templates::ConstIterator<
			PointerToConst, IteratorCategory::RANDOM_ACCESS, Traits
	>;
	using ReverseIterator = flame_ide::templates::ReverseIterator<Iterator>;
	using ConstReverseIterator = flame_ide::templates::ConstIterator<ReverseIterator>;

	BasicString();
	BasicString(const Me &string);
	BasicString(Me &&string);
	BasicString(const T *);
	~BasicString();
	Me &operator=(const Me &string);
	Me &operator=(Me &&string);

	// TODO: implement and test
	Me &operator+=(const T &object);
	Me &operator+=(T &&object);
	template<typename IntType>
	Me &operator+=(IntType integer);
	Me &operator+=(const Me &string);

	template<typename InputIterator>
	Me &operator+=(Range<InputIterator> range);

	// TODO: implement and test
	Me &operator-=(Iterator it);
	Me &operator-=(ConstIterator it);
	Me &operator-=(ReverseIterator it);
	Me &operator-=(ConstReverseIterator it);

	// TODO: implement and test
	Me &operator-=(Range<Iterator> range);
	Me &operator-=(Range<ConstIterator> range);
	Me &operator-=(Range<ReverseIterator> range);
	Me &operator-=(Range<ConstReverseIterator> range);

	template<typename IntType>
	const T &operator[](IntType integer);

	template<typename IntType>
	T &operator[](IntType integer);

	template<typename IntType>
	Me operator+(IntType integer);
	Me operator+(const Me &string);

	SizeType size() const noexcept;
	SizeType capacity() const noexcept;
	PointerToConst data() const noexcept;

	void clean();

	Me clone() const;

	Iterator begin() noexcept;
	ConstIterator begin() const noexcept;
	ConstIterator cbegin() const noexcept;
	ReverseIterator rbegin() noexcept;
	ConstReverseIterator rbegin() const noexcept;
	ConstReverseIterator crbegin() const noexcept;

	Iterator end() noexcept;
	ConstIterator end() const noexcept;
	ConstIterator cend() const noexcept;
	ReverseIterator rend() noexcept;
	ConstReverseIterator rend() const noexcept;
	ConstReverseIterator crend() const noexcept;

	void pushBack(const T &object);
	void pushBack(T &&object);
	void pushBack(const T *array);

	void popBack();

	void insert(Iterator it, const T &object);
	void insert(Iterator it, T &&object);
	template<typename InputIterator>
	void insert(Iterator it, InputIterator itBegin, InputIterator itEnd);

	void erase(Iterator it);
	void erase(Iterator itBegin, Iterator itEnd);

private:
	Pointer head;
	Pointer tail;
	SizeType stringCapacity;
};

}}

#endif // TEMPLATES_STRING_HPP
