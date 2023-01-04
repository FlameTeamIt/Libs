#ifndef FLAMEIDE_CRYPTO_PKCS11_WRAPPER_PKCS11_HPP
#define FLAMEIDE_CRYPTO_PKCS11_WRAPPER_PKCS11_HPP

#include <FlameIDE/Common/ReferenceWrapper.hpp>

#include <FlameIDE/Crypto/Pkcs11/InitializeArgs.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Mechanism.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SessionInfo.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/TokenInfo.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Structs/FunctionList.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Info.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Interface.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SlotInfo.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>

#include <FlameIDE/Os/Library.hpp>

#include <FlameIDE/Templates/Expected.hpp>
#include <FlameIDE/Templates/Variant.hpp>
#include <FlameIDE/Templates/Vector.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

// Additions

namespace flame_ide
{namespace pkcs11
{namespace structs
{

using InterfaceList = flame_ide::templates::Vector<pkcs11::structs::Interface>;
using SlotIdList = flame_ide::templates::Vector<pkcs11::value_types::SlotId>;
using MechanismList = flame_ide::templates::Vector<pkcs11::enums::Mechanism>;

using OperationState = flame_ide::templates::Vector<pkcs11::value_types::Byte>;

}}} // namespace flame_ide::pkcs11::structs

// Forward declarations

namespace flame_ide
{namespace pkcs11
{namespace wrapper
{

template<typename Struct>
using Pkcs11Expected = templates::Expected<Struct, pkcs11::enums::ReturnType>;

using FunctionList = flame_ide::ReferenceWrapper<const pkcs11::structs::FunctionList>;

class Pkcs11Library;
class Slot;
class Token;
class Session;
class Object;

}}} // namespace flame_ide::pkcs11::wrapper

// Difinitions

namespace flame_ide
{namespace pkcs11
{namespace wrapper
{

template<typename Struct>
Pkcs11Expected<Struct>
createPkcs11Expected(const Struct &value, pkcs11::enums::ReturnType error)
{
	Pkcs11Expected<Struct> expectedResult;
	if (error == pkcs11::enums::ReturnType::OK)
	{
		expectedResult = value;
	}
	else
	{
		expectedResult = error;
	}
	return expectedResult;
}

//template<typename Struct>
//Pkcs11Expected<Struct>
//createPkcs11Expected(Struct &&value, pkcs11::enums::ReturnType error)
//{
//	Pkcs11Expected<Struct> expectedResult;
//	if (error == pkcs11::enums::ReturnType::OK)
//	{
//		expectedResult = flame_ide::move(value);
//	}
//	else
//	{
//		expectedResult = error;
//	}
//	return expectedResult;
//}

}}} // namespace flame_ide::pkcs11::wrapper

// class Pkcs11Library
namespace flame_ide
{namespace pkcs11
{namespace wrapper
{

class Pkcs11Library: private os::Library
{
private:
	using os::Library::find;

private:
	template<typename T, typename ObjectCounter>
	friend struct templates::pointer_utils::Members;

	Pkcs11Library(const char *name, const char *directory = nullptr) noexcept;

public:
	using os::Library::operator bool;

	~Pkcs11Library() noexcept;

	static templates::SharedPointer<Pkcs11Library> create(
			const char *name, const char *directory = nullptr
	) noexcept;

	static templates::SharedPointer<Pkcs11Library> create(
			const char *name, const char *directory
			, pkcs11::structs::InitializeArgs args
	) noexcept;

public: // Interface
	pkcs11::enums::ReturnType initialize(const pkcs11::wrapper::InitializeArgs &args) noexcept;
	pkcs11::enums::ReturnType finalize() noexcept;

	Pkcs11Expected<pkcs11::structs::Info> getInfo() const noexcept;
	Pkcs11Expected<FunctionList> getFunctionList() const noexcept;
	Pkcs11Expected<const pkcs11::structs::InterfaceList *> getInterfaceList() const noexcept;
	Pkcs11Expected<const pkcs11::structs::Interface *> getInterface() const noexcept;

	Pkcs11Expected<pkcs11::value_types::Ulong> getSlotIdCount(
			pkcs11::enums::Bool present = pkcs11::enums::Bool::OASIS_TRUE
	) const noexcept;

	Pkcs11Expected<pkcs11::structs::SlotIdList> getSlotIdList(
			pkcs11::enums::Bool present = pkcs11::enums::Bool::OASIS_TRUE
	) const noexcept;

private:
	pkcs11::enums::ReturnType initializeFunctionList() noexcept;
	pkcs11::enums::ReturnType initializeInterfaceList() noexcept;
	pkcs11::enums::ReturnType initializeMain(pkcs11::structs::InitializeArgs args) noexcept;
	pkcs11::enums::ReturnType initializeInfo() noexcept;

private:
	pkcs11::enums::ReturnType status = pkcs11::enums::ReturnType::CRYPTOKI_NOT_INITIALIZED;

	pkcs11::structs::FunctionList functionList;
	Pkcs11Expected<pkcs11::structs::InterfaceList> ifaceList;
	pkcs11::structs::Info info;
};

}}} // namespace flame_ide::pkcs11::wrapper

// class Slot
namespace flame_ide
{namespace pkcs11
{namespace wrapper
{

class Slot
{
private:
	template<typename T, typename ObjectCounter>
	friend struct templates::pointer_utils::Members;

	Slot(templates::SharedPointer<Pkcs11Library> library
		 , pkcs11::value_types::SlotId id);

public:
	static templates::SharedPointer<Slot> create(
			templates::SharedPointer<Pkcs11Library> library
			, pkcs11::value_types::SlotId id
	);

	const templates::SharedPointer<Pkcs11Library> &getLibrary() const;
	pkcs11::value_types::SlotId getSlotId() const;

public: // Interface
	Pkcs11Expected<pkcs11::structs::SlotInfo> getSlotInfo() const;
	pkcs11::enums::ReturnType waitForSlotEvent(pkcs11::enums::WaitForSlotEventFlags flags);

private:
	templates::SharedPointer<Pkcs11Library> library;
	pkcs11::value_types::SlotId id;
};


}}} // namespace flame_ide::pkcs11::wrapper

// class Token - presented in Slot
namespace flame_ide
{namespace pkcs11
{namespace wrapper
{

class Token
{
private:
	template<typename T, typename ObjectCounter>
	friend struct templates::pointer_utils::Members;

	Token(templates::SharedPointer<Slot> slot);

public:
	static templates::SharedPointer<Token> create(templates::SharedPointer<Slot> slot);

	const templates::SharedPointer<Slot> &getSlot() const noexcept;

public: // Interface
	Pkcs11Expected<pkcs11::structs::TokenInfo> getTokenInfo() const;
	Pkcs11Expected<pkcs11::value_types::Ulong> getMechanismCount() const;
	Pkcs11Expected<pkcs11::structs::MechanismList> getMechanismList() const;

	pkcs11::enums::ReturnType closeAllSessions() noexcept;

private:
	templates::SharedPointer<Slot> slot;
};

}}} // namespace flame_ide::pkcs11::wrapper

// class Session
namespace flame_ide
{namespace pkcs11
{namespace wrapper
{

class Session
{
private:
	Session(templates::SharedPointer<Token> token);

public:
	~Session() noexcept;

	const templates::SharedPointer<Token> &getToken() const noexcept;
	pkcs11::value_types::SessionHandle getHandle() const noexcept;

public: // Interface
	// Session management
	static templates::SharedPointer<Session> open(templates::SharedPointer<Token> token);
	pkcs11::enums::ReturnType close() noexcept;

	Pkcs11Expected<pkcs11::structs::SessionInfo> getSessionInfo() const noexcept;

	pkcs11::enums::ReturnType cancel();

	pkcs11::enums::ReturnType setOperationState();
	pkcs11::enums::ReturnType getOperationState();

	pkcs11::enums::ReturnType login();
	pkcs11::enums::ReturnType loginUser();
	pkcs11::enums::ReturnType logout();

	// Objects

	// ..

private:
	templates::SharedPointer<Token> token;
	pkcs11::value_types::SessionHandle handle;
};

}}} // namespace flame_ide::pkcs11::wrapper

// class Object
namespace flame_ide
{namespace pkcs11
{namespace wrapper
{

class Object
{
private:
	Object(templates::SharedPointer<Session> session
			, pkcs11::enums::ObjectClass objectClass
			, bool token);

public:
	~Object() noexcept;

	static templates::SharedPointer<Object> create(
			templates::SharedPointer<Session> session
			, pkcs11::enums::ObjectClass objectClass
			, bool token = false
	);

	const templates::SharedPointer<Session> &getSession() const noexcept;
	pkcs11::value_types::ObjectHandle getHandle() const noexcept;

public: // Interface
	pkcs11::enums::ReturnType addAttribute();

private:
	templates::SharedPointer<Session> session;
	pkcs11::value_types::ObjectHandle handle;
};


}}} // namespace flame_ide::pkcs11::wrapper



#endif // FLAMEIDE_CRYPTO_PKCS11_WRAPPER_PKCS11_HPP
