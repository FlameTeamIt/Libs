#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackOfb64.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SkipjackOfb64::SkipjackOfb64() noexcept = default;
SkipjackOfb64::~SkipjackOfb64() noexcept = default;

pkcs11::enums::Mechanism SkipjackOfb64::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SKIPJACK_OFB64;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

