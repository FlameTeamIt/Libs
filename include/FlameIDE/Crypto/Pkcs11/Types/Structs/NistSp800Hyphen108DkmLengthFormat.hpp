#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SP800_108_DKM_LENGTH_FORMAT_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SP800_108_DKM_LENGTH_FORMAT_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct NistSp800Hyphen108DkmLengthFormat: public WithParent<::CK_SP800_108_DKM_LENGTH_FORMAT>
{
	NistSp800Hyphen108DkmLengthFormat() noexcept;

	NistSp800Hyphen108DkmLengthFormat(const NistSp800Hyphen108DkmLengthFormat &params) noexcept;

	NistSp800Hyphen108DkmLengthFormat(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param widthInBits
	/// @param isLittleEndian
	/// @param dkmLengthMethod
	NistSp800Hyphen108DkmLengthFormat(
			const decltype(Parent::ulWidthInBits) &widthInBits
			, const decltype(Parent::bLittleEndian) &isLittleEndian
			, const decltype(Parent::dkmLengthMethod) &dkmLengthMethod
	) noexcept;

	NistSp800Hyphen108DkmLengthFormat &operator=(
			const NistSp800Hyphen108DkmLengthFormat &params
	) noexcept;

	NistSp800Hyphen108DkmLengthFormat &operator=(const Parent &params) noexcept;

	using Parent::dkmLengthMethod;
	using Parent::bLittleEndian;
	using Parent::ulWidthInBits;
};

using NistSp800Hyphen108DkmLengthFormatPtr = ::CK_SP800_108_DKM_LENGTH_FORMAT_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SP800_108_DKM_LENGTH_FORMAT_HPP
