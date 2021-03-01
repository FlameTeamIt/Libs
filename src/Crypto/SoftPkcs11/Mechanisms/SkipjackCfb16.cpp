#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackCfb16.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SkipjackCfb16::SkipjackCfb16() noexcept = default;
SkipjackCfb16::~SkipjackCfb16() noexcept = default;

pkcs11::enums::Mechanism SkipjackCfb16::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SKIPJACK_CFB16;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

