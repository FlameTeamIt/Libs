#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_DATE_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_DATE_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

/// @brief Define a date
struct Date: public WithParent<::CK_DATE>
{
	Date() noexcept;
	Date(const Date &date) noexcept;
	Date(const Parent &date) noexcept;

	Date(const decltype(Parent::year) &year
			, const decltype(Parent::month) &month
			, const decltype(Parent::day) &day);

	Date &operator=(const Date &date) noexcept;
	Date &operator=(const Parent &date) noexcept;

	using Parent::year;  ///< Year ("1900" - "9999")
	using Parent::month; ///< Month ("01" - "12")
	using Parent::day;   ///< Day ("01" - "31")
};

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_DATE_HPP
