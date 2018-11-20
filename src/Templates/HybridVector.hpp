#ifndef TEMPLATES_HYBRIDVECTOR_HPP
#define TEMPLATES_HYBRIDVECTOR_HPP

#include <Templates/Array.hpp>
#include <Templates/Vector.hpp>
#include <Templates/Variant.hpp>
#include <Templates/Iterator.hpp>

// TODO: провести аудит кода и написать тесты.

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

	using typename Parent::SsizeType;

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
		if (isArrayIterator())
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
		if (isArrayIterator())
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
		if (isArrayIterator())
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
		if (isArrayIterator())
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

	SsizeType operator-(const Me &iterator)
	{
		if (isArrayIterator() && iterator.isArrayIterator())
		{
			const ArrayIterator &meIt = *(wrappedIterator.template get<ArrayIterator>());
			const ArrayIterator &itIt = *(iterator.wrappedIterator.template get<ArrayIterator>());
			return meIt - itIt;
		}
		else if (isVectorIterator() && iterator.isVectorIterator())
		{
			const VectorIterator &meIt = *(wrappedIterator.template get<VectorIterator>());
			const VectorIterator &itIt = *(iterator.wrappedIterator.template get<VectorIterator>());
			return meIt - itIt;
		}
		return SsizeType(0);
	}

	template<typename IntType>
	Me &operator+=(IntType value)
	{
		if (isArrayIterator())
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
		if (isArrayIterator())
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
			if (isArrayIterator())
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
			if (isArrayIterator())
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
			if (isArrayIterator())
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
			if (isArrayIterator())
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

	operator ArrayIterator()
	{
		ArrayIterator it;
		if (isArrayIterator())
		{
			it = *(wrappedIterator.template get<ArrayIterator>());
		}
		return it;
	}

	operator VectorIterator()
	{
		VectorIterator it;
		if (isVectorIterator())
		{
			it = *(wrappedIterator.template get<VectorIterator>());
		}
		return it;
	}

private:
	inline bool isArrayIterator() const noexcept
	{
		return wrappedIterator && wrappedIterator.template getCurrentIndex() == ARRAY_INDEX;
	}

	inline bool isVectorIterator() const noexcept
	{
		return wrappedIterator && wrappedIterator.template getCurrentIndex() == VECTOR_INDEX;
	}

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
	ConstIterator(Me &&) noexcept = default;

	ConstIterator(ConstArrayIterator iterator) : Parent(WrappedIterator(iterator))
	{}

	ConstIterator(ConstVectorIterator iterator) : Parent(WrappedIterator(iterator))
	{}

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) noexcept = default;

	Me &operator++()
	{
		if (isArrayIterator())
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
		if (isArrayIterator())
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
		if (isArrayIterator())
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
		if (isArrayIterator())
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
		if (isArrayIterator())
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
			if (isArrayIterator())
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
			if (isArrayIterator())
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
			if (isArrayIterator())
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
			if (isArrayIterator())
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
	inline bool isArrayIterator() const noexcept
	{
		return wrappedIterator && wrappedIterator.template getCurrentIndex() == ARRAY_INDEX;
	}

	inline bool isVectorIterator() const noexcept
	{
		return wrappedIterator && wrappedIterator.template getCurrentIndex() == VECTOR_INDEX;
	}

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

	using typename Traits::Type;

	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	using typename Traits::Pointer;
	using typename Traits::PointerToConst;

	using typename Traits::SizeType;
	using typename Traits::SsizeType;

	HybridVector() = default;
	HybridVector(const Me &) = default;
	HybridVector(Me &&) noexcept = default;

	HybridVector(const Array &array) : container(array)
	{}

	HybridVector(Array &&array) noexcept : container(move(array))
	{}

	HybridVector(const Vector &vector) : container(vector)
	{}

	HybridVector(Vector &&vector) noexcept : container(move(vector))
	{}

	~HybridVector() = default;

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) noexcept = default;

	Me &operator=(const Array &array)
	{
		container = array;
	}

	Me &operator=(Array &&array) noexcept
	{
		container = move(array);
	}

	Me &operator=(const Vector &vector)
	{
		container = vector;
	}

	Me &operator=(Vector &&vector) noexcept
	{
		container = move(vector);
	}

	template<typename IntType>
	Reference operator[](IntType index)
	{
		return this->begin()[index];
	}

	Pointer data()
	{
		if (container)
		{
			if (this->isArray())
			{
				Array &realContainer = *(container.template get<Array>());
				return realContainer.data();
			}
			else
			{
				Vector &realContainer = *(container.template get<Vector>());
				return realContainer.data();
			}
		}
		return Pointer();
	}

	PointerToConst data() const
	{
		if (container)
		{
			if (this->isArray())
			{
				const Array &realContainer = *(container.template get<Array>());
				return realContainer.data();
			}
			else
			{
				const Vector &realContainer = *(container.template get<Vector>());
				return realContainer.data();
			}
		}
		return Pointer();
	}

	SizeType size() const
	{
		if (container)
		{
			if (this->isArray())
			{
				const Array &realContainer = *(container.template get<Array>());
				return realContainer.size();
			}
			else
			{
				const Vector &realContainer = *(container.template get<Vector>());
				return realContainer.size();
			}
		}
		return SizeType();
	}

	SizeType capacity() const
	{
		if (container)
		{
			if (this->isArray())
			{
				const Array &realContainer = *(container.template get<Array>());
				return realContainer.capacity();
			}
			else
			{
				const Vector &realContainer = *(container.template get<Vector>());
				return realContainer.capacity();
			}
		}
		return SizeType();
	}

	inline void clean() noexcept
	{
		this->reset();
		container = Array{};
	}

	Me clone() const
	{
		Me copy;
		if (container)
		{
			if (this->isArray())
			{
				const Array &realContainer = *(container.template get<Array>());
				copy = Me(realContainer);
			}
			else
			{
				const Vector &realContainer = *(container.template get<Vector>());
				copy = Me(realContainer);
			}
		}
		return copy;
	}

	Iterator begin()
	{
		if (container)
		{
			if (this->isArray())
			{
				Array &realContainer = *(container.template get<Array>());
				return realContainer.begin();
			}
			else
			{
				Vector &realContainer = *(container.template get<Vector>());
				return realContainer.begin();
			}
		}
		return Iterator();
	}

	ConstIterator begin() const
	{
		if (container)
		{
			if (this->isArray())
			{
				const Array &realContainer = *(container.template get<Array>());
				return realContainer.begin();
			}
			else
			{
				const Vector &realContainer = *(container.template get<Vector>());
				return realContainer.begin();
			}
		}
		return ConstIterator();
	}

	ConstIterator cbegin() const
	{
		return this->begin();
	}

	ReverseIterator rbegin()
	{
		if (container)
		{
			if (this->isArray())
			{
				Array &realContainer = *(container.template get<Array>());
				return Iterator(--(realContainer.end()));
			}
			else
			{
				Vector &realContainer = *(container.template get<Vector>());
				return Iterator(--(realContainer.end()));
			}
		}
		return ReverseIterator{ Iterator{} };
	}

	ConstReverseIterator rbegin() const
	{
		if (container)
		{
			if (this->isArray())
			{
				const Array &realContainer = *(container.template get<Array>());
				return --(realContainer.end());
			}
			else
			{
				const Vector &realContainer = *(container.template get<Vector>());
				return --(realContainer.end());
			}
		}
		return ConstReverseIterator();
	}

	ConstReverseIterator crbegin() const
	{
		return this->rbegin();
	}

	Iterator end()
	{
		if (container)
		{
			if (this->isArray())
			{
				Array &realContainer = *(container.template get<Array>());
				return realContainer.end();
			}
			else
			{
				Vector &realContainer = *(container.template get<Vector>());
				return realContainer.end();
			}
		}
		return Iterator();
	}

	ConstIterator end() const
	{
		if (container)
		{
			if (this->isArray())
			{
				const Array &realContainer = *(container.template get<Array>());
				return realContainer.end();
			}
			else
			{
				const Vector &realContainer = *(container.template get<Vector>());
				return realContainer.end();
			}
		}
		return ConstIterator();
	}

	ConstIterator cend() const
	{
		return this->end();
	}

	ReverseIterator rend()
	{
		if (container)
		{
			if (this->isArray())
			{
				Array &realContainer = *(container.template get<Array>());
				return Iterator(--(realContainer.begin()));
			}
			else
			{
				Vector &realContainer = *(container.template get<Vector>());
				return Iterator(--(realContainer.begin()));
			}
		}
		return ReverseIterator{ Iterator{} };
	}

	ConstReverseIterator rend() const
	{
		if (container)
		{
			if (this->isArray())
			{
				const Array &realContainer = *(container.template get<Array>());
				return --(realContainer.begin());
			}
			else
			{
				const Vector &realContainer = *(container.template get<Vector>());
				return --(realContainer.begin());
			}
		}
		return ConstReverseIterator();
	}

	ConstReverseIterator crend() const
	{
		return this->rend();
	}

	void pushBack(ConstReference object)
	{
		if (container)
		{
			if (this->isArray())
			{
				Array *realContainer = container.template get<Array>();
				if (realContainer->capacity() > realContainer->size())
				{
					realContainer->pushBack(object);
				}
				else
				{
					this->useVector();
					this->pushBack(object);
				}
			}
			else
			{
				container.template get<Vector>()->pushBack(object);
			}
		}
		else
		{
			this->useArray();
			this->pushBack(object);
		}
	}

	void pushBack(MoveReference object)
	{
		if (container)
		{
			if (this->isArray())
			{
				Array *realContainer = container.template get<Array>();
				if (realContainer->capacity() > realContainer->size())
				{
					realContainer->pushBack(move(object));
				}
				else
				{
					this->useVector();
					this->pushBack(move(object));
				}
			}
			else
			{
				container.template get<Vector>()->pushBack(move(object));
			}
		}
		else
		{
			this->useArray();
			this->pushBack(move(object));
		}
	}

	template<typename ...Args>
	void emplaceBack(Args &&...args)
	{
		if (container)
		{
			if (this->isArray())
			{
				Array *realContainer = container.template get<Array>();
				if (realContainer->capacity() > realContainer->size())
				{
					realContainer->emplaceBack(forward(args)...);
				}
				else
				{
					this->useVector();
					this->emplaceBack(forward(args)...);
				}
			}
			else
			{
				container.template get<Vector>()->emplaceBack(forward(args)...);
			}
		}
		else
		{
			this->useArray();
			this->emplaceBack(forward(args)...);
		}
	}

	void popBack()
	{
		if (container)
		{
			if (this->isArray())
			{
				container.template get<Array>()->popBack();
			}
			else
			{
				container.template get<Vector>()->popBack();
			}
		}
	}

	void insert(Iterator it, ConstReference object)
	{
		if (container)
		{
			if (this->isArray())
			{
				Array *realContainer = container.template get<Array>();
				if (realContainer->capacity() > realContainer->size())
				{
					realContainer->insert(it.operator typename Array::Iterator(), object);
				}
				else
				{
					auto diff = this->begin() - it;

					this->useVector();

					it = this->begin() + diff;
					this->insert(it, object);
				}
			}
			else
			{
				container.template get<Vector>()->insert(it, object);
			}
		}
		else
		{
			this->useArray();
			this->insert(it, move(object));
		}
	}

	void insert(Iterator it, MoveReference object)
	{
		if (container)
		{
			if (this->isArray())
			{
				Array *realContainer = container.template get<Array>();
				if (realContainer->capacity() > realContainer->size())
				{
					realContainer->insert(it.operator typename Array::Iterator(), move(object));
				}
				else
				{
					auto diff = this->begin() - it;

					this->useVector();

					it = this->begin() + diff;
					this->insert(it, move(object));
				}
			}
			else
			{
				container.template get<Vector>()->insert(it, move(object));
			}
		}
		else
		{
			this->useArray();
			this->insert(it, move(object));
		}
	}

	template<typename InputIterator>
	void insert(Iterator it, InputIterator itBegin, InputIterator itEnd)
	{
		auto countElements = countIterations(itBegin, itEnd);
		if (container)
		{
			if (this->isArray())
			{
				Array *realContainer = container.template get<Array>();
				if (countElements < realContainer->capacity() - realContainer->size())
				{
					realContainer->insert(it.operator typename Array::Iterator(), itBegin, itEnd);
				}
				else
				{
					auto diff = this->begin() - it;

					this->useVector();

					it = this->begin() + diff;
					this->insert(it, itBegin, itEnd);
				}
			}
			else
			{
				container.template get<Vector>()->insert(
						it.operator typename Vector::Iterator()
						, itBegin, itEnd
				);
			}
		}
		else if (it == Iterator())
		{
			if (countElements > ARRAY_CAPACITY)
			{
				this->useVector();
				this->insert(this->end(), itBegin, itEnd);
			}
			else
			{
				this->useArray();
				this->insert(this->end(), itBegin, itEnd);
			}
		}
	}

	template<typename ...Args>
	void emplace(Iterator it, Args &&...args)
	{
		if (container)
		{
			if (this->isArray())
			{
				Array *realContainer = container.template get<Array>();
				if (realContainer->capacity() == realContainer->size())
				{
					auto diff = it - begin();

					this->useVector();

					it = begin() + diff;
					this->emplace(it, forward(args)...);
				}
				else
				{
					realContainer->emplace(it, forward(args)...);
				}
			}
			else
			{
				container.template get<Vector>()->emplace(it, forward(args)...);
			}
		}
		else
		{
			this->useArray();
			this->emplace(it, args...);
		}
	}

	void erase(Iterator it)
	{
		if (container)
		{
			if (this->isArray())
			{
				Array *realContainer = container.template get<Array>();
				realContainer->erase(it);
				if (!realContainer->size())
				{
					this->reset();
				}
			}
			else
			{
				Vector *realContainer = container.template get<Vector>();
				realContainer->erase(it);
				if (realContainer->size() < ARRAY_CAPACITY)
				{
					this->useArray();
				}
			}
		}
	}

	void erase(Iterator itBegin, Iterator itEnd)
	{
		if (container)
		{
			if (this->isArray())
			{
				Array *realContainer = container.template get<Array>();
				realContainer->erase(itBegin, itEnd);
				if (!realContainer->size())
				{
					this->reset();
				}
			}
			else
			{
				Vector *realContainer = container.template get<Vector>();
				realContainer->erase(itBegin, itEnd);
				if (realContainer->size() < ARRAY_CAPACITY)
				{
					this->useArray();
				}
			}
		}
	}

	void reset()
	{
		container.template reset();
	}

private:
	void useArray()
	{
		if (container)
		{
			if (this->isVector())
			{
				Vector *realContainer = container.template get<Vector>();
				auto range = makeRange(
						realContainer->begin(),
						realContainer->begin()
						+ (
								realContainer->size() > ARRAY_CAPACITY
										? ARRAY_CAPACITY
										: realContainer->size()
						)
				);

				Array array;
				for (Reference i : range)
				{
					array.pushBack(move(i));
				}

				this->reset();
				container = move(array);
			}
		}
		else
		{
			container = Array{};
		}
	}

	void useVector()
	{
		auto lambdaMakeVector = [](SizeType reserveSize) -> Vector
		{
			Vector vector;
			vector.reserve(reserveSize * SizeType(2));
			return vector;
		};

		if (container)
		{
			if (this->isArray())
			{
				Array *realContainer = container.template get<Array>();

				Vector vector = lambdaMakeVector(realContainer->size());
				for (Reference i : *realContainer)
				{
					vector.pushBack(move(i));
				}

				this->reset();
				container = move(vector);
			}
		}
		else
		{
			container = move(lambdaMakeVector(ARRAY_CAPACITY));
		}
	}

	inline bool isArray() const noexcept
	{
		return container
				&& container.template getCurrentIndex() == hybrid_vector_utils::ARRAY_INDEX;
	}

	inline bool isVector() const noexcept
	{
		return container
				&& container.template getCurrentIndex() == hybrid_vector_utils::VECTOR_INDEX;
	}

	ContainerVariant container;
};

}}

#endif // TEMPLATES_HYBRIDVECTOR_HPP
