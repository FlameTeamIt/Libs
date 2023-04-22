#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SP800_108_KDF_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SP800_108_KDF_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct NistSp800Hyphen108KdfParams: public WithParent<::CK_SP800_108_KDF_PARAMS>
{
	NistSp800Hyphen108KdfParams() noexcept;

	NistSp800Hyphen108KdfParams(const NistSp800Hyphen108KdfParams &params) noexcept;
	NistSp800Hyphen108KdfParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param additionalDerivedKeys
	/// @param additionalDerivedKeysCount
	/// @param dataParams
	/// @param dataParamsCount
	NistSp800Hyphen108KdfParams(
			const decltype(Parent::pAdditionalDerivedKeys) &additionalDerivedKeys
			, const decltype(Parent::ulAdditionalDerivedKeys) &additionalDerivedKeysCount
			, const decltype(Parent::pDataParams) &dataParams
			, const decltype(Parent::ulNumberOfDataParams) &dataParamsCount
	) noexcept;

	NistSp800Hyphen108KdfParams &operator=(const NistSp800Hyphen108KdfParams &params) noexcept;
	NistSp800Hyphen108KdfParams &operator=(const Parent &params) noexcept;

	using Parent::ulNumberOfDataParams;
	using Parent::pDataParams;
	using Parent::ulAdditionalDerivedKeys;
	using Parent::pAdditionalDerivedKeys;
};

using NistSp800Hyphen108KdfParamsPtr = ::CK_SP800_108_KDF_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SP800_108_KDF_PARAMS_HPP
