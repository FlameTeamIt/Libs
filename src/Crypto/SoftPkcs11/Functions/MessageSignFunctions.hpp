#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_MESSAGESIGNFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_MESSAGESIGNFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace message
{

pkcs11::value_types::ReturnType signInit(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::value_types::ObjectHandle key
);

pkcs11::value_types::ReturnType sign(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
		, pkcs11::value_types::BytePtr data
		, pkcs11::value_types::Ulong dataLength
		, pkcs11::value_types::BytePtr signature
		, pkcs11::value_types::UlongPtr signatureLength
);

pkcs11::value_types::ReturnType signBegin(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
);

pkcs11::value_types::ReturnType signNext(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
		, pkcs11::value_types::BytePtr sata
		, pkcs11::value_types::Ulong dataLength
		, pkcs11::value_types::BytePtr signature
		, pkcs11::value_types::UlongPtr signatureLength
);

pkcs11::value_types::ReturnType signFinal(
		pkcs11::value_types::SessionHandle session
);

}}}} // flame_ide::soft_pkcs11::functions::message

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_MESSAGESIGNFUNCTIONS_HPP
