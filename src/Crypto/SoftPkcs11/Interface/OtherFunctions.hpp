#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_OTHERFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_OTHERFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// \brief C_SeedRandom
/// \param hSession
/// \param pSeed
/// \param ulSeedLen
/// \return
///
CK_RV C_SeedRandom(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pSeed
		, CK_ULONG ulSeedLen
);

///
/// \brief C_GenerateRandom
/// \param hSession
/// \param RandomData
/// \param ulRandomLen
/// \return
///
CK_RV C_GenerateRandom(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR RandomData
		, CK_ULONG ulRandomLen
);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_OTHERFUNCTIONS_HPP
