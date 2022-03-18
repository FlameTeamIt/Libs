#ifndef FLAMEIDE_SRC_CRYPTO_PKCS11_TESTS_TESTAGGREGATOR_HPP
#define FLAMEIDE_SRC_CRYPTO_PKCS11_TESTS_TESTAGGREGATOR_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Os/Library.hpp>

namespace flame_ide
{namespace pkcs11
{namespace tests
{

class TestAggregator: public ::TestAggregator
{
public:
	TestAggregator();
	virtual ~TestAggregator() override = default;

protected:
	flame_ide::os::Library pkcs11Library;
};

}}} // namespace flame_ide::pkcs11::tests

#endif // FLAMEIDE_SRC_CRYPTO_PKCS11_TESTS_TESTAGGREGATOR_HPP
