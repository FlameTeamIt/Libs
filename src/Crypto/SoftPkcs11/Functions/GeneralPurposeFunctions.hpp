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

}}}} // flame_ide::soft_pkcs11::functions::general_purpose

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_GENERALPURPOSEFUNCTIONS_HPP
