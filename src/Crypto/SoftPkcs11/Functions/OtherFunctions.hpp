#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_OTHERFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_OTHERFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace other
{

///
/// @brief seedRandom
/// @param session
/// @param seed
/// @param seedLength
/// @return
///
pkcs11::value_types::ReturnType seedRandom(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr seed
		, pkcs11::value_types::Ulong seedLength
);

///
/// @brief generateRandom
/// @param session
/// @param randomData
/// @param randomLength
/// @return
///
pkcs11::value_types::ReturnType generateRandom(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr randomData
		, pkcs11::value_types::Ulong randomLength
);

}}}} // flame_ide::soft_pkcs11::functions::other

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_OTHERFUNCTIONS_HPP
