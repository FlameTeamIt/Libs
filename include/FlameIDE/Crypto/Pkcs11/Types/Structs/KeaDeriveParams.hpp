#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_KEA_DERIVE_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_KEA_DERIVE_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct KeaDeriveParams: public WithParent<::CK_KEA_DERIVE_PARAMS>
{
	KeaDeriveParams() noexcept;

	KeaDeriveParams(const KeaDeriveParams &params) noexcept;
	KeaDeriveParams(const Parent &params) noexcept;

	KeaDeriveParams(
			const decltype(Parent::isSender) &isSender
			, const decltype(Parent::ulRandomLen) &randomLength
			, const decltype(Parent::pRandomA) &randomA
			, const decltype(Parent::pRandomB) &randomB
			, const decltype(Parent::ulPublicDataLen) &publicDataLength
			, const decltype(Parent::pPublicData) &publicData
	) noexcept;

	KeaDeriveParams &operator=(const KeaDeriveParams &params) noexcept;
	KeaDeriveParams &operator=(const Parent &params) noexcept;

	using Parent::isSender;
	using Parent::ulRandomLen;
	using Parent::pRandomA;
	using Parent::pRandomB;
	using Parent::ulPublicDataLen;
	using Parent::pPublicData;
};
using KeaDeriveParamsPtr = CK_KEA_DERIVE_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_KEA_DERIVE_PARAMS_HPP
