#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/GeneralPurposeFunctions.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace general_purpose
{

pkcs11::value_types::ReturnType initialize(pkcs11::value_types::ValuePtr)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType finalize(pkcs11::value_types::ValuePtr)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getInfo(pkcs11::structs::InfoPtr info)
{
	(void)info;
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getFunctionList(
		pkcs11::structs::FunctionListPtrPtr functionList
)
{
	(void)functionList;
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::service
