#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/JuniperShuffle.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

JuniperShuffle::JuniperShuffle() noexcept = default;
JuniperShuffle::~JuniperShuffle() noexcept = default;

pkcs11::enums::Mechanism JuniperShuffle::getType() const noexcept
{
	return pkcs11::enums::Mechanism::JUNIPER_SHUFFLE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

