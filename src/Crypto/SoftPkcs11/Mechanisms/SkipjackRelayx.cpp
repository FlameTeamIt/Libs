#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackRelayx.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SkipjackRelayx::SkipjackRelayx() noexcept = default;
SkipjackRelayx::~SkipjackRelayx() noexcept = default;

pkcs11::enums::Mechanism SkipjackRelayx::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SKIPJACK_RELAYX;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

