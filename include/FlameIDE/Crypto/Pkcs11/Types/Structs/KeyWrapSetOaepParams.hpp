#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_KEY_WRAP_SET_OAEP_PARAMS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_KEY_WRAP_SET_OAEP_PARAMS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief Provide the parameters to the CKM_KEY_WRAP_SET_OAEP mechanism
struct KeyWrapSetOaepParams: public WithParent<::CK_KEY_WRAP_SET_OAEP_PARAMS>
{
	KeyWrapSetOaepParams() noexcept;

	KeyWrapSetOaepParams(const KeyWrapSetOaepParams &params) noexcept;
	KeyWrapSetOaepParams(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param block Block contents byte
	/// @param extraData Extra data
	/// @param extraDataLength Length of extra data in bytes
	KeyWrapSetOaepParams(
			const decltype(Parent::bBC) &block
			, const decltype(Parent::pX) &extraData
			, const decltype(Parent::ulXLen) &extraDataLength
	) noexcept;

	KeyWrapSetOaepParams &operator=(const KeyWrapSetOaepParams &params) noexcept;
	KeyWrapSetOaepParams &operator=(const Parent &params) noexcept;

	using Parent::bBC;
	using Parent::pX;
	using Parent::ulXLen;
};
using KeyWrapSetOaepParamsPtr = CK_KEY_WRAP_SET_OAEP_PARAMS_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_KEY_WRAP_SET_OAEP_PARAMS_HPP
