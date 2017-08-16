#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <Templates/Utils.hpp>

namespace flame_ide
{namespace templates
{

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Traits::SizeType RESIZE_FACTOR[] = {3, 2}
>
class Vector
{
public:


private:
	T *head;
	T *tail;
};

}}

#endif // VECTOR_HPP
