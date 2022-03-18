#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_GLOBALCONTEXT_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_GLOBALCONTEXT_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Callbacks.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mutex.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{

class Pkcs11Interface: public pkcs11::structs::Interface
{
public:
	Pkcs11Interface(pkcs11::structs::FunctionList3 &functionList);

private:
	pkcs11::value_types::Utf8Char name[sizeof("PKCS 11")];
};

struct GlobalContext
{
public:
	~GlobalContext() noexcept;

	Mutex createMutex() noexcept;

	pkcs11::structs::FunctionListPtr getFunctionList() noexcept;

	pkcs11::structs::InterfacePtr getInterface() noexcept;

	pkcs11::enums::ReturnType getStatus() const noexcept;

public:
	static GlobalContext &get() noexcept;

public:
	ExternalCallbacks externalCallbacks;
	GeneralPurposeCallbacks generalPurposeCallbacks;
	ManagementCallbacks managementCallbacks;
	SessionCallbacks sessionCallbacks;
	ObjectCallbacks objectCallbacks;
	EncryptCallbacks encryptCallbacks;
	DecryptCallbacks decryptCallbacks;
	DigestCallbacks digestCallbacks;
	SignCallbacks signCallbacks;
	VerifyCallbacks verifyCallbacks;
	DualOperationCallbacks dualOperationCallbacks;
	KeyCallbacks keyCallbacks;
	ParallelManagementCallbacks parallelManagementCallbacks;
	RandomGenerationCallbacks randomGenerationCallbacks;

	// v3.0
	MessageEncriptionFunctions messageEncriptionFunctions;
	MessageDecriptionFunctions messageDecriptionFunctions;
	MessageSignFunctions messageSignFunctions;
	MessageVerifyFunctions messageVerifyFunctions;

	pkcs11::enums::InitializeArgsFlags initFlags
			= pkcs11::enums::InitializeArgsFlags::LIBRARY_CANT_CREATE_OS_THREADS;

private:
	GlobalContext() noexcept;

private:
	pkcs11::structs::FunctionList functionList = createFunctionList();
	pkcs11::structs::FunctionList3 functionList3 = createFunctionList3();
	Pkcs11Interface interface;

	pkcs11::enums::ReturnType status = pkcs11::enums::ReturnType::OK;
};

}} // flame_ide::soft_pkcs11

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_GLOBALCONTEXT_HPP

