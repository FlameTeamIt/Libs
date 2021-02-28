#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCtr.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesCtr::AesCtr() noexcept = default;
AesCtr::~AesCtr() noexcept = default;

pkcs11::enums::Mechanism AesCtr::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_CTR;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

