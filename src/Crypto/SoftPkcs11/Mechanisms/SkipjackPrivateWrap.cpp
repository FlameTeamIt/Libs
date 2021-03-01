#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackPrivateWrap.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SkipjackPrivateWrap::SkipjackPrivateWrap() noexcept = default;
SkipjackPrivateWrap::~SkipjackPrivateWrap() noexcept = default;

pkcs11::enums::Mechanism SkipjackPrivateWrap::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SKIPJACK_PRIVATE_WRAP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

