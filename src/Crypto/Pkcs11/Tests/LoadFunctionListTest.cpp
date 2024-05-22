#include <FlameIDE/../../src/Crypto/Pkcs11/Tests/LoadFunctionListTest.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Callbacks.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/FunctionList.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/FunctionList3.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Interface.hpp>

namespace flame_ide
{namespace pkcs11
{namespace tests
{

LoadFunctionListTest::LoadFunctionListTest(flame_ide::os::Library &pkcs11Library)
		: ::AbstractTest("LoadFunctionListTest")
		, pkcs11Library{ pkcs11Library }
{}

int LoadFunctionListTest::vStart()
{
	if (loadFunctionList() && loadFunctionList3())
	{
		return ::AbstractTest::SUCCESS;
	}
	return ::AbstractTest::FAILED;
}

bool LoadFunctionListTest::loadFunctionList() noexcept
{
	auto getFunctionList = pkcs11Library.find<pkcs11::callbacks::GetFunctionList>("C_GetFunctionList");
	if (!getFunctionList)
	{
		return false;
	}

	pkcs11::structs::FunctionListPtr functionList = nullptr;
	auto result = getFunctionList(&functionList);
	if (result != CKR_OK || !functionList)
	{
		return false;
	}

	return true;
}

bool LoadFunctionListTest::loadFunctionList3() noexcept
{
	auto getInterfaceList = pkcs11Library.find<pkcs11::callbacks::GetInterfaceList>("C_GetInterfaceList");
	if (!getInterfaceList)
	{
		return false;
	}

	pkcs11::structs::Interface iface;
	pkcs11::value_types::Ulong count = 0;
	auto result = getInterfaceList(nullptr, &count);
	if (result != CKR_OK || count == 0)
	{
		return false;
	}

	result = getInterfaceList(&iface, &count);
	if (result != CKR_OK)
	{
		return false;
	}

	auto functionList = reinterpret_cast<pkcs11::structs::FunctionList3Ptr>(iface.pFunctionList);
	if (functionList->C_GetInterfaceList != getInterfaceList)
	{
		return false;
	}

	return true;
}

}}} // namespace flame_ide::pkcs11::tests
