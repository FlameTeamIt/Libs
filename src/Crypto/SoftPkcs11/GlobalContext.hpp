#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_GLOBALCONTEXT_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_GLOBALCONTEXT_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Callbacks.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mutex.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{

class GlobalContext
{
private:
	GlobalContext() noexcept;

	~GlobalContext() noexcept;

public: // General purpose
	pkcs11::enums::ReturnType initialize(
			const pkcs11::structs::InitializeArgs &args
	) noexcept;

	pkcs11::enums::ReturnType finalize() noexcept;

	pkcs11::structs::Info getInfo() noexcept;

	pkcs11::structs::FunctionListPtr getFunctionList() noexcept;

	void getInterfaceList();

	pkcs11::structs::InterfacePtr getInterface() noexcept;

public:
	pkcs11::enums::ReturnType getStatus() const noexcept;

	const CallbackAggregator &callbacks() const;

	Mutex createMutex() noexcept;

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
	void setExternalCallbacks(
			pkcs11::callbacks::CreateMutex create
			, pkcs11::callbacks::DestroyMutex destroy
			, pkcs11::callbacks::LockMutex lock
			, pkcs11::callbacks::UnlockMutex unlock
	);

private:
	CallbackAggregator callbackAggregator;

	pkcs11::enums::InitializeArgsFlags initFlags;

	pkcs11::structs::FunctionList functionList = createFunctionList();
	pkcs11::structs::FunctionList3 functionList3 = createFunctionList3();
	Pkcs11Interface interface;

	pkcs11::enums::ReturnType status = pkcs11::enums::ReturnType::OK;
};

}} // flame_ide::soft_pkcs11

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_GLOBALCONTEXT_HPP

