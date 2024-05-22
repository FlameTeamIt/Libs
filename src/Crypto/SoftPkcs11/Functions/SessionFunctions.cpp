#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/SessionFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace session
{

pkcs11::value_types::ReturnType open(
		pkcs11::value_types::SlotId slotId
		, pkcs11::value_types::Flags flags
		, pkcs11::value_types::ValuePtr application
		, pkcs11::callbacks::Notify notifyCallback
		, pkcs11::value_types::SessionHandlePtr session
)
{
	flame_ide::unused(slotId);
	flame_ide::unused(flags);
	flame_ide::unused(application);
	flame_ide::unused(notifyCallback);
	flame_ide::unused(session);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType close(pkcs11::value_types::SessionHandle session)
{
	flame_ide::unused(session);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType closeAll(pkcs11::value_types::SlotId slotId)
{
	flame_ide::unused(slotId);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getInfo(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::SessionInfoPtr info
)
{
	flame_ide::unused(session);
	flame_ide::unused(info);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getOperationState(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr operationState
		, pkcs11::value_types::UlongPtr operationStateLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(operationState);
	flame_ide::unused(operationStateLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType setOperationState(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr operationState
		, pkcs11::value_types::Ulong operationStateLength
		, pkcs11::value_types::ObjectHandle encryptionKey
		, pkcs11::value_types::ObjectHandle authenticationKey
)
{
	flame_ide::unused(session);
	flame_ide::unused(operationState);
	flame_ide::unused(operationStateLength);
	flame_ide::unused(encryptionKey);
	flame_ide::unused(authenticationKey);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType login(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::User userType
		, pkcs11::value_types::Utf8CharPtr pin
		, pkcs11::value_types::Ulong pinLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(userType);
	flame_ide::unused(pin);
	flame_ide::unused(pinLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType logout(pkcs11::value_types::SessionHandle session)
{
	flame_ide::unused(session);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

// v3.0

pkcs11::value_types::ReturnType loginUser(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::User user
		, pkcs11::value_types::Utf8CharPtr pin
		, pkcs11::value_types::Ulong pinLength
		, pkcs11::value_types::Utf8CharPtr username
		, pkcs11::value_types::Ulong usernameLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(user);
	flame_ide::unused(pin);
	flame_ide::unused(pinLength);
	flame_ide::unused(username);
	flame_ide::unused(usernameLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType sessionCancel(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::Flags flags
)
{
	flame_ide::unused(session);
	flame_ide::unused(flags);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::session
