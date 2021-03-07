#include <FlameIDE/../../src/Os/Tests/LibraryTest.hpp>

#include <FlameIDE/Os/Library.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

LibraryTest::LibraryTest() : ::AbstractTest("Library")
{}

LibraryTest::~LibraryTest() = default;

int LibraryTest::vStart()
{
	Library library("SoftPkcs11");
	if (!library)
	{
		return FAILED;
	}

	auto getfuncitonList = library.find<pkcs11::callbacks::GetFunctionList>(
			"C_GetFunctionList"
	);
	if (!getfuncitonList)
	{
		return FAILED;
	}

	return SUCCESS;
}

}}} // namespace flame_ide::os::tests
