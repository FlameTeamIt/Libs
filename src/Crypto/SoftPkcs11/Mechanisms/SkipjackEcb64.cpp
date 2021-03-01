#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackEcb64.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SkipjackEcb64::SkipjackEcb64() noexcept = default;
SkipjackEcb64::~SkipjackEcb64() noexcept = default;

pkcs11::enums::Mechanism SkipjackEcb64::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SKIPJACK_ECB64;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

