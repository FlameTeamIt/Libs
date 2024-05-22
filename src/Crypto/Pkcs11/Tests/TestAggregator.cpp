#include <FlameIDE/../../src/Crypto/Pkcs11/Tests/TestAggregator.hpp>

#include <FlameIDE/../../src/Crypto/Pkcs11/Tests/LoadFunctionListTest.hpp>

#include <utility>

namespace flame_ide
{namespace pkcs11
{namespace tests
{

TestAggregator::TestAggregator()
	: ::TestAggregator("PKCS#11 Wrapper")
	, pkcs11Library("SoftPkcs11", SHARED_LIBRARY_DIRECTORY)
{
	if (!pkcs11Library)
	{
		std::cerr << "Load PKCS#11 library failed" << std::endl;
		return;
	}

	this->pushBackTest(
			std::make_shared<LoadFunctionListTest>(pkcs11Library)
	);
}

}}} // namespace flame_ide::pkcs11::tests
