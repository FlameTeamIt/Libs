#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_VERIFYFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_VERIFYFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace verify
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
/// \param signature
/// \param signatureLength
/// \return
///
pkcs11::value_types::ReturnType final(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr signature
		, pkcs11::value_types::Ulong signatureLength
);

///
/// \brief full
/// \param session
/// \param data
/// \param dataLength
/// \param signature
/// \param signatureLength
/// \return
///
pkcs11::value_types::ReturnType full(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr data
		, pkcs11::value_types::Ulong dataLength
		, pkcs11::value_types::BytePtr signature
		, pkcs11::value_types::Ulong signatureLength
);

namespace recover
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
/// \brief full
/// \param session
/// \param data
/// \param dataLength
/// \param signature
/// \param signatureLength
/// \return
///
pkcs11::value_types::ReturnType full(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr data
		, pkcs11::value_types::Ulong dataLength
		, pkcs11::value_types::BytePtr signature
		, pkcs11::value_types::UlongPtr signatureLength
);

} // namespace recover

}}}} // flame_ide::soft_pkcs11::functions::verify

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_VERIFYFUNCTIONS_HPP
