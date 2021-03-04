#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesOfb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesOfb::AesOfb() noexcept = default;
AesOfb::~AesOfb() noexcept = default;

pkcs11::enums::Mechanism AesOfb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_OFB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

