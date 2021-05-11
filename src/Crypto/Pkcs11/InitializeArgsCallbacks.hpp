#ifndef FLAMEIDE_SRC_CRYPTO_PKCS11_INITIALIZEARGSCALLBACKS_HPP
#define FLAMEIDE_SRC_CRYPTO_PKCS11_INITIALIZEARGSCALLBACKS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

namespace flame_ide
{
namespace pkcs11
{

///
/// @brief Allocate memory mutex and initialize
/// @param[in,out] mutex non-null pointer for allocation
/// @return CKR_OK for success
/// @return CKR_HOST_MEMORY -- no memory
/// @return CKR_ARGUMENTS_BAD -- invalid argument
///
CK_RV createMutex(CK_VOID_PTR_PTR mutex) noexcept;

///
/// @brief Deinitialize mutex and free memory
/// @param[in,out] mutex pointer to allocated mutex
/// @return CKR_OK for success
/// @return CKR_ARGUMENTS_BAD -- invalid argument
///
CK_RV destroyMutex(CK_VOID_PTR mutex) noexcept;

///
/// @brief Lock mutex
/// @param[in,out] mutex pointer to allocated mutex
/// @return CKR_OK for success
/// @return CKR_ARGUMENTS_BAD -- invalid argument
///
CK_RV lockMutex(CK_VOID_PTR mutex) noexcept;

///
/// @brief unlockMutex
/// @param[in,out] mutex pointer to allocated mutex
/// @return CKR_OK for success
/// @return CKR_ARGUMENTS_BAD -- invalid argument
///
CK_RV unlockMutex(CK_VOID_PTR mutex) noexcept;

} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEIDE_SRC_CRYPTO_PKCS11_INITIALIZEARGSCALLBACKS_HPP
