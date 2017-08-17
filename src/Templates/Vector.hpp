#ifndef TEMPLATES_VECTOR
#define TEMPLATES_VECTOR

#include <Templates/Utils.hpp>
#include <Templates/Iterator.hpp>
#include <Templates/Allocator.hpp>
#include <Templates/InitializerList.hpp>

namespace flame_ide
{namespace templates
{

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ArrayAllocator<T, Traits>
	, typename Traits::SizeType START_SIZE = 16
	, typename Traits::SizeType RESIZE_FACTOR_MULT = 3
	, typename Traits::SizeType RESIZE_FACTOR_DIV = 2
>
class Vector
{
public:
	static_assert(RESIZE_FACTOR_MULT > RESIZE_FACTOR_DIV, "Error");

	using Me = Vector<
		T, Traits, Allocator
		, START_SIZE
		, RESIZE_FACTOR_MULT
		, RESIZE_FACTOR_DIV
	>;

	using SizeType = typename Traits::SizeType;
	using Type = typename Traits::Type;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Iterator = Pointer;
	using ConstIterator = PointerToConst;
	using ReverseIterator = flame_ide::templates::RaReverseIterator<Iterator, Traits>;
	using ConstReverseIterator = const ReverseIterator;

	/**
	 * @brief Vector
	 */
	Vector();

	/**
	 * @brief Vector
	 * @param vector
	 */
	template<typename Traits1
		, typename Allocator1
		, SizeType START_SIZE1
		, SizeType RESIZE_FACTOR_MULT1
		, SizeType RESIZE_FACTOR_DIV1>
	Vector(const Vector<T, Traits1, Allocator1
			, START_SIZE1, RESIZE_FACTOR_MULT1
			, RESIZE_FACTOR_DIV1> &vector);

	/**
	 * @brief Vector
	 * @param vector
	 */
	template<typename Traits1
		, typename Allocator1
		, SizeType START_SIZE1
		, SizeType RESIZE_FACTOR_MULT1
		, SizeType RESIZE_FACTOR_DIV1>
	Vector(Vector<T, Traits1, Allocator1
			, START_SIZE1
			, RESIZE_FACTOR_MULT1
			, RESIZE_FACTOR_DIV1> &&vector) noexcept;

	/**
	 * @brief Vector
	 * @param size
	 */
	Vector(SizeType size);

	template<typename ...Args>
	Vector(Args &&...args);

	~Vector();

	/**
	 * @brief operator =
	 * @param vector
	 * @return
	 */
	template<typename Traits1
		, typename Allocator1
		, SizeType START_SIZE1
		, SizeType RESIZE_FACTOR_MULT1
		, SizeType RESIZE_FACTOR_DIV1>
	Me &operator=(
			const Vector<T, Traits1, Allocator1
			, START_SIZE1
			, RESIZE_FACTOR_MULT1
			, RESIZE_FACTOR_DIV1> &vector);

	/**
	 * @brief operator =
	 * @param vector
	 * @return
	 */
	template<typename Traits1
		, typename Allocator1
		, SizeType START_SIZE1
		, SizeType RESIZE_FACTOR_MULT1
		, SizeType RESIZE_FACTOR_DIV1>
	Me &operator=(
			Vector<T, Traits1, Allocator1
			, START_SIZE1
			, RESIZE_FACTOR_MULT1
			, RESIZE_FACTOR_DIV1> &&vector) noexcept;

	/**
	 * @brief operator []
	 * @param index
	 * @return
	 */
	Reference operator[](SizeType index) noexcept;

	/**
	 * @brief operator []
	 * @param index
	 * @return
	 */
	ConstReference operator[](SizeType index) const noexcept;

	/**
	 * @brief size
	 * @return
	 */
	SizeType size() const noexcept;

	/**
	 * @brief capacity
	 * @param index
	 * @return
	 */
	SizeType capacity() const noexcept;

	/**
	 * @brief resize
	 * @param size
	 */
	void resize(SizeType size);

	/**
	 * @brief reserve
	 * @param capacity
	 */
	void reserve(SizeType vectorCapacity);

	/**
	 * @brief first
	 * @return
	 */
	Reference first();

	/**
	 * @brief first
	 * @return
	 */
	ConstReference first() const;

	/**
	 * @brief last
	 * @return
	 */
	Reference last();

	/**
	 * @brief last
	 * @return
	 */
	ConstReference last() const;

	/**
	 * @brief clean
	 */
	void clean();

	/**
	 * @brief clone
	 * @return
	 */
	Me clone();

	/**
	 * @brief begin
	 * @return
	 */
	Iterator begin();

	/**
	 * @brief begin
	 * @return
	 */
	ConstIterator begin() const;

	/**
	 * @brief end
	 * @return
	 */
	Iterator end();

	/**
	 * @brief end
	 * @return
	 */
	ConstIterator end() const;

	/**
	 * @brief rbegin
	 * @return
	 */
	ReverseIterator rbegin();

	/**
	 * @brief rbegin
	 * @return
	 */
	ConstReverseIterator rbegin() const;

	/**
	 * @brief rend
	 * @return
	 */
	ReverseIterator rend();

	/**
	 * @brief rend
	 * @return
	 */
	ConstReverseIterator rend() const;

	/**
	 * @brief pushBack
	 * @param object
	 */
	void pushBack(ConstReference object);

	/**
	 * @brief pushBack
	 * @param object
	 */
	void pushBack(MoveReference object);


	/**
	 * @brief emplaceBack
	 * @param args
	 */
	template<typename ...Args>
	void emplaceBack(Args &&...args);

	/**
	 * @brief popBack
	 */
	void popBack();

	/**
	 * @brief insert
	 * @param it
	 * @param type
	 */
	void insert(Iterator it, ConstReference type);

	/**
	 * @brief insert
	 * @param it
	 * @param type
	 */
	void insert(Iterator it, MoveReference type);

	/**
	 * @brief insert
	 * @param it
	 * @param begin
	 * @param end
	 */
	template<typename InputIterator>
	void insert(Iterator it, InputIterator begin, InputIterator end);

	/**
	 * @brief erase
	 * @param it
	 */
	void erase(Iterator it);

	/**
	 * @brief erase
	 * @param itBegin
	 * @param itEnd
	 */
	void erase(Iterator itBegin, Iterator itEnd);

private:
	T *head;
	T *tail;
	SizeType vectorCapacity;
	Allocator allocator;
};

}}

namespace flame_ide
{namespace templates
{

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV
>::Vector() : head(nullptr), tail(nullptr), vectorCapacity(0), allocator()
{}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV
>
template<typename Traits1
	, typename Allocator1
	, typename Traits::SizeType START_SIZE1
	, typename Traits::SizeType RESIZE_FACTOR_MULT1
	, typename Traits::SizeType RESIZE_FACTOR_DIV1>
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::Vector(
		const Vector<T, Traits1, Allocator1
		, START_SIZE1, RESIZE_FACTOR_MULT1
		, RESIZE_FACTOR_DIV1> &vector)
		: head(vector.allocator.createArray(vector.size()))
		, tail(head + vector.size())
		, vectorCapacity(vector.size())
{
	Iterator it = head;
	for (const Type &i : vector)
		placementNew<Type>(it, i);
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
template<typename Traits1
	, typename Allocator1
	, typename Traits::SizeType START_SIZE1
	, typename Traits::SizeType RESIZE_FACTOR_MULT1
	, typename Traits::SizeType RESIZE_FACTOR_DIV1>
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::Vector(
		Vector<T, Traits1, Allocator1
		, START_SIZE1, RESIZE_FACTOR_MULT1
		, RESIZE_FACTOR_DIV1> &&vector) noexcept
		: head(vector.head)
		, tail(vector.tail)
		, vectorCapacity(vector.vectorCapacity)
{
	vector.head = nullptr;
	vector.tail = nullptr;
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::Vector(
		typename Traits::SizeType size)
{
	head = allocator.createArray((size * RESIZE_FACTOR_MULT) / RESIZE_FACTOR_DIV);
	tail = head + size;
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
template<typename ...Args>
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::Vector(Args &&...args) :
		head(allocator.createArray(sizeof...(Args)))
		, tail(head + sizeof...(Args))
		, vectorCapacity(sizeof...(Args))
{
	InitializerList<Type, sizeof...(Args)> list(args...);
	auto itList = list.begin();
	for (auto &i : *this)
		placementNew<Type>(&i, *itList);
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
Vector<T, Traits, Allocator, START_SIZE
	, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::~Vector()
{
	for (auto &i : *this)
		i.~T();
	allocator.freeArray(head);
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
template<typename Traits1
	, typename Allocator1
	, typename Traits::SizeType START_SIZE1
	, typename Traits::SizeType RESIZE_FACTOR_MULT1
	, typename Traits::SizeType RESIZE_FACTOR_DIV1>
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV> &
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::operator=(
		const Vector<T, Traits1, Allocator1
		, START_SIZE1, RESIZE_FACTOR_MULT1
		, RESIZE_FACTOR_DIV1> &vector)
{
	auto tempHead = allocator.createArray(vector.size());
	auto it = tempHead;
	for (const Type &i : vector)
		placementNew<Type>(it++, i);

	for (auto &i : *this)
		i.~T();
	allocator.freeArray(head);

	vectorCapacity = vector.size();
	head = tempHead;
	tail = head + vectorCapacity;
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
template<typename Traits1
	, typename Allocator1
	, typename Traits::SizeType START_SIZE1
	, typename Traits::SizeType RESIZE_FACTOR_MULT1
	, typename Traits::SizeType RESIZE_FACTOR_DIV1>
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV> &
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::operator=(
		Vector<T, Traits1, Allocator1
		, START_SIZE1, RESIZE_FACTOR_MULT1
		, RESIZE_FACTOR_DIV1> &&vector) noexcept
{
	head = vector.head;
	tail = vector.tail;
	vectorCapacity = vector.vectorCapacity;

	vector.head = nullptr;
	vector.tail = nullptr;
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
typename Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::Reference
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::operator[](
		Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::SizeType index)
{
	return *(head + index);
}

template<typename T
		 , typename Traits
		 , typename Allocator
		 , typename Traits::SizeType START_SIZE
		 , typename Traits::SizeType RESIZE_FACTOR_MULT
		 , typename Traits::SizeType RESIZE_FACTOR_DIV>
typename Vector<T, Traits, Allocator, START_SIZE
	, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::ConstReference
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::operator[](
		Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::SizeType index) const
{
	return *(head + index);
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
typename Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::SizeType
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::size() const
{
	return SizeType(tail - head);
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
typename Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::SizeType
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::capacity() const
{
	return vectorCapacity;
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
void Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::resize(
		Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::SizeType newSize)
{}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
void Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::reserve(
				Vector<T, Traits, Allocator, START_SIZE
				, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::SizeType newCapacity)
{}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
typename Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::Reference
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::first()
{
	return *head;
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
typename Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::ConstReference
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::first() const
{
	return *head;
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
typename Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::Reference
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::last()
{
	return *(tail - 1);
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
typename Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::ConstReference
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::last() const
{
	return *(tail - 1);
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
void Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::clean()
{
	for (auto &i : *this)
		i.~T();
	tail = head;
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
typename Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::Iterator
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::begin()
{
	return head;
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
typename Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::ConstIterator
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::begin() const
{
	return head;
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
typename Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::Iterator
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::end()
{
	return tail;
}

template<typename T
	, typename Traits
	, typename Allocator
	, typename Traits::SizeType START_SIZE
	, typename Traits::SizeType RESIZE_FACTOR_MULT
	, typename Traits::SizeType RESIZE_FACTOR_DIV>
typename Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::ConstIterator
Vector<T, Traits, Allocator, START_SIZE
		, RESIZE_FACTOR_MULT, RESIZE_FACTOR_DIV>::end() const
{
	return tail;
}

}}

#endif // TEMPLATES_VECTOR
