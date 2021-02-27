#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_OTHERFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_OTHERFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Mix additional seed material into the token's random number generator
/// @param[in] hSession The session's handle
/// @param[in] pSeed The seed material
/// @param[in] ulSeedLen Length of seed material
/// @return See CKR_* values
///
CK_RV C_SeedRandom(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pSeed, CK_ULONG ulSeedLen);

///
/// @brief Generate random data
/// @param[in] hSession The session's handle
/// @param[out] RandomData Receives the random data
/// @param[in] ulRandomLen Count of bytes to generate
/// @return See CKR_* values
///
CK_RV C_GenerateRandom(CK_SESSION_HANDLE hSession, CK_BYTE_PTR RandomData
		, CK_ULONG ulRandomLen);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_OTHERFUNCTIONS_HPP
