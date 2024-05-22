#ifndef FLAMEIDE_TEMPLATES_ASINTEGRALTYPE_HPP
#define FLAMEIDE_TEMPLATES_ASINTEGRALTYPE_HPP

#include <FlameIDE/Common/Traits.hpp>

namespace flame_ide
{namespace templates
{

template<typename IntType, typename Meta = void>
struct AsIntegralType
{
	static_assert(IsIntegralTrait<IntType>::VALUE, "Type is not integral");

	using Me = AsIntegralType<IntType, Meta>;

	constexpr AsIntegralType() noexcept;
	constexpr AsIntegralType(const Me &) noexcept = default;
	constexpr AsIntegralType(Me &&) noexcept = default;

	template<typename IntType1>
	constexpr AsIntegralType(IntType1 val) noexcept;

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

	IntType val;
};

}}

namespace flame_ide
{namespace templates
{

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta>::AsIntegralType(IntType1 initValue) noexcept
		: val(static_cast<IntType>(initValue))
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta>&
AsIntegralType<IntType, Meta>::operator=(IntType1 newValue) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	val = newValue;
	return *this;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>::operator bool() noexcept
{
	return val;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>::operator Types::ichar_t() noexcept
{
	return static_cast<Types::ichar_t>(val);
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>::operator Types::short_t() noexcept
{
	return static_cast<Types::short_t>(val);
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>::operator Types::int_t() noexcept
{
	return static_cast<Types::int_t>(val);
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>::operator Types::long_t() noexcept
{
	return static_cast<Types::long_t>(val);
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>::operator Types::uichar_t() noexcept
{
	return static_cast<Types::uichar_t>(val);
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>::operator Types::ushort_t() noexcept
{
	return static_cast<Types::ushort_t>(val);
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>::operator Types::uint_t() noexcept
{
	return static_cast<Types::uint_t>(val);
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>::operator Types::ulong_t() noexcept
{
	return static_cast<Types::ulong_t>(val);
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr bool AsIntegralType<IntType, Meta>::operator==(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	return static_cast<IntType1>(this->val) == value;
}

template<typename IntType, typename Meta>
constexpr bool AsIntegralType<IntType, Meta>::operator==(Me value) noexcept
{
	return this->val == value.val;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr bool AsIntegralType<IntType, Meta>::operator!=(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	return this->val != static_cast<IntType>(value);
}

template<typename IntType, typename Meta>
constexpr bool AsIntegralType<IntType, Meta>::operator!=(Me value) noexcept
{
	return this->val != value.val;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr bool AsIntegralType<IntType, Meta>::operator>(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	return this->val > static_cast<IntType>(value);
}

template<typename IntType, typename Meta>
constexpr bool AsIntegralType<IntType, Meta>::operator>(Me value) noexcept
{
	return this->val > value.val;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr bool AsIntegralType<IntType, Meta>::operator<(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	return this->val < static_cast<IntType>(value);
}

template<typename IntType, typename Meta>
constexpr bool AsIntegralType<IntType, Meta>::operator<(Me value) noexcept
{
	return this->val < value.val;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr bool AsIntegralType<IntType, Meta>::operator>=(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	return this->val > static_cast<IntType>(value);
}

template<typename IntType, typename Meta>
constexpr bool AsIntegralType<IntType, Meta>::operator>=(Me value) noexcept
{
	return this->val > value.val;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr bool AsIntegralType<IntType, Meta>::operator<=(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	return this->val < static_cast<IntType>(value);
}

template<typename IntType, typename Meta>
constexpr bool AsIntegralType<IntType, Meta>::operator<=(Me value) noexcept
{
	return this->val < value.val;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator>>=(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	this->val >>= static_cast<IntType>(value);
	return *this;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator>>=(Me value) noexcept
{
	this->val >>= value.val;
	return *this;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator<<=(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	this->val <<= static_cast<IntType>(value);
	return *this;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator<<=(Me value) noexcept
{
	this->val <<= value.val;
	return *this;
}


template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator|=(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	this->val |= static_cast<IntType>(value);
	return *this;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator|=(Me value) noexcept
{
	this->val |= value.val;
	return *this;
}



template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator+=(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	this->val += static_cast<IntType>(value);
	return *this;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator+=(Me value) noexcept
{
	this->val += value.val;
	return *this;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator-=(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	this->val -= static_cast<IntType>(value);
	return *this;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator-=(Me value) noexcept
{
	this->val -= value.val;
	return *this;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator*=(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	this->val *= static_cast<IntType>(value);
	return *this;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator*=(Me value) noexcept
{
	this->val *= value.val;
	return *this;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator/=(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");
	this->val /= static_cast<IntType>(value);
	return *this;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta> &
AsIntegralType<IntType, Meta>::operator/=(Me value) noexcept
{
	this->val /= value.val;
	return *this;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator<<(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me.val <<= static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator<<(Me value) noexcept
{
	Me me = *this;
	me.val <<= value.val;
	return me;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator>>(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me.val >>= static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator>>(Me value) noexcept
{
	Me me = *this;
	me.val >>= value.val;
	return me;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator|(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me.val |= static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator|(Me value) noexcept
{
	Me me = *this;
	me.val |= value.val;
	return me;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator+(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me.val += static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator+(Me value) noexcept
{
	Me me = *this;
	me.val += value.val;
	return me;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator-(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me.val -= static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator-(Me value) noexcept
{
	Me me = *this;
	me.val -= value.val;
	return me;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator*(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me.val *= static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator*(Me value) noexcept
{
	Me me = *this;
	me.val *= value.val;
	return me;
}

template<typename IntType, typename Meta>
template<typename IntType1>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator/(IntType1 value) noexcept
{
	static_assert(IsIntegralTrait<IntType1>::VALUE, "Type is not integral");

	Me me = *this;
	me.val /= static_cast<IntType>(value);
	return me;
}

template<typename IntType, typename Meta>
constexpr AsIntegralType<IntType, Meta>
AsIntegralType<IntType, Meta>::operator/(Me value) noexcept
{
	Me me = *this;
	me.val /= value.val;
	return me;
}

}}

#endif // FLAMEIDE_TEMPLATES_ASINTEGRALTYPE_HPP
