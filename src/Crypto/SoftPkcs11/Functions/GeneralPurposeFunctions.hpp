#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_GENERALPURPOSEFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_GENERALPURPOSEFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace general_purpose
{

///
/// @brief initialize
/// @param arguments
/// @return
///
pkcs11::value_types::ReturnType initialize(pkcs11::value_types::ValuePtr arguments);

///
/// @brief finalize
/// @return
///
pkcs11::value_types::ReturnType finalize(
		pkcs11::value_types::ValuePtr /* reserved */
);

///
/// @brief getInfo
/// @param info
/// @return
///
pkcs11::value_types::ReturnType getInfo(
		pkcs11::structs::InfoPtr info
);

///
/// @brief getFunctionList
/// @param functionList
/// @return
///
pkcs11::value_types::ReturnType getFunctionList(
		pkcs11::structs::FunctionListPtrPtr functionList
);

// v3.0

///
/// @brief getIterfaceList
/// @param interfaces
/// @param count
/// @return
///
pkcs11::value_types::ReturnType getIterfaceList(
		pkcs11::structs::InterfacePtr interfaces
		, pkcs11::value_types::UlongPtr count
);

///
/// @brief getIterface
/// @param interfaceName
/// @param version
/// @param interface
/// @param flags
/// @return
///
pkcs11::value_types::ReturnType getIterface(
		pkcs11::value_types::Utf8CharPtr interfaceName
		, pkcs11::structs::VersionPtr version
		, pkcs11::structs::InterfacePtrPtr interface
		, pkcs11::value_types::Flags flags
);

}}}} // flame_ide::soft_pkcs11::functions::general_purpose

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_GENERALPURPOSEFUNCTIONS_HPP
