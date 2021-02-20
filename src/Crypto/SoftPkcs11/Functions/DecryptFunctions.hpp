#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_DECRYPTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_DECRYPTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace decrypt
{

///
/// @brief init
/// @param session
/// @param mechanism
/// @param object
/// @return
///
pkcs11::value_types::ReturnType init(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::value_types::ObjectHandle object
);

///
/// @brief update
/// @param session
/// @param encryptedDataPart
/// @param encryptedDataPartLen
/// @param dataPart
/// @param dataPartLen
/// @return
///
pkcs11::value_types::ReturnType update(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr encryptedDataPart
		, pkcs11::value_types::Ulong encryptedDataPartLength
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::UlongPtr dataPartLength
);

///
/// @brief final
/// @param session
/// @param lastPart
/// @param lastPartLength
/// @return
///
pkcs11::value_types::ReturnType final(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr lastPart
		, pkcs11::value_types::UlongPtr lastPartLength
);

///
/// @brief full
/// @param session
/// @param encryptedData
/// @param encryptedDataLength
/// @param data
/// @param dataLength
/// @return
///
pkcs11::value_types::ReturnType full(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr encryptedData
		, pkcs11::value_types::Ulong encryptedDataLength
		, pkcs11::value_types::BytePtr data
		, pkcs11::value_types::UlongPtr dataLength
);

}}}} // flame_ide::soft_pkcs11::functions::decrypt

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_DECRYPTFUNCTIONS_HPP
