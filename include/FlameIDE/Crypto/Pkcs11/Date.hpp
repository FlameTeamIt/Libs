#ifndef FLAMEIDE_CRYPTO_PKCS11_DATE_HPP
#define FLAMEIDE_CRYPTO_PKCS11_DATE_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

#include <FlameIDE/Common/Traits/Numbers.hpp>

namespace flame_ide
{
namespace pkcs11
{

class Date: public structs::Date
{
	using Parent = structs::Date;

public:
	using CharType = value_types::Char;
	static constexpr Types::size_t YEAR_SIZE = sizeof(year);
	static constexpr Types::size_t MONTH_SIZE = sizeof(month);
	static constexpr Types::size_t DAY_SIZE = sizeof(day);

	using YearType = CharType[YEAR_SIZE];
	using MonthType = CharType[MONTH_SIZE];
	using DayType = CharType[DAY_SIZE];

	Date() noexcept;
	Date(const Date &) noexcept = default;

	/// @brief Date
	/// @param cryptokiDate
	Date(const Parent &cryptokiDate) noexcept;

	/// @brief Date
	/// @param initYear
	/// @param initMonth
	/// @param initDay
	Date(const YearType &initYear, const MonthType &initMonth
			, const DayType &initDay) noexcept;

	Date &operator=(const Date&) noexcept = default;

	bool operator==(const Date &date) noexcept;
	bool operator<(const Date &date) noexcept;
	bool operator>(const Date &date) noexcept;
	bool operator>=(const Date &date) noexcept;
	bool operator<=(const Date &date) noexcept;

private:
	using Parent::year;
	using Parent::month;
	using Parent::day;
};

} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEIDE_CRYPTO_PKCS11_DATE_HPP
