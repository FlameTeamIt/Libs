#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesGcm.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesGcm::AesGcm() noexcept = default;
AesGcm::~AesGcm() noexcept = default;

pkcs11::enums::Mechanism AesGcm::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_GCM;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

