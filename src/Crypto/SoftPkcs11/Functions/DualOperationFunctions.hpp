#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_DUALOPERATIONFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_DUALOPERATIONFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace dual_operations
{

///
/// \brief digestEncryptUpdate
/// \param session
/// \param dataPart
/// \param dataPartLength
/// \param encryptedDataPart
/// \param encryptedDataPartLength
/// \return
///
pkcs11::value_types::ReturnType digestEncryptUpdate(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::Ulong dataPartLength
		, pkcs11::value_types::BytePtr encryptedDataPart
		, pkcs11::value_types::UlongPtr encryptedDataPartLength
);

///
/// \brief decryptDigestUpdate
/// \param session
/// \param encryptedDataPart
/// \param encryptedDataPartLength
/// \param dataPart
/// \param dataPartLength
/// \return
///
pkcs11::value_types::ReturnType decryptDigestUpdate(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr encryptedDataPart
		, pkcs11::value_types::Ulong encryptedDataPartLength
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::UlongPtr dataPartLength
);

///
/// \brief signEncryptUpdate
/// \param session
/// \param dataPart
/// \param dataPartLength
/// \param encryptedDataPart
/// \param encryptedDataPartLength
/// \return
///
pkcs11::value_types::ReturnType signEncryptUpdate(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::Ulong dataPartLength
		, pkcs11::value_types::BytePtr encryptedDataPart
		, pkcs11::value_types::UlongPtr encryptedDataPartLength
);

///
/// \brief decryptVerifyUpdate
/// \param session
/// \param encryptedDataPart
/// \param encryptedDataPartLength
/// \param dataPart
/// \param dataPartLength
/// \return
///
pkcs11::value_types::ReturnType decryptVerifyUpdate(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr encryptedDataPart
		, pkcs11::value_types::Ulong encryptedDataPartLength
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::UlongPtr dataPartLength
);

}}}} // flame_ide::soft_pkcs11::functions::dual_operations

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_DUALOPERATIONFUNCTIONS_HPP
