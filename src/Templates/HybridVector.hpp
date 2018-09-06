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
class Iterator: public iterator_utils::BaseIterator<
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
	using Parent = iterator_utils::BaseIterator<
		Variant<
			typename Array<T, ARRAY_CAPACITY, ArrayTraits, FalseType::VALUE>::Iterator
			, typename Vector<T, VectorTraits, VectorAllocator>::Iterator
		>
		, IteratorCategory::RANDOM_ACCESS
		, IteratorAccess::NON_CONSTANT
		, Traits
	>;

	using Me = Iterator<
		T, ARRAY_CAPACITY, ArrayTraits, VectorTraits, VectorAllocator, Traits
	>;

private:
};

template<typename T
	, SizeTraits::SizeType ARRAY_CAPACITY
	, typename ArrayTraits = ContainerTraits<T>
	, typename VectorTraits = ContainerTraits<T>
	, typename VectorAllocator = allocator::ArrayAllocator<T, VectorTraits>
	, typename Traits = ContainerTraits<T>
>
class ConstIterator: public iterator_utils::BaseIterator<
	Variant<
		typename Array<T, ARRAY_CAPACITY, ArrayTraits, FalseType::VALUE>::Iterator
		, typename Vector<T, VectorTraits, VectorAllocator>::Iterator
	>
	, IteratorCategory::RANDOM_ACCESS
	, IteratorAccess::CONSTANT
	, Traits
>
{
public:
	using Parent = iterator_utils::BaseIterator<
		Variant<
			typename Array<T, ARRAY_CAPACITY, ArrayTraits, FalseType::VALUE>::Iterator
			, typename Vector<T, VectorTraits, VectorAllocator>::Iterator
		>
		, IteratorCategory::RANDOM_ACCESS
		, IteratorAccess::NON_CONSTANT
		, Traits
	>;

	using Me = ConstIterator<
		T, ARRAY_CAPACITY, ArrayTraits, VectorTraits, VectorAllocator, Traits
	>;

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
	using Array = Array<T, ARRAY_CAPACITY, ArrayTraits, FalseType::VALUE>;
	using Vector = Vector<T, VectorTraits, VectorAllocator>;
	using ContainerVariant = Variant<Array, Vector>;

	using Me = HybridVector<
		T
		, ARRAY_CAPACITY, ArrayTraits
		, VectorTraits, VectorAllocator, Traits
	>;

	HybridVector();
	~HybridVector();

private:
	ContainerVariant container;
};

}}

#endif // TEMPLATES_HYBRIDVECTOR_HPP
