#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackCfb8.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SkipjackCfb8::SkipjackCfb8() noexcept = default;
SkipjackCfb8::~SkipjackCfb8() noexcept = default;

pkcs11::enums::Mechanism SkipjackCfb8::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SKIPJACK_CFB8;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

