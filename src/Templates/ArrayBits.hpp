#ifndef TEMPLATES_ARRAYBITS_HPP
#define TEMPLATES_ARRAYBITS_HPP

#include <Templates/Utils.hpp>
#include <Templates/Byte.hpp>

namespace flame_ide
{namespace templates
{namespace bits
{

template<Types::size_t TEMPLATE_COUNT_BITS>
struct ArrayBits
{
	constexpr static Types::size_t COUNT_BYTES = TEMPLATE_COUNT_BITS / 8 + ((TEMPLATE_COUNT_BITS % 8) ? 1 : 0);

	ArrayBits();

	template<typename T>
	ArrayBits(const T& object) noexcept;

	bool operator[](SizeTraits::SizeType index) const noexcept;
	void set(SizeTraits::SizeType index, bool value) noexcept;
	void revert() noexcept;

	SizeTraits::SizeType size() const noexcept
	{
		return TEMPLATE_COUNT_BITS;
	}

	Byte bytes[COUNT_BYTES];
};

}}}

namespace flame_ide
{namespace templates
{namespace bits
{

template<Types::size_t TEMPLATE_COUNT_BITS>
ArrayBits<TEMPLATE_COUNT_BITS>::ArrayBits()
{}

template<Types::size_t TEMPLATE_COUNT_BITS>
template<typename T>
ArrayBits<TEMPLATE_COUNT_BITS>::ArrayBits(const T& object) noexcept
{
	copy(reinterpret_cast<const Types::uchar_t*>(&object)
			, reinterpret_cast<const Types::uchar_t*>(&object) + COUNT_BYTES
			, reinterpret_cast<Types::uchar_t*>(bytes));
}

template<Types::size_t TEMPLATE_COUNT_BITS>
bool ArrayBits<TEMPLATE_COUNT_BITS>::operator[](SizeTraits::SizeType index) const noexcept
{
//	return bytes[index / 8][index % 8];
}

// TODO: fix setting bit value.
template<Types::size_t TEMPLATE_COUNT_BITS>
void ArrayBits<TEMPLATE_COUNT_BITS>::set(SizeTraits::SizeType index, bool value) noexcept
{
	bytes[index / 8].set(index % 8, value);
}

template<Types::size_t TEMPLATE_COUNT_BITS>
void ArrayBits<TEMPLATE_COUNT_BITS>::revert() noexcept
{
}

}}}

#endif // TEMPLATES_ARRAYBITS_HPP
