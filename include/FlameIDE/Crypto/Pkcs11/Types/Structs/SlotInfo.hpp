#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SLOT_INFO_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SLOT_INFO_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

/// @brief Provides information about a slot
struct SlotInfo: public WithParent<::CK_SLOT_INFO>
{
	SlotInfo() noexcept;
	SlotInfo(const SlotInfo &info) noexcept;
	SlotInfo(const Parent &info) noexcept;

	SlotInfo(const decltype(Parent::slotDescription) &slotDescription
			, const decltype(Parent::manufacturerID) &manufacturerId
			, const decltype(Parent::flags) &flags
			, const decltype(Parent::hardwareVersion) &hardwareVersion
			, const decltype(Parent::firmwareVersion) &firmwareVersion) noexcept;

	SlotInfo &operator=(const SlotInfo &info) noexcept;
	SlotInfo &operator=(const Parent &info) noexcept;

	using Parent::slotDescription; ///< blank padded
	using Parent::manufacturerID;  ///< blank padded
	using Parent::flags;           ///< Bit flags provided capabilities of the slot

	using Parent::hardwareVersion; ///< version of hardware
	using Parent::firmwareVersion; ///< version of firmware
};
using SlotInfoPtr = ::CK_SLOT_INFO_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_SLOT_INFO_HPP
