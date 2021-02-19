#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_SESSIONFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_SESSIONFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Callbacks.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace session
{

///
/// \brief open
/// \param slotId
/// \param flags
/// \param application
/// \param notifyCallback
/// \param session
/// \return
///
pkcs11::value_types::ReturnType open(
		pkcs11::value_types::SlotId slotId
		, pkcs11::value_types::Flags flags
		, pkcs11::value_types::ValuePtr application
		, pkcs11::callbacks::Notify notifyCallback
		, pkcs11::value_types::SessionHandlePtr session
);

///
/// \brief close
/// \param session
/// \return
///
pkcs11::value_types::ReturnType close(pkcs11::value_types::SessionHandle session);

///
/// \brief closeAll
/// \param slotId
/// \return
///
pkcs11::value_types::ReturnType closeAll(pkcs11::value_types::SlotId slotId);

///
/// \brief getInfo
/// \param session
/// \param info
/// \return
///
pkcs11::value_types::ReturnType getInfo(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::SessionInfoPtr info
);

///
/// \brief getOperationState
/// \param session
/// \param operationState
/// \param operationStateLength
/// \return
///
pkcs11::value_types::ReturnType getOperationState(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr operationState
		, pkcs11::value_types::UlongPtr operationStateLength
);

///
/// \brief setOperationState
/// \param session
/// \param operationState
/// \param operationStateLength
/// \param encryptionKey
/// \param authenticationKey
/// \return
///
pkcs11::value_types::ReturnType setOperationState(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr operationState
		, pkcs11::value_types::Ulong operationStateLength
		, pkcs11::value_types::ObjectHandle encryptionKey
		, pkcs11::value_types::ObjectHandle authenticationKey
);

///
/// \brief login
/// \param session
/// \param userType
/// \param pin
/// \param pinLength
/// \return
///
pkcs11::value_types::ReturnType login(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::User userType
		, pkcs11::value_types::Utf8CharPtr pin
		, pkcs11::value_types::Ulong pinLength
);

///
/// \brief logout
/// \param session
/// \return
///
pkcs11::value_types::ReturnType logout(pkcs11::value_types::SessionHandle session);

}}}} // flame_ide::soft_pkcs11::functions::session

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_SESSIONFUNCTIONS_HPP
