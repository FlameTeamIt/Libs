#ifndef FLAMEIDE_TEMPLATES_HYBRIDVECTOR_HPP
#define FLAMEIDE_TEMPLATES_HYBRIDVECTOR_HPP

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/Vector.hpp>
#include <FlameIDE/Templates/Variant.hpp>
#include <FlameIDE/Templates/Iterator.hpp>

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

template<
	typename T
	, SizeTraits::SizeType ARRAY_CAPACITY
	, typename ArrayTraits = ContainerTraits<T>
	, typename VectorTraits = ContainerTraits<T>
	, typename VectorAllocator = allocator::ArrayAllocator<T, VectorTraits>
	, typename Traits = ContainerTraits<T>
>
class Iterator: public
		iterator_utils::BaseIterator<
			Variant<
				typename Array<
					T, ARRAY_CAPACITY, FalseType::VALUE, ArrayTraits
				>::Iterator
				, typename Vector<T, VectorTraits, VectorAllocator>::Iterator
			>
			, IteratorCategory::RANDOM_ACCESS
			, IteratorAccess::NON_CONSTANT
			, Traits
		>
{
public:
	using ArrayIterator = typename flame_ide::templates::Array<
		T, ARRAY_CAPACITY, FalseType::VALUE, ArrayTraits
	>::Iterator;

	using VectorIterator = typename flame_ide::templates::Vector<
		T, VectorTraits, VectorAllocator
	>::Iterator;

	using WrappedIterator = flame_ide::templates::Variant<
		ArrayIterator, VectorIterator
	>;

	using Parent = iterator_utils::BaseIterator<
		Variant<
			typename Array<T, ARRAY_CAPACITY, FalseType::VALUE, ArrayTraits>::Iterator
			, typename Vector<T, VectorTraits, VectorAllocator>::Iterator
		>
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
	Iterator(const Me &it) noexcept : Parent(it)
	{}

	Iterator(Me &&) noexcept = default;
	Iterator(ArrayIterator iterator);
	Iterator(VectorIterator iterator);

	Me &operator=(const Me &) noexcept = default;
	Me &operator=(Me &&) noexcept = default;

	Me &operator++();
	Me operator++(int);

	Me &operator--();
	Me operator--(int);

	Reference operator*();
	Pointer operator->();

	ConstReference operator*() const;
	PointerToConst operator->() const;

	template<typename IntType>
	Me operator+(IntType value);

	template<typename IntType>
	Me operator-(IntType value);
	SsizeType operator-(const Me &iterator);

	template<typename IntType>
	Me &operator+=(IntType value);

	template<typename IntType>
	Me &operator-=(IntType value);

	bool operator==(const Me &iterator) const;

	bool operator!=(const Me &iterator) const;

	bool operator<(const Me &iterator) const;

	bool operator>(const Me &iterator) const;

	bool operator<=(const Me &iterator) const;

	bool operator>=(const Me &iterator) const;

	template<typename IntType>
	Reference operator[](IntType index);

	template<typename IntType>
	ConstReference operator[](IntType index) const;

	operator ArrayIterator() noexcept;

	operator VectorIterator() noexcept;

private:
	inline bool isArrayIterator() const noexcept;

	inline bool isVectorIterator() const noexcept;

	using Parent::internalData;
	using Parent::wrappedIterator;
};

template<typename T
	, flame_ide::SizeTraits::SizeType ARRAY_CAPACITY
	, typename ArrayTraits = flame_ide::ContainerTraits<T>
	, typename VectorTraits = flame_ide::ContainerTraits<T>
	, typename VectorAllocator =
			flame_ide::templates::allocator::ArrayAllocator<T, VectorTraits>
	, typename Traits = flame_ide::ContainerTraits<T>
>
class ConstIterator:
		public iterator_utils::BaseIterator<
			Variant<
				typename flame_ide::templates::Array<
					T, ARRAY_CAPACITY, FalseType::VALUE, ArrayTraits
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
		T, ARRAY_CAPACITY, FalseType::VALUE, ArrayTraits
	>::ConstIterator;

	using ConstVectorIterator = typename flame_ide::templates::Vector<
		T, VectorTraits, VectorAllocator
	>::ConstIterator;

	using WrappedIterator = flame_ide::templates::Variant<
		ConstArrayIterator, ConstVectorIterator
	>;

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
	ConstIterator(const Me &it) noexcept : Parent(it)
	{}
	ConstIterator(Me &&) noexcept = default;

	ConstIterator(ConstArrayIterator iterator) noexcept;

	ConstIterator(ConstVectorIterator iterator) noexcept;

	Me &operator=(const Me &) noexcept = default;
	Me &operator=(Me &&) noexcept = default;

	Me &operator++();

	Me operator++(int);

	Me &operator--();

	Me operator--(int);

	ConstReference operator*() const;

	PointerToConst operator->() const;

	template<typename IntType>
	Me operator+(IntType value);

	template<typename IntType>
	Me operator-(IntType value);

	template<typename IntType>
	Me &operator+=(IntType value);

	template<typename IntType>
	Me &operator-=(IntType value);

	bool operator==(const Me &iterator) const;

	bool operator!=(const Me &iterator) const;

	bool operator<(const Me &iterator) const;

	bool operator>(const Me &iterator) const;

	bool operator<=(const Me &iterator) const;

	bool operator>=(const Me &iterator) const;

	template<typename IntType>
	ConstReference operator[](IntType index) const;

	operator ConstArrayIterator() noexcept;

	operator ConstVectorIterator() noexcept;

private:
	inline bool isArrayIterator() const noexcept;

	inline bool isVectorIterator() const noexcept;

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
class HybridVector
{
public:
	using Array = flame_ide::templates::Array<
		T, ARRAY_CAPACITY, FalseType::VALUE, ArrayTraits
	>;
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

	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using SizeType = typename Traits::SizeType;
	using SsizeType = typename Traits::SsizeType;

	HybridVector() = default;
	HybridVector(const Me &) = default;
	HybridVector(Me &&) noexcept = default;

	///
	/// @brief HybridVector
	/// @param array
	///
	HybridVector(const Array &array) noexcept;

	///
	/// @brief HybridVector
	/// @param array
	///
	HybridVector(Array &&array) noexcept;

	///
	/// @brief HybridVector
	/// @param vector
	///
	HybridVector(const Vector &vector) noexcept;

	///
	/// @brief HybridVector
	/// @param vector
	///
	HybridVector(Vector &&vector) noexcept;

	~HybridVector() = default;

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) noexcept = default;

	///
	/// @brief operator =
	/// @param array
	/// @return
	///
	Me &operator=(const Array &array) noexcept;

	///
	/// @brief operator =
	/// @param array
	/// @return
	///
	Me &operator=(Array &&array) noexcept;

	///
	/// @brief operator =
	/// @param vector
	/// @return
	///
	Me &operator=(const Vector &vector) noexcept;

	///
	/// @brief operator =
	/// @param vector
	/// @return
	///
	Me &operator=(Vector &&vector) noexcept;

	///
	/// @brief operator []
	/// @param index
	/// @return
	///
	template<typename IntType>
	Reference operator[](IntType index) noexcept;

	///
	/// @brief operator []
	/// @param index
	/// @return
	///
	template<typename IntType>
	ConstReference operator[](IntType index) const noexcept;

	///
	/// @brief data
	/// @return
	///
	Pointer data() noexcept;

	///
	/// @brief data
	/// @return
	///
	PointerToConst data() const noexcept;

	///
	/// @brief size
	/// @return
	///
	SizeType size() const noexcept;

	///
	/// @brief capacity
	/// @return
	///
	SizeType capacity() const noexcept;

	///
	/// @brief clean
	///
	inline void clean() noexcept;

	///
	/// @brief clone
	/// @return
	///
	Me clone() const;

	///
	/// @brief begin
	/// @return
	///
	Iterator begin();

	///
	/// @brief begin
	/// @return
	///
	ConstIterator begin() const;

	///
	/// @brief cbegin
	/// @return
	///
	ConstIterator cbegin() const;

	///
	/// @brief rbegin
	/// @return
	///
	ReverseIterator rbegin();

	///
	/// @brief rbegin
	/// @return
	///
	ConstReverseIterator rbegin() const;

	///
	/// @brief crbegin
	/// @return
	///
	ConstReverseIterator crbegin() const;

	///
	/// @brief end
	/// @return
	///
	Iterator end();

	///
	/// @brief end
	/// @return
	///
	ConstIterator end() const;

	///
	/// @brief cend
	/// @return
	///
	ConstIterator cend() const;

	///
	/// @brief rend
	/// @return
	///
	ReverseIterator rend();

	///
	/// @brief rend
	/// @return
	///
	ConstReverseIterator rend() const;

	///
	/// @brief crend
	/// @return
	///
	ConstReverseIterator crend() const;

	///
	/// @brief pushBack
	/// @param object
	///
	void pushBack(ConstReference object);

	///
	/// @brief pushBack
	/// @param object
	///
	void pushBack(MoveReference object);

	///
	/// @brief emplaceBack
	/// @param args
	///
	template<typename ...Args>
	void emplaceBack(Args &&...args);

	///
	/// @brief popBack
	///
	void popBack();

	///
	/// @brief insert
	/// @param it
	/// @param object
	///
	void insert(Iterator it, ConstReference object);

	///
	/// @brief insert
	/// @param it
	/// @param object
	///
	void insert(Iterator it, MoveReference object);

	///
	/// @brief insert
	/// @param it
	/// @param itBegin
	/// @param itEnd
	///
	template<typename InputIterator>
	void insert(Iterator it, InputIterator itBegin, InputIterator itEnd);

	///
	/// @brief emplace
	/// @param it
	/// @param args
	///
	template<typename ...Args>
	void emplace(Iterator it, Args &&...args);

	///
	/// @brief erase
	/// @param it
	///
	void erase(Iterator it);

	///
	/// @brief erase
	/// @param itBegin
	/// @param itEnd
	///
	void erase(Iterator itBegin, Iterator itEnd);

	///
	/// @brief reset
	///
	void reset();

private:
	///
	/// @brief useArray
	///
	void useArray();

	///
	/// @brief useVector
	///
	void useVector();

	///
	/// @brief isArray
	/// @return
	///
	inline bool isArray() const noexcept;

	///
	/// @brief isVector
	/// @return
	///
	inline bool isVector() const noexcept;

	ContainerVariant container; ///<
};

}}

namespace flame_ide
{namespace templates
{

namespace hybrid_vector_utils
{

// Iterator<
//     T, ARRAY_CAPACITY
//     , ArrayTraits, VectorTraits
//     , VectorAllocator
//     , Traits
// >

#define ITERATOR_TEMPLATE \
template< \
	typename T \
	, SizeTraits::SizeType ARRAY_CAPACITY \
	, typename ArrayTraits, typename VectorTraits \
	, typename VectorAllocator \
	, typename Traits \
>

#define ITERATOR_TYPE \
Iterator< \
	T, ARRAY_CAPACITY, ArrayTraits, VectorTraits, VectorAllocator, Traits \
>

ITERATOR_TEMPLATE
ITERATOR_TYPE::Iterator(ArrayIterator iterator) :
		Parent(WrappedIterator(iterator))
{}

ITERATOR_TEMPLATE
ITERATOR_TYPE::Iterator(VectorIterator iterator) :
		Parent(WrappedIterator(iterator))
{}

ITERATOR_TEMPLATE
ITERATOR_TYPE &ITERATOR_TYPE::operator++()
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

ITERATOR_TEMPLATE
ITERATOR_TYPE ITERATOR_TYPE::operator++(int)
{
	Me myCopy = *this;
	operator++();
	return myCopy;
}

ITERATOR_TEMPLATE
ITERATOR_TYPE &ITERATOR_TYPE::operator--()
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

ITERATOR_TEMPLATE
ITERATOR_TYPE ITERATOR_TYPE::operator--(int)
{
	Me myCopy = *this;
	operator--();
	return myCopy;
}

ITERATOR_TEMPLATE
typename ITERATOR_TYPE::Reference ITERATOR_TYPE::operator*()
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

ITERATOR_TEMPLATE
typename ITERATOR_TYPE::Pointer ITERATOR_TYPE::operator->()
{
	return &(operator*());
}

ITERATOR_TEMPLATE
typename ITERATOR_TYPE::ConstReference
ITERATOR_TYPE::operator*() const
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

ITERATOR_TEMPLATE
typename ITERATOR_TYPE::PointerToConst
ITERATOR_TYPE::operator->() const
{
	return &(operator*());
}

ITERATOR_TEMPLATE
template<typename IntType>
ITERATOR_TYPE ITERATOR_TYPE::operator+(IntType value)
{
	static_assert(IsIntegralType<IntType>::VALUE, "Need itegral contant.");

	Me me = *this;
	me += value;
	return me;
}

ITERATOR_TEMPLATE
template<typename IntType>
ITERATOR_TYPE ITERATOR_TYPE::operator-(IntType value)
{
	static_assert(IsIntegralType<IntType>::VALUE, "Need itegral contant.");

	Me me = *this;
	me -= value;
	return me;
}

ITERATOR_TEMPLATE
typename ITERATOR_TYPE::SsizeType
ITERATOR_TYPE::operator-(const Me &iterator)
{
	if (isArrayIterator() && iterator.isArrayIterator())
	{
		const ArrayIterator &meIt = *(
				wrappedIterator.template get<ArrayIterator>()
		);
		const ArrayIterator &itIt = *(
				iterator.wrappedIterator.template get<ArrayIterator>()
		);
		return meIt - itIt;
	}
	else if (isVectorIterator() && iterator.isVectorIterator())
	{
		const VectorIterator &meIt = *(
				wrappedIterator.template get<VectorIterator>()
		);
		const VectorIterator &itIt = *(
				iterator.wrappedIterator.template get<VectorIterator>()
		);
		return meIt - itIt;
	}
	return SsizeType(0);
}

ITERATOR_TEMPLATE
template<typename IntType>
ITERATOR_TYPE &ITERATOR_TYPE::operator+=(IntType value)
{
	static_assert(IsIntegralType<IntType>::VALUE, "Need itegral contant.");

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

ITERATOR_TEMPLATE
template<typename IntType>
ITERATOR_TYPE &ITERATOR_TYPE::operator-=(IntType value)
{
	static_assert(IsIntegralType<IntType>::VALUE, "Need itegral contant.");

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

ITERATOR_TEMPLATE
bool ITERATOR_TYPE::operator==(const Me &iterator) const
{
	return wrappedIterator == iterator.wrappedIterator;
}

ITERATOR_TEMPLATE
bool ITERATOR_TYPE::operator!=(const Me &iterator) const
{
	return !operator==(iterator);
}

ITERATOR_TEMPLATE
bool ITERATOR_TYPE::operator<(const Me &iterator) const
{
	if (wrappedIterator.template getCurrentIndex() ==
			iterator.wrappedIterator.template getCurrentIndex())
	{
		if (isArrayIterator())
		{
			ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
			ArrayIterator &itIt = *(
					iterator.wrappedIterator.template get<ArrayIterator>()
			);
			return it < itIt;
		}
		else
		{
			VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
			VectorIterator &itIt = *(
					iterator.wrappedIterator.template get<VectorIterator>()
			);
			return it < itIt;
		}
	}
	return false;
}

ITERATOR_TEMPLATE
bool ITERATOR_TYPE::operator>(const Me &iterator) const
{
	if (wrappedIterator.template getCurrentIndex() ==
			iterator.wrappedIterator.template getCurrentIndex())
	{
		if (isArrayIterator())
		{
			ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
			ArrayIterator &itIt = *(
					iterator.wrappedIterator.template get<ArrayIterator>()
			);
			return it > itIt;
		}
		else
		{
			VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
			VectorIterator &itIt = *(
					iterator.wrappedIterator.template get<VectorIterator>()
			);
			return it > itIt;
		}
	}
	return false;
}

ITERATOR_TEMPLATE
bool ITERATOR_TYPE::operator<=(const Me &iterator) const
{
	if (wrappedIterator.template getCurrentIndex() ==
			iterator.wrappedIterator.template getCurrentIndex())
	{
		if (isArrayIterator())
		{
			ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
			ArrayIterator &itIt = *(
					iterator.wrappedIterator.template get<ArrayIterator>()
			);
			return it <= itIt;
		}
		else
		{
			VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
			VectorIterator &itIt = *(
					iterator.wrappedIterator.template get<VectorIterator>()
			);
			return it <= itIt;
		}
	}
	return false;
}

ITERATOR_TEMPLATE
bool ITERATOR_TYPE::operator>=(const Me &iterator) const
{
	if (wrappedIterator.template getCurrentIndex() ==
			iterator.wrappedIterator.template getCurrentIndex())
	{
		if (isArrayIterator())
		{
			ArrayIterator &it = *(wrappedIterator.template get<ArrayIterator>());
			ArrayIterator &itIt = *(
					iterator.wrappedIterator.template get<ArrayIterator>()
			);
			return it >= itIt;
		}
		else
		{
			VectorIterator &it = *(wrappedIterator.template get<VectorIterator>());
			VectorIterator &itIt = *(
					iterator.wrappedIterator.template get<VectorIterator>()
			);
			return it >= itIt;
		}
	}
	return false;
}

ITERATOR_TEMPLATE template<typename IntType>
typename ITERATOR_TYPE::Reference
ITERATOR_TYPE::operator[](IntType index)
{
	return operator->()[index];
}

ITERATOR_TEMPLATE template<typename IntType>
typename ITERATOR_TYPE::ConstReference
ITERATOR_TYPE::operator[](IntType index) const
{
	return operator->()[index];
}

ITERATOR_TEMPLATE
ITERATOR_TYPE::operator ArrayIterator() noexcept
{
	ArrayIterator it{};
	if (isArrayIterator())
	{
		it = *(wrappedIterator.template get<ArrayIterator>());
	}
	return it;
}

ITERATOR_TEMPLATE
ITERATOR_TYPE::operator VectorIterator() noexcept
{
	VectorIterator it{};
	if (isVectorIterator())
	{
		it = *(wrappedIterator.template get<VectorIterator>());
	}
	return it;
}

ITERATOR_TEMPLATE
inline bool ITERATOR_TYPE::isArrayIterator() const noexcept
{
	return wrappedIterator && wrappedIterator.getCurrentIndex() == ARRAY_INDEX;
}

ITERATOR_TEMPLATE
inline bool ITERATOR_TYPE::isVectorIterator() const noexcept
{
	return wrappedIterator && wrappedIterator.getCurrentIndex() == VECTOR_INDEX;
}

#undef ITERATOR_TEMPLATE
#undef ITERATOR_TYPE

// ConstIterator<
//     T, ARRAY_CAPACITY
//     , ArrayTraits, VectorTraits
//     , VectorAllocator
//     , Traits
// >

#define ITERATOR_TEMPLATE \
	template<typename T \
		, flame_ide::SizeTraits::SizeType ARRAY_CAPACITY \
		, typename ArrayTraits \
		, typename VectorTraits \
		, typename VectorAllocator \
		, typename Traits \
	>

#define ITERATOR_TYPE \
	ConstIterator< \
		T, ARRAY_CAPACITY \
		, ArrayTraits, VectorTraits \
		, VectorAllocator \
		, Traits \
	>

ITERATOR_TEMPLATE
ITERATOR_TYPE::ConstIterator(ConstArrayIterator iterator) noexcept :
		Parent(vWrappedIterator(iterator))
{}

ITERATOR_TEMPLATE
ITERATOR_TYPE::ConstIterator(ConstVectorIterator iterator) noexcept :
		Parent(WrappedIterator(iterator))
{}

ITERATOR_TEMPLATE
ITERATOR_TYPE &ITERATOR_TYPE::operator++()
{
	if (isArrayIterator())
	{
		ConstArrayIterator &it = *(
				wrappedIterator.template get<ConstArrayIterator>()
		);
		++it;
	}
	else
	{
		ConstVectorIterator &it = *(
				wrappedIterator.template get<ConstVectorIterator>()
		);
		++it;
	}
	return *this;
}

ITERATOR_TEMPLATE
ITERATOR_TYPE ITERATOR_TYPE::operator++(int)
{
	Me myCopy = *this;
	operator++();
	return myCopy;
}

ITERATOR_TEMPLATE
ITERATOR_TYPE &ITERATOR_TYPE::operator--()
{
	if (isArrayIterator())
	{
		ConstArrayIterator &it = *(
				wrappedIterator.template get<ConstArrayIterator>()
		);
		--it;
	}
	else
	{
		ConstVectorIterator &it = *(
				wrappedIterator.template get<ConstVectorIterator>()
		);
		--it;
	}
	return *this;
}

ITERATOR_TEMPLATE
ITERATOR_TYPE ITERATOR_TYPE::operator--(int)
{
	Me myCopy = *this;
	operator--();
	return myCopy;
}

ITERATOR_TEMPLATE
typename ITERATOR_TYPE::ConstReference
ITERATOR_TYPE::operator*() const
{
	if (isArrayIterator())
	{
		const ConstArrayIterator &it = *(
				wrappedIterator.template get<ConstArrayIterator>()
		);
		return *it;
	}
	else
	{
		const ConstVectorIterator &it = *(
				wrappedIterator.template get<ConstVectorIterator>()
		);
		return *it;
	}
}

ITERATOR_TEMPLATE
typename ITERATOR_TYPE::PointerToConst
ITERATOR_TYPE::operator->() const
{
	return &(operator*());
}

ITERATOR_TEMPLATE template<typename IntType>
ITERATOR_TYPE ITERATOR_TYPE::operator+(IntType value)
{
	Me me = *this;
	me += value;
	return me;
}

ITERATOR_TEMPLATE template<typename IntType>
ITERATOR_TYPE ITERATOR_TYPE::operator-(IntType value)
{
	Me me = *this;
	me -= value;
	return me;
}

ITERATOR_TEMPLATE template<typename IntType>
ITERATOR_TYPE &ITERATOR_TYPE::operator+=(IntType value)
{
	if (isArrayIterator())
	{
		ConstArrayIterator &it = *(
				wrappedIterator.template get<ConstArrayIterator>()
		);
		it += value;
	}
	else
	{
		ConstVectorIterator &it = *(
				wrappedIterator.template get<ConstVectorIterator>()
		);
		it += value;
	}
	return *this;
}

ITERATOR_TEMPLATE template<typename IntType>
ITERATOR_TYPE &ITERATOR_TYPE::operator-=(IntType value)
{
	if (isArrayIterator())
	{
		ConstArrayIterator &it = *(
				wrappedIterator.template get<ConstArrayIterator>()
		);
		it -= value;
	}
	else
	{
		ConstVectorIterator &it = *(
				wrappedIterator.template get<ConstVectorIterator>()
		);
		it -= value;
	}
	return *this;
}

ITERATOR_TEMPLATE
bool ITERATOR_TYPE::operator==(const Me &iterator) const
{
	return wrappedIterator == iterator.wrappedIterator;
}

ITERATOR_TEMPLATE
bool ITERATOR_TYPE::operator!=(const Me &iterator) const
{
	return !operator==(iterator);
}

ITERATOR_TEMPLATE
bool ITERATOR_TYPE::operator<(const Me &iterator) const
{
	if (wrappedIterator.template getCurrentIndex() ==
			iterator.wrappedIterator.template getCurrentIndex())
	{
		if (isArrayIterator())
		{
			ConstArrayIterator &it = *(
					wrappedIterator.template get<ConstArrayIterator>()
			);
			ConstArrayIterator &itIt = *(
					iterator.wrappedIterator.template get<ConstArrayIterator>()
			);
			return it < itIt;
		}
		else
		{
			ConstVectorIterator &it = *(
					wrappedIterator.template get<ConstVectorIterator>());
			ConstVectorIterator &itIt = *(
					iterator.wrappedIterator.template get<ConstVectorIterator>()
			);
			return it < itIt;
		}
	}
	return false;
}

ITERATOR_TEMPLATE
bool ITERATOR_TYPE::operator>(const Me &iterator) const
{
	if (wrappedIterator.template getCurrentIndex() ==
			iterator.wrappedIterator.template getCurrentIndex())
	{
		if (isArrayIterator())
		{
			ConstArrayIterator &it = *(
					wrappedIterator.template get<ConstArrayIterator>()
			);
			ConstArrayIterator &itIt = *(
					iterator.wrappedIterator.template get<ConstArrayIterator>()
			);
			return it > itIt;
		}
		else
		{
			ConstVectorIterator &it = *(
					wrappedIterator.template get<ConstVectorIterator>()
			);
			ConstVectorIterator &itIt = *(
					iterator.wrappedIterator.template get<ConstVectorIterator>()
			);
			return it > itIt;
		}
	}
	return false;
}

ITERATOR_TEMPLATE
bool ITERATOR_TYPE::operator<=(const Me &iterator) const
{
	if (wrappedIterator.template getCurrentIndex() ==
			iterator.wrappedIterator.template getCurrentIndex())
	{
		if (isArrayIterator())
		{
			ConstArrayIterator &it = *(
					wrappedIterator.template get<ConstArrayIterator>()
			);
			ConstArrayIterator &itIt = *(
					iterator.wrappedIterator.template get<ConstArrayIterator>()
			);
			return it <= itIt;
		}
		else
		{
			ConstVectorIterator &it = *(
					wrappedIterator.template get<ConstVectorIterator>()
			);
			ConstVectorIterator &itIt = *(
					iterator.wrappedIterator.template get<ConstVectorIterator>()
			);
			return it <= itIt;
		}
	}
	return false;
}

ITERATOR_TEMPLATE
bool ITERATOR_TYPE::operator>=(const Me &iterator) const
{
	if (wrappedIterator.template getCurrentIndex() ==
			iterator.wrappedIterator.template getCurrentIndex())
	{
		if (isArrayIterator())
		{
			ConstArrayIterator &it = *(
					wrappedIterator.template get<ConstArrayIterator>());
			ConstArrayIterator &itIt = *(
					iterator.wrappedIterator.template get<ConstArrayIterator>()
			);
			return it >= itIt;
		}
		else
		{
			ConstVectorIterator &it = *(
					wrappedIterator.template get<ConstVectorIterator>()
			);
			ConstVectorIterator &itIt = *(
					iterator.wrappedIterator.template get<ConstVectorIterator>()
			);
			return it >= itIt;
		}
	}
	return false;
}

ITERATOR_TEMPLATE
template<typename IntType>
typename ITERATOR_TYPE::ConstReference
ITERATOR_TYPE::operator[](IntType index) const
{
	return operator->()[index];
}

ITERATOR_TEMPLATE
inline bool ITERATOR_TYPE::isArrayIterator() const noexcept
{
	return wrappedIterator && wrappedIterator.getCurrentIndex() == ARRAY_INDEX;
}

ITERATOR_TEMPLATE
inline bool ITERATOR_TYPE::isVectorIterator() const noexcept
{
	return wrappedIterator && wrappedIterator.getCurrentIndex() == VECTOR_INDEX;
}

#undef ITERATOR_TEMPLATE
#undef ITERATOR_TYPE

} // namespace hybrid_vector_utils

#define HYBVECTOR_TEMPLATE \
	template<typename T \
		, SizeTraits::SizeType ARRAY_CAPACITY \
		, typename ArrayTraits \
		, typename VectorTraits \
		, typename VectorAllocator \
		, typename Traits \
	>


#define HYBVECTOR_TYPE \
	HybridVector< \
		T \
		, ARRAY_CAPACITY \
		, ArrayTraits, VectorTraits \
		, VectorAllocator \
		, Traits \
	>

HYBVECTOR_TEMPLATE
HYBVECTOR_TYPE::HybridVector(const Array &array) noexcept : container(array)
{}

HYBVECTOR_TEMPLATE
HYBVECTOR_TYPE::HybridVector(Array &&array) noexcept : container(move(array))
{}

HYBVECTOR_TEMPLATE
HYBVECTOR_TYPE::HybridVector(const Vector &vector) noexcept : container(vector)
{}

HYBVECTOR_TEMPLATE
HYBVECTOR_TYPE::HybridVector(Vector &&vector) noexcept : container(move(vector))
{}

HYBVECTOR_TEMPLATE
HYBVECTOR_TYPE &HYBVECTOR_TYPE::operator=(const Array &array) noexcept
{
	container = array;
}

HYBVECTOR_TEMPLATE
HYBVECTOR_TYPE &HYBVECTOR_TYPE::operator=(Array &&array) noexcept
{
	container = move(array);
}

HYBVECTOR_TEMPLATE
HYBVECTOR_TYPE &HYBVECTOR_TYPE::operator=(const Vector &vector) noexcept
{
	container = vector;
}

HYBVECTOR_TEMPLATE
HYBVECTOR_TYPE &HYBVECTOR_TYPE::operator=(Vector &&vector) noexcept
{
	container = move(vector);
}

HYBVECTOR_TEMPLATE
template<typename IntType>
typename HYBVECTOR_TYPE::Reference HYBVECTOR_TYPE::operator[](IntType index) noexcept
{
	return this->begin()[index];
}

HYBVECTOR_TEMPLATE
template<typename IntType>
typename HYBVECTOR_TYPE::ConstReference
HYBVECTOR_TYPE::operator[](IntType index) const noexcept
{
	return this->begin()[index];
}

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::Pointer HYBVECTOR_TYPE::data() noexcept
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

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::PointerToConst
HYBVECTOR_TYPE::data() const noexcept
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

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::SizeType
HYBVECTOR_TYPE::size() const noexcept
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

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::SizeType
HYBVECTOR_TYPE::capacity() const noexcept
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

HYBVECTOR_TEMPLATE
void HYBVECTOR_TYPE::clean() noexcept
{
	this->reset();
	container = Array{};
}

HYBVECTOR_TEMPLATE
HYBVECTOR_TYPE HYBVECTOR_TYPE::clone() const
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

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::Iterator HYBVECTOR_TYPE::begin()
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

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::ConstIterator HYBVECTOR_TYPE::begin() const
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

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::ConstIterator HYBVECTOR_TYPE::cbegin() const
{
	return this->begin();
}

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::ReverseIterator HYBVECTOR_TYPE::rbegin()
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

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::ConstReverseIterator HYBVECTOR_TYPE::rbegin() const
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

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::ConstReverseIterator HYBVECTOR_TYPE::crbegin() const
{
	return this->rbegin();
}

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::Iterator HYBVECTOR_TYPE::end()
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

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::ConstIterator HYBVECTOR_TYPE::end() const
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

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::ConstIterator HYBVECTOR_TYPE::cend() const
{
	return this->end();
}

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::ReverseIterator HYBVECTOR_TYPE::rend()
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

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::ConstReverseIterator HYBVECTOR_TYPE::rend() const
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

HYBVECTOR_TEMPLATE
typename HYBVECTOR_TYPE::ConstReverseIterator HYBVECTOR_TYPE::crend() const
{
	return this->rend();
}

HYBVECTOR_TEMPLATE
void HYBVECTOR_TYPE::pushBack(ConstReference object)
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

HYBVECTOR_TEMPLATE
void HYBVECTOR_TYPE::pushBack(MoveReference object)
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

HYBVECTOR_TEMPLATE
template<typename ...Args>
void HYBVECTOR_TYPE::emplaceBack(Args &&...args)
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

HYBVECTOR_TEMPLATE
void HYBVECTOR_TYPE::popBack()
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

HYBVECTOR_TEMPLATE
void HYBVECTOR_TYPE::insert(Iterator it, ConstReference object)
{
	if (container)
	{
		if (this->isArray())
		{
			Array *realContainer = container.template get<Array>();
			if (realContainer->capacity() > realContainer->size())
			{
				realContainer->insert(
						it.operator typename Array::Iterator(), object
				);
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

HYBVECTOR_TEMPLATE
void HYBVECTOR_TYPE::insert(Iterator it, MoveReference object)
{
	if (container)
	{
		if (this->isArray())
		{
			Array *realContainer = container.template get<Array>();
			if (realContainer->capacity() > realContainer->size())
			{
				realContainer->insert(
						it.operator typename Array::Iterator(), move(object)
				);
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

HYBVECTOR_TEMPLATE
template<typename InputIterator>
void HYBVECTOR_TYPE::insert(Iterator it, InputIterator itBegin, InputIterator itEnd)
{
	auto countElements = countIterations(itBegin, itEnd);
	if (container)
	{
		if (this->isArray())
		{
			Array *realContainer = container.template get<Array>();
			if (countElements < realContainer->capacity() - realContainer->size())
			{
				realContainer->insert(
						it.operator typename Array::Iterator(), itBegin, itEnd
				);
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

HYBVECTOR_TEMPLATE
template<typename ...Args>
void HYBVECTOR_TYPE::emplace(Iterator it, Args &&...args)
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

HYBVECTOR_TEMPLATE
void HYBVECTOR_TYPE::erase(Iterator it)
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

HYBVECTOR_TEMPLATE
void HYBVECTOR_TYPE::erase(Iterator itBegin, Iterator itEnd)
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

HYBVECTOR_TEMPLATE
void HYBVECTOR_TYPE::reset()
{
	container.reset();
}

// private

HYBVECTOR_TEMPLATE
void HYBVECTOR_TYPE::useArray()
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

HYBVECTOR_TEMPLATE
void HYBVECTOR_TYPE::useVector()
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

HYBVECTOR_TEMPLATE
inline bool HYBVECTOR_TYPE:: isArray() const noexcept
{
	return container
			&& container.getCurrentIndex() == hybrid_vector_utils::ARRAY_INDEX;
}

HYBVECTOR_TEMPLATE
inline bool HYBVECTOR_TYPE::isVector() const noexcept
{
	return container
			&& container.getCurrentIndex() == hybrid_vector_utils::VECTOR_INDEX;
}

}}

#endif // FLAMEIDE_TEMPLATES_HYBRIDVECTOR_HPP
