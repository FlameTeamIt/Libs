#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TOKEN_INFO_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TOKEN_INFO_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

/// @brief Information about a token
struct TokenInfo: public WithParent<::CK_TOKEN_INFO>
{
	TokenInfo() noexcept;
	TokenInfo(const TokenInfo &info) noexcept;
	TokenInfo(const Parent &info) noexcept;

	TokenInfo(const decltype(Parent::label) &label
			, const decltype(Parent::manufacturerID) &manufacturerId
			, const decltype(Parent::model) &model
			, const decltype(Parent::serialNumber) &serialNumber
			, const decltype(Parent::flags) &flags
			, const decltype(Parent::ulMaxSessionCount) &maxSessionCount
			, const decltype(Parent::ulSessionCount) &sessionCount
			, const decltype(Parent::ulMaxRwSessionCount) &maxRwSessionCount
			, const decltype(Parent::ulRwSessionCount) &rwSessionCount
			, const decltype(Parent::ulMaxPinLen) &maxPinLen
			, const decltype(Parent::ulMinPinLen) &minPinLen
			, const decltype(Parent::ulTotalPublicMemory) &totalPublicMemory
			, const decltype(Parent::ulFreePublicMemory) &freePublicMemory
			, const decltype(Parent::ulTotalPrivateMemory) &totalPrivateMemory
			, const decltype(Parent::ulFreePrivateMemory) &freePrivateMemory
			, const decltype(Parent::hardwareVersion) &hardwareVersion
			, const decltype(Parent::firmwareVersion) &firmwareVersion
			, const decltype(Parent::utcTime) &utcTime) noexcept;

	TokenInfo &operator=(const TokenInfo &info) noexcept;
	TokenInfo &operator=(const Parent &info) noexcept;

	using Parent::label;          ///< Blank padded
	using Parent::manufacturerID; ///< Blank padded
	using Parent::model;          ///< Blank padded
	using Parent::serialNumber;   ///< Blank padded
	using Parent::flags;          ///< Token flags

	using Parent::ulMaxSessionCount;    ///< Max open sessions
	using Parent::ulSessionCount;       ///< Sessions now open
	using Parent::ulMaxRwSessionCount;  ///< Max R/W sessions
	using Parent::ulRwSessionCount;     ///< R/W sess. now open
	using Parent::ulMaxPinLen;          ///< In bytes
	using Parent::ulMinPinLen;          ///< In bytes
	using Parent::ulTotalPublicMemory;  ///< In bytes
	using Parent::ulFreePublicMemory;   ///< In bytes
	using Parent::ulTotalPrivateMemory; ///< In bytes
	using Parent::ulFreePrivateMemory;  ///< In bytes
	using Parent::hardwareVersion;      ///< Version of hardware
	using Parent::firmwareVersion;      ///< Version of firmware
	using Parent::utcTime;              ///< Time
};
using TokenInfoPtr = ::CK_TOKEN_INFO_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_TOKEN_INFO_HPP
