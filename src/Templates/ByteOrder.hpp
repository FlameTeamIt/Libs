#ifndef TEMPLATES_BYTEORDER_HPP
#define TEMPLATES_BYTEORDER_HPP

#include <Templates/Traits.hpp>

namespace flame_ide
{namespace templates
{

template<typename T, ByteOrder NEED>
T convertValueOrder(T value);

template<> static inline
Types::uchar_t
convertValueOrder<Types::uchar_t, ByteOrder::BIG_ENDIAN>(Types::uchar_t value)
{
	return value;
}

template<> static inline
Types::uchar_t
convertValueOrder<Types::uchar_t, ByteOrder::LITTLE_ENDIAN>(Types::uchar_t value)
{
	return value;
}

template<> static inline
Types::uchar_t
convertValueOrder<Types::uchar_t, ByteOrder::PDP_ENDIAN>(Types::uchar_t value)
{}

}}

#endif // TEMPLATES_BYTEORDER_HPP
