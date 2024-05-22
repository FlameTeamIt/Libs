#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_DERIVED_KEY_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_DERIVED_KEY_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

struct DerivedKey: public WithParent<::CK_DERIVED_KEY>
{
	DerivedKey() noexcept;

	DerivedKey(const DerivedKey &params) noexcept;
	DerivedKey(const Parent &params) noexcept;

	/// @brief Constructor
	/// @param attribute
	/// @param attributeCount
	/// @param keyHandle
	DerivedKey(
			const decltype(Parent::pTemplate) &attribute
			, const decltype(Parent::ulAttributeCount) &attributeCount
			, const decltype(Parent::phKey) &keyHandle
	) noexcept;

	DerivedKey &operator=(const DerivedKey &params) noexcept;
	DerivedKey &operator=(const Parent &params) noexcept;

	using Parent::pTemplate;
	using Parent::ulAttributeCount;
	using Parent::phKey;
};

using DerivedKeyPtr = ::CK_DERIVED_KEY_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_DERIVED_KEY_HPP
