#ifndef FLAMEIDE_TEMPLATES_CYCLEINTEGER_HPP
#define FLAMEIDE_TEMPLATES_CYCLEINTEGER_HPP

#include <FlameIDE/Templates/AsIntegralType.hpp>

namespace flame_ide
{namespace templates
{

template<typename IntType, typename Meta = void>
class CycleInteger: public AsIntegralType<IntType, Meta>
{
	static_assert(IsIntegralType<IntType>::VALUE, "Type is not integral");

	using Me = CycleInteger<IntType, Meta>;
	using Parent = AsIntegralType<IntType, Meta>;

	constexpr CycleInteger() noexcept;
	constexpr CycleInteger(const Me &) noexcept = default;
	constexpr CycleInteger(Me &&) noexcept = default;

	template<typename IntType1>
	constexpr CycleInteger(IntType1 val) noexcept;

	constexpr Me &operator=(const Me &) noexcept = default;
	constexpr Me &operator=(Me &&) noexcept = default;

	template<typename IntType1>
	constexpr Me &operator=(IntType1 val) noexcept;

	constexpr operator bool() noexcept;

	constexpr operator Types::ichar_t() noexcept;
	constexpr operator Types::int_t() noexcept;
	constexpr operator Types::short_t() noexcept;
	constexpr operator Types::long_t() noexcept;

	constexpr operator Types::uichar_t() noexcept;
	constexpr operator Types::uint_t() noexcept;
	constexpr operator Types::ushort_t() noexcept;
	constexpr operator Types::ulong_t() noexcept;

	template<typename IntType1>
	constexpr bool operator==(IntType1 val) noexcept;
	constexpr bool operator==(Me val) noexcept;

	template<typename IntType1>
	constexpr bool operator!=(IntType1 val) noexcept;
	constexpr bool operator!=(Me val) noexcept;

	template<typename IntType1>
	constexpr bool operator>(IntType1 val) noexcept;
	constexpr bool operator>(Me val) noexcept;

	template<typename IntType1>
	constexpr bool operator<(IntType1 val) noexcept;
	constexpr bool operator<(Me val) noexcept;

	template<typename IntType1>
	constexpr bool operator>=(IntType1 val) noexcept;
	constexpr bool operator>=(Me val) noexcept;

	template<typename IntType1>
	constexpr bool operator<=(IntType1 val) noexcept;
	constexpr bool operator<=(Me val) noexcept;

	template<typename IntType1>
	constexpr Me &operator>>=(IntType1 val) noexcept;
	constexpr Me &operator>>=(Me val) noexcept;

	template<typename IntType1>
	constexpr Me &operator<<=(IntType1 val) noexcept;
	constexpr Me &operator<<=(Me val) noexcept;

	template<typename IntType1>
	constexpr Me &operator|=(IntType1 val) noexcept;
	constexpr Me &operator|=(Me val) noexcept;

	template<typename IntType1>
	constexpr Me &operator+=(IntType1 val) noexcept;
	constexpr Me &operator+=(Me val) noexcept;

	template<typename IntType1>
	constexpr Me &operator-=(IntType1 val) noexcept;
	constexpr Me &operator-=(Me val) noexcept;

	template<typename IntType1>
	constexpr Me &operator*=(IntType1 val) noexcept;
	constexpr Me &operator*=(Me val) noexcept;

	template<typename IntType1>
	constexpr Me &operator/=(IntType1 val) noexcept;
	constexpr Me &operator/=(Me val) noexcept;

	template<typename IntType1>
	constexpr Me operator>>(IntType1 val) noexcept;
	constexpr Me operator>>(Me val) noexcept;

	template<typename IntType1>
	constexpr Me operator<<(IntType1 val) noexcept;
	constexpr Me operator<<(Me val) noexcept;

	template<typename IntType1>
	constexpr Me operator|(IntType1 val) noexcept;
	constexpr Me operator|(Me val) noexcept;

	template<typename IntType1>
	constexpr Me operator+(IntType1 val) noexcept;
	constexpr Me operator+(Me val) noexcept;

	template<typename IntType1>
	constexpr Me operator-(IntType1 val) noexcept;
	constexpr Me operator-(Me val) noexcept;

	template<typename IntType1>
	constexpr Me operator*(IntType1 val) noexcept;
	constexpr Me operator*(Me val) noexcept;

	template<typename IntType1>
	constexpr Me operator/(IntType1 val) noexcept;
	constexpr Me operator/(Me val) noexcept;
};

}}

namespace flame_ide
{namespace templates
{

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta>::CycleInteger(IntType1 initValue) noexcept
		: Parent(initValue)
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta>&
CycleInteger<IntType, Meta>::operator=(IntType1 newValue) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	this->Parent::operator=(newValue);
	return *this;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>::operator bool() noexcept
{
	return this->Parent::operator bool();
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>::operator Types::ichar_t() noexcept
{
	return this->Parent::operator Types::ichar_t();
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>::operator Types::short_t() noexcept
{
	return this->Parent::operator Types::short_t();
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>::operator Types::int_t() noexcept
{
	return this->Parent::operator Types::int_t();
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>::operator Types::long_t() noexcept
{
	return this->Parent::operator Types::long_t();
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>::operator Types::uichar_t() noexcept
{
	return this->Parent::operator Types::uichar_t();
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>::operator Types::ushort_t() noexcept
{
	return this->Parent::operator Types::ushort_t();
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>::operator Types::uint_t() noexcept
{
	return this->Parent::operator Types::uint_t();
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>::operator Types::ulong_t() noexcept
{
	return this->Parent::operator Types::ulong_t();
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr bool CycleInteger<IntType, Meta>::operator==(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	return this->Parent::operator==(value);
}

template<typename IntType, typename Meta>
constexpr bool CycleInteger<IntType, Meta>::operator==(Me value) noexcept
{
	return this->Parent::operator==(value);
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr bool CycleInteger<IntType, Meta>::operator!=(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	return this->Parent::operator!=(value);
}

template<typename IntType, typename Meta>
constexpr bool CycleInteger<IntType, Meta>::operator!=(Me value) noexcept
{
	return this->Parent::operator!=(value);
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr bool CycleInteger<IntType, Meta>::operator>(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	return this->Parent::operator>(value);
}

template<typename IntType, typename Meta>
constexpr bool CycleInteger<IntType, Meta>::operator>(Me value) noexcept
{
	return this->Parent::operator>(value);
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr bool CycleInteger<IntType, Meta>::operator<(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	return this->Parent::operator<(value);
}

template<typename IntType, typename Meta>
constexpr bool CycleInteger<IntType, Meta>::operator<(Me value) noexcept
{
	return this->Parent::operator<(value);
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr bool CycleInteger<IntType, Meta>::operator>=(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	return this->Parent::operator>=(value);
}

template<typename IntType, typename Meta>
constexpr bool CycleInteger<IntType, Meta>::operator>=(Me value) noexcept
{
	return this->Parent::operator>=(value);
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr bool CycleInteger<IntType, Meta>::operator<=(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	return this->Parent::operator<=(value);
}

template<typename IntType, typename Meta>
constexpr bool CycleInteger<IntType, Meta>::operator<=(Me value) noexcept
{
	return this->Parent::operator<=(value);
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator>>=(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	constexpr Types::size_t BIT_SIZE = sizeof(IntType1) * 8;

	value %= BIT_SIZE;

	IntType tempVal[] = { this->val >> value, this->val << (BIT_SIZE - value) };
	this->val = tempVal[0] | tempVal[1];

	return *this;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator>>=(Me value) noexcept
{
	return this->operator>>(value.val);
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator<<=(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	constexpr Types::size_t BIT_SIZE = sizeof(IntType1) * 8;

	value %= BIT_SIZE;

	IntType tempVal[] = { this->val << value, this->val >> (BIT_SIZE - value) };
	this->val = tempVal[0] | tempVal[1];

	// TODO
	return *this;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator<<=(Me value) noexcept
{
	return this->operator<<(value.val);
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator|=(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");
	this->Parent::operator|=(value);
	return *this;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator|=(Me value) noexcept
{
	this->Parent::operator|=(value);
	return *this;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator+=(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");
	this->Parent::operator+=(value);
	return *this;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator+=(Me value) noexcept
{
	this->Parent::operator+=(value);
	return *this;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator-=(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");
	this->Parent::operator-=(value);
	return *this;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator-=(Me value) noexcept
{
	this->Parent::operator-=(value);
	return *this;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator*=(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");
	this->Parent::operator*=(value);
	return *this;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator*=(Me value) noexcept
{
	this->Parent::operator*=(value);
	return *this;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator/=(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	this->Parent::operator/=(value);
	return *this;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta> &
CycleInteger<IntType, Meta>::operator/=(Me value) noexcept
{
	this->Parent::operator/=(value);
	return *this;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator<<(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me <<= static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator<<(Me value) noexcept
{
	// TODO
	Me me = *this;
	me <<= value;
	return me;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator>>(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me >>= static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator>>(Me value) noexcept
{
	Me me = *this;
	me >>= value.val;
	return me;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator|(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me.val |= static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator|(Me value) noexcept
{
	Me me = *this;
	me |= value.val;
	return me;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator+(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me += static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator+(Me value) noexcept
{
	Me me = *this;
	me.val += value.val;
	return me;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator-(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me -= static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator-(Me value) noexcept
{
	Me me = *this;
	me -= value.val;
	return me;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator*(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me *= static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator*(Me value) noexcept
{
	Me me = *this;
	me *= value.val;
	return me;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator/(IntType1 value) noexcept
{
	static_assert(IsIntegralType<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me /= static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr CycleInteger<IntType, Meta>
CycleInteger<IntType, Meta>::operator/(Me value) noexcept
{
	Me me = *this;
	me /= value.val;
	return me;
}

}}

#endif // FLAMEIDE_TEMPLATES_CYCLEINTEGER_HPP
