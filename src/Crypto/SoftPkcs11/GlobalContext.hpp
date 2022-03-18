#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_GLOBALCONTEXT_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_GLOBALCONTEXT_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Callbacks.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mutex.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{

struct GlobalContext
{
public:
	~GlobalContext() noexcept;

	Mutex createMutex() noexcept;

	pkcs11::structs::FunctionListPtr getFunctionList() noexcept;

	pkcs11::structs::InterfacePtr getInterface() noexcept;

	pkcs11::enums::ReturnType getStatus() const noexcept;

	const Callbacks &callbacks() const;

public:
	static GlobalContext &get() noexcept;

private:
	class Pkcs11Interface: public pkcs11::structs::Interface
	{
	public:
		Pkcs11Interface(pkcs11::structs::FunctionList3 &functionList);

	private:
		pkcs11::value_types::Utf8Char name[sizeof("PKCS 11")];
	};


private:
	GlobalContext() noexcept;

private:
	Callbacks internalCallbacks;

	pkcs11::enums::InitializeArgsFlags initFlags
			= pkcs11::enums::InitializeArgsFlags::LIBRARY_CANT_CREATE_OS_THREADS;

private:
	pkcs11::structs::FunctionList functionList = createFunctionList();
	pkcs11::structs::FunctionList3 functionList3 = createFunctionList3();
	Pkcs11Interface interface;

	pkcs11::enums::ReturnType status = pkcs11::enums::ReturnType::OK;
};

}} // flame_ide::soft_pkcs11

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_GLOBALCONTEXT_HPP

