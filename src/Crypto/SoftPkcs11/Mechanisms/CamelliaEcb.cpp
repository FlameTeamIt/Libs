#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaEcb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CamelliaEcb::CamelliaEcb() noexcept = default;
CamelliaEcb::~CamelliaEcb() noexcept = default;

pkcs11::enums::Mechanism CamelliaEcb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAMELLIA_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

