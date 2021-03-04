#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackCfb64.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SkipjackCfb64::SkipjackCfb64() noexcept = default;
SkipjackCfb64::~SkipjackCfb64() noexcept = default;

pkcs11::enums::Mechanism SkipjackCfb64::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SKIPJACK_CFB64;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

