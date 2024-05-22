#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Date.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

Date::Date() noexcept
		: Date(Parent{})
{}

Date::Date(const Date &date) noexcept
		: Date(static_cast<const Parent &>(date))
{}

Date::Date(const decltype(Parent::year) &year
		, const decltype(Parent::month) &month
		, const decltype(Parent::day) &day)
{
	copy(this->year, year);
	copy(this->month, month);
	copy(this->day, day);
}

Date::Date(const Parent &date) noexcept
{
	operator=(date);
}

Date &Date::operator=(const Date &date) noexcept
{
	return operator=(static_cast<const Parent &>(date));
}

Date &Date::operator=(const Parent &date) noexcept
{
	copy(year, date.year);
	copy(month, date.month);
	copy(day, date.day);
	return *this;
}

}}} // flame_ide::pkcs11::structs
