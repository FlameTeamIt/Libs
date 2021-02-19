#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_ENCRYPTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_ENCRYPTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace encrypt
{

///
/// \brief init
/// \param session
/// \param mechanism
/// \param key
/// \return
///
pkcs11::value_types::ReturnType init(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::value_types::ObjectHandle key
);

///
/// \brief update
/// \param session
/// \param dataPart
/// \param dataPartLength
/// \param encryptedDataPart
/// \param encryptedDataPartLength
/// \return
///
pkcs11::value_types::ReturnType update(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::Ulong dataPartLength
		, pkcs11::value_types::BytePtr encryptedDataPart
		, pkcs11::value_types::UlongPtr encryptedDataPartLength
);

///
/// \brief final
/// \param session
/// \param lastEncryptedDataPart
/// \param lastEncryptedDataPartLength
/// \return
///
pkcs11::value_types::ReturnType final(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr lastEncryptedDataPart
		, pkcs11::value_types::UlongPtr lastEncryptedDataPartLength
);

///
/// \brief full
/// \param session
/// \param data
/// \param dataLength
/// \param encryptedData
/// \param encryptedDataLength
/// \return
///
pkcs11::value_types::ReturnType full(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr data
		, pkcs11::value_types::Ulong dataLength
		, pkcs11::value_types::BytePtr encryptedData
		, pkcs11::value_types::UlongPtr encryptedDataLength
);

}}}} // flame_ide::soft_pkcs11::functions::encrypt

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_ENCRYPTFUNCTIONS_HPP
