#ifndef TEMPLATES_WIDEINT_HPP
#define TEMPLATES_WIDEINT_HPP

#include <Templates/Utils.hpp>
#include <Templates/Array.hpp>

namespace flame_ide
{namespace templates
{

namespace wide_int_utils
{

template<Types::ullong_t BITS>
struct TypeHelper;



}

template<Types::ullong_t BITS, bool SIGNED>
class WideInt
{
public:
	using Me = WideInt<BITS, SIGNED>;

	WideInt();

	template<typename IntegerType>
	WideInt(IntegerType value);
	WideInt(const Me &integer);

	template<typename IntegerType>
	Me &operator=(IntegerType &value);
	Me &operator=(const Me &value);

	template<typename IntegerType>
	WideInt<BITS, SIGNED> &operator=(const IntegerType &value);

	template<typename IntegerType>
	operator<<(IntegerType value);
	operator<<(const Me &value);

	template<typename IntegerType>
	operator>>(IntegerType value);
	operator>>(const Me &value);

	template<typename IntegerType>
	operator+(IntegerType value);
	operator+(const Me &value);

	template<typename IntegerType>
	operator+=(IntegerType value);
	operator+=(const Me &value);

	template<typename IntegerType>
	operator-(IntegerType value);
	operator-(const Me &value);

	template<typename IntegerType>
	operator-=(IntegerType value);
	operator-=(const Me &value);

	template<typename IntegerType>
	operator*(IntegerType value);
	operator*(const Me &value);

	template<typename IntegerType>
	operator*=(IntegerType value);
	operator*=(const Me &value);

	template<typename IntegerType>
	operator/(IntegerType value);
	operator/(const Me &value);

	template<typename IntegerType>
	operator/=(IntegerType value);
	operator/=(const Me &value);

	operator++();
	operator++(int);
	operator--();
	operator--(int);

private:
};

}}

#endif // TEMPLATES_WIDEINT_HPP
