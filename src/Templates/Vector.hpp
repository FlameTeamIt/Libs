#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <Templates/Utils.hpp>
#include <Templates/Iterator.hpp>
#include <Templates/Allocator.hpp>

namespace flame_ide
{namespace templates
{

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ArrayAllocator<T, Traits>
	, typename Traits::SizeType RESIZE_FACTOR[2] = {3, 2}
>
class Vector
{
public:
	// TODO: typedefs

private:
	T *head;
	T *tail;
	Allocator allocator;
};

}}

#endif // VECTOR_HPP
