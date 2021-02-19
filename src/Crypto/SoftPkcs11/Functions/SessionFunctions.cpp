#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/SessionFunctions.hpp>

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
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType close(pkcs11::value_types::SessionHandle session)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType closeAll(pkcs11::value_types::SlotId slotId)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getInfo(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::SessionInfoPtr info
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getOperationState(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr operationState
		, pkcs11::value_types::UlongPtr operationStateLength
)
{
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
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType login(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::User userType
		, pkcs11::value_types::Utf8CharPtr pin
		, pkcs11::value_types::Ulong pinLength
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType logout(pkcs11::value_types::SessionHandle session)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::session
