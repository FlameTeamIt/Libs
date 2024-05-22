#ifndef FLAMEIDE_SRC_CRYPTO_PKCS11_INITIALIZEARGSCALLBACKS_HPP
#define FLAMEIDE_SRC_CRYPTO_PKCS11_INITIALIZEARGSCALLBACKS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>

namespace flame_ide
{namespace pkcs11
{namespace value_types
{

using MutexPtr = ValuePtr;
using MutexPtrPtr = ValuePtrPtr;

}}} // namespace flame_ide::pkcs11::value_types

namespace flame_ide
{namespace pkcs11
{

///
/// @brief Allocate memory mutex and initialize
/// @param[in,out] mutex non-null pointer for allocation
/// @return CKR_OK for success
/// @return CKR_HOST_MEMORY -- no memory
/// @return CKR_ARGUMENTS_BAD -- invalid argument
///
value_types::ReturnType createMutex(value_types::MutexPtrPtr mutex) noexcept;

///
/// @brief Deinitialize mutex and free memory
/// @param[in,out] mutex pointer to allocated mutex
/// @return CKR_OK for success
/// @return CKR_ARGUMENTS_BAD -- invalid argument
///
value_types::ReturnType destroyMutex(value_types::MutexPtr mutex) noexcept;

///
/// @brief Lock mutex
/// @param[in,out] mutex pointer to allocated mutex
/// @return CKR_OK for success
/// @return CKR_ARGUMENTS_BAD -- invalid argument
///
value_types::ReturnType lockMutex(value_types::MutexPtr mutex) noexcept;

///
/// @brief unlockMutex
/// @param[in,out] mutex pointer to allocated mutex
/// @return CKR_OK for success
/// @return CKR_ARGUMENTS_BAD -- invalid argument
///
value_types::ReturnType unlockMutex(value_types::MutexPtr mutex) noexcept;

}} // namespace flame_ide::pkcs11

#endif // FLAMEIDE_SRC_CRYPTO_PKCS11_INITIALIZEARGSCALLBACKS_HPP
