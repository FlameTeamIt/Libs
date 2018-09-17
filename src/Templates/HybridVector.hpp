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

	using typename Parent::Type;

	using typename Parent::Reference;
	using typename Parent::ConstReference;

	using typename Parent::Pointer;
	using typename Parent::PointerToConst;

	Iterator() = default;
	Iterator(const Me &) = default;
	Iterator(Me &&) noexcept = default;

	Iterator(ArrayIterator iterator) : Parent(WrappedIterator(iterator))
	{}

	Iterator(VectorIterator iterator) : Parent(WrappedIterator(iterator))
	{}

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) noexcept = default;

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

	Pointer operator->()
	{
		return &(operator*());
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

	PointerToConst operator->() const
	{
		return &(operator*());
	}

	template<typename IntType>
	Me operator+(IntType value)
	{
		Me me = *this;
		me += value;
		return me;
	}

	template<typename IntType>
	Me operator-(IntType value)
	{
		Me me = *this;
		me -= value;
		return me;
	}

	template<typename IntType>
	Me &operator+=(IntType value)
	{
		if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
		{
			ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
			it += value;
		}
		else
		{
			VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
			it += value;
		}
		return *this;
	}

	template<typename IntType>
	Me &operator-=(IntType value)
	{
		if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
		{
			ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
			it -= value;
		}
		else
		{
			VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
			it -= value;
		}
		return *this;
	}

	bool operator==(const Me &iterator)
	{
		return wrappedIterator == iterator.wrappedIterator;
	}

	bool operator!=(const Me &iterator)
	{
		return !operator==(iterator);
	}

	bool operator<(const Me &iterator)
	{
		if (wrappedIterator.template getCurrentIndex() ==
				iterator.wrappedIterator.template getCurrentIndex())
		{
			if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
			{
				ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
				ArrayIterator &itIt = *(iterator.wrappedIterator.template get<ArrayIterator>());
				return it < itIt;
			}
			else
			{
				VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
				VectorIterator &itIt = *(iterator.wrappedIterator.template get<VectorIterator>());
				return it < itIt;
			}
		}
		return false;
	}

	bool operator>(const Me &iterator)
	{
		if (wrappedIterator.template getCurrentIndex() ==
				iterator.wrappedIterator.template getCurrentIndex())
		{
			if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
			{
				ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
				ArrayIterator &itIt = *(iterator.wrappedIterator.template get<ArrayIterator>());
				return it > itIt;
			}
			else
			{
				VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
				VectorIterator &itIt = *(iterator.wrappedIterator.template get<VectorIterator>());
				return it > itIt;
			}
		}
		return false;
	}

	bool operator<=(const Me &iterator)
	{
		if (wrappedIterator.template getCurrentIndex() ==
				iterator.wrappedIterator.template getCurrentIndex())
		{
			if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
			{
				ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
				ArrayIterator &itIt = *(iterator.wrappedIterator.template get<ArrayIterator>());
				return it <= itIt;
			}
			else
			{
				VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
				VectorIterator &itIt = *(iterator.wrappedIterator.template get<VectorIterator>());
				return it <= itIt;
			}
		}
		return false;
	}

	bool operator>=(const Me &iterator)
	{
		if (wrappedIterator.template getCurrentIndex() ==
				iterator.wrappedIterator.template getCurrentIndex())
		{
			if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
			{
				ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
				ArrayIterator &itIt = *(iterator.wrappedIterator.template get<ArrayIterator>());
				return it >= itIt;
			}
			else
			{
				VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
				VectorIterator &itIt = *(iterator.wrappedIterator.template get<VectorIterator>());
				return it >= itIt;
			}
		}
		return false;
	}

	template<typename IntType>
	Reference operator[](IntType index)
	{
		return operator->()[index];
	}

	template<typename IntType>
	ConstReference operator[](IntType index)
	{
		return operator->()[index];
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
				>::ConstIterator
				, typename flame_ide::templates::Vector<
					T, VectorTraits, VectorAllocator
				>::ConstIterator
			>
			, IteratorCategory::RANDOM_ACCESS
			, IteratorAccess::CONSTANT
			, Traits
		>
{
public:
	using Me = ConstIterator<
		T, ARRAY_CAPACITY, ArrayTraits, VectorTraits, VectorAllocator, Traits
	>;

	using ConstArrayIterator = typename flame_ide::templates::Array<
		T, ARRAY_CAPACITY, ArrayTraits, FalseType::VALUE
	>::ConstIterator;

	using ConstVectorIterator = typename flame_ide::templates::Vector<
		T, VectorTraits, VectorAllocator
	>::ConstIterator;

	using WrappedIterator = flame_ide::templates::Variant<ConstArrayIterator, ConstVectorIterator>;

	using Parent = iterator_utils::BaseIterator<
		Variant<
			ConstArrayIterator
			, ConstVectorIterator
		>
		, IteratorCategory::RANDOM_ACCESS
		, IteratorAccess::CONSTANT
		, Traits
	>;

	using typename Parent::Reference;
	using typename Parent::ConstReference;
	using typename Parent::Pointer;
	using typename Parent::PointerToConst;

	ConstIterator() = default;
	ConstIterator(const Me &) = default;
	ConstIterator(Me &&) = default;

	ConstIterator(ConstArrayIterator iterator) : Parent(WrappedIterator(iterator))
	{}

	ConstIterator(ConstVectorIterator iterator) : Parent(WrappedIterator(iterator))
	{}

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Me &operator++()
	{
		if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
		{
			ConstArrayIterator &it = *(wrappedIterator.template get<ConstArrayIterator>());
			++it;
		}
		else
		{
			ConstVectorIterator &it = *(wrappedIterator.template get<ConstVectorIterator>());
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
			ConstArrayIterator &it = *(wrappedIterator.template get<ConstArrayIterator>());
			--it;
		}
		else
		{
			ConstVectorIterator &it = *(wrappedIterator.template get<ConstVectorIterator>());
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

	ConstReference operator*() const
	{
		if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
		{
			const ConstArrayIterator &it = *(wrappedIterator.template get<ConstArrayIterator>());
			return *it;
		}
		else
		{
			const ConstVectorIterator &it = *(wrappedIterator.template get<ConstVectorIterator>());
			return *it;
		}
	}

	PointerToConst operator->() const
	{
		return &(operator*());
	}

	template<typename IntType>
	Me operator+(IntType value)
	{
		Me me = *this;
		me += value;
		return me;
	}

	template<typename IntType>
	Me operator-(IntType value)
	{
		Me me = *this;
		me -= value;
		return me;
	}

	template<typename IntType>
	Me &operator+=(IntType value)
	{
		if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
		{
			ConstArrayIterator &it = *(wrappedIterator.template get<ConstArrayIterator>());
			it += value;
		}
		else
		{
			ConstVectorIterator &it = *(wrappedIterator.template get<ConstVectorIterator>());
			it += value;
		}
		return *this;
	}

	template<typename IntType>
	Me &operator-=(IntType value)
	{
		if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
		{
			ConstArrayIterator &it = *(wrappedIterator.template get<ConstArrayIterator>());
			it -= value;
		}
		else
		{
			ConstVectorIterator &it = *(wrappedIterator.template get<ConstVectorIterator>());
			it -= value;
		}
		return *this;
	}

	bool operator==(const Me &iterator)
	{
		return wrappedIterator == iterator.wrappedIterator;
	}

	bool operator!=(const Me &iterator)
	{
		return !operator==(iterator);
	}

	bool operator<(const Me &iterator)
	{
		if (wrappedIterator.template getCurrentIndex() ==
				iterator.wrappedIterator.template getCurrentIndex())
		{
			if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
			{
				ConstArrayIterator &it = *(wrappedIterator.template get<ConstArrayIterator>());
				ConstArrayIterator &itIt = *(iterator.wrappedIterator.template get<ConstArrayIterator>());
				return it < itIt;
			}
			else
			{
				ConstVectorIterator &it = *(wrappedIterator.template get<ConstVectorIterator>());
				ConstVectorIterator &itIt = *(iterator.wrappedIterator.template get<ConstVectorIterator>());
				return it < itIt;
			}
		}
		return false;
	}

	bool operator>(const Me &iterator)
	{
		if (wrappedIterator.template getCurrentIndex() ==
				iterator.wrappedIterator.template getCurrentIndex())
		{
			if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
			{
				ConstArrayIterator &it = *(wrappedIterator.template get<ConstArrayIterator>());
				ConstArrayIterator &itIt = *(iterator.wrappedIterator.template get<ConstArrayIterator>());
				return it > itIt;
			}
			else
			{
				ConstVectorIterator &it = *(wrappedIterator.template get<ConstVectorIterator>());
				ConstVectorIterator &itIt = *(iterator.wrappedIterator.template get<ConstVectorIterator>());
				return it > itIt;
			}
		}
		return false;
	}

	bool operator<=(const Me &iterator)
	{
		if (wrappedIterator.template getCurrentIndex() ==
				iterator.wrappedIterator.template getCurrentIndex())
		{
			if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
			{
				ConstArrayIterator &it = *(wrappedIterator.template get<ConstArrayIterator>());
				ConstArrayIterator &itIt = *(iterator.wrappedIterator.template get<ConstArrayIterator>());
				return it <= itIt;
			}
			else
			{
				ConstVectorIterator &it = *(wrappedIterator.template get<ConstVectorIterator>());
				ConstVectorIterator &itIt = *(iterator.wrappedIterator.template get<ConstVectorIterator>());
				return it <= itIt;
			}
		}
		return false;
	}

	bool operator>=(const Me &iterator)
	{
		if (wrappedIterator.template getCurrentIndex() ==
				iterator.wrappedIterator.template getCurrentIndex())
		{
			if (wrappedIterator.template getCurrentIndex() == ARRAY_INDEX)
			{
				ConstArrayIterator &it = *(wrappedIterator.template get<ConstArrayIterator>());
				ConstArrayIterator &itIt = *(iterator.wrappedIterator.template get<ConstArrayIterator>());
				return it >= itIt;
			}
			else
			{
				ConstVectorIterator &it = *(wrappedIterator.template get<ConstVectorIterator>());
				ConstVectorIterator &itIt = *(iterator.wrappedIterator.template get<ConstVectorIterator>());
				return it >= itIt;
			}
		}
		return false;
	}

	template<typename IntType>
	ConstReference operator[](IntType index)
	{
		return operator->()[index];
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

	using ReverseIterator = flame_ide::templates::ReverseIterator<
		Iterator
	>;
	using ConstReverseIterator = flame_ide::templates::ConstReverseIterator<
		ConstIterator
	>;

	HybridVector();
	~HybridVector();

private:
	ContainerVariant container;
};

}}

#endif // TEMPLATES_HYBRIDVECTOR_HPP
