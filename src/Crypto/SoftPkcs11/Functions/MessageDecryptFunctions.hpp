#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_MESSAGEDECRYPTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_MESSAGEDECRYPTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace message
{

pkcs11::value_types::ReturnType decryptInit(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::value_types::ObjectHandle key
);

pkcs11::value_types::ReturnType decrypt(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
		, pkcs11::value_types::BytePtr associatedData
		, pkcs11::value_types::Ulong associatedDataLength
		, pkcs11::value_types::BytePtr cipherText
		, pkcs11::value_types::Ulong cipherTextLength
		, pkcs11::value_types::BytePtr plainText
		, pkcs11::value_types::UlongPtr plainTextLength
);

pkcs11::value_types::ReturnType decryptBegin(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
		, pkcs11::value_types::BytePtr associatedData
		, pkcs11::value_types::Ulong associatedDataLength
);

pkcs11::value_types::ReturnType decryptNext(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
		, pkcs11::value_types::BytePtr cipherText
		, pkcs11::value_types::Ulong cipherTextLength
		, pkcs11::value_types::BytePtr plainText
		, pkcs11::value_types::UlongPtr plainTextLength
		, pkcs11::value_types::Flags flags
);

pkcs11::value_types::ReturnType decryptFinal(
		pkcs11::value_types::SessionHandle session
);

}}}} // flame_ide::soft_pkcs11::functions::message

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_MESSAGEDECRYPTFUNCTIONS_HPP
