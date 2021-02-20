#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_KEYFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_KEYFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace key
{

///
/// @brief generateKey
/// @param session
/// @param mechanism
/// @param attributeList
/// @param attributeListLength
/// @param key
/// @return
///
pkcs11::value_types::ReturnType generateKey(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
		, pkcs11::value_types::ObjectHandlePtr key
);

///
/// @brief generateKeyPair
/// @param session
/// @param mechanism
/// @param publicKeyAttrbuteList
/// @param publicKeyAttributeListLength
/// @param privateKeyTemplate
/// @param privateKeyAttributeCount
/// @param publicKey
/// @param privateKey
/// @return
///
pkcs11::value_types::ReturnType generateKeyPair(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::structs::AttributePtr publicKeyAttrbuteList
		, pkcs11::value_types::Ulong publicKeyAttributeListLength
		, pkcs11::structs::AttributePtr privateKeyTemplate
		, pkcs11::value_types::Ulong privateKeyAttributeCount
		, pkcs11::value_types::ObjectHandlePtr publicKey
		, pkcs11::value_types::ObjectHandlePtr privateKey
);

///
/// @brief wrapKey
/// @param session
/// @param mechanism
/// @param hWrappingKey
/// @param hKey
/// @param pWrappedKey
/// @param pulWrappedKeyLen
/// @return
///
pkcs11::value_types::ReturnType wrapKey(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::value_types::ObjectHandle hWrappingKey
		, pkcs11::value_types::ObjectHandle hKey
		, pkcs11::value_types::BytePtr pWrappedKey
		, pkcs11::value_types::UlongPtr pulWrappedKeyLen
);

///
/// @brief unwrapKey
/// @param session
/// @param mechanism
/// @param unwrappingKey
/// @param wrappedKey
/// @param wrappedKeyLength
/// @param pTemplate
/// @param ulAttributeCount
/// @param phKey
/// @return
///
pkcs11::value_types::ReturnType unwrapKey(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::value_types::ObjectHandle unwrappingKey
		, pkcs11::value_types::BytePtr wrappedKey
		, pkcs11::value_types::Ulong wrappedKeyLength
		, pkcs11::structs::AttributePtr pTemplate
		, pkcs11::value_types::Ulong ulAttributeCount
		, pkcs11::value_types::ObjectHandlePtr phKey
);

///
/// @brief deriveKey
/// @param session
/// @param mechanism
/// @param baseKey
/// @param attributeList
/// @param attributeListLength
/// @param key
/// @return
///
pkcs11::value_types::ReturnType deriveKey(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::value_types::ObjectHandle baseKey
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
		, pkcs11::value_types::ObjectHandlePtr key
);

}}}} // flame_ide::soft_pkcs11::functions::key

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_KEYFUNCTIONS_HPP
