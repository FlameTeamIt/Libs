#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCts.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesCts::AesCts() noexcept = default;
AesCts::~AesCts() noexcept = default;

pkcs11::enums::Mechanism AesCts::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_CTS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

