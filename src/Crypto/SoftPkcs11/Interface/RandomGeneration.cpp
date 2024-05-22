#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/RandomGeneration.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_SeedRandom(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pSeed
		, CK_ULONG ulSeedLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.randomGeneration
			.seedRandom(hSession, pSeed, ulSeedLen);
}

CK_RV C_GenerateRandom(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR RandomData
		, CK_ULONG ulRandomLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.randomGeneration
			.generateRandom(hSession, RandomData, ulRandomLen);
}
