#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_MECHANISM_INFO_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_MECHANISM_INFO_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

/// @brief Information about a particular mechanism
struct MechanismInfo: public WithParent<::CK_MECHANISM_INFO>
{
	MechanismInfo() noexcept;
	MechanismInfo(const MechanismInfo &info) noexcept;
	MechanismInfo(const Parent &info) noexcept;

	MechanismInfo(const decltype(Parent::ulMinKeySize) &minKeySize
			, const decltype(Parent::ulMaxKeySize) &maxKeySize
			, const decltype(Parent::flags) &flags) noexcept;

	MechanismInfo &operator=(const MechanismInfo &info) noexcept;
	MechanismInfo &operator=(const Parent &info) noexcept;

	using Parent::ulMinKeySize; ///<
	using Parent::ulMaxKeySize; ///<
	using Parent::flags;        ///<
};
using MechanismInfoPtr = ::CK_MECHANISM_INFO_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_MECHANISM_INFO_HPP
