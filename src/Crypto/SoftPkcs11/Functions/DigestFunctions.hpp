#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_DIGESTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_DIGESTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace digest
{

///
/// \brief init
/// \param session
/// \param mechanism
/// \return
///
pkcs11::value_types::ReturnType init(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
);

///
/// \brief update
/// \param session
/// \param dataPart
/// \param dataPartLength
/// \return
///
pkcs11::value_types::ReturnType update(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::Ulong dataPartLength
);

///
/// \brief final
/// \param session
/// \param digestData
/// \param digestDataLength
/// \return
///
pkcs11::value_types::ReturnType final(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr digestData
		, pkcs11::value_types::UlongPtr digestDataLength
);

///
/// \brief full
/// \param session
/// \param data
/// \param dataLength
/// \param digestData
/// \param digestDataLength
/// \return
///
pkcs11::value_types::ReturnType full(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr data
		, pkcs11::value_types::Ulong dataLength
		, pkcs11::value_types::BytePtr digestData
		, pkcs11::value_types::UlongPtr digestDataLength
);

///
/// \brief key
/// \param session
/// \param key
/// \return
///
pkcs11::value_types::ReturnType key(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ObjectHandle key
);

}}}} // flame_ide::soft_pkcs11::functions::digest

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_DIGESTFUNCTIONS_HPP
