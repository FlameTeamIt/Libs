#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SP800_108_COUNTER_FORMAT_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SP800_108_COUNTER_FORMAT_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct NistSp800Hyphen108CounterFormat: public WithParent<::CK_SP800_108_COUNTER_FORMAT>
{
	NistSp800Hyphen108CounterFormat() noexcept;

	NistSp800Hyphen108CounterFormat(const NistSp800Hyphen108CounterFormat &params) noexcept;
	NistSp800Hyphen108CounterFormat(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param isLittleEndian
	/// @param widthInBits
	NistSp800Hyphen108CounterFormat(
			const decltype(Parent::bLittleEndian) isLittleEndian
			, const decltype(Parent::ulWidthInBits) &widthInBits
	) noexcept;

	NistSp800Hyphen108CounterFormat &operator=(
			const NistSp800Hyphen108CounterFormat &params
	) noexcept;
	NistSp800Hyphen108CounterFormat &operator=(const Parent &params) noexcept;

	using Parent::bLittleEndian;
	using Parent::ulWidthInBits;
};

using NistSp800Hyphen108CounterFormatPtr = ::CK_SP800_108_COUNTER_FORMAT_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SP800_108_COUNTER_FORMAT_HPP
