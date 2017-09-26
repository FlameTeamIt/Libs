#ifndef TEMPLATES_STRING_HPP
#define TEMPLATES_STRING_HPP

#include <Others/PrimitiveTypes.hpp>
#include <Templates/Allocator.hpp>
#include <Templates/Iterator.hpp>

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

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ArrayAllocator<T>>
class BasicString: public Traits
{
public:
	using Me = BasicString<T, Traits, Allocator>;

	using typename Traits::Type;

	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	using typename Traits::Pointer;

	using typename Traits::SizeType;
	using typename Traits::SsizeType;

	using Iterator = flame_ide::templates::Iterator<Pointer
			, IteratorCategory::RANDOM_ACCESS, Traits>;
	using ConstIterator = flame_ide::templates::ConstIterator<Iterator>;
	using ReverseIterator = flame_ide::templates::ReverseIterator<Iterator>;
	using ConstReverseIterator = flame_ide::templates::ConstIterator<ReverseIterator>;

	BasicString();
	BasicString(const Me &string);
	BasicString(Me &&string);
	~BasicString();
	Me &operator=(const Me &string);
	Me &operator=(Me &&string);

	Me &operator+=();

private:
	T *head;
	T *tail;
	SizeType stringCapacity;
};

}}

#endif // TEMPLATES_STRING_HPP
