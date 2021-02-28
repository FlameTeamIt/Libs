#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonShuffle.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

BatonShuffle::BatonShuffle() noexcept = default;
BatonShuffle::~BatonShuffle() noexcept = default;

pkcs11::enums::Mechanism BatonShuffle::getType() const noexcept
{
	return pkcs11::enums::Mechanism::BATON_SHUFFLE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

