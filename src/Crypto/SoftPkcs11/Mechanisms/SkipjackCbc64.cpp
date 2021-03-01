#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackCbc64.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SkipjackCbc64::SkipjackCbc64() noexcept = default;
SkipjackCbc64::~SkipjackCbc64() noexcept = default;

pkcs11::enums::Mechanism SkipjackCbc64::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SKIPJACK_CBC64;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

