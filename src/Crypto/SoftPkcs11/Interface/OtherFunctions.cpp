#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/OtherFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_SeedRandom(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pSeed
		, CK_ULONG ulSeedLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.otherCallbacks
			.seedRandom(hSession, pSeed, ulSeedLen);
}

CK_RV C_GenerateRandom(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR RandomData
		, CK_ULONG ulRandomLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.otherCallbacks
			.generateRandom(hSession, RandomData, ulRandomLen);
}
