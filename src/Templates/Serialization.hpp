#ifndef TEMPLATE_SERIALIZATION_HPP
#define TEMPLATE_SERIALIZATION_HPP

#include <Templates/Traits.hpp>

namespace flame_ide
{namespace templates
{

template<ByteOrder CURRENT_ORDER, ByteOrder NEED_ORDER>
struct ToNeedOrder
{
	template<typename T>
	T operator()(T value);
};

template<ByteOrder ORDER>
class Serializer
{
};

template<ByteOrder ORDER>
class Deserializer
{
};

}}

#endif // TEMPLATE_SERIALIZATION_HPP
