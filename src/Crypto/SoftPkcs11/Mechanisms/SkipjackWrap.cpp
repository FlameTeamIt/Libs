#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackWrap.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SkipjackWrap::SkipjackWrap() noexcept = default;
SkipjackWrap::~SkipjackWrap() noexcept = default;

pkcs11::enums::Mechanism SkipjackWrap::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SKIPJACK_WRAP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

