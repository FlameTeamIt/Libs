#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackCfb32.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SkipjackCfb32::SkipjackCfb32() noexcept = default;
SkipjackCfb32::~SkipjackCfb32() noexcept = default;

pkcs11::enums::Mechanism SkipjackCfb32::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SKIPJACK_CFB32;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

