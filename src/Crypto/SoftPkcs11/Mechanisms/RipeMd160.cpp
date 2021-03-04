#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd160.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RipeMd160::RipeMd160() noexcept = default;
RipeMd160::~RipeMd160() noexcept = default;

pkcs11::enums::Mechanism RipeMd160::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RIPEMD160;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

