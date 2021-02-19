#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_MANAGEMENTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_MANAGEMENTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace management
{

///
/// \brief getSlotList
/// \param tokenPresent
/// \param list
/// \param count
/// \return
///
pkcs11::value_types::ReturnType getSlotList(
		pkcs11::value_types::Bool tokenPresent
		, pkcs11::value_types::SlotIdPtr list
		, pkcs11::value_types::UlongPtr count
);

///
/// \brief getSlotInfo
/// \param id
/// \param info
/// \return
///
pkcs11::value_types::ReturnType getSlotInfo(
		pkcs11::value_types::SlotId id
		, pkcs11::structs::SlotInfoPtr info
);

///
/// \brief getTokenInfo
/// \param slotId
/// \param tokenInfo
/// \return
///
pkcs11::value_types::ReturnType getTokenInfo(
		pkcs11::value_types::SlotId slotId
		, pkcs11::structs::TokenInfoPtr tokenInfo
);

///
/// \brief getMechanismList
/// \param slotId
/// \param mechanismList
/// \param mechanismCount
/// \return
///
pkcs11::value_types::ReturnType getMechanismList(
		pkcs11::value_types::SlotId slotId
		, pkcs11::value_types::MechanismPtr mechanismList
		, pkcs11::value_types::UlongPtr mechanismCount
);

///
/// \brief getMechanismInfo
/// \param slotId
/// \param mechanismType
/// \param mechanismInfo
/// \return
///
pkcs11::value_types::ReturnType getMechanismInfo(
		pkcs11::value_types::SlotId slotId
		, pkcs11::value_types::Mechanism mechanismType
		, pkcs11::structs::MechanismInfoPtr mechanismInfo
);

///
/// \brief initToken
/// \param slotId
/// \param pin
/// \param pinLenength
/// \param label
/// \return
///
pkcs11::value_types::ReturnType initToken(
		pkcs11::value_types::SlotId slotId
		, pkcs11::value_types::Utf8CharPtr pin
		, pkcs11::value_types::Ulong pinLenength
		, pkcs11::value_types::Utf8CharPtr label
);

///
/// \brief initPin
/// \param session
/// \param pin
/// \param pinLength
/// \return
///
pkcs11::value_types::ReturnType initPin(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::Utf8CharPtr pin
		, pkcs11::value_types::Ulong pinLength
);

///
/// \brief setPin
/// \param session
/// \param oldPin
/// \param oldLength
/// \param newPin
/// \param newLength
/// \return
///
pkcs11::value_types::ReturnType setPin(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::Utf8CharPtr oldPin
		, pkcs11::value_types::Ulong oldLength
		, pkcs11::value_types::Utf8CharPtr newPin
		, pkcs11::value_types::Ulong newLength
);

}}}} // flame_ide::soft_pkcs11::functions::management

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_MANAGEMENTFUNCTIONS_HPP
