#ifndef FLAMEIDE_SRC_CRYPTO_PKCS11_TESTS_LOADFUNCTIONLISTTEST_HPP
#define FLAMEIDE_SRC_CRYPTO_PKCS11_TESTS_LOADFUNCTIONLISTTEST_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Os/Library.hpp>

namespace flame_ide
{namespace pkcs11
{namespace tests
{

class LoadFunctionListTest: public ::AbstractTest
{
public:
	LoadFunctionListTest(flame_ide::os::Library &pkcs11Library);
	virtual ~LoadFunctionListTest() override = default;

private:
	virtual int vStart() override;

	bool loadFunctionList() noexcept;
	bool loadFunctionList3() noexcept;

private:
	flame_ide::os::Library &pkcs11Library;

};

}}} // namespace flame_ide::pkcs11::tests

#endif // FLAMEIDE_SRC_CRYPTO_PKCS11_TESTS_LOADFUNCTIONLISTTEST_HPP
