#ifndef TEMPLATES_HYBRIDVECTOR_HPP
#define TEMPLATES_HYBRIDVECTOR_HPP

#include <Templates/Array.hpp>
#include <Templates/Vector.hpp>
#include <Templates/Variant.hpp>
#include <Templates/Iterator.hpp>

namespace flame_ide
{namespace templates
{

namespace hybrid_vector_utils
{

enum
{
	ARRAY_INDEX
	, VECTOR_INDEX
};

template<typename T
	, SizeTraits::SizeType ARRAY_CAPACITY
	, typename ArrayTraits = ContainerTraits<T>
	, typename VectorTraits = ContainerTraits<T>
	, typename VectorAllocator = allocator::ArrayAllocator<T, VectorTraits>
	, typename Traits = ContainerTraits<T>
>
class Iterator: public
		iterator_utils::BaseIterator<
			Variant<
				typename Array<T, ARRAY_CAPACITY, ArrayTraits, FalseType::VALUE>::Iterator
				, typename Vector<T, VectorTraits, VectorAllocator>::Iterator
			>
			, IteratorCategory::RANDOM_ACCESS
			, IteratorAccess::NON_CONSTANT
			, Traits
		>
{
public:
	using ArrayIterator = typename flame_ide::templates::Array<
		T, ARRAY_CAPACITY, ArrayTraits, FalseType::VALUE
	>::Iterator;

	using VectorIterator = typename flame_ide::templates::Vector<
		T, VectorTraits, VectorAllocator
	>::Iterator;

	using WrappedIterator = flame_ide::templates::Variant<ArrayIterator, VectorIterator>;

	using Parent = iterator_utils::BaseIterator<
		WrappedIterator
		, IteratorCategory::RANDOM_ACCESS
		, IteratorAccess::NON_CONSTANT
		, Traits
	>;

	using Me = Iterator<
		T, ARRAY_CAPACITY, ArrayTraits, VectorTraits, VectorAllocator, Traits
	>;

	using typename Parent::Reference;
	using typename Parent::ConstReference;

	using typename Parent::Pointer;
	using typename Parent::PointerToConst;

	Iterator() = default;
	Iterator(const Me &) = default;
	Iterator(Me &&) = default;

	Iterator(ArrayIterator iterator) : Parent(WrappedIterator(iterator))
	{}

	Iterator(VectorIterator iterator) : Parent(WrappedIterator(iterator))
	{}

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Me &operator++()
	{
		if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
		{
			ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
			++it;
		}
		else
		{
			VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
			++it;
		}
		return *this;
	}

	Me operator++(int)
	{
		Me myCopy = *this;
		operator++();
		return myCopy;
	}

	Me &operator--()
	{
		if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
		{
			ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
			--it;
		}
		else
		{
			VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
			--it;
		}
		return *this;
	}

	Me operator--(int)
	{
		Me myCopy = *this;
		operator--();
		return myCopy;
	}

	bool operator==(const Me &iterator)
	{
		auto index = wrappedIterator.template getCurrentIndex();
		auto itIndex = iterator.wrappedIterator.template getCurrentIndex();
		if (index == itIndex)
		{
			if (index == ARRAY_INDEX)
			{
				ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
				ArrayIterator &itIt = *(iterator.wrappedIterator.template get<ArrayIterator>());
				return it == itIt;
			}
			else
			{
				VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
				VectorIterator &itIt = *(iterator.wrappedIterator.template get<VectorIterator>());
				return it == itIt;
			}
		}
		return false;
	}

	bool operator!=(const Me &iterator)
	{
		return !operator==(iterator);
	}

	Reference operator*()
	{
		if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
		{
			ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
			return *it;
		}
		else
		{
			VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
			return *it;
		}
	}

	ConstReference operator*() const
	{
		if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
		{
			const ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
			return *it;
		}
		else
		{
			const VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
			return *it;
		}
	}

	Pointer operator->()
	{
		return &(operator*());
	}

	PointerToConst operator->() const
	{
		return &(operator*());
	}

private:
	using Parent::internalData;
	using Parent::wrappedIterator;
};

template<typename T
	, flame_ide::SizeTraits::SizeType ARRAY_CAPACITY
	, typename ArrayTraits = flame_ide::ContainerTraits<T>
	, typename VectorTraits = flame_ide::ContainerTraits<T>
	, typename VectorAllocator = flame_ide::templates::allocator::ArrayAllocator<T, VectorTraits>
	, typename Traits = flame_ide::ContainerTraits<T>
>
class ConstIterator:
		public iterator_utils::BaseIterator<
			Variant<
				typename flame_ide::templates::Array<
					T, ARRAY_CAPACITY, ArrayTraits, FalseType::VALUE
				>::Iterator
				, typename flame_ide::templates::Vector<
					T, VectorTraits, VectorAllocator
				>::Iterator
			>
			, IteratorCategory::RANDOM_ACCESS
			, IteratorAccess::CONSTANT
			, Traits
		>
{
public:
	using Parent = iterator_utils::BaseIterator<
		Variant<
			typename flame_ide::templates::Array<
				T, ARRAY_CAPACITY, ArrayTraits, FalseType::VALUE
			>::ConstIterator
			, typename flame_ide::templates::Vector<
				T, VectorTraits, VectorAllocator
			>::ConstIterator
		>
		, IteratorCategory::RANDOM_ACCESS
		, IteratorAccess::CONSTANT
		, Traits
	>;

	using Me = ConstIterator<
		T, ARRAY_CAPACITY, ArrayTraits, VectorTraits, VectorAllocator, Traits
	>;

	using ConstArrayIterator = typename flame_ide::templates::Array<
		T, ARRAY_CAPACITY, ArrayTraits, FalseType::VALUE
	>::Iterator;

	using ConstVectorIterator = typename flame_ide::templates::Vector<
		T, VectorTraits, VectorAllocator
	>::ConstIterator;


	using typename Parent::Reference;
	using typename Parent::ConstReference;
	using typename Parent::Pointer;
	using typename Parent::PointerToConst;

	ConstIterator() = default;
	ConstIterator(const Me &) = default;
	ConstIterator(Me &&) = default;
	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Me &operator++();
	Me operator++(int);

	Me &operator--();
	Me operator--(int);

	ConstReference operator*() const
	{
	}

	PointerToConst operator->() const
	{
	}

private:
	using Parent::internalData;
	using Parent::wrappedIterator;
};

}

template<typename T
	, SizeTraits::SizeType ARRAY_CAPACITY
	, typename ArrayTraits = ContainerTraits<T>
	, typename VectorTraits = ContainerTraits<T>
	, typename VectorAllocator = allocator::ArrayAllocator<T, VectorTraits>
	, typename Traits = ContainerTraits<T>
>
class HybridVector: public Traits
{
public:
	using Array = flame_ide::templates::Array<T, ARRAY_CAPACITY, ArrayTraits, FalseType::VALUE>;
	using Vector = flame_ide::templates::Vector<T, VectorTraits, VectorAllocator>;
	using ContainerVariant = flame_ide::templates::Variant<Array, Vector>;

	using Me = HybridVector<
		T, ARRAY_CAPACITY, ArrayTraits, VectorTraits, VectorAllocator, Traits
	>;

	using Iterator = hybrid_vector_utils::Iterator<
		T, ARRAY_CAPACITY, ArrayTraits, VectorTraits, VectorAllocator
	>;

	using ConstIterator = hybrid_vector_utils::ConstIterator<
		T, ARRAY_CAPACITY, ArrayTraits, VectorTraits, VectorAllocator
	>;

	HybridVector();
	~HybridVector();

private:
	ContainerVariant container;
};

}}

#endif // TEMPLATES_HYBRIDVECTOR_HPP
