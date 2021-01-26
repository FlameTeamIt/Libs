#ifndef FLAMEIDE_SRC_CRYPTO_PKCS11_INITIALIZEARGSCALLBACKS_HPP
#define FLAMEIDE_SRC_CRYPTO_PKCS11_INITIALIZEARGSCALLBACKS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

namespace flame_ide
{
namespace pkcs11
{

CK_RV createMutex(CK_VOID_PTR_PTR mutex);

CK_RV destroyMutex(CK_VOID_PTR mutex);

CK_RV lockMutex(CK_VOID_PTR mutex);

CK_RV unlockMutex(CK_VOID_PTR mutex);

} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEIDE_SRC_CRYPTO_PKCS11_INITIALIZEARGSCALLBACKS_HPP
